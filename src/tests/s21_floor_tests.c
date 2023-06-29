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
  
  // print_decimal_bits(d1);
  // print_decimal_bits(correct);

  ck_assert_int_eq(s21_floor(d1, &result), S21_OK);
  ck_assert_int_eq(s21_is_equal(correct, result), S21_EQUAL);
  // print_decimal_bits(result);


  // ASSERT_BITS_EQ
}
END_TEST

Suite *floor_tests(void) {
  Suite *s_floor = suite_create(PRE_TEST_HEADER "S21_FLOOR" POST_TEST_HEADER);
  TCase *tc_floor = tcase_create("floor_tc");

  suite_add_tcase(s_floor, tc_floor);
  tcase_add_test(tc_floor, s21_floor_1);
  tcase_add_test(tc_floor, s21_floor_2);

  return s_floor;
}
