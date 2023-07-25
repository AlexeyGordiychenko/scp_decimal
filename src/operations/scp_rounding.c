#include "scp_common.h"

/**
 * @brief Floor rounding operation
 * @param value Number
 * @param result Rusult number
 * @return num Error code
 */
int scp_floor(scp_decimal value, scp_decimal *result) {
  if (result == NULL) {
    return SCP_ERROR;
  }

  scp_decimal scp_min_decimal_value = {{-1, -1, -1, 1u << SCP_SIGN_SHIFT}};
  scp_decimal zero_decimal = {{0, 0, 0, 0}};
  scp_decimal one_decimal = {{1, 0, 0, 0}};
  int error_flag = 1;

  if (scp_is_equal(value, scp_min_decimal_value)) {
    error_flag = 0;
    *result = value;
  } else {
    error_flag = 0;
    scp_decimal decimal_integer_part = zero_decimal;
    scp_truncate(value, &decimal_integer_part);

    if (scp_is_equal(value, decimal_integer_part)) {
      *result = decimal_integer_part;
    } else if (scp_is_less(value, zero_decimal)) {
      int sub_flag = scp_sub(decimal_integer_part, one_decimal, result);
      if (sub_flag) error_flag = 1;
    } else if (scp_is_greater_or_equal(value, zero_decimal)) {
      *result = decimal_integer_part;
    }
  }
  if (scp_is_equal(value, scp_min_decimal_value)) {
    *result = scp_min_decimal_value;
    error_flag = 0;
  }
  return error_flag;
}

/**
 * @brief Pure rounding operation
 * @param value Number
 * @param result Rusult number
 * @return num Error code
 */
int scp_round(scp_decimal value, scp_decimal *result) {
  if (result == NULL) {
    return SCP_ERROR;
  }
  scp_decimal scp_min_decimal_value = {{-1, -1, -1, 1u << SCP_SIGN_SHIFT}};
  scp_decimal scp_max_decimal_value = {{-1, -1, -1, 0}};
  scp_decimal zero_decimal = {{0, 0, 0, 0}};
  scp_decimal one_decimal = {{1, 0, 0, 0}};
  scp_decimal one_half_decimal = {{5, 0, 0, 1 << SCP_EXP_SHIFT}};
  scp_decimal one_half_decimal_negated = {
      {5, 0, 0, 1 << SCP_EXP_SHIFT | 1u << SCP_SIGN_SHIFT}};
  int error_flag = 1;

  if (scp_is_less_or_equal(value, scp_max_decimal_value) &&
      scp_is_greater_or_equal(value, scp_min_decimal_value)) {
    error_flag = 0;
    scp_decimal decimal_integer_part = zero_decimal;
    scp_decimal decimal_fract_part = zero_decimal;
    scp_truncate(value, &decimal_integer_part);
    scp_sub(value, decimal_integer_part, &decimal_fract_part);

    // decimal = 0
    if (scp_is_equal(value, zero_decimal)) {
      *result = zero_decimal;
    }
    // decimal > 0
    if (scp_is_greater(value, zero_decimal)) {
      if (scp_is_equal(value, decimal_integer_part)) {
        *result = decimal_integer_part;
      } else if (scp_is_less(decimal_fract_part, one_half_decimal)) {
        *result = decimal_integer_part;
      } else if (scp_is_greater_or_equal(decimal_fract_part,
                                         one_half_decimal)) {
        scp_add(decimal_integer_part, one_decimal, result);
      }
    }
    // decimal < 0
    if (scp_is_less(value, zero_decimal)) {
      if (scp_is_equal(value, decimal_integer_part)) {
        *result = decimal_integer_part;
      } else if (scp_is_greater(decimal_fract_part, one_half_decimal_negated)) {
        *result = decimal_integer_part;
      } else if (scp_is_less_or_equal(decimal_fract_part,
                                      one_half_decimal_negated)) {
        scp_sub(decimal_integer_part, one_decimal, result);
      }
    }
  }
  return error_flag;
}

/**
 * @brief Truncate rounding operation
 * @param value Number
 * @param result Rusult number
 * @return num Error code
 */
int scp_truncate(scp_decimal value, scp_decimal *result) {
  if (result == NULL) {
    return SCP_ERROR;
  }
  int exp = get_decimal_exp(value);
  decrease_exp(&value, exp, false, false);
  *result = value;

  return SCP_OK;
}

/**
 * @brief Negate a number
 * @param value Number
 * @param result Nagetive number
 * @return num Error code
 */
int scp_negate(scp_decimal value, scp_decimal *result) {
  if (result == NULL) {
    return SCP_ERROR;
  }
  *result = value;
  unsigned int mask = 1u << SCP_SIGN_SHIFT;
  if (check_bit(value.bits[3], 31) == 0) {
    result->bits[3] |= mask;
  } else {
    result->bits[3] &= ~mask;
  }
  return SCP_OK;
}
