#include "s21_decimal_tests.h"

START_TEST(s21_div_1) {
  // 442320 / 40 = 11058
  s21_decimal d1 = {{0x6bfd0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x28, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x2b32, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_2) {
  // 38410781346 / 3 = 12803593782
  s21_decimal d1 = {{0xf17602a2, 0x8, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xfb275636, 0x2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_3) {
  // 32768 / -2 = -16384
  s21_decimal d1 = {{0x8000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x4000, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_4) {
  // 32768 / 2 = 16384
  s21_decimal d1 = {{0x8000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x4000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_5) {
  // 30064771176 / -2 = -15032385588
  s21_decimal d1 = {{0x68, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x80000034, 0x3, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_6) {
  //-101 / 10.01 = -10.08991008991008991008991009
  s21_decimal d1 = {{0x65, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3e9, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {
      {0x36cf2721, 0x32c513ad, 0x3429e28, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_7) {
  // 2.25 / -1.5 = -1.5
  s21_decimal d1 = {{0xe1, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xf, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0xf, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_8) {
  // 0 / 0.015 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_9) {
  // 0.0000 / 5.7 = 0.000
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x39, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_10) {
  // 101 / 0 = S21_DIV_ZERO_ERR
  s21_decimal d1 = {{0x65, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_DIV_ZERO_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_11) {
  //-579 / 0 = S21_DIV_ZERO_ERR
  s21_decimal d1 = {{0x243, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_DIV_ZERO_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_12) {
  // 7 / -3 = -2.3333333333333333333333333333
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x25555555, 0x9101058d, 0x4b64e186, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_13) {
  //-10 / 3 = -3.3333333333333333333333333333
  s21_decimal d1 = {{0xa, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x35555555, 0xcf2607ee, 0x6bb4afe4, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_14) {
  // 10.0 / 3 = 3.3333333333333333333333333333
  s21_decimal d1 = {{0x64, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x35555555, 0xcf2607ee, 0x6bb4afe4, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_15) {
  //-7 / -3.0 = 2.3333333333333333333333333333
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1e, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0x25555555, 0x9101058d, 0x4b64e186, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_16) {
  // 2 / 3 = 0.6666666666666666666666666667
  s21_decimal d1 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xaaaaaab, 0x296e0196, 0x158a8994, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_17) {
  // 7.0 / 7 = 1
  s21_decimal d1 = {{0x46, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_18) {
  // 7922816251426433759354395033.5 / 0.1 = 79228162514264337593543950335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_19) {
  // 7922816251426433759354395033.5 / 0.01 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_20) {
  // 7922816251426433759354395033.5 / 0.7 = 11318308930609191084791992905
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x49249249, 0x92492492, 0x24924924, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_21) {
  // 79228162514264337593543950335 / 0.4 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_22) {
  // 0.0000000000000000000000000001 / 8 = 0
  s21_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal d2 = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_23) {
  // 20 / 0.00005 = 400000
  s21_decimal d1 = {{0x14, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x61a80, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_24) {
  //-936582642837 / 0.1041747302401649 = -8990497414083.03230156190427
  s21_decimal d1 = {{0x10acfc95, 0xda, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xb1e7c671, 0x3b376, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0x662eb2db, 0x23ef54ff, 0x2e7ad30, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_25) {
  // 936582642836 / -0.1041747302401641 = -8990497414073.502086318918586
  s21_decimal d1 = {{0x10acfc94, 0xda, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xb1e7c669, 0x3b376, 0x0, sign_and_exp_bits(1, 16)}};
  s21_decimal correct = {
      {0xd7a20bba, 0x6737764b, 0x1d0cc3e1, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_26) {
  //-75384834.34934734873487 / -1349.34984 = 55867.523836033025160376496580
  s21_decimal d1 = {{0xe36ae38f, 0xa9793779, 0x198, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0x80af1c8, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0x972204fa, 0x9272c199, 0x120d40d5, sign_and_exp_bits(0, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_27) {
  // 4449249363747.434387 / 43764 = 101664595.64362111294671419431
  s21_decimal d1 = {{0x234c6f93, 0x3dbee8b9, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0xaaf4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x373bf827, 0x4ef17458, 0x20d97f8d, sign_and_exp_bits(0, 20)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_28) {
  //-0.3183718237812378127 / -0.3183718237812378127 = 1
  s21_decimal d1 = {{0x85bd4a0f, 0x2c2ed6de, 0x0, sign_and_exp_bits(1, 19)}};
  s21_decimal d2 = {{0x85bd4a0f, 0x2c2ed6de, 0x0, sign_and_exp_bits(1, 19)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_29) {
  // 948347948.43877834 / 10000000000000000 = 0.000000094834794843877834
  s21_decimal d1 = {{0x530431ca, 0x150ebbe, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0x6fc10000, 0x2386f2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x530431ca, 0x150ebbe, 0x0, sign_and_exp_bits(0, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_30) {
  //-184838746726726348023 / 0.00000000193289 = S21_SMALL_ERR
  s21_decimal d1 = {{0x8eebacf7, 0x52724d4, 0xa, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2f309, 0x0, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_31) {
  // 45284674874386437639 / 0.00000000048934 = S21_HUGE_ERR
  s21_decimal d1 = {{0xa8dc5607, 0x74737bde, 0x2, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xbf26, 0x0, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = S21_D_ZERO;
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_32) {
  // 75384834.34934734873487 / 1349.34984 = 55867.523836033025160376496580
  s21_decimal d1 = {{0xe36ae38f, 0xa9793779, 0x198, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {{0x80af1c8, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0x972204fa, 0x9272c199, 0x120d40d5, sign_and_exp_bits(0, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_33) {
  // 7.9228162514264337593543950335 / 0.5 = 15.845632502852867518708790067
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 28)}};
  s21_decimal d2 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x33333333, 0x33333333, 0x33333333, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

Suite *div_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "S21_DIV" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("tc");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_div_1);
  tcase_add_test(tc1_1, s21_div_2);
  tcase_add_test(tc1_1, s21_div_3);
  tcase_add_test(tc1_1, s21_div_4);
  tcase_add_test(tc1_1, s21_div_5);
  tcase_add_test(tc1_1, s21_div_6);
  tcase_add_test(tc1_1, s21_div_7);
  tcase_add_test(tc1_1, s21_div_8);
  tcase_add_test(tc1_1, s21_div_9);
  tcase_add_test(tc1_1, s21_div_10);
  tcase_add_test(tc1_1, s21_div_11);
  tcase_add_test(tc1_1, s21_div_12);
  tcase_add_test(tc1_1, s21_div_13);
  tcase_add_test(tc1_1, s21_div_14);
  tcase_add_test(tc1_1, s21_div_15);
  tcase_add_test(tc1_1, s21_div_16);
  tcase_add_test(tc1_1, s21_div_17);
  tcase_add_test(tc1_1, s21_div_18);
  tcase_add_test(tc1_1, s21_div_19);
  tcase_add_test(tc1_1, s21_div_20);
  tcase_add_test(tc1_1, s21_div_21);
  tcase_add_test(tc1_1, s21_div_22);
  tcase_add_test(tc1_1, s21_div_23);
  tcase_add_test(tc1_1, s21_div_24);
  tcase_add_test(tc1_1, s21_div_25);
  tcase_add_test(tc1_1, s21_div_26);
  tcase_add_test(tc1_1, s21_div_27);
  tcase_add_test(tc1_1, s21_div_28);
  tcase_add_test(tc1_1, s21_div_29);
  tcase_add_test(tc1_1, s21_div_30);
  tcase_add_test(tc1_1, s21_div_31);
  tcase_add_test(tc1_1, s21_div_32);
  tcase_add_test(tc1_1, s21_div_33);

  return s1;
}
