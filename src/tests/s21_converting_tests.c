#include "s21_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *           CONVERTING FUNCTIONS TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(s21_int_to_dec_1) {
  int src = 0;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_int_to_dec_2) {
  int src = __INT_MAX__;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_int_to_dec_3) {
  int src = -__INT_MAX__ - 1;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_int_to_dec_4) {
  ck_assert_int_eq(s21_from_int_to_decimal(0, NULL), S21_ERROR);
}
END_TEST

START_TEST(s21_float_to_dec_1) {
  float src = 0.1234;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_float_to_dec_2) {
  float src = 0;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_float_to_dec_3) {
  float src = -0.1234;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_float_to_dec_4) {
  float src = -powf(2, 70);
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_float_to_dec_5) {
  float src = 0x1.fffffep+127f;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), S21_ERROR);
}
END_TEST

START_TEST(s21_float_to_dec_6) {
  float src = NAN;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), S21_ERROR);
}
END_TEST

START_TEST(s21_float_to_dec_7) {
  float src = 3E-40;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), S21_ERROR);
}
END_TEST

START_TEST(s21_dec_to_int_1) {
  s21_decimal src = {{0, 0, 0, 0}};
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, 0);
}
END_TEST

START_TEST(s21_dec_to_int_2) {
  s21_decimal src = {{__INT_MAX__, 0, 0, 0}};
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, __INT_MAX__);
}
END_TEST

START_TEST(s21_dec_to_int_3) {
  s21_decimal src = {
      {(unsigned)__INT_MAX__ + 1, 0, 0, (unsigned)1 << S21_SIGN_SHIFT}};
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, -__INT_MAX__ - 1);
}
END_TEST

START_TEST(s21_dec_to_int_4) {
  s21_decimal src = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_from_decimal_to_int(src, NULL), S21_ERROR);
}
END_TEST

START_TEST(s21_dec_to_int_5) {
  s21_decimal src = {{-1, -1, 0, 0}};
  int dst;
  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), S21_ERROR);
}
END_TEST

START_TEST(s21_dec_to_int_6) {
  s21_decimal src = {{-1, -1, 0, 0b00000000000010000000000000000000}};
  int dst;
  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), S21_ERROR);
}
END_TEST

START_TEST(s21_dec_to_int_7) {
  s21_decimal src = {{-1, -1, 0, 0b00000000000010000000000000000001}};
  int dst;
  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), S21_ERROR);
}
END_TEST

START_TEST(s21_dec_to_int_8) {
  s21_decimal src = {{1, 0, 0, 0b00000000000011000000000000000001}};
  int dst;
  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), S21_OK);
}
END_TEST

START_TEST(s21_dec_to_int_9) {
  int isrc = 0;
  s21_decimal src;
  s21_from_int_to_decimal(isrc, &src);
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(s21_dec_to_int_10) {
  int isrc = -1;
  s21_decimal src;
  s21_from_int_to_decimal(isrc, &src);
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(s21_dec_to_int_11) {
  int isrc = 1;
  s21_decimal src;
  s21_from_int_to_decimal(isrc, &src);
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(s21_dec_to_int_12) {
  int isrc = __INT_MAX__;
  s21_decimal src;
  s21_from_int_to_decimal(isrc, &src);
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(s21_dec_to_int_13) {
  int isrc = -__INT_MAX__ - 1;
  s21_decimal src;
  s21_from_int_to_decimal(isrc, &src);
  int dst;
  s21_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(s21_dec_to_float_1) {
  float fsrc = 0.3333333333333333333333333333333;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_2) {
  float fsrc = -99999.99999;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_3) {
  float fsrc = 2000000;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_4) {
  s21_decimal src = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_from_decimal_to_float(src, NULL), S21_ERROR);
}
END_TEST

START_TEST(s21_dec_to_float_5) {
  s21_decimal src = {{-1, -1, -1, 0}};
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(pow(2, 96)));
}
END_TEST

START_TEST(s21_dec_to_float_6) {
  float fsrc = -0.000000002;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_7) {
  float fsrc = 0.231252;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_8) {
  float fsrc = -1844674407370956.01;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_9) {
  float fsrc = -6871947673;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_10) {
  float fsrc = 0.3331;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_11) {
  float fsrc = 0.000001234567890;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_12) {
  float fsrc = 1234567890.0;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_13) {
  float fsrc = 1234567890.1234567890;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_14) {
  float fsrc = 12345.67890;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_15) {
  float fsrc = 2394609.283479727364423;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_16) {
  float fsrc = 0.191919191919;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_17) {
  float fsrc = 0.919191919191;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_18) {
  float fsrc = 2.5010501050105;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_19) {
  float fsrc = powf(2, 67);
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(s21_dec_to_float_20) {
  float fsrc = 0.000000491919191919;
  s21_decimal src;
  s21_from_float_to_decimal(fsrc, &src);
  float dst;
  s21_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

Suite *converting_tests(void) {
  Suite *s = suite_create(PRE_TEST_HEADER "S21_CONVERTING" POST_TEST_HEADER);
  TCase *tc = tcase_create("converting_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_int_to_dec_1);
  tcase_add_test(tc, s21_int_to_dec_2);
  tcase_add_test(tc, s21_int_to_dec_3);
  tcase_add_test(tc, s21_int_to_dec_4);

  tcase_add_test(tc, s21_float_to_dec_1);
  tcase_add_test(tc, s21_float_to_dec_2);
  tcase_add_test(tc, s21_float_to_dec_3);
  tcase_add_test(tc, s21_float_to_dec_4);
  tcase_add_test(tc, s21_float_to_dec_5);
  tcase_add_test(tc, s21_float_to_dec_6);
  tcase_add_test(tc, s21_float_to_dec_7);

  tcase_add_test(tc, s21_dec_to_int_1);
  tcase_add_test(tc, s21_dec_to_int_2);
  tcase_add_test(tc, s21_dec_to_int_3);
  tcase_add_test(tc, s21_dec_to_int_4);
  tcase_add_test(tc, s21_dec_to_int_5);
  tcase_add_test(tc, s21_dec_to_int_6);
  tcase_add_test(tc, s21_dec_to_int_7);
  tcase_add_test(tc, s21_dec_to_int_8);
  tcase_add_test(tc, s21_dec_to_int_9);
  tcase_add_test(tc, s21_dec_to_int_10);
  tcase_add_test(tc, s21_dec_to_int_11);
  tcase_add_test(tc, s21_dec_to_int_12);
  tcase_add_test(tc, s21_dec_to_int_13);

  tcase_add_test(tc, s21_dec_to_float_1);
  tcase_add_test(tc, s21_dec_to_float_2);
  tcase_add_test(tc, s21_dec_to_float_3);
  tcase_add_test(tc, s21_dec_to_float_4);
  tcase_add_test(tc, s21_dec_to_float_5);
  tcase_add_test(tc, s21_dec_to_float_6);
  tcase_add_test(tc, s21_dec_to_float_7);
  tcase_add_test(tc, s21_dec_to_float_8);
  tcase_add_test(tc, s21_dec_to_float_9);
  tcase_add_test(tc, s21_dec_to_float_10);
  tcase_add_test(tc, s21_dec_to_float_11);
  tcase_add_test(tc, s21_dec_to_float_12);
  tcase_add_test(tc, s21_dec_to_float_13);
  tcase_add_test(tc, s21_dec_to_float_14);
  tcase_add_test(tc, s21_dec_to_float_15);
  tcase_add_test(tc, s21_dec_to_float_16);
  tcase_add_test(tc, s21_dec_to_float_17);
  tcase_add_test(tc, s21_dec_to_float_18);
  tcase_add_test(tc, s21_dec_to_float_19);
  tcase_add_test(tc, s21_dec_to_float_20);

  suite_add_tcase(s, tc);
  return s;
}
