#include "scp_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *             COMMON.C FUNCTIONS TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(scp_common_0) {
  // 79228162514264337593543950335 + 1 = false
  scp_decimal result = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(add_bits(&result, d2), false);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_common_1) {
  // 79228162514264337593543950335 * 2 = false
  scp_decimal result = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(left_shift_bits(&result, false), false);
  ASSERT_BITS_EQ
}
END_TEST

Suite *common_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "SCP_COMMON" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("SCP_COMMON");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, scp_common_0);
  tcase_add_test(tc1_1, scp_common_1);

  return s1;
}
