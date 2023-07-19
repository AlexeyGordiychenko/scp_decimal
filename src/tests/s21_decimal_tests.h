#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>

#include "../operations/s21_common.h"
#include "../s21_decimal.h"

#define PRE_TEST_HEADER "\033[33m**"
#define POST_TEST_HEADER "**\033[0m"

#define ASSERT_BITS_EQ                                                        \
  for (int i = 0; i < 4; i++) {                                               \
    ck_assert_msg(result.bits[i] == correct.bits[i], "bits[%d]: %x != %x", i, \
                  result.bits[i], correct.bits[i]);                           \
  }

unsigned int sign_and_exp_bits(int sign, int exp);

Suite *comparison_tests(void);
Suite *converting_tests(void);
Suite *truncate_tests(void);
Suite *add_tests(void);
Suite *sub_tests(void);
Suite *div_tests(void);
Suite *floor_tests(void);
Suite *round_tests(void);
Suite *negate_tests(void);
Suite *mul_tests(void);
Suite *common_tests(void);

#endif  // S21_DECIMAL_TESTS_H
