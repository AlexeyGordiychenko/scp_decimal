#include "scp_common.h"

#include <stdint.h>

/**
 * @brief Raturn value of certain bit
 * @param numb Number
 * @param pos Bit position
 * @return num Bit value
 */
int check_bit(unsigned int numb, int pos) {
  int a = 1u << pos;
  return (numb & a) > 0 ? 1 : 0;
}

/**
 * @brief Change value of a certain bit
 * @param numb Number
 * @param pos Bit position
 * @return numb Changed number
 */
unsigned int set_bit(unsigned int numb, int pos) {
  int bit = check_bit(numb, pos);
  if (bit == 0) {
    numb |= (1 << pos);
  } else {
    numb &= ~(1 << pos);
  }
  return numb;
}

/**
 * @brief Raturn value of a sign bit
 * @param d Number
 * @return num Value of sign bit
 */
int get_decimal_sign(scp_decimal d) {
  return (d.bits[3] >> SCP_SIGN_SHIFT) & 0x1;
}

/**
 * @brief Sets value of a sign bit
 * @param d Number
 * @param sign Sign value
 * @return num Value of exp bit
 */
void set_decimal_sign(scp_decimal *d, int sign) {
  d->bits[3] = (d->bits[3] & 0x7FFFFFFF) | ((unsigned)sign << SCP_SIGN_SHIFT);
}

/**
 * @brief Raturn value of a sign bit
 * @param d Number
 * @return num Value of sign bit
 */
int get_decimal_exp(scp_decimal d) {
  return (d.bits[3] >> SCP_EXP_SHIFT) & 0xFF;
}

/**
 * @brief Sets value of a exp bit
 * @param d Number
 * @param exp Exp value
 * @return num Value of exp bit
 */
void set_decimal_exp(scp_decimal *d, int exp) {
  d->bits[3] = (d->bits[3] & 0xFF00FFFF) | ((unsigned)exp << SCP_EXP_SHIFT);
}

/**
 * @brief Raturn value of a exp bit from scp_big_decimal
 * @param d Number
 * @return num Value of exp bit
 */
int get_decimal_exp_big(scp_big_decimal d) {
  return (d.bits[6] >> SCP_EXP_SHIFT) & 0xFF;
}

/**
 * @brief Sets value of a exp bit in scp_big_decimal
 * @param d Number
 * @param exp Exp value
 * @return num Value of exp bit
 */
void set_decimal_exp_big(scp_big_decimal *d, int exp) {
  d->bits[6] = (d->bits[6] & 0xFF00FFFF) | ((unsigned)exp << SCP_EXP_SHIFT);
}

/**
 * @brief Check if number is zero
 * @param d Number
 * @param use_all_bits Flag
 * @return num Result of checking
 */
int decimal_is_zero(scp_decimal d, bool use_all_bits) {
  return d.bits[0] == 0 && d.bits[1] == 0 && d.bits[2] == 0 &&
         (use_all_bits ? d.bits[3] == 0 : true);
}

/**
 * @brief Check if numbers mantissas are equal
 * @param d First number
 * @param d2 Second number
 * @param use_all_bits Flag
 * @return num Result of checking
 */
int mantissa_is_equal(scp_decimal d1, scp_decimal d2, bool use_all_bits) {
  return d1.bits[0] == d2.bits[0] && d1.bits[1] == d2.bits[1] &&
         d1.bits[2] == d2.bits[2] &&
         (use_all_bits ? d1.bits[3] == d2.bits[3] : true);
}

/**
 * @brief Check if numbers mantissas are less
 * @param d First number
 * @param d2 Second number
 * @param use_all_bits Flag
 * @return num Result of checking
 */
int mantissa_is_less(scp_decimal d1, scp_decimal d2, bool use_all_bits) {
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

/**
 * @brief Increases number exp by 1 and mantissa by 10
 * @param d Number
 * @return res New exp value
 */
int increase_exp(scp_decimal *d) {
  int res = -1;

  int exp = get_decimal_exp(*d);
  if (exp >= SCP_MAX_EXP) return res;

  if (multiply_mantissa_by_10(d, false)) {
    set_decimal_exp(d, ++exp);
    res = exp;
  }

  return res;
}

/**
 * @brief Decrease number exp by n and mantissa by 10^n
 * @param d Number
 * @param n Scale value
 * @param has_reminder Flag
 * @param with_round Flag
 * @return res New exp value
 */
int decrease_exp(scp_decimal *d, int n, bool has_reminder, bool with_round) {
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

/**
 * @brief Decrease number exp by n and mantissa by 10^n in scp_big_decimal
 * @param d Number
 * @param n Scale value
 * @param has_reminder Flag
 * @param with_round Flag
 * @return res New exp value
 */
int decrease_exp_big(scp_big_decimal *d, int n, int reminder, bool with_round) {
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

/**
 * @brief Normalizes two numbers to have same exp
 * @param d1 First number
 * @param d2 Secnd number
 */
void decimal_normalization(scp_decimal *d1, scp_decimal *d2) {
  int exp1 = get_decimal_exp(*d1);
  int exp2 = get_decimal_exp(*d2);

  if (exp1 == exp2 && exp1 <= SCP_MAX_EXP) return;

  int tmp_exp;

  int max_exp = (exp1 > exp2) ? exp1 : exp2;
  if (max_exp > SCP_MAX_EXP) max_exp = SCP_MAX_EXP;

  /*
   *      Increase to the max
   */
  if (max_exp > exp1) {
    while ((tmp_exp = increase_exp(d1)) && tmp_exp != -1 && max_exp > exp1++)
      ;
  }
  if (max_exp > exp2) {
    while ((tmp_exp = increase_exp(d2)) && tmp_exp != -1 && max_exp > exp2++)
      ;
  }
  /*
   *      if increase didn't help, then descrease
   */
  int min_exp = (exp1 > exp2) ? exp2 : exp1;
  if (min_exp > SCP_MAX_EXP) min_exp = SCP_MAX_EXP;

  decrease_exp(d1, exp1 - min_exp, false, true);
  decrease_exp(d2, exp2 - min_exp, false, true);
}

/**
 * @brief Compares two numbers
 * @param value_1 First number
 * @param value_2 Secnd number
 * @param mode Comparation mode
 * @return res Bool result of comparation
 */
int decimal_comparison(scp_decimal value_1, scp_decimal value_2, int mode) {
  int res = false;

  int value1_zero = decimal_is_zero(value_1, false);
  int value2_zero = decimal_is_zero(value_2, false);
  int value1_sign = get_decimal_sign(value_1);
  int value2_sign = get_decimal_sign(value_2);

  if (value1_zero && value2_zero) {
    res = (mode != SCP_LESS);
  } else if (value1_zero || value2_zero) {
    res = mode != SCP_EQUAL &&
          ((value1_zero && !value2_sign) || (value2_zero && value1_sign));
  } else if (value1_sign != value2_sign) {
    res = mode != SCP_EQUAL && value1_sign;
  } else {
    decimal_normalization(&value_1, &value_2);

    int eq = false;
    int less = false;
    if (mode == SCP_EQUAL || mode == SCP_LESS_OR_EQUAL) {
      eq = mantissa_is_equal(value_1, value_2, false);
    }
    if (mode == SCP_LESS || mode == SCP_LESS_OR_EQUAL) {
      less = (value1_sign) ? mantissa_is_less(value_2, value_1, false)
                           : mantissa_is_less(value_1, value_2, false);
    }

    if (mode == SCP_EQUAL) {
      res = eq;
    } else if (mode == SCP_LESS) {
      res = less;
    } else if (mode == SCP_LESS_OR_EQUAL) {
      res = eq || less;
    }
  }
  return res;
}

/**
 * @brief Sum two numbers with same sign
 * @param value_1 First number
 * @param value_2 Secnd number
 * @param result Sum
 * @return num Error code
 */
int sum_same_sign(scp_decimal value_1, scp_decimal value_2,
                  scp_decimal *result) {
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
    return SCP_HUGE_ERR;
  else if (carry != 0) {
    decrease_exp(&value_1, 1, false, true);
    decrease_exp(&value_2, 1, false, true);
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
    sum_same_sign(value_1, value_2, result);
  }
  return SCP_OK;
}

/**
 * @brief Sum two numbers with same sign in scp_big_decimal
 * @param value_1 First number
 * @param value_2 Secnd number
 * @param result Sum
 * @return num Error code
 */
int sum_same_sign_big(scp_big_decimal value_1, scp_big_decimal value_2,
                      scp_big_decimal *result) {
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
  if (carry != 0 && get_decimal_exp_big(value_1) == 0) return SCP_HUGE_ERR;

  return SCP_OK;
}

int sub_pos(scp_decimal greater, scp_decimal lower, scp_decimal *result) {
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
  return SCP_OK;
}

/**
 * @brief Decimal fabs function
 * @param value_1 Number
 * @return value New number
 */
scp_decimal scp_decimal_fabs(scp_decimal value) {
  if (check_bit(value.bits[3], 31) == 1)
    value.bits[3] = set_bit(value.bits[3], 31);
  return value;
}

/**
 * @brief Copy exp from value to result
 * @param value Number (from)
 * @param result Number (to)
 */
void set_same_exp(scp_decimal value, scp_decimal *result) {
  int temp = check_bit(result->bits[3], 31);
  for (int i = 0; i < 32; i++) {
    result->bits[3] = value.bits[3] & 0b01111111111111111111111111111111;
  }
  if (temp == 1) result->bits[3] = set_bit(result->bits[3], 31);
}

/**
 * @brief Substract of mantissas
 * @param value_1 First number
 * @param value_1 Second number
 * @param result Result number
 * @return flag Error code
 */
int sub_mantis(scp_decimal value_1, scp_decimal value_2, scp_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  scp_decimal first_val = scp_decimal_fabs(value_1);
  scp_decimal second_val = scp_decimal_fabs(value_2);
  int flag = SCP_OK;

  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 0)) {
    /*
     *      |v1|>|v2| (+v1) - (+v2)
     */
    if (scp_is_greater_or_equal(first_val, second_val)) {
      sub_pos(first_val, second_val, result);
    } else {
      sub_pos(second_val, first_val, result);
      result->bits[3] = set_bit(result->bits[3], 31);
    }
  }

  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 1)) {
    /*
     *      |v1|>|v2| (-v1) - (-v2)
     */
    if (scp_is_greater_or_equal(first_val, second_val)) {
      sub_pos(first_val, second_val, result);
      result->bits[3] = set_bit(result->bits[3], 31);
    } else {
      sub_pos(second_val, first_val, result);
    }
  }
  /*
   *      (+v1) - (-v2)
   */
  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 1)) {
    flag = scp_add(first_val, second_val, result);
  }
  /*
   *      (-v1) - (+v2)
   */
  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 0)) {
    flag = scp_add(first_val, second_val, result);
    if (flag == SCP_HUGE_ERR) flag = SCP_SMALL_ERR;
    result->bits[3] = set_bit(result->bits[3], 31);
  }
  return flag;
}

/**
 * @brief Addition of mantissas
 * @param value_1 First number
 * @param value_1 Second number
 * @param result Result number
 * @return flag Error code
 */
int add_mantis(scp_decimal value_1, scp_decimal value_2, scp_decimal *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  int flag = SCP_OK;
  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 0)) {  // (+v1) + (+v2)
    flag = sum_same_sign(value_1, value_2, result);
  }
  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 1)) {  // (-v1) + (-v2)
    flag = sum_same_sign(value_1, value_2, result);
    if (flag == SCP_HUGE_ERR) flag = SCP_SMALL_ERR;
    result->bits[3] = set_bit(result->bits[3], 31);
  }
  if ((check_bit(value_1.bits[3], 31) == 0 &&
       check_bit(value_2.bits[3], 31) == 1)) {  // (v1) + (-v2)
    value_2.bits[3] = set_bit(value_2.bits[3], 31);
    flag = scp_sub(value_1, value_2, result);
  }
  if ((check_bit(value_1.bits[3], 31) == 1 &&
       check_bit(value_2.bits[3], 31) == 0)) {  // (-v1) + (+v2)
    value_1.bits[3] = set_bit(value_1.bits[3], 31);
    flag = scp_sub(value_2, value_1, result);
    if (decimal_is_zero(*result, false) &&
        check_bit(result->bits[3], 31) == 0) {
      result->bits[3] = set_bit(result->bits[3], 31);
    }
  }
  return flag;
}

/**
 * @brief Divide value of mantissa by 10
 * @param d Number
 * @return remainder Remainder value
 */
int divide_mantissa_by_10(scp_decimal *d) {
  // Divide the 96-bit integer by 10.
  unsigned long long remainder = 0;

  for (int i = 2; i >= 0; --i) {
    unsigned long long temp = (remainder << 32) | d->bits[i];
    d->bits[i] = (unsigned int)(temp / 10);
    remainder = temp % 10;
  }

  return (int)remainder;
}

/**
 * @brief Divide value of mantissa by 10 in scp_bif_decimal
 * @param d Number
 * @return remainder Remainder value
 */
int divide_mantissa_by_10_big(scp_big_decimal *d) {
  unsigned long long remainder = 0;

  for (int i = 5; i >= 0; --i) {
    unsigned int bit = d->bits[i] & SCP_MAX4BITS;
    unsigned long long temp = (remainder << 32) | bit;
    bit = (unsigned int)(temp / 10);
    remainder = temp % 10;
    d->bits[i] = bit & SCP_MAX4BITS;
  }

  return (int)remainder;
}

/**
 * @brief Multiply value of mantissa by 10
 * @param d Number
 * @param use_all_bits Flag
 * @return res Was operation succeed
 */
bool multiply_mantissa_by_10(scp_decimal *d, bool use_all_bits) {
  bool res = false;
  scp_decimal tmp_d = *d;
  unsigned long long carry = 0;
  int i_max = use_all_bits ? 3 : 2;
  for (int i = 0; i <= i_max; i++) {
    unsigned int x = tmp_d.bits[i];
    unsigned long long x_by_8 = (unsigned long long)x << 3;
    unsigned long long x_by_2 = (unsigned long long)x << 1;
    unsigned long long sum = x_by_8 + x_by_2 + carry;

    /*
     *      Move the lower 32 bits to the current element.
     */
    tmp_d.bits[i] = (unsigned int)(sum & 0xFFFFFFFF);

    /*
     *      Calculate the carry for the next iteration.
     */
    carry = sum >> 32;
  }
  /*
   *      Check if there's a carry left after processing all elements.
   */
  if (carry == 0) {
    *d = tmp_d;
    res = true;
  }

  return res;
}

/**
 * @brief Substract bits of mantissa
 * @param minuend Minuend
 * @param subtrahend Subtrahend
 * @param use_all_bits Flag
 * @return res Was operation succeed
 */
bool subtract_bits(scp_decimal *minuend, scp_decimal subtrahend,
                   bool use_all_bits) {
  if (mantissa_is_less(*minuend, subtrahend, use_all_bits)) {
    return false;
  }

  unsigned long long borrow = 0;
  bool res = true;
  scp_decimal tmp = *minuend;
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

/**
 * @brief Addict bits of mantissa
 * @param accumulator Accumulator
 * @param addend Addend
 * @return res Was operation succeed
 */
bool add_bits(scp_decimal *accumulator, scp_decimal addend) {
  unsigned long long carry = 0;
  bool res = true;
  scp_decimal tmp = *accumulator;

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

/**
 * @brief Addict bits of mantissa in scp_big_decimal
 * @param accumulator Accumulator
 * @param addend Addend
 * @return res Was operation succeed
 */
bool add_bits_big(scp_big_decimal *accumulator, scp_big_decimal addend) {
  unsigned long long carry = 0;
  bool res = true;
  scp_big_decimal tmp = *accumulator;

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

/**
 * @brief Left shift of all mantissa bits
 * @param d Number
 * @param use_all_bits Flag
 * @return res Was operation succeed
 */
bool left_shift_bits(scp_decimal *d, bool use_all_bits) {
  bool res = true;
  unsigned long long carry = 0;
  scp_decimal tmp = *d;

  int i_max = use_all_bits ? 3 : 2;
  for (int i = 0; i <= i_max; i++) {
    unsigned long long new_carry = tmp.bits[i] >> SCP_SIGN_SHIFT;
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

/**
 * @brief Left shift of all mantissa bits in scp_big_decimal
 * @param d Number
 * @return res Was operation succeed
 */
bool left_shift_bits_big(scp_big_decimal *d) {
  bool res = true;
  unsigned long long carry = 0;
  scp_big_decimal tmp = *d;

  for (int i = 0; i < 6; i++) {
    unsigned long long new_carry = tmp.bits[i] >> SCP_SIGN_SHIFT;
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

/**
 * @brief Right shift of all mantissa bits
 * @param d Number
 * @param use_all_bits Flag
 * @return res Was operation succeed
 */
void right_shift_bits(scp_decimal *d, bool use_all_bits) {
  unsigned long long carry = 0;
  int i_max = use_all_bits ? 3 : 2;
  for (int i = i_max; i >= 0; i--) {
    unsigned long long new_carry = d->bits[i] & 1;
    d->bits[i] >>= 1;
    d->bits[i] |= (unsigned int)(carry << SCP_SIGN_SHIFT);
    carry = new_carry;
  }
}

/**
 * @brief Switch bit of scp_decimal
 * @param d Number
 * @param bit_position Index
 */
void set_bit96(scp_decimal *d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  d->bits[index] |= (1 << bit_offset);
}

/**
 * @brief Switch bit of scp_big_decimal
 * @param d Number
 * @param bit_position Index
 */
void set_bit192(scp_big_decimal *d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  d->bits[index] |= (1 << bit_offset);
}

/**
 * @brief Sets to 0 bit of scp_big_decimal
 * @param d Number
 * @param bit_position Index
 */
void set_zero_bit192(scp_big_decimal *d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  d->bits[index] &= ~(1 << bit_offset);
}

/**
 * @brief Gets bit of scp_big_decimal
 * @param d Number
 * @param bit_position Index
 */
int get_bit192(scp_big_decimal d, int bit_position) {
  int index = bit_position / 32;
  int bit_offset = bit_position % 32;
  return check_bit(d.bits[index], bit_offset);
}

/**
 * @brief Divide mantissas
 * @param value_1 Dividend
 * @param value_2 Divisor
 * @param quotient Quotient
 * @param remainder Remainder
 */
void div_mantissas(scp_decimal value_1, scp_decimal value_2,
                   scp_decimal *quotient, scp_decimal *remainder) {
  scp_decimal temp_divisor = value_2;
  scp_decimal temp_remainder = value_1;
  temp_divisor.bits[3] = 0;
  *quotient = SCP_D_ZERO;

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

/**
 * @brief Round float number after 7 digits
 * @param src Number
 * @return new_src Rounded number
 */
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

/**
 * @brief Convert double to scp_decimal
 * @param src Number (from)
 * @param dst Number (to)
 */
void convert_to_decimal(double src, scp_decimal *dst) {
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

  dst->bits[3] = (scale << 16) | ((unsigned)sign << 31);
  for (int i = 0; i < 96; ++i) {
    if (fmod(floor(scaled_value), 2) == 1)
      dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
    scaled_value /= 2;
  }
}

/**
 * @brief Remove the trailing zeros from scp_decimal and decrease exp
 * @param d Number
 * @param from_exp Start sacle
 * @param to_exp End scale
 */
int truncate_trailing_zeros(scp_decimal *d, int from_exp, int to_exp) {
  int exp_new = from_exp;
  bool res = true;
  while (exp_new > to_exp && res) {
    scp_decimal tmp = *d;
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

/**
 * @brief Banking roundinig
 * @param d Number
 * @param quotient Quotient
 * @param has_reminder Flag
 */
void bank_rounding(scp_decimal *d, int quotient, bool has_reminder) {
  if (quotient > 5 || (quotient == 5 && (d->bits[0] & 1 || has_reminder))) {
    add_bits(d, SCP_D_ONE);
  }
}

/**
 * @brief Banking roundinig for scp_big_decimal
 * @param d Number
 * @param quotient Quotient
 * @param has_reminder Flag
 */
void bank_rounding_big(scp_big_decimal *d, int quotient, bool has_reminder) {
  if (quotient > 5 || (quotient == 5 && (d->bits[0] & 1 || has_reminder))) {
    add_bits_big(d, SCP_D_ONE_BIG);
  }
}

/**
 * @brief Convert scp_big_decimal to scp_decimal and round
 * @param mul_res Number
 */
void from_big_to_decimal_with_rounding(scp_big_decimal *mul_res) {
  if (((mul_res->bits[3] != 0 || mul_res->bits[4] != 0 ||
        mul_res->bits[5] != 0) &&
       get_decimal_exp_big(*mul_res) > 0) ||
      get_decimal_exp_big(*mul_res) > 28) {
    scp_big_decimal temp = *mul_res;
    int reminder = 0;
    int n = 0;
    int flag = 0;
    if (get_decimal_exp_big(*mul_res) > 28) {
      n = get_decimal_exp_big(*mul_res) - 28;
      decrease_exp_big(&temp, get_decimal_exp_big(*mul_res) - 28, reminder, 1);
      reminder = 0;

      if ((temp.bits[3] != 0 || temp.bits[4] != 0 || temp.bits[5] != 0) &&
          get_decimal_exp_big(temp) > 0) {
        scp_big_decimal temp1 = *mul_res;
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
        scp_big_decimal temp1 = *mul_res;
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
    decrease_exp_big(mul_res, n, 0, 1);
  }
}

/**
 * @brief Multiply two scp_bif_decimal numbers
 * @param value_1_big Fist number
 * @param value_2_big Second number
 * @param flag Flag
 * @return mul_res Result number
 */
scp_big_decimal bits_mult(scp_big_decimal *value_1_big,
                          scp_big_decimal *value_2_big, int *flag) {
  scp_big_decimal mul_res_tmp;
  scp_big_decimal mul_res = {{0, 0, 0, 0, 0, 0, 0}};
  int i = 0;
  while ((value_1_big->bits[0] != 0 || value_1_big->bits[1] != 0 ||
          value_1_big->bits[2] != 0 || value_1_big->bits[3] != 0 ||
          value_1_big->bits[4] != 0 || value_1_big->bits[5] != 0) &&
         i < 192) {
    if (get_bit192((*value_1_big), i) != 0) {
      mul_res_tmp = mul_res;
      int err_code = sum_same_sign_big(mul_res_tmp, *value_2_big, &mul_res);
      if (err_code == SCP_HUGE_ERR) {
        *flag = SCP_HUGE_ERR;
        i = 192;
      }
      set_zero_bit192(value_1_big, i);
    }
    left_shift_bits_big(value_2_big);
    i++;
  }
  return mul_res;
}

/**
 * @brief Divide two numbers
 * @param value_1 Fist number
 * @param value_2 Second number
 * @param result Rusult number
 * @param result_sign Sign value
 * @param exp1 Exp of value_1
 * @param exp2 Exp of value_2
 * @return res Error code
 */
int get_div_result(scp_decimal value_1, scp_decimal value_2,
                   scp_decimal *result, int result_sign, int exp1, int exp2) {
  int res = SCP_OK;
  int exp = exp1 - exp2;
  int max_exp = (exp1 > exp2) ? exp1 : exp2;

  scp_decimal quotient = SCP_D_ZERO;
  scp_decimal remainder = value_1;
  remainder.bits[3] = 0;
  int tmp_quotient_int = 0;

  /*
   *      Perform the division operation on the 96-bit integer numbers
   */
  if (mantissa_is_equal(value_1, value_2, false)) {
    quotient = SCP_D_ONE;
  } else {
    div_mantissas(remainder, value_2, &quotient, &remainder);
    while (!decimal_is_zero(remainder, true) && exp <= (SCP_MAX_EXP + 1) &&
           multiply_mantissa_by_10(&remainder, true)) {
      scp_decimal tmp_quotient;
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

  /*
   *      Store the result and ajust the final value
   */
  *result = quotient;
  if (exp < 0) {
    for (; exp && multiply_mantissa_by_10(result, false); exp++) {
    }
  }
  if (exp < 0) {
    res = result_sign ? SCP_SMALL_ERR : SCP_HUGE_ERR;
  } else {
    set_decimal_exp(result, exp);
    set_decimal_sign(result, result_sign);
    if (exp > SCP_MAX_EXP) {
      exp = decrease_exp(result, exp - SCP_MAX_EXP, has_reminder, true);
    } else {
      bank_rounding(result, tmp_quotient_int, has_reminder);
    }
    truncate_trailing_zeros(result, exp, max_exp);
  }
  return res;
}
