#include "s21_decimal_tests.h"

START_TEST(s21_negate_1) {
  // s21_negate(5.5) = -5.5
  s21_decimal d1 = {{55, 0, 0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{55, 0, 0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_2) {
  // s21_negate(-5.5) = 5.5
  s21_decimal d1 = {{55, 0, 0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{55, 0, 0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_3) {
  // s21_negate(S21_MAX_DECIMAL_VALUE) = -S21_MAX_DECIMAL_VALUE
  s21_decimal d1 = {{-1, -1, -1, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{-1, -1, -1, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_4) {
  // s21_negate(S21_MAX_DECIMAL_VALUE / 10^1) = -S21_MAX_DECIMAL_VALUE / 10^1
  // 7922816251426433759354395033,5 => -7922816251426433759354395033,5
  s21_decimal d1 = {{-1 & 0b10011001100110011001100110011001,
                     -1 & 0b10011001100110011001100110011001,
                     -1 & 0b00011001100110011001100110011001,
                     sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{-1 & 0b10011001100110011001100110011001,
                          -1 & 0b10011001100110011001100110011001,
                          -1 & 0b00011001100110011001100110011001,
                          sign_and_exp_bits(1, 0)}};
  s21_decimal result;
  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_5) {
  // -35,8 => 35,8
  s21_decimal d1 = {{358, 0, 0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{358, 0, 0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;
  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_6) {
  // -99,9999999 => 99,9999999
  s21_decimal d1 = {{999999999, 0, 0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{999999999, 0, 0, sign_and_exp_bits(0, 7)}};
  s21_decimal result;
  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_7) {
  // 99,9999999 => -99,9999999
  s21_decimal d1 = {{999999999, 0, 0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {{999999999, 0, 0, sign_and_exp_bits(1, 7)}};

  s21_decimal result;

  // print_decimal_bits(d1);
  // print_decimal_bits(correct);
  // s21_negate(d1, &result);
  // print_decimal_bits(result);

  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_8) {
  // -0,0 => 0
  s21_decimal d1 = {{0, 0, 0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;
  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_9) {
  // 0,0 => -0,0
  s21_decimal d1 = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0, 0, 0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;
  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_negate_10) {
  // -MAX_DECIMAL => MAX_DECIMAL
  s21_decimal d1 = {{-1, -1, -1, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{-1, -1, -1, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  // print_decimal_bits(d1);
  // print_decimal_bits(correct);
  // s21_negate(d1, &result);
  // print_decimal_bits(result);

  ck_assert_int_eq(s21_negate(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

Suite *negate_tests(void) {
  Suite *s_negate = suite_create(PRE_TEST_HEADER "S21_NEGATE" POST_TEST_HEADER);
  TCase *tc_negate = tcase_create("negate_tc");

  suite_add_tcase(s_negate, tc_negate);
  tcase_add_test(tc_negate, s21_negate_1);
  tcase_add_test(tc_negate, s21_negate_2);
  tcase_add_test(tc_negate, s21_negate_3);
  tcase_add_test(tc_negate, s21_negate_4);
  tcase_add_test(tc_negate, s21_negate_5);
  tcase_add_test(tc_negate, s21_negate_6);
  tcase_add_test(tc_negate, s21_negate_7);
  tcase_add_test(tc_negate, s21_negate_8);
  tcase_add_test(tc_negate, s21_negate_9);
  tcase_add_test(tc_negate, s21_negate_10);

  return s_negate;
}
