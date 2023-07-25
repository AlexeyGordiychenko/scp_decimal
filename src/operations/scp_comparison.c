#include "scp_common.h"

/**
 * @brief Check if value_1 < value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int scp_is_less(scp_decimal value_1, scp_decimal value_2) {
  return decimal_comparison(value_1, value_2, SCP_LESS);
}

/**
 * @brief Check if value_1 <= value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int scp_is_less_or_equal(scp_decimal value_1, scp_decimal value_2) {
  return decimal_comparison(value_1, value_2, SCP_LESS_OR_EQUAL);
}

/**
 * @brief Check if value_1 > value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int scp_is_greater(scp_decimal value_1, scp_decimal value_2) {
  return !scp_is_less_or_equal(value_1, value_2);
}

/**
 * @brief Check if value_1 >= value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int scp_is_greater_or_equal(scp_decimal value_1, scp_decimal value_2) {
  return !scp_is_less(value_1, value_2);
}

/**
 * @brief Check if value_1 == value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int scp_is_equal(scp_decimal value_1, scp_decimal value_2) {
  return decimal_comparison(value_1, value_2, SCP_EQUAL);
}

/**
 * @brief Check if value_1 != value_2
 * @param value_1 Number
 * @param value_2 Number
 * @return num Result of comparing
 */
int scp_is_not_equal(scp_decimal value_1, scp_decimal value_2) {
  return !scp_is_equal(value_1, value_2);
}
