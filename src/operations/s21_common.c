#include "s21_common.h"

#include <stdint.h>

int check_bit(unsigned int numb, int pos) {
  int a = 1u << pos;
  return (numb & a) > 0 ? 1 : 0;
}

unsigned int set_bit(unsigned int numb, int pos) {
  int bit = check_bit(numb, pos);
  if (bit == 0) {
    numb |= (1 << pos);
  } else {
    numb &= ~(1 << pos);
  }
  return numb;
}

int get_decimal_sign(s21_decimal d) {
  return (d.bits[3] >> S21_SIGN_SHIFT) & 0x1;
}

// int get_decimal_sign_big(s21_big_decimal d) {
//   return (d.bits[6] >> S21_SIGN_SHIFT) & 0x1;
// }

int get_decimal_exp(s21_decimal d) {
  return (d.bits[3] >> S21_EXP_SHIFT) & 0xFF;
}

int get_decimal_exp_big(s21_big_decimal d) {
  return (d.bits[6] >> S21_EXP_SHIFT) & 0xFF;
}

void set_decimal_sign(s21_decimal *d, int sign) {
  d->bits[3] = (d->bits[3] & 0x7FFFFFFF) | ((unsigned)sign << S21_SIGN_SHIFT);
}

void set_decimal_exp(s21_decimal *d, int exp) {
  d->bits[3] = (d->bits[3] & 0xFF00FFFF) | ((unsigned)exp << S21_EXP_SHIFT);
}

void set_decimal_exp_big(s21_big_decimal *d, int exp) {
  d->bits[6] = (d->bits[6] & 0xFF00FFFF) | ((unsigned)exp << S21_EXP_SHIFT);
}

int decimal_is_zero(s21_decimal d, bool use_all_bits) {
  return d.bits[0] == 0 && d.bits[1] == 0 && d.bits[2] == 0 &&
         (use_all_bits ? d.bits[3] == 0 : true);
}

int mantissa_is_equal(s21_decimal d1, s21_decimal d2, bool use_all_bits) {
  return d1.bits[0] == d2.bits[0] && d1.bits[1] == d2.bits[1] &&
         d1.bits[2] == d2.bits[2] &&
         (use_all_bits ? d1.bits[3] == d2.bits[3] : true);
}

int mantissa_is_less(s21_decimal d1, s21_decimal d2, bool use_all_bits) {
  int res = 0;
  if (use_all_bits && d1.bits[3] != d2.bits[3]) {
    res = d1.bits[3] < d2.bits[3];
  } else if (d1.bits[2] != d2.bits[2]) {
    res = d1.bits[2] < d2.bits[2];
  } else if (d1.bits[1] != d2.bits[1]) {
    res = d1.bits[1] < d2.bits[1];
  } else if (d1.bits[0] != d2.bits[0]) {
    res = d1.bits[0] < d2.bits[0];
  }
  return res;
}

int increase_exp(s21_decimal *d) {
  // multiply bits[0-2] by 10, and increase exp
  // return the new exp or -1 in case of an error
  int res = -1;

  int exp = get_decimal_exp(*d);
  if (exp >= S21_MAX_EXP) return res;

  if (multiply_mantissa_by_10(d, false)) {
    set_decimal_exp(d, ++exp);
    res = exp;
  }

  return res;
}

int decrease_exp(s21_decimal *d, int n, bool has_reminder, bool with_round) {
  // divide bits[0-2] by 10, and decrease exp
  // return the new exp

  int exp = get_decimal_exp(*d);
  if (exp == 0 || n <= 0) return exp;

  int last_reminder = 0;

  for (int i = 1; i <= n && exp > 0; i++, exp--) {
    last_reminder = divide_mantissa_by_10(d);
    if (!has_reminder && i != n && last_reminder) has_reminder = true;
  }

  if (with_round) {
    bank_rounding(d, last_reminder, has_reminder);
  }

  set_decimal_exp(d, exp);

  return exp;
}

int decrease_exp_big(s21_big_decimal *d, int n, int reminder, bool with_round) {
  int exp = get_decimal_exp_big(*d);
  if (exp == 0 || n <= 0) return exp;

  int last_reminder = reminder;
  bool has_reminder = reminder != 0 ? true : false;

  for (int i = 1; i <= n && exp > 0; i++, exp--) {
    last_reminder = divide_mantissa_by_10_big(d);
    if (!has_reminder && i != n && last_reminder) has_reminder = true;
  }

  if (with_round) {
    bank_rounding_big(d, last_reminder, has_reminder);
  }

  set_decimal_exp_big(d, exp);

  return exp;
}

void decimal_normalization(s21_decimal *d1, s21_decimal *d2) {
  int exp1 = get_decimal_exp(*d1);
  int exp2 = get_decimal_exp(*d2);

  if (exp1 == exp2 && exp1 <= S21_MAX_EXP) return;

  int tmp_exp;

  int max_exp = (exp1 > exp2) ? exp1 : exp2;
  if (max_exp > S21_MAX_EXP) max_exp = S21_MAX_EXP;

  // increase to the max
  if (max_exp > exp1) {
    while ((tmp_exp = increase_exp(d1)) && tmp_exp != -1 && max_exp > exp1++)
      ;
  }
  if (max_exp > exp2) {
    while ((tmp_exp = increase_exp(d2)) && tmp_exp != -1 && max_exp > exp2++)
      ;
  }

  // if increase didn't help, then descrease
  int min_exp = (exp1 > exp2) ? exp2 : exp1;
  if (min_exp > S21_MAX_EXP) min_exp = S21_MAX_EXP;

  decrease_exp(d1, exp1 - min_exp, false, true);
  decrease_exp(d2, exp2 - min_exp, false, true);
}

int decimal_comparison(s21_decimal value_1, s21_decimal value_2, int mode) {
  int res = false;

  int value1_zero = decimal_is_zero(value_1, false);
  int value2_zero = decimal_is_zero(value_2, false);
  int value1_sign = get_decimal_sign(value_1);
  int value2_sign = get_decimal_sign(value_2);

  if (value1_zero && value2_zero) {
    res = (mode != S21_LESS);
  } else if (value1_zero || value2_zero) {
    res = mode != S21_EQUAL &&
          ((value1_zero && !value2_sign) || (value2_zero && value1_sign));
  } else if (value1_sign != value2_sign) {
    res = mode != S21_EQUAL && value1_sign;
  } else {
    decimal_normalization(&value_1, &value_2);

    int eq = false;
    int less = false;
    if (mode == S21_EQUAL || mode == S21_LESS_OR_EQUAL) {
      eq = mantissa_is_equal(value_1, value_2, false);
    }
    if (mode == S21_LESS || mode == S21_LESS_OR_EQUAL) {
      less = (value1_sign) ? mantissa_is_less(value_2, value_1, false)
                           : mantissa_is_less(value_1, value_2, false);
    }

    if (mode == S21_EQUAL) {
      res = eq;
    } else if (mode == S21_LESS) {
      res = less;
    } else if (mode == S21_LESS_OR_EQUAL) {
      res = eq || less;
    }
  }
  return res;
}

int sum_same_sign(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result) {
  set_same_exp(value_1, result);
  int carry = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      int sum =
          check_bit(value_1.bits[i], j) + check_bit(value_2.bits[i], j) + carry;
      carry = 0;
      if (sum == 1) (*result).bits[i] = set_bit((*result).bits[i], j);
      if (sum == 2) carry = 1;
      if (sum == 3) {
        carry = 1;
        (*result).bits[i] = set_bit((*result).bits[i], j);
      }
    }
  }
  if (carry != 0 && get_decimal_exp(value_1) == 0)
    return S21_HUGE_ERR;
  else if (carry != 0) {
    decrease_exp(&value_1, 1, false, true);
    decrease_exp(&value_2, 1, false, true);
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
    sum_same_sign(value_1, value_2, result);
  }
  return S21_OK;
}

int sum_same_sign_big(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result) {
  int carry = 0;
  for (int i = 0; i < 192; i++) {
    int sum = get_bit192(value_1, i) + get_bit192(value_2, i) + carry;
    carry = 0;
    if (sum == 1) set_bit192(result, i);
    if (sum == 2) {
      carry = 1;
      set_zero_bit192(result, i);
    }
    if (sum == 3) {
      carry = 1;
      set_bit192(result, i);
    }
  }
  if (carry != 0 && get_decimal_exp_big(value_1) == 0) return S21_HUGE_ERR;

  return S21_OK;
}

int sub_pos(s21_decimal greater, s21_decimal lower, s21_decimal *result) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      int sum = check_bit(greater.bits[i], j) - check_bit(lower.bits[i], j);
      if (sum == -1) {
        (*result).bits[i] = set_bit((*result).bits[i], j);
        int k = 0;
        int index = j < 31 ? j + 1 : 0;
        if (index == 0) k += 1;
        while (check_bit(greater.bits[i + k], index) != 1) {
          greater.bits[i + k] = set_bit(greater.bits[i + k], index);
          index += 1;
          if (index == 32) {
            k += 1;
            index = 0;
          }
        }
        greater.bits[i + k] = set_bit(greater.bits[i + k], index);
      }
      if (sum == 1) (*result).bits[i] = set_bit((*result).bits[i], j);
    }
  }
  return S21_OK;
}

s21_decimal s21_decimal_fabs(s21_decimal value) {
  if (check_bit(value.bits[3], 31) == 1)
    value.bits[3] = set_bit(value.bits[3], 31);
  return value;
}

void set_same_exp(s21_decimal value, s21_decimal *result) {
  int temp = check_bit(result->bits[3], 31);
  for (int i = 0; i < 32; i++) {
    result->bits[3] = value.bits[3] & 0b01111111111111111111111111111111;
  }
  if (temp == 1) result->bits[3] = set_bit(result->bits[3], 31);
}
int sub_mantis(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  s21_decimal first_val = s21_decimal_fabs(value_1);
  s21_decimal second_val = s21_decimal_fabs(value_2);
  int flag = S21_OK;

  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 0)) {
    if (s21_is_greater_or_equal(first_val,
                                second_val)) {  // |v1|>|v2| (+v1) - (+v2)
      sub_pos(first_val, second_val, result);
    } else {  // |v2|>|v1| (+v1) - (+v2)

      sub_pos(second_val, first_val, result);
      result->bits[3] = set_bit(result->bits[3], 31);
    }
  }

  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 1)) {
    if (s21_is_greater_or_equal(first_val,
                                second_val)) {  // |v1|>|v2| (-v1) - (-v2)
      sub_pos(first_val, second_val, result);
      result->bits[3] = set_bit(result->bits[3], 31);
    } else {  // |v2|>|v1| (-v1) - (-v2)

      sub_pos(second_val, first_val, result);
    }
  }

  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 1)) {  // (+v1) - (-v2)
    flag = s21_add(first_val, second_val, result);
  }

  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 0)) {  // (-v1) - (+v2)
    flag = s21_add(first_val, second_val, result);
    if (flag == S21_HUGE_ERR) flag = S21_SMALL_ERR;
    result->bits[3] = set_bit(result->bits[3], 31);
  }
  return flag;
}

int add_mantis(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int flag = S21_OK;
  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 0)) {  // (+v1) + (+v2)
    flag = sum_same_sign(value_1, value_2, result);
  }
  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 1)) {  // (-v1) + (-v2)
    flag = sum_same_sign(value_1, value_2, result);
    if (flag == S21_HUGE_ERR) flag = S21_SMALL_ERR;
    result->bits[3] = set_bit(result->bits[3], 31);
  }
  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 1)) {  // (v1) + (-v2)
    value_2.bits[3] = set_bit(value_2.bits[3], 31);
    flag = s21_sub(value_1, value_2, result);
  }
  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 0)) {  // (-v1) + (+v2)
    value_1.bits[3] = set_bit(value_1.bits[3], 31);
    flag = s21_sub(value_2, value_1, result);
    if (decimal_is_zero(*result, false) &&
        check_bit(result->bits[3], 31) == 0) {
      result->bits[3] = set_bit(result->bits[3], 31);
    }
  }
  return flag;
}

int divide_mantissa_by_10(s21_decimal *d) {
  // Divide the 96-bit integer by 10.
  unsigned long long remainder = 0;

  for (int i = 2; i >= 0; --i) {
    unsigned long long temp = (remainder << 32) | d->bits[i];
    d->bits[i] = (unsigned int)(temp / 10);
    remainder = temp % 10;
  }

  return (int)remainder;
}

int divide_mantissa_by_10_big(s21_big_decimal *d) {
  unsigned long long remainder = 0;

  for (int i = 5; i >= 0; --i) {
    unsigned int bit = d->bits[i] & S21_MAX4BITS;
    unsigned long long temp = (remainder << 32) | bit;
    bit = (unsigned int)(temp / 10);
    remainder = temp % 10;
    d->bits[i] = bit & S21_MAX4BITS;
  }

  return (int)remainder;
}

bool multiply_mantissa_by_10(s21_decimal *d, bool use_all_bits) {
  // returns true and modifies the decimal if the multiplication is within
  // bounds returns false and don't touch the decimal otherwise

  bool res = false;
  s21_decimal tmp_d = *d;
  unsigned long long carry = 0;
  int i_max = use_all_bits ? 3 : 2;
  for (int i = 0; i <= i_max; i++) {
    unsigned int x = tmp_d.bits[i];
    unsigned long long x_by_8 = (unsigned long long)x << 3;
    unsigned long long x_by_2 = (unsigned long long)x << 1;
    unsigned long long sum = x_by_8 + x_by_2 + carry;

    // Move the lower 32 bits to the current element.
    tmp_d.bits[i] = (unsigned int)(sum & 0xFFFFFFFF);

    // Calculate the carry for the next iteration.
    carry = sum >> 32;
  }

  // Check if there's a carry left after processing all elements.
  if (carry == 0) {
    *d = tmp_d;
    res = true;
  }

  return res;
}

bool subtract_bits(s21_decimal *minuend, s21_decimal subtrahend,
                   bool use_all_bits) {
  if (mantissa_is_less(*minuend, subtrahend, use_all_bits)) {
    return false;
  }

  unsigned long long borrow = 0;
  bool res = true;
  s21_decimal tmp = *minuend;
  int i_max = use_all_bits ? 3 : 2;
  for (int i = 0; i <= i_max; i++) {
    unsigned long long temp =
        (unsigned long long)tmp.bits[i] - subtrahend.bits[i] - borrow;
    tmp.bits[i] = (unsigned int)temp;
    borrow = (temp >> 32) & 1;
  }

  *minuend = tmp;

  return res;
}

bool add_bits(s21_decimal *accumulator, s21_decimal addend) {
  unsigned long long carry = 0;
  bool res = true;
  s21_decimal tmp = *accumulator;

  for (int i = 0; i < 3; i++) {
    unsigned long long sum;
    sum = carry + tmp.bits[i] + addend.bits[i];
    tmp.bits[i] = (unsigned int)(sum & 0xFFFFFFFF);
    carry = (sum >> 32);
  }

  if (carry) {
    res = false;
  } else {
    *accumulator = tmp;
  }
  return res;
}

bool add_bits_big(s21_big_decimal *accumulator, s21_big_decimal addend) {
  unsigned long long carry = 0;
  bool res = true;
  s21_big_decimal tmp = *accumulator;

  for (int i = 0; i < 6; i++) {
    unsigned long long sum;
    sum = carry + tmp.bits[i] + addend.bits[i];
    tmp.bits[i] = (unsigned int)(sum & 0xFFFFFFFF);
    carry = (sum >> 32);
  }

  if (carry) {
    res = false;
  } else {
    *accumulator = tmp;
  }
  return res;
}

bool left_shift_bits(s21_decimal *d, bool use_all_bits) {
  bool res = true;
  unsigned long long carry = 0;
  s21_decimal tmp = *d;

  int i_max = use_all_bits ? 3 : 2;
  for (int i = 0; i <= i_max; i++) {
    unsigned long long new_carry = tmp.bits[i] >> S21_SIGN_SHIFT;
    tmp.bits[i] <<= 1;
    tmp.bits[i] |= (unsigned int)carry;
    carry = new_carry;
  }

  if (carry) {
    res = false;
  } else {
    *d = tmp;
  }
  return res;
}

bool left_shift_bits_big(s21_big_decimal *d) {
  bool res = true;
  unsigned long long carry = 0;
  s21_big_decimal tmp = *d;

  for (int i = 0; i < 6; i++) {
    unsigned long long new_carry = tmp.bits[i] >> S21_SIGN_SHIFT;
    tmp.bits[i] <<= 1;
    tmp.bits[i] |= (unsigned int)carry;
    carry = new_carry;
  }

  if (carry) {
    res = false;
  } else {
    *d = tmp;
  }
  return res;
}

void right_shift_bits(s21_decimal *d, bool use_all_bits) {
  unsigned long long carry = 0;
  int i_max = use_all_bits ? 3 : 2;
  for (int i = i_max; i >= 0; i--) {
    unsigned long long new_carry = d->bits[i] & 1;
    d->bits[i] >>= 1;
    d->bits[i] |= (unsigned int)(carry << S21_SIGN_SHIFT);
    carry = new_carry;
  }
}

void set_bit96(s21_decimal *d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  d->bits[index] |= (1 << bit_offset);
}

void set_bit192(s21_big_decimal *d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  d->bits[index] |= (1 << bit_offset);
}

void set_zero_bit192(s21_big_decimal *d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  d->bits[index] &= ~(1 << bit_offset);
}

int get_bit192(s21_big_decimal d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  return check_bit(d.bits[index], bit_offset);
}

void div_mantissas(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *quotient, s21_decimal *remainder) {
  s21_decimal temp_divisor = value_2;
  s21_decimal temp_remainder = value_1;
  temp_divisor.bits[3] = 0;
  *quotient = S21_D_ZERO;

  int shift_count = 0;
  while ((mantissa_is_less(temp_divisor, temp_remainder, true) ||
          mantissa_is_equal(temp_divisor, temp_remainder, true)) &&
         ++shift_count && left_shift_bits(&temp_divisor, true)) {
  }

  if (!mantissa_is_less(temp_divisor, temp_remainder, true) &&
      !mantissa_is_equal(temp_divisor, temp_remainder, true)) {
    right_shift_bits(&temp_divisor, true);
  }
  for (int i = 0; i < shift_count; i++) {
    if (subtract_bits(&temp_remainder, temp_divisor, true)) {
      set_bit96(quotient, shift_count - 1 - i);
    }
    right_shift_bits(&temp_divisor, true);
  }

  *remainder = temp_remainder;
}

double conv_round(float src) {
  char e[64];
  sprintf(e, "%E", src);

  int sign = src < 0 ? 1 : 0;
  double new_src = 0;

  int mypow = 0;
  for (int i = 0 + sign; i < 8 + sign; ++i) {
    if (e[i] >= '0' && e[i] <= '9') {
      new_src += (e[i] - '0') * pow(10, -mypow);
      mypow++;
    }
  }

  int myexp = 0;
  for (int i = 10 + sign; e[i] != '\0'; ++i) {
    myexp *= 10;
    myexp += e[i] - '0';
  }

  if (e[9 + sign] == '+') {
    new_src *= pow(10, myexp);
  } else {
    new_src /= pow(10, myexp);
  }

  if (sign) new_src = -new_src;
  return new_src;
}

void convert_to_decimal(double src, s21_decimal *dst) {
  dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;

  int sign = 0;
  if (src < 0) {
    sign = 1;
    src = -src;
  }

  const double max_dec = (pow(2, 96) - 1);
  double scaled_value = src;
  int scale = 0;

  while (scaled_value <= max_dec && scale < 28 &&
         scaled_value != floor(scaled_value)) {
    scaled_value *= 10.;
    scale++;
  }

  double mypow = pow(10., scale);

  while (scaled_value <= max_dec && scale < 28 && scaled_value / mypow != src) {
    scale++;
    scaled_value = src * pow(10., scale);

    mypow = pow(10., scale);
  }

  dst->bits[3] = (scale << 16) | (sign << 31);
  for (int i = 0; i < 96; ++i) {
    if (fmod(floor(scaled_value), 2) == 1)
      dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
    scaled_value /= 2;
  }
}

int truncate_trailing_zeros(s21_decimal *d, int from_exp, int to_exp) {
  // remove the trailing zeros from decimal
  // and decrease exp

  // int exp = get_decimal_exp(*d);
  int exp_new = from_exp;
  bool res = true;
  while (exp_new > to_exp && res) {
    s21_decimal tmp = *d;
    if (divide_mantissa_by_10(&tmp) == 0) {
      exp_new--;
      *d = tmp;
    } else {
      res = false;
    }
  }
  if (from_exp != exp_new) set_decimal_exp(d, exp_new);
  return exp_new;
}

void bank_rounding(s21_decimal *d, int quotient, bool has_reminder) {
  if (quotient > 5 || (quotient == 5 && (d->bits[0] & 1 || has_reminder))) {
    add_bits(d, S21_D_ONE);
  }
}

void bank_rounding_big(s21_big_decimal *d, int quotient, bool has_reminder) {
  if (quotient > 5 || (quotient == 5 && (d->bits[0] & 1 || has_reminder))) {
    add_bits_big(d, S21_D_ONE_BIG);
  }
}

void from_big_to_decimal_with_rounding(s21_big_decimal *mul_res) {
  if (((mul_res->bits[3] != 0 || mul_res->bits[4] != 0 ||
        mul_res->bits[5] != 0) &&
       get_decimal_exp_big(*mul_res) > 0) ||
      get_decimal_exp_big(*mul_res) > 28) {
    s21_big_decimal temp = *mul_res;
    int reminder = 0;
    int n = 0;
    int flag = 0;
    if (get_decimal_exp_big(*mul_res) > 28) {
      n = get_decimal_exp_big(*mul_res) - 28;
      decrease_exp_big(&temp, get_decimal_exp_big(*mul_res) - 28, reminder, 1);
      reminder = 0;

      if ((temp.bits[3] != 0 || temp.bits[4] != 0 || temp.bits[5] != 0) &&
          get_decimal_exp_big(temp) > 0) {
        s21_big_decimal temp1 = *mul_res;
        decrease_exp_big(&temp1, get_decimal_exp_big(*mul_res) + 1 - 28,
                         reminder, 0);
        while (
            ((temp1.bits[3] != 0 || temp1.bits[4] != 0 || temp1.bits[5] != 0) &&
             get_decimal_exp_big(temp1) > 0)) {
          decrease_exp_big(&temp1, 1, reminder, 0);
          n += 1;
        }
        n += 1;
      }
      flag = 1;
    }
    if ((temp.bits[3] != 0 || temp.bits[4] != 0 || temp.bits[5] != 0) &&
        get_decimal_exp_big(temp) > 0 && flag == 0) {
      if ((temp.bits[3] != 0 || temp.bits[4] != 0 || temp.bits[5] != 0) &&
          get_decimal_exp_big(temp) > 0) {
        s21_big_decimal temp1 = *mul_res;
        decrease_exp_big(&temp, get_decimal_exp_big(*mul_res) - 28, reminder,
                         0);
        while (
            ((temp1.bits[3] != 0 || temp1.bits[4] != 0 || temp1.bits[5] != 0) &&
             get_decimal_exp_big(temp1) > 0)) {
          decrease_exp_big(&temp1, 1, reminder, 0);
          n += 1;
        }
      }
    }
    decrease_exp_big(&*mul_res, n, 0, 1);
  }
}

s21_big_decimal bits_mult(s21_big_decimal *value_1_big,
                          s21_big_decimal *value_2_big, int *flag) {
  s21_big_decimal mul_res_tmp = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal mul_res = {{0, 0, 0, 0, 0, 0, 0}};
  int i = 0;
  while ((value_1_big->bits[0] != 0 || value_1_big->bits[1] != 0 ||
          value_1_big->bits[2] != 0 || value_1_big->bits[3] != 0 ||
          value_1_big->bits[4] != 0 || value_1_big->bits[5] != 0) &&
         i < 192) {
    if (get_bit192((*value_1_big), i) != 0) {
      mul_res_tmp = mul_res;
      int err_code = sum_same_sign_big(mul_res_tmp, *value_2_big, &mul_res);
      if (err_code == S21_HUGE_ERR) {
        *flag = S21_HUGE_ERR;
        i = 192;
      }
      set_zero_bit192(&(*value_1_big), i);
    }
    left_shift_bits_big(&(*value_2_big));
    i++;
  }
  return mul_res;
}

int get_div_result(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result, int result_sign, int exp1, int exp2) {
  int res = S21_OK;
  int exp = exp1 - exp2;
  int max_exp = (exp1 > exp2) ? exp1 : exp2;

  s21_decimal quotient = S21_D_ZERO;
  s21_decimal remainder = value_1;
  remainder.bits[3] = 0;  // we will use all 4 bits
  int tmp_quotient_int = 0;

  // Perform the division operation on the 96-bit integer numbers
  if (mantissa_is_equal(value_1, value_2, false)) {
    quotient = S21_D_ONE;
  } else {
    div_mantissas(remainder, value_2, &quotient, &remainder);
    while (!decimal_is_zero(remainder, true) && exp <= (S21_MAX_EXP + 1) &&
           multiply_mantissa_by_10(&remainder, true)) {
      s21_decimal tmp_quotient;
      div_mantissas(remainder, value_2, &tmp_quotient, &remainder);
      if (multiply_mantissa_by_10(&quotient, false) &&
          add_bits(&quotient, tmp_quotient)) {
        exp++;
      } else {
        max_exp = 0;
        tmp_quotient_int = tmp_quotient.bits[0];
        break;
      }
    }
  }

  bool has_reminder = !decimal_is_zero(remainder, true);

  // Store the result and ajust the final value (exp, rounding, trailing zeros)
  *result = quotient;
  if (exp < 0) {
    for (; exp && multiply_mantissa_by_10(result, false); exp++) {
    }
  }
  if (exp < 0) {
    res = result_sign ? S21_SMALL_ERR : S21_HUGE_ERR;
  } else {
    set_decimal_exp(result, exp);
    set_decimal_sign(result, result_sign);
    if (exp > S21_MAX_EXP) {
      exp = decrease_exp(result, exp - S21_MAX_EXP, has_reminder, true);
    } else {
      bank_rounding(result, tmp_quotient_int, has_reminder);
    }
    truncate_trailing_zeros(result, exp, max_exp);
  }
  return res;
}
