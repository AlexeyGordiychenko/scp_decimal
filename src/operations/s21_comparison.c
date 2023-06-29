#include "s21_common.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  return decimal_comparison(value_1, value_2, S21_LESS);
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return decimal_comparison(value_1, value_2, S21_LESS_OR_EQUAL);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less_or_equal(value_1, value_2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less(value_1, value_2);
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  return decimal_comparison(value_1, value_2, S21_EQUAL);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}
