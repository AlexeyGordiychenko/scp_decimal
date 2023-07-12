#include "s21_common.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_normalization(&value_1, &value_2);
  int flag = add_mantis(value_1, value_2, result);
  return flag;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_normalization(&value_1, &value_2);
  int flag = sub_mantis(value_1, value_2, result);
  set_same_exp(value_1, result);
  return flag;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = S21_OK;
  s21_big_decimal value_1_big = {{0, 0, 0, 0, 0, 0, 0}};
  ;
  s21_big_decimal value_2_big = {{0, 0, 0, 0, 0, 0, 0}};
  ;

  for (int i = 0; i < 3; i++) {
    value_1_big.bits[i] = (uint64_t)value_1.bits[i] & S21_MAX4BITS;
    value_2_big.bits[i] = (uint64_t)value_2.bits[i] & S21_MAX4BITS;
  }

  s21_big_decimal mul_res = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal mul_res_tmp = {{0, 0, 0, 0, 0, 0, 0}};

  int i = 0;
  while ((value_1_big.bits[0] != 0 || value_1_big.bits[1] != 0 ||
          value_1_big.bits[2] != 0 || value_1_big.bits[3] != 0 ||
          value_1_big.bits[4] != 0 || value_1_big.bits[5] != 0) &&
         i < 192) {
    if (get_bit192(&value_1_big, i) != 0) {
      mul_res_tmp = mul_res;
      int err_code = sum_same_sign_big(mul_res_tmp, value_2_big, &mul_res);
      if (err_code == S21_HUGE_ERR) {
        flag = S21_HUGE_ERR;
        i = 192;
      }
      set_zero_bit192(&value_1_big, i);
    }
    left_shift_bits_big(&value_2_big);
    i++;
  }

  int res_exp = get_decimal_exp(value_1) + get_decimal_exp(value_2);
  int res_sign = get_decimal_sign(value_1) != get_decimal_sign(value_2) ? 1 : 0;
  mul_res.bits[6] = ((res_exp << 16) | (res_sign << 31)) & S21_MAX4BITS;

  if (mul_res.bits[3] != 0 || mul_res.bits[4] != 0 || mul_res.bits[5] != 0) {
    while ((mul_res.bits[3] != 0 || mul_res.bits[4] != 0 ||
            mul_res.bits[5] != 0) &&
           get_decimal_exp_big(mul_res) > 0) {
      decrease_exp_big(&mul_res, 1);
    }

    if (mul_res.bits[3] != 0 || mul_res.bits[4] != 0 || mul_res.bits[5] != 0) {
      if (!get_decimal_sign_big(mul_res))
        flag = S21_HUGE_ERR;
      else
        flag = S21_SMALL_ERR;
    }
  }

  while (get_decimal_exp_big(mul_res) > 28) {
    decrease_exp_big(&mul_res, 1);
  }

  if (flag == S21_OK) {
    result->bits[0] = mul_res.bits[0] & S21_MAX4BITS;
    result->bits[1] = mul_res.bits[1] & S21_MAX4BITS;
    result->bits[2] = mul_res.bits[2] & S21_MAX4BITS;
    result->bits[3] = mul_res.bits[6] & S21_MAX4BITS;
  }
  return flag;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = S21_OK;

  // get sign and exp here just to maintain them both for the result even if
  // value_1 or value_2 is zero (behaviour as in C#)
  int result_sign = get_decimal_sign(value_1) ^ get_decimal_sign(value_2);
  int exp1 = get_decimal_exp(value_1);
  int exp2 = get_decimal_exp(value_2);
  int exp = exp1 - exp2;
  int max_exp = (exp1 > exp2) ? exp1 : exp2;

  // Check for division by zero
  if (decimal_is_zero(value_2, false)) {
    *result = S21_D_ZERO;
    return S21_DIV_ZERO_ERR;
  }

  if (decimal_is_zero(value_1, false)) {
    *result = value_1;
    set_decimal_sign(result, result_sign);
    set_decimal_exp(result, exp < 0 ? 0 : exp);
    return S21_OK;
  }

  s21_decimal quotient = S21_D_ZERO;
  s21_decimal remainder = value_1;
  remainder.bits[3] = 0;  // we will use all 4 bits
  int tmp_quotient_int = 0;
  bool has_reminder = false;

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
        has_reminder = !decimal_is_zero(remainder, true);
        remainder = S21_D_ZERO;
      }
    }
  }

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
      exp = decrease_exp(result, exp - S21_MAX_EXP, tmp_quotient_int, true);
    } else {
      bank_rounding(result, tmp_quotient_int, has_reminder);
    }
    truncate_trailing_zeros(result, exp, max_exp);
  }

  // zero the result if something is wrong
  if (res != S21_OK || decimal_is_zero(*result, false)) {
    *result = S21_D_ZERO;
  }

  return res;
}
