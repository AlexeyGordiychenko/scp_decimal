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
  return S21_OK;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = S21_OK;
  s21_decimal quotient = S21_D_ZERO, remainder = S21_D_ZERO;

  // Check for division by zero
  if (decimal_is_zero(value_2)) {
    *result = S21_D_ZERO;
    return S21_DIV_ZERO_ERR;  // Division by zero error
  }

  if (decimal_is_zero(value_1)) {
    *result = S21_D_ZERO;
    return S21_OK;
  }

  // Adjust the exponent of the result
  int exp = get_decimal_exp(value_1) - get_decimal_exp(value_2);

  // Perform the division operation on the 96-bit integer numbers
  if (mantissa_is_equal(value_1, value_2)) {
    quotient = S21_D_ONE;
  } else {
    div_mantissas(value_1, value_2, &quotient, &remainder);
    while (!decimal_is_zero(remainder) && exp <= (S21_MAX_EXP + 1) &&
           multiply_mantissa_by_10(&remainder)) {
      s21_decimal tmp_quotient;
      div_mantissas(remainder, value_2, &tmp_quotient, &remainder);
      if (multiply_mantissa_by_10(&quotient) &&
          add_bits(&quotient, tmp_quotient)) {
        exp++;
      } else {
        remainder = S21_D_ZERO;
        if (((tmp_quotient.bits[0] > 5 ||
              (tmp_quotient.bits[0] == 5 && quotient.bits[0] & 1)))) {
          add_bits(&quotient, S21_D_ONE);
        }
      }
    }
  }
  // Store the result in the s21_decimal *result pointer
  *result = quotient;
  if (exp < 0) {
    for (; exp && multiply_mantissa_by_10(result); exp++) {
    }
  }
  while (exp > S21_MAX_EXP) {
    divide_mantissa_by_10(result, (exp == (S21_MAX_EXP + 1)));
    exp--;
  }

  int result_sign = get_decimal_sign(value_1) ^ get_decimal_sign(value_2);
  if (exp < 0) {
    res = result_sign ? S21_SMALL_ERR : S21_HUGE_ERR;
  } else {
    if (decimal_is_zero(*result)) exp = 0;
    set_decimal_exp(result, exp);
    set_decimal_sign(result, result_sign);
  }

  if (res != S21_OK) {
    *result = S21_D_ZERO;
  }

  return res;
}
