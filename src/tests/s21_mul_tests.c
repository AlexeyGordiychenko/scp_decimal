#include "s21_decimal_tests.h"

START_TEST(s21_mul_1) {
  // s21_mul(5.5) = -5.5
  s21_decimal d1 = {{1, 0, 0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{1, 0, 0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{1, 0, 0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

// START_TEST(s21_mul_2) {
//   // s21_mul(-5.5) = 5.5
//   s21_decimal d1 = {{55, 0, 0, sign_and_exp_bits(1, 1)}};
//   s21_decimal correct = {{55, 0, 0, sign_and_exp_bits(0, 1)}};
//   s21_decimal result;

//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_3) {
//   // s21_mul(S21_MAX_DECIMAL_VALUE) = -S21_MAX_DECIMAL_VALUE
//   s21_decimal d1 = {{-1, -1, -1, sign_and_exp_bits(0, 0)}};
//   s21_decimal correct = {{-1, -1, -1, sign_and_exp_bits(1, 0)}};
//   s21_decimal result;

//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_4) {
//   // s21_mul(S21_MAX_DECIMAL_VALUE / 10^1) = -S21_MAX_DECIMAL_VALUE / 10^1
//   // 7922816251426433759354395033,5 => -7922816251426433759354395033,5
//   s21_decimal d1 = {{-1 & 0b10011001100110011001100110011001,
//                      -1 & 0b10011001100110011001100110011001,
//                      -1 & 0b00011001100110011001100110011001,
//                      sign_and_exp_bits(0, 0)}};
//   s21_decimal correct = {{-1 & 0b10011001100110011001100110011001,
//                           -1 & 0b10011001100110011001100110011001,
//                           -1 & 0b00011001100110011001100110011001,
//                           sign_and_exp_bits(1, 0)}};
//   s21_decimal result;
//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_5) {
//   // -35,8 => 35,8
//   s21_decimal d1 = {{358, 0, 0, sign_and_exp_bits(1, 1)}};
//   s21_decimal correct = {{358, 0, 0, sign_and_exp_bits(0, 1)}};
//   s21_decimal result;
//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_6) {
//   // -99,9999999 => 99,9999999
//   s21_decimal d1 = {{999999999, 0, 0, sign_and_exp_bits(1, 7)}};
//   s21_decimal correct = {{999999999, 0, 0, sign_and_exp_bits(0, 7)}};
//   s21_decimal result;
//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_7) {
//   // 99,9999999 => -99,9999999
//   s21_decimal d1 = {{999999999, 0, 0, sign_and_exp_bits(0, 7)}};
//   s21_decimal correct = {{999999999, 0, 0, sign_and_exp_bits(1, 7)}};

//   s21_decimal result;

//   // print_decimal_bits(d1);
//   // print_decimal_bits(correct);
//   // s21_mul(d1, &result);
//   // print_decimal_bits(result);

//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_8) {
//   // -0,0 => 0
//   s21_decimal d1 = {{0, 0, 0, sign_and_exp_bits(1, 0)}};
//   s21_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
//   s21_decimal result;
//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_9) {
//   // 0,0 => -0,0
//   s21_decimal d1 = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
//   s21_decimal correct = {{0, 0, 0, sign_and_exp_bits(1, 0)}};
//   s21_decimal result;
//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

// START_TEST(s21_mul_10) {
//   // -MAX_DECIMAL => MAX_DECIMAL
//   s21_decimal d1 = {{-1, -1, -1, sign_and_exp_bits(1, 0)}};
//   s21_decimal correct = {{-1, -1, -1, sign_and_exp_bits(0, 0)}};
//   s21_decimal result;

//   // print_decimal_bits(d1);
//   // print_decimal_bits(correct);
//   // s21_mul(d1, &result);
//   // print_decimal_bits(result);

//   ck_assert_int_eq(s21_mul(d1, &result), S21_OK);
//   ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
// }
// END_TEST

Suite *mul_tests(void) {
  Suite *s_mul = suite_create(PRE_TEST_HEADER "S21_MUL" POST_TEST_HEADER);
  TCase *tc_mul = tcase_create("mul_tc");

  suite_add_tcase(s_mul, tc_mul);
  tcase_add_test(tc_mul, s21_mul_1);
  // tcase_add_test(tc_mul, s21_mul_2);
  // tcase_add_test(tc_mul, s21_mul_3);
  // tcase_add_test(tc_mul, s21_mul_4);
  // tcase_add_test(tc_mul, s21_mul_5);
  // tcase_add_test(tc_mul, s21_mul_6);
  // tcase_add_test(tc_mul, s21_mul_7);
  // tcase_add_test(tc_mul, s21_mul_8);
  // tcase_add_test(tc_mul, s21_mul_9);
  // tcase_add_test(tc_mul, s21_mul_10);

  return s_mul;
}
