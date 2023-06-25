#include "s21_common.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  // MIN_DECIMAL_VALUE -79,228,162,514,264,337,593,543,950,335
  // MAX_DECIMAL_VALUE 79,228,162,514,264,337,593,543,950,335
  s21_decimal s21_min_decimal_value = {{-1, -1, -1, 1 << 31}};
  s21_decimal s21_max_decimal_value = {{-1, -1, -1, 0}};
  s21_decimal zero_decimal = {{0, 0, 0, 0}};
  s21_decimal one_decimal = {{1, 0, 0, 0}};
  int error_flag = 1;

  if (s21_is_less_or_equal(value, s21_max_decimal_value) &&
      s21_is_greater_or_equal(value, s21_min_decimal_value)) {
    error_flag = 0;
    s21_decimal decimal_integer_part = zero_decimal;
    s21_truncate(value, &decimal_integer_part);

    if (s21_is_equal(value, decimal_integer_part)) {
      *result = decimal_integer_part;
    } else if (s21_is_equal(value, zero_decimal)) {
      *result = zero_decimal;
    } else if (s21_is_less(decimal_integer_part, zero_decimal)) {
      s21_sub(decimal_integer_part, one_decimal, result);
    } else if (s21_is_greater_or_equal(decimal_integer_part, zero_decimal)) {
      *result = decimal_integer_part;
    }
  }
  return error_flag;
}

int s21_round(s21_decimal value, s21_decimal *result) { return OK; }

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int exp = get_decimal_exp(value);
  while (exp--) {
    decrease_exp(&value, 0);
  }
  set_decimal_exp(&value, 0);
  *result = value;

  return OK;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  unsigned int mask = 1 << 31;
  if (check_bit(value.bits[3], 31) == 0) {
    result->bits[3] |= mask;
  } else {
    result->bits[3] &= ~mask;
  }
  return 0;
}
