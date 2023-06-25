#include "s21_decimal_tests.h"

START_TEST(s21_add_1) {
  s21_decimal resutl;
  s21_decimal first =  {{0b11111111111111111111111111111111, 5670, 1254,  0b00000000000000000000000000000000}};
  s21_decimal second = {{0b00000000000000000000000000000001, 5670, 1254, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(s21_add(first, second, &resutl), 0);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal resutl;
  s21_decimal first =  {{0b11111111111111111111111111111111, 5670, 1254,  0b00000000000001000000000000000000}};
  s21_decimal second = {{0b00000000000000000000000000000001, 5670, 1254,  0b00000000000100000000000000000000}};
  ck_assert_int_eq(s21_add(first, second, &resutl), 0);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal resutl;
  s21_decimal first =  {{0b11111111111111111111111111111111, 5670, 1254,  0b000000000000100000000000000000000}};
  s21_decimal second = {{0b00000000000000000000000000000001, 5670, 1254,  0b00000000000001000000000000000000}};
  ck_assert_int_eq(s21_add(first, second, &resutl), 0);
}
END_TEST

Suite *add_tests(void) {
  Suite *s = suite_create("\033[33m**S21_ADD**\033[0m");
  TCase *tc = tcase_create("add_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  suite_add_tcase(s, tc);
  return s;
}