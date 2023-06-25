#include "s21_decimal_tests.h"

START_TEST(s21_sub_1) {
  s21_decimal resutl;
  s21_decimal first = {
      {0b01111111111111111111111111000001, 0b11111111111111111111111111000001,
       0b11111111111111111111111111000001, 0b00000000000000000000000000000000}};
  s21_decimal second = {
      {0b11111111111111111111000000000011, 0b11111111111111111111111111000000,
       0b11111111111111111111111111000001, 0b00000000000000000000000000000000}};

  ck_assert_int_eq(s21_sub(first, second, &resutl), 0);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal resutl;
  s21_decimal first = {{0b00000000000000000000000000000000, 0,
                        0b10000000000000000000000000000000,
                        0b00000000000000000000000000000000}};
  s21_decimal second = {{4, 0, 0, 0b00000000000000000000000000000000}};

  ck_assert_int_eq(s21_sub(first, second, &resutl), 0);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal resutl;
  s21_decimal first = {{0b00000000000000000000000010000000, 0,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000}};
  s21_decimal second = {{4, 0, 100, 0b00000000000000000000000000000000}};

  ck_assert_int_eq(s21_sub(first, second, &resutl), 0);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal resutl;
  s21_decimal first = {{0b00000000000000000001111110000000, 0,
                        0b00000000000000000000000000000000,
                        0b00000000001011000000000000000000}};
  s21_decimal second = {{4, 0, 100, 0b00000000000011100000000000000000}};

  ck_assert_int_eq(s21_sub(first, second, &resutl), 0);
}
END_TEST

START_TEST(s21_sub_5) {
  s21_decimal resutl;
  s21_decimal first = {{0b11111111111111111111111111111111, 5670, 1254,
                        0b000000000000100000000000000000000}};
  s21_decimal second = {{0b00000000000000000000000000000001, 5670, 1254,
                         0b00000000000001000000000000000000}};
  ck_assert_int_eq(s21_add(first, second, &resutl), 0);
}
END_TEST

Suite *sub_tests(void) {
  Suite *s = suite_create("\033[33m**S21_SUB**\033[0m");
  TCase *tc = tcase_create("sub_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  suite_add_tcase(s, tc);
  return s;
}
