#include "s21_common.h"

/**
 * @brief Addition of two decimal
 * @param value_1 First number
 * @param value_2 Second number
 * @param result Sum
 * @return flag Error code
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) {
    return S21_OK;
  }
  decimal_normalization(&value_1, &value_2);
  int flag = add_mantis(value_1, value_2, result);
  if (flag != 0) {
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
  }
  return flag;
}

/**
 * @brief Subtraction of two decimal
 * @param value_1 Minuend
 * @param value_2 Subtrahend
 * @param result Difference
 * @return flag Error code
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) {
    return S21_OK;
  }
  decimal_normalization(&value_1, &value_2);
  int flag = sub_mantis(value_1, value_2, result);
  set_same_exp(value_1, result);
  if (flag != 0) {
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;
  }
  return flag;
}

/**
 * @brief Multiplication of two decimal
 * @param value_1 First multiplier
 * @param value_2 Second multiplier
 * @param result Product
 * @return flag Error code
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = S21_OK;
  if (result != NULL) {
    s21_big_decimal value_1_big = {{0, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal value_2_big = {{0, 0, 0, 0, 0, 0, 0}};
    for (int i = 0; i < 3; i++) {
      value_1_big.bits[i] = (uint64_t)value_1.bits[i] & S21_MAX4BITS;
      value_2_big.bits[i] = (uint64_t)value_2.bits[i] & S21_MAX4BITS;
    }
    s21_big_decimal mul_res = bits_mult(&value_1_big, &value_2_big, &flag);
    int res_exp = get_decimal_exp(value_1) + get_decimal_exp(value_2);
    int res_sign =
        get_decimal_sign(value_1) != get_decimal_sign(value_2) ? 1 : 0;
    mul_res.bits[6] =
        ((res_exp << 16) | ((unsigned)res_sign << 31)) & S21_MAX4BITS;
    from_big_to_decimal_with_rounding(&mul_res);
    if (mul_res.bits[3] != 0 || mul_res.bits[4] != 0 || mul_res.bits[5] != 0) {
      if (!res_sign)
        flag = S21_HUGE_ERR;
      else
        flag = S21_SMALL_ERR;
    }
    if (mul_res.bits[0] == 0 && mul_res.bits[1] == 0 && mul_res.bits[2] == 0) {
      mul_res.bits[6] = (unsigned)res_sign << 31;
    }
    if (flag == S21_OK) {
      result->bits[0] = mul_res.bits[0] & S21_MAX4BITS;
      result->bits[1] = mul_res.bits[1] & S21_MAX4BITS;
      result->bits[2] = mul_res.bits[2] & S21_MAX4BITS;
      result->bits[3] = mul_res.bits[6] & S21_MAX4BITS;
    } else {
      result->bits[0] = 0;
      result->bits[1] = 0;
      result->bits[2] = 0;
      result->bits[3] = 0;
    }
  }
  return flag;
}

/**
 * @brief Division of two decimal
 * @param value_1 Dividend
 * @param value_2 Divider
 * @param result Quotient
 * @return flag Error code
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) {
    return S21_OK;
  }
  /*
   *      Get sign and exp here just to maintain them both for the result even
   * if value_1 or value_2 is zero (behaviour as in C#)
   */
  int result_sign = get_decimal_sign(value_1) ^ get_decimal_sign(value_2);
  int exp1 = get_decimal_exp(value_1);
  int exp2 = get_decimal_exp(value_2);
  int exp = exp1 - exp2;

  /*
   *      Check for division by zero
   */
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

  int flag = get_div_result(value_1, value_2, result, result_sign, exp1, exp2);

  /*
   *      Zero the result if something is wrong
   */
  if (flag != S21_OK || decimal_is_zero(*result, false)) {
    *result = S21_D_ZERO;
  }

  return flag;
}
