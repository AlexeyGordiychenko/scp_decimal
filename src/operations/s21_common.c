#include "s21_common.h"

int check_bit(unsigned int numb, int pos) {
  int a = 1 << pos;
  return (numb & a) > 0 ? 1 : 0;
}

void print_binary(unsigned int num) {
  if (num > 1) {
    print_binary(num >> 1);
  }
  printf("%u", num % 2);
}

void print_full_binary(unsigned int num) {
  for (unsigned int i = 1 << S21_SIGN_SHIFT; i > 0; i = i >> 1) {
    if ((num & i) != 0)
      printf("1");
    else
      printf("0");
  }
}

void print_decimal_bits(s21_decimal obj) {
  printf("data : [");
  print_full_binary(obj.bits[3]);
  printf("] num : [");
  print_full_binary(obj.bits[2]);
  printf("] [");
  print_full_binary(obj.bits[1]);
  printf("] [");
  print_full_binary(obj.bits[0]);
  printf("]\n");
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

int get_decimal_exp(s21_decimal d) {
  return (d.bits[3] >> S21_EXP_SHIFT) & 0xFF;
}

void set_decimal_sign(s21_decimal *d, int sign) {
  d->bits[3] = (d->bits[3] & 0x7FFFFFFF) | (sign << S21_SIGN_SHIFT);
}

void set_decimal_exp(s21_decimal *d, int exp) {
  d->bits[3] = (d->bits[3] & 0xFF00FFFF) | (exp << S21_EXP_SHIFT);
}

int decimal_is_zero(s21_decimal d) {
  return d.bits[0] == 0 && d.bits[1] == 0 && d.bits[2] == 0;
}

int mantissa_is_equal(s21_decimal d1, s21_decimal d2) {
  return d1.bits[0] == d2.bits[0] && d1.bits[1] == d2.bits[1] &&
         d1.bits[2] == d2.bits[2];
}

int mantissa_is_less(s21_decimal d1, s21_decimal d2) {
  int res = 0;
  if (d1.bits[2] != d2.bits[2]) {
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

  if (multiply_mantissa_by_10(d)) {
    set_decimal_exp(d, ++exp);
    res = exp;
  }

  return res;
}

int divide_by_10(s21_decimal *d, int with_round) {
  // divide bits[0-2] by 10, and decrease exp
  // return the new exp
  int exp = get_decimal_exp(*d);
  int new_exp = exp;
  s21_decimal tmp_d = *d;

  // Divide the 96-bit integer by 10.
  unsigned long long remainder = 0;

  for (int i = 2; i >= 0; --i) {
    unsigned long long temp = (remainder << 32) | tmp_d.bits[i];
    tmp_d.bits[i] = (unsigned int)(temp / 10);
    remainder = temp % 10;
  }

  if (remainder != 0 && exp < S21_MAX_EXP) {
    // can't change mantissa but can increase exp
    new_exp++;
  } else {
    if (exp > S21_MAX_EXP) new_exp--;
    // Bank rounding (round half to even)
    if (with_round &&
        ((remainder > 5 || (remainder == 5 && tmp_d.bits[0] & 1)))) {
      tmp_d.bits[0]++;
    }
    // If after dividing/rounding we have 0 in mantissa then set exp to zero too
    if (decimal_is_zero(tmp_d)) new_exp = 0;
    *d = tmp_d;
  }

  if (exp != new_exp) set_decimal_exp(d, new_exp);

  return new_exp;
}

int decrease_exp(s21_decimal *d, bool with_round) {
  // divide bits[0-2] by 10, and decrease exp
  // return the new exp

  int exp = get_decimal_exp(*d);
  if (exp == 0) return exp;

  divide_mantissa_by_10(d, with_round);
  set_decimal_exp(d, --exp);

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

  while (exp1 > min_exp) {
    exp1 = decrease_exp(d1, (exp1 == (min_exp + 1) && min_exp != S21_MAX_EXP));
  }
  while (exp2 > min_exp) {
    exp2 = decrease_exp(d2, (exp2 == (min_exp + 1) && min_exp != S21_MAX_EXP));
  }
}

int decimal_comparison(s21_decimal value_1, s21_decimal value_2, int mode) {
  int res = false;

  int value1_zero = decimal_is_zero(value_1);
  int value2_zero = decimal_is_zero(value_2);
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
      eq = mantissa_is_equal(value_1, value_2);
    }
    if (mode == S21_LESS || mode == S21_LESS_OR_EQUAL) {
      less = (value1_sign) ? mantissa_is_less(value_2, value_1)
                           : mantissa_is_less(value_1, value_2);
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
    decrease_exp(&value_1, 1);
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
    sum_same_sign(value_1, value_2, result);
  }
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
       check_bit(value_2.bits[3], 31) == 1)) {  // (-v1) + (+v2) и (v1) + (-v2)
    flag = s21_sub(value_1, value_2, result);
  }
  return flag;
}

void divide_mantissa_by_10(s21_decimal *d, bool with_round) {
  // Divide the 96-bit integer by 10.

  unsigned long long remainder = 0;

  for (int i = 2; i >= 0; --i) {
    unsigned long long temp = (remainder << 32) | d->bits[i];
    d->bits[i] = (unsigned int)(temp / 10);
    remainder = temp % 10;
  }

  // Bank rounding (round half to even)
  if (with_round && ((remainder > 5 || (remainder == 5 && d->bits[0] & 1)))) {
    d->bits[0]++;
  }
}

bool multiply_mantissa_by_10(s21_decimal *d) {
  // returns true and modifies the decimal if the multiplication is within
  // bounds returns false and don't touch the decimal otherwise

  bool res = false;
  s21_decimal tmp_d = *d;
  unsigned long long carry = 0;

  for (int i = 0; i <= 2; i++) {
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

bool subtract_bits(s21_decimal *minuend, s21_decimal subtrahend) {
  unsigned long long borrow = 0;
  bool res = true;
  s21_decimal tmp = *minuend;

  for (int i = 0; i < 3; i++) {
    unsigned long long temp =
        (unsigned long long)tmp.bits[i] - subtrahend.bits[i] - borrow;
    tmp.bits[i] = (unsigned int)temp;
    borrow = (temp >> 32) & 1;
  }

  if (borrow) {
    res = false;
  } else {
    *minuend = tmp;
  }

  return res;
}

bool add_bits(s21_decimal *accumulator, s21_decimal addend) {
  unsigned long long sum;
  unsigned long long carry = 0;
  bool res = true;
  s21_decimal tmp = *accumulator;

  for (int i = 0; i < 3; i++) {
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

bool left_shift_bits(s21_decimal *d) {
  bool res = true;
  unsigned long long carry = 0;
  s21_decimal tmp = *d;

  for (int i = 0; i < 3; i++) {
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

void right_shift_bits(s21_decimal *d) {
  unsigned long long carry = 0;
  for (int i = 2; i >= 0; i--) {
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

void div_mantissas(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *quotient, s21_decimal *remainder) {
  s21_decimal temp_divisor = value_2;
  s21_decimal temp_remainder = value_1;
  temp_divisor.bits[3] = 0;
  temp_remainder.bits[3] = 0;

  *quotient = S21_D_ZERO;

  int shift_count = 0;
  while (s21_is_less_or_equal(temp_divisor, temp_remainder) && ++shift_count &&
         left_shift_bits(&temp_divisor)) {
  }

  if (s21_is_greater(temp_divisor, temp_remainder)) {
    right_shift_bits(&temp_divisor);
  }
  for (int i = 0; i < shift_count; i++) {
    if (s21_is_greater_or_equal(temp_remainder, temp_divisor)) {
      subtract_bits(&temp_remainder, temp_divisor);
      set_bit96(quotient, shift_count - 1 - i);
    }
    right_shift_bits(&temp_divisor);
  }

  *remainder = temp_remainder;
}

void from_float_to_decimal_small(float src, s21_decimal *dst) {
  dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;

  int sign = 0;
  if (src < 0) {
    sign = 1;
    src = -src;
  }

  int reminder = 0;
  while (src < 1) {
    src *= 10;
    ++reminder;
  }

  unsigned long num = src;
  unsigned long next = src;
  for (int i = 0; next < powf(2, 32) && i < 100; ++i) {
    num = next;
    next = src * powf(10, i);
  }

  int exp = floor(log10(num) + 1) - floor(log10(src) + 1) + reminder;

  if (exp > 0) {
    dst->bits[3] = (exp << S21_EXP_SHIFT);
  }
  if (sign == 1) {
    dst->bits[3] = set_bit(dst->bits[3], 31);
  }

  for (int i = 0; i < 32; ++i) {
    if ((num & 1) == 1) dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
    num = num >> 1;
  }
}

void from_float_to_decimal_medium(float src, s21_decimal *dst) {
  dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;

  int sign = 0;
  if (src < 0) {
    sign = 1;
    src = -src;
  }

  unsigned long long num = src;
  unsigned long long next = src;
  for (int i = 0; next < powf(2, 64) && i < 100; ++i) {
    num = next;
    next = src * powf(10, i);
  }

  int exp = floorf(log10(num) + 1) - floorf(log10(src) + 1);

  if (exp > 0) {
    dst->bits[3] = (exp << S21_EXP_SHIFT);
  }
  if (sign == 1) {
    dst->bits[3] = set_bit(dst->bits[3], 31);
  }

  for (int i = 0; i < 64; ++i) {
    if ((num & 1) == 1) dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
    num = num >> 1;
  }
}

void from_float_to_decimal_large(float src, s21_decimal *dst) {
  dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;

  int sign = 0;
  if (src < 0) {
    sign = 1;
    src = -src;
  }

  float scaledValue = src;

  for (int i = 0; i < 96; ++i) {
    if (fmodf(floorf(scaledValue), 2) == 1)
      dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
    scaledValue /= 2;
  }

  if (sign == 1) {
    dst->bits[3] = set_bit(dst->bits[3], 31);
  }
}
