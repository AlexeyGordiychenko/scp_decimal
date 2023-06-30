#include "s21_decimal_tests.h"

START_TEST(s21_floor_1) {
  // s21_floor(5.5) = 5.0
  s21_decimal d1 = {{55, 0, 0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{5, 0, 0, 0}};
  s21_decimal result;

  // print_decimal_bits(d1);
  // print_decimal_bits(correct);

  ck_assert_int_eq(s21_floor(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
  // print_decimal_bits(result);

  // ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_floor_2) {
  // s21_floor(-5.5) = -6.0
  s21_decimal d1 = {{55, 0, 0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{6, 0, 0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_floor(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_floor_3) {
  // s21_floor(S21_MAX_DECIMAL_VALUE) = S21_MAX_DECIMAL_VALUE
  s21_decimal d1 = {{-1, -1, -1, 0}};
  s21_decimal correct = {{-1, -1, -1, 0}};
  s21_decimal result;

  ck_assert_int_eq(s21_floor(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_floor_4) {
  // s21_floor(S21_MAX_DECIMAL_VALUE / 10^1) = S21_MAX_DECIMAL_VALUE
  // 7922816251426433759354395033,5 => 7922816251426433759354395033
  s21_decimal d1 = {{-1, -1, -1, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{-1 & 0b10011001100110011001100110011001,
                          -1 & 0b10011001100110011001100110011001,
                          -1 & 0b00011001100110011001100110011001, 0}};

  s21_decimal result;

  // print_decimal_bits(d1);
  // print_decimal_bits(correct);
  // s21_floor(d1, &result);
  // print_decimal_bits(result);

  ck_assert_int_eq(s21_floor(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

START_TEST(s21_floor_100) {
  // s21_floor(S21_MIN_DECIMAL_VALUE) = error code 1
  s21_decimal d1 = {{-1, -1, -1, sign_and_exp_bits(1, 0)}};
  // s21_decimal correct = {{0, 0, 0, 0}};
  // s21_decimal one = {{1, 0, 0, 0}};

  s21_decimal result;

  // print_decimal_bits(d1);
  // s21_truncate(d1, &result);
  // print_decimal_bits(result);

  // printf("\nerror code sub(MAX_DECIMAL - 1) : %d\n", s21_sub(d1, one,
  // &result)); printf("\nerror code -MAX_DECIMAL - 1 : %d\n", s21_floor(d1,
  // &result)); print_decimal_bits(result);

  ck_assert_int_eq(s21_floor(d1, &result), 1);
  // ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
}
END_TEST

Suite *floor_tests(void) {
  Suite *s_floor = suite_create(PRE_TEST_HEADER "S21_FLOOR" POST_TEST_HEADER);
  TCase *tc_floor = tcase_create("floor_tc");

  suite_add_tcase(s_floor, tc_floor);
  tcase_add_test(tc_floor, s21_floor_1);
  tcase_add_test(tc_floor, s21_floor_2);
  tcase_add_test(tc_floor, s21_floor_3);
  tcase_add_test(tc_floor, s21_floor_4);

  // FAILED TESTS
  tcase_add_test(tc_floor, s21_floor_100);

  return s_floor;
}
