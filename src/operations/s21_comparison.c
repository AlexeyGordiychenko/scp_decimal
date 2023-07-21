#include "s21_common.h"

/**
 * @brief Check if value_1 < value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  return decimal_comparison(value_1, value_2, S21_LESS);
}

/**
 * @brief Check if value_1 <= value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return decimal_comparison(value_1, value_2, S21_LESS_OR_EQUAL);
}

/**
 * @brief Check if value_1 > value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less_or_equal(value_1, value_2);
}

/**
 * @brief Check if value_1 >= value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less(value_1, value_2);
}

/**
 * @brief Check if value_1 == value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  return decimal_comparison(value_1, value_2, S21_EQUAL);
}

/**
 * @brief Check if value_1 != value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}
