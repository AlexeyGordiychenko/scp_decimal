#include "s21_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *           COMPARATION FUNCTIONS TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(s21_comparison_0) {
  //-5343122372281.8514525874287 < 52795676156494.0948781
  s21_decimal d1 = {
      {0xefdfe86f, 0x71231b6e, 0x2c3280, sign_and_exp_bits(1, 13)}};
  s21_decimal d2 = {{0x93e9552d, 0x9edf3568, 0x1c, sign_and_exp_bits(0, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_1) {
  // 77941310041 == 77941310041
  s21_decimal d1 = {{0x25aa0259, 0x12, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x25aa0259, 0x12, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_2) {
  //-71596119749080155567.408 < 71596119749080155567.408
  s21_decimal d1 = {{0xdc0a3530, 0x3bc1fb49, 0xf29, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0xdc0a3530, 0x3bc1fb49, 0xf29, sign_and_exp_bits(0, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_3) {
  // 9.1536269615500000 < 816.14
  s21_decimal d1 = {{0x927f0ae0, 0x14533c0, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal d2 = {{0x13ece, 0x0, 0x0, sign_and_exp_bits(0, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_4) {
  //-5224.2996767 < 88.54
  s21_decimal d1 = {{0x29ecde1f, 0xc, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0x2296, 0x0, 0x0, sign_and_exp_bits(0, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_5) {
  // 5671.18600000000000 < 83125.394
  s21_decimal d1 = {{0xaa845000, 0x7decf5c, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {{0x4f46492, 0x0, 0x0, sign_and_exp_bits(0, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_6) {
  // 64080169.46478496949586930 < 74870164.57027
  s21_decimal d1 = {
      {0xb179cbf2, 0x4b73bd54, 0x54cf3, sign_and_exp_bits(0, 17)}};
  s21_decimal d2 = {{0x34f4d343, 0x6cf, 0x0, sign_and_exp_bits(0, 5)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_7) {
  // 84884.5 == 84884.5
  s21_decimal d1 = {{0xcf3cd, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xcf3cd, 0x0, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_8) {
  // 1.911 == 1.911
  s21_decimal d1 = {{0x777, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x777, 0x0, 0x0, sign_and_exp_bits(0, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_9) {
  // 400312059930927925344 == 400312059930927925344
  s21_decimal d1 = {{0x1fd78860, 0xb3722190, 0x15, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1fd78860, 0xb3722190, 0x15, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_10) {
  //-3.1912985678075359 == -3.1912985678075359
  s21_decimal d1 = {{0xff1055df, 0x7160b0, 0x0, sign_and_exp_bits(1, 16)}};
  s21_decimal d2 = {{0xff1055df, 0x7160b0, 0x0, sign_and_exp_bits(1, 16)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_11) {
  // 38.39198343305 > -4
  s21_decimal d1 = {{0xe20db089, 0x37d, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_12) {
  //-1814799481687075203.43968 < -0.3
  s21_decimal d1 = {{0x12202fa0, 0xc364977, 0x266e, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(1, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_13) {
  // 219008709.8829094723824698553 == 219008709.8829094723824698553
  s21_decimal d1 = {
      {0x3d60c4b9, 0x862ea11e, 0x71398fb, sign_and_exp_bits(0, 19)}};
  s21_decimal d2 = {
      {0x3d60c4b9, 0x862ea11e, 0x71398fb, sign_and_exp_bits(0, 19)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_14) {
  // 78641.14000000000 > 924.3
  s21_decimal d1 = {{0xb9717400, 0x1bf05e, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0x241b, 0x0, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_15) {
  //-7937.1899149 > -9714.6593677
  s21_decimal d1 = {{0x7aef110d, 0x12, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0x9e63618d, 0x16, 0x0, sign_and_exp_bits(1, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_16) {
  //-627.095 > -85586.653
  s21_decimal d1 = {{0x99197, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x519f2dd, 0x0, 0x0, sign_and_exp_bits(1, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_17) {
  // 20 == 20
  s21_decimal d1 = {{0x14, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x14, 0x0, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_18) {
  // 9.482703567995 < 913
  s21_decimal d1 = {{0xdd2d7c7b, 0x89f, 0x0, sign_and_exp_bits(0, 12)}};
  s21_decimal d2 = {{0x391, 0x0, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_19) {
  //-6663218400504.2061241 < -441592047959
  s21_decimal d1 = {{0xf4ff3fb9, 0x9cb51251, 0x3, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0xd0efe957, 0x66, 0x0, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_20) {
  // 60544594375.3 == 60544594375.3
  s21_decimal d1 = {{0xf763f1c9, 0x8c, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xf763f1c9, 0x8c, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_21) {
  //-30943750.986025972891203 < 30943750.986025972891203
  s21_decimal d1 = {{0x7d817e43, 0x76cf66c5, 0x68d, sign_and_exp_bits(1, 15)}};
  s21_decimal d2 = {{0x7d817e43, 0x76cf66c5, 0x68d, sign_and_exp_bits(0, 15)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_22) {
  // 683533142 > -354.06
  s21_decimal d1 = {{0x28bde356, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x8a4e, 0x0, 0x0, sign_and_exp_bits(1, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_23) {
  //-3799.1217 > -5350548042.8807717
  s21_decimal d1 = {{0x243b331, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x727ee625, 0xbe16f3, 0x0, sign_and_exp_bits(1, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_24) {
  // 10373018161810451 > 290150.6
  s21_decimal d1 = {{0x7ec88c13, 0x24da34, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2c4602, 0x0, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_25) {
  // 0.5562 < 2.4945850707
  s21_decimal d1 = {{0x15ba, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0xcee37953, 0x5, 0x0, sign_and_exp_bits(0, 10)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_26) {
  // 945237042.42 > -986083490138471822
  s21_decimal d1 = {{0x20d43b2, 0x16, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xb494bd8e, 0xdaf45b5, 0x0, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_27) {
  //-4.25 == -4.25
  s21_decimal d1 = {{0x1a9, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x1a9, 0x0, 0x0, sign_and_exp_bits(1, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_28) {
  //-469.7977089 < 469.7977089
  s21_decimal d1 = {{0x18057101, 0x1, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0x18057101, 0x1, 0x0, sign_and_exp_bits(0, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_29) {
  // 820025000783503587381 > 0.05100
  s21_decimal d1 = {{0xb0267835, 0x74220988, 0x2c, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x13ec, 0x0, 0x0, sign_and_exp_bits(0, 5)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_30) {
  // 12379928711937485.1984611191 == 12379928711937485.1984611191
  s21_decimal d1 = {
      {0x79245777, 0xcd66c0f2, 0x666784, sign_and_exp_bits(0, 10)}};
  s21_decimal d2 = {
      {0x79245777, 0xcd66c0f2, 0x666784, sign_and_exp_bits(0, 10)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_31) {
  // 25094.64399847066059153561 > -25094.64399847066059153561
  s21_decimal d1 = {{0xc502099, 0x5673ccb0, 0x21366, sign_and_exp_bits(0, 20)}};
  s21_decimal d2 = {{0xc502099, 0x5673ccb0, 0x21366, sign_and_exp_bits(1, 20)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_32) {
  // 95482558.0398 > -95482558.0398
  s21_decimal d1 = {{0x500a1f6e, 0xde, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x500a1f6e, 0xde, 0x0, sign_and_exp_bits(1, 4)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_33) {
  // 7137.130003558 < 7287616788942.337
  s21_decimal d1 = {{0xbe193c66, 0x67d, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x81f6ce01, 0x19e40c, 0x0, sign_and_exp_bits(0, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_34) {
  //-3315 == -3315
  s21_decimal d1 = {{0xcf3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xcf3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_35) {
  //-34.4 > -2377.493122185520224562
  s21_decimal d1 = {{0x158, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x1a501932, 0xe2585621, 0x80, sign_and_exp_bits(1, 18)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_36) {
  // 4 < 88756651.1539898502080
  s21_decimal d1 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x744b4bc0, 0x1d75afb7, 0x30, sign_and_exp_bits(0, 13)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_37) {
  // 1.598922709571391563 > -1.598922709571391563
  s21_decimal d1 = {{0x9f4ed04b, 0x163083bb, 0x0, sign_and_exp_bits(0, 18)}};
  s21_decimal d2 = {{0x9f4ed04b, 0x163083bb, 0x0, sign_and_exp_bits(1, 18)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_38) {
  //-586220711945.5041851805 < 586220711945.5041851805
  s21_decimal d1 = {{0x3af919d, 0xca776bd7, 0x13d, sign_and_exp_bits(1, 10)}};
  s21_decimal d2 = {{0x3af919d, 0xca776bd7, 0x13d, sign_and_exp_bits(0, 10)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_39) {
  // 3.51315779564292780472 < 5555612733165.4014349712254
  s21_decimal d1 = {{0xb71bb1b8, 0xb7c6029, 0x13, sign_and_exp_bits(0, 20)}};
  s21_decimal d2 = {
      {0xc6c19b7e, 0xb288597e, 0x2df477, sign_and_exp_bits(0, 13)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_40) {
  //-7.5687945146965868795453 > -12664811049608213981.4358291
  s21_decimal d1 = {{0xd761d63d, 0xd3e0b3e, 0x1007, sign_and_exp_bits(1, 22)}};
  s21_decimal d2 = {
      {0x9b04ed13, 0xd3b9ab16, 0x68c2c7, sign_and_exp_bits(1, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_41) {
  // 1 > -1
  s21_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_42) {
  // 936 > -558645923075127919220.15
  s21_decimal d1 = {{0x3a8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x37a1f55f, 0x6cf54063, 0xbd4, sign_and_exp_bits(1, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_43) {
  //-7887120581.5169885483 < 7887120581.5169885483
  s21_decimal d1 = {{0xb3eca52b, 0x468ecfcf, 0x4, sign_and_exp_bits(1, 10)}};
  s21_decimal d2 = {{0xb3eca52b, 0x468ecfcf, 0x4, sign_and_exp_bits(0, 10)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_44) {
  // 57.0 > 12
  s21_decimal d1 = {{0x23a, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xc, 0x0, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_45) {
  // 10.0940 == 10.0940
  s21_decimal d1 = {{0x18a4c, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x18a4c, 0x0, 0x0, sign_and_exp_bits(0, 4)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_46) {
  //-6.78522820431853372264 == -6.78522820431853372264
  s21_decimal d1 = {{0xfcc7c368, 0xc8654e36, 0x24, sign_and_exp_bits(1, 20)}};
  s21_decimal d2 = {{0xfcc7c368, 0xc8654e36, 0x24, sign_and_exp_bits(1, 20)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_47) {
  //-803961.72676683 < 264632.85960
  s21_decimal d1 = {{0xb1504e4b, 0x491e, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0x2955b2c8, 0x6, 0x0, sign_and_exp_bits(0, 5)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_48) {
  //-14.4 < 14.4
  s21_decimal d1 = {{0x90, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x90, 0x0, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_49) {
  //-491301083305.7017827428383552 < 756.219017742862
  s21_decimal d1 = {
      {0xa55fbb40, 0xeea8b626, 0xfdff282, sign_and_exp_bits(1, 16)}};
  s21_decimal d2 = {{0xf5ecca0e, 0x2afc6, 0x0, sign_and_exp_bits(0, 12)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_50) {
  //-8441.992 == -8441.992
  s21_decimal d1 = {{0x80d088, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x80d088, 0x0, 0x0, sign_and_exp_bits(1, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_51) {
  // 64712822322745.2 > -2739714451187.094
  s21_decimal d1 = {{0x47de9e3c, 0x24c8f, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x7aa62596, 0x9bbc1, 0x0, sign_and_exp_bits(1, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_52) {
  //-30440114133.078403 < -8676.72
  s21_decimal d1 = {{0x5dd31183, 0x6c251f, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0xd3d58, 0x0, 0x0, sign_and_exp_bits(1, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_53) {
  //-184.3301 < 76259.40
  s21_decimal d1 = {{0x1c2065, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x745cd4, 0x0, 0x0, sign_and_exp_bits(0, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_54) {
  //-182959575020 < 81.95
  s21_decimal d1 = {{0x993d8fec, 0x2a, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2003, 0x0, 0x0, sign_and_exp_bits(0, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_55) {
  //-664.71932000 > -5478905046158389179994.981
  s21_decimal d1 = {{0x7a093060, 0xf, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0xabe5365, 0x9a65604, 0x48834, sign_and_exp_bits(1, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_56) {
  // 472874.66421984032713 > -472874.66421984032713
  s21_decimal d1 = {{0xca91f7c9, 0x903ed42b, 0x2, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {{0xca91f7c9, 0x903ed42b, 0x2, sign_and_exp_bits(1, 14)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_57) {
  // 955994157159478.315229 > -955994157159478.315229
  s21_decimal d1 = {{0xc7a9c8dd, 0xd31584dc, 0x33, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0xc7a9c8dd, 0xd31584dc, 0x33, sign_and_exp_bits(1, 6)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_58) {
  //-68 < 68
  s21_decimal d1 = {{0x44, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x44, 0x0, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_59) {
  // 7 > -90.55649065201
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x6ebee8f1, 0x83c, 0x0, sign_and_exp_bits(1, 11)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_60) {
  // 24844.86 > -79831323173557544961.733
  s21_decimal d1 = {{0x25e906, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0x7b4046c5, 0xaa29d5df, 0x10e7, sign_and_exp_bits(1, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_61) {
  // 971.0 < 5121.72
  s21_decimal d1 = {{0x25ee, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x7d0ac, 0x0, 0x0, sign_and_exp_bits(0, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_62) {
  // 735435341166270544034.2878107 == 735435341166270544034.2878107
  s21_decimal d1 = {
      {0xec87279b, 0x4ebb399e, 0x17c360e9, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {
      {0xec87279b, 0x4ebb399e, 0x17c360e9, sign_and_exp_bits(0, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_63) {
  // 63 > 8.5400000
  s21_decimal d1 = {{0x3f, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x51719c0, 0x0, 0x0, sign_and_exp_bits(0, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_64) {
  //-9.55186190544 < 82635174338.7
  s21_decimal d1 = {{0x658898d0, 0xde, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {{0x6666f19b, 0xc0, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_65) {
  // 0 > -38521881.6
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x16f5f900, 0x0, 0x0, sign_and_exp_bits(1, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_66) {
  // 446.2525749737783 > -446.2525749737783
  s21_decimal d1 = {{0xbe1d3937, 0xfdaa4, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {{0xbe1d3937, 0xfdaa4, 0x0, sign_and_exp_bits(1, 13)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_67) {
  //-49904024.45424 < 444425838355868842383386.54
  s21_decimal d1 = {{0xeb2a4070, 0x489, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {
      {0x56fc6a5e, 0x4c19ed74, 0x24c315, sign_and_exp_bits(0, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_68) {
  // 830392237.50078729563 == 830392237.50078729563
  s21_decimal d1 = {{0x3f9f8d5b, 0x8066960a, 0x4, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0x3f9f8d5b, 0x8066960a, 0x4, sign_and_exp_bits(0, 11)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_69) {
  // 318 == 318
  s21_decimal d1 = {{0x13e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x13e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_70) {
  // 586.89 > -2818600842771070.95
  s21_decimal d1 = {{0xe541, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xd7b2d997, 0x3e95e40, 0x0, sign_and_exp_bits(1, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_71) {
  //-2.902 < 2.902
  s21_decimal d1 = {{0xb56, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0xb56, 0x0, 0x0, sign_and_exp_bits(0, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_72) {
  //-2228635870188251051.132 < 958670.7250929124
  s21_decimal d1 = {{0x846f47c, 0xd089241e, 0x78, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x3841dde4, 0x220f0f, 0x0, sign_and_exp_bits(0, 10)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_73) {
  // 5230.28927269 > -5230.28927269
  s21_decimal d1 = {{0xc6f41325, 0x79, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0xc6f41325, 0x79, 0x0, sign_and_exp_bits(1, 8)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_74) {
  // 129572620407508795347659169 == 129572620407508795347659169
  s21_decimal d1 = {
      {0x123b69a1, 0xd3b7c80c, 0x6b2e11, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x123b69a1, 0xd3b7c80c, 0x6b2e11, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_75) {
  //-75981288432676656344000000000 == -75981288432676656344000000000
  s21_decimal d1 = {
      {0xf4e27000, 0x5908a192, 0xf5823fab, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xf4e27000, 0x5908a192, 0xf5823fab, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_76) {
  // 9 > -4623818281137480266.8017909
  s21_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x7492d8f5, 0xe9acd976, 0x263f50, sign_and_exp_bits(1, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_77) {
  //-97.86530814803912665 < 5831513962.100019285406847533
  s21_decimal d1 = {{0xbfcd27d9, 0x87d0bdec, 0x0, sign_and_exp_bits(1, 17)}};
  s21_decimal d2 = {
      {0xe4c5122d, 0x5454d82e, 0x12d7b71d, sign_and_exp_bits(0, 18)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_78) {
  // 1386969769679.2180637861 == 1386969769679.2180637861
  s21_decimal d1 = {{0xb76f40a5, 0xe0b8ba6c, 0x2ef, sign_and_exp_bits(0, 10)}};
  s21_decimal d2 = {{0xb76f40a5, 0xe0b8ba6c, 0x2ef, sign_and_exp_bits(0, 10)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_79) {
  //-6444995.472398161886481440089 == -6444995.472398161886481440089
  s21_decimal d1 = {
      {0xe3135d59, 0xa4443efd, 0x14d32ce0, sign_and_exp_bits(1, 21)}};
  s21_decimal d2 = {
      {0xe3135d59, 0xa4443efd, 0x14d32ce0, sign_and_exp_bits(1, 21)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_80) {
  //-47.9 < 47.9
  s21_decimal d1 = {{0x1df, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x1df, 0x0, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_81) {
  //-75011777.725011439026333 < -170937.04
  s21_decimal d1 = {{0x69ee809d, 0x6588cb77, 0xfe2, sign_and_exp_bits(1, 15)}};
  s21_decimal d2 = {{0x104d448, 0x0, 0x0, sign_and_exp_bits(1, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_82) {
  // 2909131657.188 > -4907.6116325
  s21_decimal d1 = {{0x55c24fe4, 0x2a5, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x6d2a1b65, 0xb, 0x0, sign_and_exp_bits(1, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_83) {
  // 113322171.628270531 < 25470268320447700.56803578312
  s21_decimal d1 = {{0x291433c3, 0x19299ea, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {
      {0x9899f1c8, 0x3bed5c52, 0x83ad9e9, sign_and_exp_bits(0, 11)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_84) {
  // 6151.33 == 6151.33
  s21_decimal d1 = {{0x962dd, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0x962dd, 0x0, 0x0, sign_and_exp_bits(0, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_85) {
  // 6610787104365005787558999 == 6610787104365005787558999
  s21_decimal d1 = {{0x509ef457, 0x7cad50c5, 0x577e3, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x509ef457, 0x7cad50c5, 0x577e3, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_86) {
  // 89899476.69108325179767 < 31574635646346.896
  s21_decimal d1 = {{0x18a96177, 0x58960e45, 0x1e7, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {{0xbd9ce690, 0x702cf6, 0x0, sign_and_exp_bits(0, 3)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_87) {
  // 83209272461.796328205 == 83209272461.796328205
  s21_decimal d1 = {{0x4010430d, 0x82c2b871, 0x4, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x4010430d, 0x82c2b871, 0x4, sign_and_exp_bits(0, 9)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_88) {
  // 4236179554.1520 > 59448486.09741
  s21_decimal d1 = {{0x1fc67a10, 0x2687, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x2496f1cd, 0x568, 0x0, sign_and_exp_bits(0, 5)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_89) {
  //-1.79649344043284618 < 59.47022154
  s21_decimal d1 = {{0x67d4f88a, 0x27e3e20, 0x0, sign_and_exp_bits(1, 17)}};
  s21_decimal d2 = {{0x62785b4a, 0x1, 0x0, sign_and_exp_bits(0, 8)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_90) {
  //-200000 < 200000
  s21_decimal d1 = {{0x30d40, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x30d40, 0x0, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_91) {
  // 616625771.3 == 616625771.3
  s21_decimal d1 = {{0x6f89a031, 0x1, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x6f89a031, 0x1, 0x0, sign_and_exp_bits(0, 1)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_92) {
  //-67794615816176132.010000 < -9477233827911899.77491
  s21_decimal d1 = {{0x1951b010, 0x274af58b, 0xe5b, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x186e5993, 0x604dd365, 0x33, sign_and_exp_bits(1, 5)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_93) {
  // 22.3180449269365445579315964 > 9.3137
  s21_decimal d1 = {
      {0x70691afc, 0x65d01daa, 0xb89c4c, sign_and_exp_bits(0, 25)}};
  s21_decimal d2 = {{0x16bd1, 0x0, 0x0, sign_and_exp_bits(0, 4)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_94) {
  //-3388017339887.879393866843862 == -3388017339887.879393866843862
  s21_decimal d1 = {
      {0xf0de86d6, 0x428f483, 0xaf28094, sign_and_exp_bits(1, 15)}};
  s21_decimal d2 = {
      {0xf0de86d6, 0x428f483, 0xaf28094, sign_and_exp_bits(1, 15)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_95) {
  // 694 < 1197060.720000000000
  s21_decimal d1 = {{0x2b6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xee2c6000, 0x109cd061, 0x0, sign_and_exp_bits(0, 12)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_96) {
  // 2.55331931 < 2972890526.9067001167
  s21_decimal d1 = {{0xf380e5b, 0x0, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0xebfa2d4f, 0x9c9249d4, 0x1, sign_and_exp_bits(0, 10)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_97) {
  //-73692.284197810106 < -76
  s21_decimal d1 = {{0xf64c2fba, 0x105cebd, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal d2 = {{0x4c, 0x0, 0x0, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_98) {
  //-6 == -6
  s21_decimal d1 = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_99) {
  //-0.94 == -0.94
  s21_decimal d1 = {{0x5e, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x5e, 0x0, 0x0, sign_and_exp_bits(1, 2)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_101) {
  // 2.456782000 == 2.456782
  s21_decimal d1 = {{0x926f84b0, 0x0, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x257cce, 0x0, 0x0, sign_and_exp_bits(0, 6)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_102) {
  // 0.000 == 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_103) {
  // 0.0000100 < 0.0001000
  s21_decimal d1 = {{0x64, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0x3e8, 0x0, 0x0, sign_and_exp_bits(0, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_104) {
  // 0.0010000 > 0.0001000
  s21_decimal d1 = {{0x2710, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0x3e8, 0x0, 0x0, sign_and_exp_bits(0, 7)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_105) {
  // 79228162514264337593543950335 == 79228162514264337593543950335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_106) {
  // 79228162514264337593543950335 > -79228162514264337593543950335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_107) {
  // 79228162514264.337593543950335 > -79228162514264337593543950335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 15)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_108) {
  // 79228162514264.337593543950335 > 7922.8162514264337593543950335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 15)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 25)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_109) {
  // 0.0000000000000000000000000001 > 0.00000000000000000000000000001
  s21_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 29)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 0);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 1);
}
END_TEST

START_TEST(s21_comparison_110) {
  // 0.00000000000000000000000000001 == 0.0000000000000000000000000000001
  s21_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 29)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 31)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

START_TEST(s21_comparison_111) {
  // 0.00000000000000000000000000005 == 0.00000000000000000000000000001
  s21_decimal d1 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 29)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 29)}};

  ck_assert_int_eq(s21_is_less(d1, d2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_greater(d1, d2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_equal(d1, d2), 1);
  ck_assert_int_eq(s21_is_not_equal(d1, d2), 0);
}
END_TEST

Suite *comparison_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "S21_COMPARISON" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("tc");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_comparison_0);
  tcase_add_test(tc1_1, s21_comparison_1);
  tcase_add_test(tc1_1, s21_comparison_2);
  tcase_add_test(tc1_1, s21_comparison_3);
  tcase_add_test(tc1_1, s21_comparison_4);
  tcase_add_test(tc1_1, s21_comparison_5);
  tcase_add_test(tc1_1, s21_comparison_6);
  tcase_add_test(tc1_1, s21_comparison_7);
  tcase_add_test(tc1_1, s21_comparison_8);
  tcase_add_test(tc1_1, s21_comparison_9);
  tcase_add_test(tc1_1, s21_comparison_10);
  tcase_add_test(tc1_1, s21_comparison_11);
  tcase_add_test(tc1_1, s21_comparison_12);
  tcase_add_test(tc1_1, s21_comparison_13);
  tcase_add_test(tc1_1, s21_comparison_14);
  tcase_add_test(tc1_1, s21_comparison_15);
  tcase_add_test(tc1_1, s21_comparison_16);
  tcase_add_test(tc1_1, s21_comparison_17);
  tcase_add_test(tc1_1, s21_comparison_18);
  tcase_add_test(tc1_1, s21_comparison_19);
  tcase_add_test(tc1_1, s21_comparison_20);
  tcase_add_test(tc1_1, s21_comparison_21);
  tcase_add_test(tc1_1, s21_comparison_22);
  tcase_add_test(tc1_1, s21_comparison_23);
  tcase_add_test(tc1_1, s21_comparison_24);
  tcase_add_test(tc1_1, s21_comparison_25);
  tcase_add_test(tc1_1, s21_comparison_26);
  tcase_add_test(tc1_1, s21_comparison_27);
  tcase_add_test(tc1_1, s21_comparison_28);
  tcase_add_test(tc1_1, s21_comparison_29);
  tcase_add_test(tc1_1, s21_comparison_30);
  tcase_add_test(tc1_1, s21_comparison_31);
  tcase_add_test(tc1_1, s21_comparison_32);
  tcase_add_test(tc1_1, s21_comparison_33);
  tcase_add_test(tc1_1, s21_comparison_34);
  tcase_add_test(tc1_1, s21_comparison_35);
  tcase_add_test(tc1_1, s21_comparison_36);
  tcase_add_test(tc1_1, s21_comparison_37);
  tcase_add_test(tc1_1, s21_comparison_38);
  tcase_add_test(tc1_1, s21_comparison_39);
  tcase_add_test(tc1_1, s21_comparison_40);
  tcase_add_test(tc1_1, s21_comparison_41);
  tcase_add_test(tc1_1, s21_comparison_42);
  tcase_add_test(tc1_1, s21_comparison_43);
  tcase_add_test(tc1_1, s21_comparison_44);
  tcase_add_test(tc1_1, s21_comparison_45);
  tcase_add_test(tc1_1, s21_comparison_46);
  tcase_add_test(tc1_1, s21_comparison_47);
  tcase_add_test(tc1_1, s21_comparison_48);
  tcase_add_test(tc1_1, s21_comparison_49);
  tcase_add_test(tc1_1, s21_comparison_50);
  tcase_add_test(tc1_1, s21_comparison_51);
  tcase_add_test(tc1_1, s21_comparison_52);
  tcase_add_test(tc1_1, s21_comparison_53);
  tcase_add_test(tc1_1, s21_comparison_54);
  tcase_add_test(tc1_1, s21_comparison_55);
  tcase_add_test(tc1_1, s21_comparison_56);
  tcase_add_test(tc1_1, s21_comparison_57);
  tcase_add_test(tc1_1, s21_comparison_58);
  tcase_add_test(tc1_1, s21_comparison_59);
  tcase_add_test(tc1_1, s21_comparison_60);
  tcase_add_test(tc1_1, s21_comparison_61);
  tcase_add_test(tc1_1, s21_comparison_62);
  tcase_add_test(tc1_1, s21_comparison_63);
  tcase_add_test(tc1_1, s21_comparison_64);
  tcase_add_test(tc1_1, s21_comparison_65);
  tcase_add_test(tc1_1, s21_comparison_66);
  tcase_add_test(tc1_1, s21_comparison_67);
  tcase_add_test(tc1_1, s21_comparison_68);
  tcase_add_test(tc1_1, s21_comparison_69);
  tcase_add_test(tc1_1, s21_comparison_70);
  tcase_add_test(tc1_1, s21_comparison_71);
  tcase_add_test(tc1_1, s21_comparison_72);
  tcase_add_test(tc1_1, s21_comparison_73);
  tcase_add_test(tc1_1, s21_comparison_74);
  tcase_add_test(tc1_1, s21_comparison_75);
  tcase_add_test(tc1_1, s21_comparison_76);
  tcase_add_test(tc1_1, s21_comparison_77);
  tcase_add_test(tc1_1, s21_comparison_78);
  tcase_add_test(tc1_1, s21_comparison_79);
  tcase_add_test(tc1_1, s21_comparison_80);
  tcase_add_test(tc1_1, s21_comparison_81);
  tcase_add_test(tc1_1, s21_comparison_82);
  tcase_add_test(tc1_1, s21_comparison_83);
  tcase_add_test(tc1_1, s21_comparison_84);
  tcase_add_test(tc1_1, s21_comparison_85);
  tcase_add_test(tc1_1, s21_comparison_86);
  tcase_add_test(tc1_1, s21_comparison_87);
  tcase_add_test(tc1_1, s21_comparison_88);
  tcase_add_test(tc1_1, s21_comparison_89);
  tcase_add_test(tc1_1, s21_comparison_90);
  tcase_add_test(tc1_1, s21_comparison_91);
  tcase_add_test(tc1_1, s21_comparison_92);
  tcase_add_test(tc1_1, s21_comparison_93);
  tcase_add_test(tc1_1, s21_comparison_94);
  tcase_add_test(tc1_1, s21_comparison_95);
  tcase_add_test(tc1_1, s21_comparison_96);
  tcase_add_test(tc1_1, s21_comparison_97);
  tcase_add_test(tc1_1, s21_comparison_98);
  tcase_add_test(tc1_1, s21_comparison_99);
  tcase_add_test(tc1_1, s21_comparison_101);
  tcase_add_test(tc1_1, s21_comparison_102);
  tcase_add_test(tc1_1, s21_comparison_103);
  tcase_add_test(tc1_1, s21_comparison_104);
  tcase_add_test(tc1_1, s21_comparison_105);
  tcase_add_test(tc1_1, s21_comparison_106);
  tcase_add_test(tc1_1, s21_comparison_107);
  tcase_add_test(tc1_1, s21_comparison_108);
  tcase_add_test(tc1_1, s21_comparison_109);
  tcase_add_test(tc1_1, s21_comparison_110);
  tcase_add_test(tc1_1, s21_comparison_111);

  return s1;
}
