#include "scp_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *           CONVERTING FUNCTIONS TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(scp_int_to_dec_1) {
  int src = 0;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_int_to_decimal(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_int_to_dec_2) {
  int src = __INT_MAX__;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_int_to_decimal(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_int_to_dec_3) {
  int src = -__INT_MAX__ - 1;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_int_to_decimal(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_int_to_dec_4) {
  ck_assert_int_eq(scp_from_int_to_decimal(0, NULL), SCP_ERROR);
}
END_TEST

START_TEST(scp_float_to_dec_1) {
  float src = 0.1234;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_float_to_decimal(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_float_to_dec_2) {
  float src = 0;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_float_to_decimal(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_float_to_dec_3) {
  float src = -0.1234;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_float_to_decimal(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_float_to_dec_4) {
  float src = -powf(2, 70);
  scp_decimal dst;
  ck_assert_int_eq(scp_from_float_to_decimal(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_float_to_dec_5) {
  float src = 0x1.fffffep+127f;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_float_to_decimal(src, &dst), SCP_ERROR);
}
END_TEST

START_TEST(scp_float_to_dec_6) {
  float src = NAN;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_float_to_decimal(src, &dst), SCP_ERROR);
}
END_TEST

START_TEST(scp_float_to_dec_7) {
  float src = 3E-40;
  scp_decimal dst;
  ck_assert_int_eq(scp_from_float_to_decimal(src, &dst), SCP_ERROR);
}
END_TEST

START_TEST(scp_dec_to_int_1) {
  scp_decimal src = {{0, 0, 0, 0}};
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, 0);
}
END_TEST

START_TEST(scp_dec_to_int_2) {
  scp_decimal src = {{__INT_MAX__, 0, 0, 0}};
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, __INT_MAX__);
}
END_TEST

START_TEST(scp_dec_to_int_3) {
  scp_decimal src = {
      {(unsigned)__INT_MAX__ + 1, 0, 0, (unsigned)1 << SCP_SIGN_SHIFT}};
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(dst, -__INT_MAX__ - 1);
}
END_TEST

START_TEST(scp_dec_to_int_4) {
  scp_decimal src = {{0, 0, 0, 0}};
  ck_assert_int_eq(scp_from_decimal_to_int(src, NULL), SCP_ERROR);
}
END_TEST

START_TEST(scp_dec_to_int_5) {
  scp_decimal src = {{-1, -1, 0, 0}};
  int dst;
  ck_assert_int_eq(scp_from_decimal_to_int(src, &dst), SCP_ERROR);
}
END_TEST

START_TEST(scp_dec_to_int_6) {
  scp_decimal src = {{-1, -1, 0, 0b00000000000010000000000000000000}};
  int dst;
  ck_assert_int_eq(scp_from_decimal_to_int(src, &dst), SCP_ERROR);
}
END_TEST

START_TEST(scp_dec_to_int_7) {
  scp_decimal src = {{-1, -1, 0, 0b00000000000010000000000000000001}};
  int dst;
  ck_assert_int_eq(scp_from_decimal_to_int(src, &dst), SCP_ERROR);
}
END_TEST

START_TEST(scp_dec_to_int_8) {
  scp_decimal src = {{1, 0, 0, 0b00000000000011000000000000000001}};
  int dst;
  ck_assert_int_eq(scp_from_decimal_to_int(src, &dst), SCP_OK);
}
END_TEST

START_TEST(scp_dec_to_int_9) {
  int isrc = 0;
  scp_decimal src;
  scp_from_int_to_decimal(isrc, &src);
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(scp_dec_to_int_10) {
  int isrc = -1;
  scp_decimal src;
  scp_from_int_to_decimal(isrc, &src);
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(scp_dec_to_int_11) {
  int isrc = 1;
  scp_decimal src;
  scp_from_int_to_decimal(isrc, &src);
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(scp_dec_to_int_12) {
  int isrc = __INT_MAX__;
  scp_decimal src;
  scp_from_int_to_decimal(isrc, &src);
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(scp_dec_to_int_13) {
  int isrc = -__INT_MAX__ - 1;
  scp_decimal src;
  scp_from_int_to_decimal(isrc, &src);
  int dst;
  scp_from_decimal_to_int(src, &dst);
  ck_assert_int_eq(isrc, dst);
}
END_TEST

START_TEST(scp_dec_to_float_1) {
  float fsrc = 0.3333333333333333333333333333333;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_2) {
  float fsrc = -99999.99999;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_3) {
  float fsrc = 2000000;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_4) {
  scp_decimal src = {{0, 0, 0, 0}};
  ck_assert_int_eq(scp_from_decimal_to_float(src, NULL), SCP_ERROR);
}
END_TEST

START_TEST(scp_dec_to_float_5) {
  scp_decimal src = {{-1, -1, -1, 0}};
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(pow(2, 96)));
}
END_TEST

START_TEST(scp_dec_to_float_6) {
  float fsrc = -0.000000002;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_7) {
  float fsrc = 0.231252;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_8) {
  float fsrc = -1844674407370956.01;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_9) {
  float fsrc = -6871947673;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_10) {
  float fsrc = 0.3331;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_11) {
  float fsrc = 0.000001234567890;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_12) {
  float fsrc = 1234567890.0;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_13) {
  float fsrc = 1234567890.1234567890;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_14) {
  float fsrc = 12345.67890;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_15) {
  float fsrc = 2394609.283479727364423;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_16) {
  float fsrc = 0.191919191919;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_17) {
  float fsrc = 0.919191919191;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_18) {
  float fsrc = 2.5010501050105;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_19) {
  float fsrc = powf(2, 67);
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

START_TEST(scp_dec_to_float_20) {
  float fsrc = 0.000000491919191919;
  scp_decimal src;
  scp_from_float_to_decimal(fsrc, &src);
  float dst;
  scp_from_decimal_to_float(src, &dst);
  ck_assert_float_eq(dst, (float)conv_round(fsrc));
}
END_TEST

Suite *converting_tests(void) {
  Suite *s = suite_create(PRE_TEST_HEADER "SCP_CONVERTING" POST_TEST_HEADER);
  TCase *tc = tcase_create("converting_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, scp_int_to_dec_1);
  tcase_add_test(tc, scp_int_to_dec_2);
  tcase_add_test(tc, scp_int_to_dec_3);
  tcase_add_test(tc, scp_int_to_dec_4);

  tcase_add_test(tc, scp_float_to_dec_1);
  tcase_add_test(tc, scp_float_to_dec_2);
  tcase_add_test(tc, scp_float_to_dec_3);
  tcase_add_test(tc, scp_float_to_dec_4);
  tcase_add_test(tc, scp_float_to_dec_5);
  tcase_add_test(tc, scp_float_to_dec_6);
  tcase_add_test(tc, scp_float_to_dec_7);

  tcase_add_test(tc, scp_dec_to_int_1);
  tcase_add_test(tc, scp_dec_to_int_2);
  tcase_add_test(tc, scp_dec_to_int_3);
  tcase_add_test(tc, scp_dec_to_int_4);
  tcase_add_test(tc, scp_dec_to_int_5);
  tcase_add_test(tc, scp_dec_to_int_6);
  tcase_add_test(tc, scp_dec_to_int_7);
  tcase_add_test(tc, scp_dec_to_int_8);
  tcase_add_test(tc, scp_dec_to_int_9);
  tcase_add_test(tc, scp_dec_to_int_10);
  tcase_add_test(tc, scp_dec_to_int_11);
  tcase_add_test(tc, scp_dec_to_int_12);
  tcase_add_test(tc, scp_dec_to_int_13);

  tcase_add_test(tc, scp_dec_to_float_1);
  tcase_add_test(tc, scp_dec_to_float_2);
  tcase_add_test(tc, scp_dec_to_float_3);
  tcase_add_test(tc, scp_dec_to_float_4);
  tcase_add_test(tc, scp_dec_to_float_5);
  tcase_add_test(tc, scp_dec_to_float_6);
  tcase_add_test(tc, scp_dec_to_float_7);
  tcase_add_test(tc, scp_dec_to_float_8);
  tcase_add_test(tc, scp_dec_to_float_9);
  tcase_add_test(tc, scp_dec_to_float_10);
  tcase_add_test(tc, scp_dec_to_float_11);
  tcase_add_test(tc, scp_dec_to_float_12);
  tcase_add_test(tc, scp_dec_to_float_13);
  tcase_add_test(tc, scp_dec_to_float_14);
  tcase_add_test(tc, scp_dec_to_float_15);
  tcase_add_test(tc, scp_dec_to_float_16);
  tcase_add_test(tc, scp_dec_to_float_17);
  tcase_add_test(tc, scp_dec_to_float_18);
  tcase_add_test(tc, scp_dec_to_float_19);
  tcase_add_test(tc, scp_dec_to_float_20);

  suite_add_tcase(s, tc);
  return s;
}
