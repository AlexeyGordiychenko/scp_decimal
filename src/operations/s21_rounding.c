#include "s21_common.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  // MIN_DECIMAL_VALUE -79,228,162,514,264,337,593,543,950,335
  // MAX_DECIMAL_VALUE 79,228,162,514,264,337,593,543,950,335
  s21_decimal s21_min_decimal_value = {{-1, -1, -1, 1u << S21_SIGN_SHIFT}};
  // s21_decimal s21_max_decimal_value = {{-1, -1, -1, 0}};
  s21_decimal zero_decimal = {{0, 0, 0, 0}};
  s21_decimal one_decimal = {{1, 0, 0, 0}};
  int error_flag = 1;

  if (s21_is_not_equal(value, s21_min_decimal_value)) {
    error_flag = 0;
    s21_decimal decimal_integer_part = zero_decimal;
    s21_truncate(value, &decimal_integer_part);

    if (s21_is_equal(value, decimal_integer_part)) {
      *result = decimal_integer_part;
    } else if (s21_is_equal(value, zero_decimal)) {
      *result = zero_decimal;
    } else if (s21_is_less_or_equal(decimal_integer_part, zero_decimal)) {
      int sub_flag = s21_sub(decimal_integer_part, one_decimal, result);
      if (sub_flag) error_flag = 1;
    } else if (s21_is_greater_or_equal(decimal_integer_part, zero_decimal)) {
      *result = decimal_integer_part;
    }
  }
  return error_flag;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal s21_min_decimal_value = {{-1, -1, -1, 1u << S21_SIGN_SHIFT}};
  s21_decimal s21_max_decimal_value = {{-1, -1, -1, 0}};
  s21_decimal zero_decimal = {{0, 0, 0, 0}};
  s21_decimal one_decimal = {{1, 0, 0, 0}};
  s21_decimal one_half_decimal = {{5, 0, 0, 1 << S21_EXP_SHIFT}};
  s21_decimal one_half_decimal_negated = {
      {5, 0, 0, 1 << S21_EXP_SHIFT | 1u << S21_SIGN_SHIFT}};
  int error_flag = 1;

  if (s21_is_less_or_equal(value, s21_max_decimal_value) &&
      s21_is_greater_or_equal(value, s21_min_decimal_value)) {
    error_flag = 0;
    s21_decimal decimal_integer_part = zero_decimal;
    s21_decimal decimal_fract_part = zero_decimal;
    s21_truncate(value, &decimal_integer_part);
    s21_sub(value, decimal_integer_part, &decimal_fract_part);

    // decimal = 0
    if (s21_is_equal(value, zero_decimal)) {
      *result = zero_decimal;
    }
    // decimal > 0
    if (s21_is_greater(value, zero_decimal)) {
      if (s21_is_equal(value, decimal_integer_part)) {
        *result = decimal_integer_part;
      } else if (s21_is_less(decimal_fract_part, one_half_decimal)) {
        *result = decimal_integer_part;
      } else if (s21_is_greater_or_equal(decimal_fract_part,
                                         one_half_decimal)) {
        s21_add(decimal_integer_part, one_decimal, result);
      }
    }
    // decimal < 0
    if (s21_is_less(value, zero_decimal)) {
      if (s21_is_equal(value, decimal_integer_part)) {
        *result = decimal_integer_part;
      } else if (s21_is_greater(decimal_fract_part, one_half_decimal_negated)) {
        *result = decimal_integer_part;
      } else if (s21_is_less_or_equal(decimal_fract_part,
                                      one_half_decimal_negated)) {
        s21_sub(decimal_integer_part, one_decimal, result);
      }
    }
  }
  return error_flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int exp = get_decimal_exp(value);
  decrease_exp(&value, exp, 0, false);
  *result = value;

  return S21_OK;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  unsigned int mask = 1u << S21_SIGN_SHIFT;
  if (check_bit(value.bits[3], 31) == 0) {
    result->bits[3] |= mask;
  } else {
    result->bits[3] &= ~mask;
  }
  return 0;
}
