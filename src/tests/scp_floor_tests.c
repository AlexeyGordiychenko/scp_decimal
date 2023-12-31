#include "scp_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *              FLOOR FUNCTION TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(scp_floor_0) {
  // 18442464887646.57 -> 18442464887646
  scp_decimal d1 = {{0x18d750f1, 0x68d55, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0xf891835e, 0x10c5, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_1) {
  //-5.897906420561987 -> -6
  scp_decimal d1 = {{0x591db843, 0x14f41d, 0x0, sign_and_exp_bits(1, 15)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_2) {
  //-452.5136691688 -> -453
  scp_decimal d1 = {{0x972a41e8, 0x41d, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x1c5, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_3) {
  //-2928.8 -> -2929
  scp_decimal d1 = {{0x7268, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0xb71, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_4) {
  // 8.70245119282081253291707 -> 8
  scp_decimal d1 = {{0x879ff6bb, 0x151b2ecd, 0xb848, sign_and_exp_bits(0, 23)}};
  scp_decimal correct = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_5) {
  // 5 -> 5
  scp_decimal d1 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_6) {
  // 74761373411873832956956126.9 -> 74761373411873832956956126
  scp_decimal d1 = {
      {0x840f8ab5, 0xbc4ec32e, 0x26a695d, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0xda018dde, 0x2c6e46b7, 0x3dd756, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_7) {
  //-756581913443626651770555.200 -> -756581913443626651770556
  scp_decimal d1 = {
      {0x90720b40, 0xb6003aa0, 0x271d473, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {
      {0xdf605ebc, 0x63410633, 0xa036, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_8) {
  //-91 -> -91
  scp_decimal d1 = {{0x5b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x5b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_9) {
  // 60650140836164.62720974042 -> 60650140836164
  scp_decimal d1 = {
      {0x49f3bcda, 0x1280fb5d, 0x50451, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0x3619a144, 0x3729, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_10) {
  //-94502.878100 -> -94503
  scp_decimal d1 = {{0xcf7b94, 0x16, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal correct = {{0x17127, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_11) {
  //-22200404368.608186095 -> -22200404369
  scp_decimal d1 = {{0x84ebceef, 0x3417ae26, 0x1, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0x2b3f4991, 0x5, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_12) {
  //-2198.3 -> -2199
  scp_decimal d1 = {{0x55df, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x897, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_13) {
  // 6058.100619 -> 6058
  scp_decimal d1 = {{0x6917478b, 0x1, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {{0x17aa, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_14) {
  // 1610479939246570442981075.5 -> 1610479939246570442981075
  scp_decimal d1 = {{0x852bf443, 0xeca7f36e, 0xd5252, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0xda1dfed3, 0x4add9857, 0x15508, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_15) {
  //-30362 -> -30362
  scp_decimal d1 = {{0x769a, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x769a, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_16) {
  //-9672.55572515 -> -9673
  scp_decimal d1 = {{0x34ecc023, 0xe1, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {{0x25c9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_17) {
  //-9636615152675.6 -> -9636615152676
  scp_decimal d1 = {{0xfe3ae964, 0x57a4, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0xb305e424, 0x8c3, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_18) {
  // 4927348.6 -> 4927348
  scp_decimal d1 = {{0x2efda8e, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x4b2f74, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_19) {
  // 888458642689.808033106664 -> 888458642689
  scp_decimal d1 = {{0x607bcae8, 0x7084eebf, 0xbc23, sign_and_exp_bits(0, 12)}};
  scp_decimal correct = {{0xdc430501, 0xce, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_20) {
  //-39725.25859688735613 -> -39726
  scp_decimal d1 = {{0xd7cce37d, 0x37213f38, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {{0x9b2e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_21) {
  // 51244488568850339702715.93000 -> 51244488568850339702715
  scp_decimal d1 = {
      {0xc6912228, 0x2bd90cfc, 0x108ed841, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {
      {0xca01a7bb, 0xf823806e, 0xad9, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_22) {
  // 388612 -> 388612
  scp_decimal d1 = {{0x5ee04, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x5ee04, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_23) {
  // 8.53 -> 8
  scp_decimal d1 = {{0x355, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_24) {
  //-58666895589342696235.271 -> -58666895589342696236
  scp_decimal d1 = {{0x670e107, 0x56ba73f9, 0xc6c, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {
      {0x3db3d32c, 0x2e2aaeb5, 0x3, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_25) {
  //-8577992 -> -8577992
  scp_decimal d1 = {{0x82e3c8, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x82e3c8, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_26) {
  // 705582 -> 705582
  scp_decimal d1 = {{0xac42e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0xac42e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_27) {
  //-854.58913 -> -855
  scp_decimal d1 = {{0x517ffe1, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {{0x357, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_28) {
  //-187.23159309862397194800 -> -188
  scp_decimal d1 = {{0x3412b230, 0xfc0830c5, 0x3f6, sign_and_exp_bits(1, 20)}};
  scp_decimal correct = {{0xbc, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_29) {
  //-910609973098957649.93 -> -910609973098957650
  scp_decimal d1 = {{0x6d236c01, 0xefb9a697, 0x4, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x277dcb52, 0xca322f2, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_30) {
  //-344159.3 -> -344160
  scp_decimal d1 = {{0x3483b9, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x54060, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_31) {
  //-6.06078964830 -> -7
  scp_decimal d1 = {{0x1d1f145e, 0x8d, 0x0, sign_and_exp_bits(1, 11)}};
  scp_decimal correct = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_32) {
  // 85804019161838964414206105 -> 85804019161838964414206105
  scp_decimal d1 = {
      {0x50a5d099, 0x32fc5359, 0x46f9b5, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x50a5d099, 0x32fc5359, 0x46f9b5, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_33) {
  //-6257.842380 -> -6258
  scp_decimal d1 = {{0x74ff18cc, 0x1, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal correct = {{0x1872, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_34) {
  //-738117313189.3352718903 -> -738117313190
  scp_decimal d1 = {{0x60c86237, 0x225ac053, 0x190, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0xdb3862a6, 0xab, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_35) {
  // 2691888576417875 -> 2691888576417875
  scp_decimal d1 = {{0x265f5053, 0x99042, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x265f5053, 0x99042, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_36) {
  //-69 -> -69
  scp_decimal d1 = {{0x45, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x45, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_37) {
  // 3702861823.77795921675747003 -> 3702861823
  scp_decimal d1 = {
      {0x6eafebb, 0x2b34699e, 0x1324b26, sign_and_exp_bits(0, 17)}};
  scp_decimal correct = {{0xdcb52fff, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_38) {
  // 48.5719692836609 -> 48
  scp_decimal d1 = {{0x6dc07f01, 0x1b9c2, 0x0, sign_and_exp_bits(0, 13)}};
  scp_decimal correct = {{0x30, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_39) {
  //-574745.05565 -> -574746
  scp_decimal d1 = {{0x61bf5b5d, 0xd, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {{0x8c51a, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_40) {
  //-1359.1488 -> -1360
  scp_decimal d1 = {{0xcf63c0, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x550, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_41) {
  // 9 -> 9
  scp_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_42) {
  // 55064393.68531738613 -> 55064393
  scp_decimal d1 = {{0x6a8f7ff5, 0x4c6acd6e, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0x3483749, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_43) {
  // 28350457461.88139755201219 -> 28350457461
  scp_decimal d1 = {
      {0xb02be2c3, 0x234a81fd, 0x25858, sign_and_exp_bits(0, 14)}};
  scp_decimal correct = {{0x99d1a675, 0x6, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_44) {
  //-70554857906307429 -> -70554857906307429
  scp_decimal d1 = {{0xfaaf0165, 0xfaa944, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0xfaaf0165, 0xfaa944, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_45) {
  // 324750481049877831.0388 -> 324750481049877831
  scp_decimal d1 = {{0x77eda6f4, 0xc2ec321, 0xb0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x879d7d47, 0x481bed7, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_46) {
  //-3.8 -> -4
  scp_decimal d1 = {{0x26, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_47) {
  //-1677.3778 -> -1678
  scp_decimal d1 = {{0xfff292, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x68e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_48) {
  // 90710303293369343.30252996 -> 90710303293369343
  scp_decimal d1 = {{0x6b43bec4, 0x8a1bd97b, 0x780dd, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0x4d44ebff, 0x142448a, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_49) {
  //-3195983936106739057.02 -> -3195983936106739058
  scp_decimal d1 = {{0x1db0e026, 0x535195af, 0x11, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {
      {0xf37f3572, 0x2c5a6a74, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_50) {
  //-9816.772747093473075361 -> -9817
  scp_decimal d1 = {{0x8a0da0a1, 0x2b16d1fd, 0x214, sign_and_exp_bits(1, 18)}};
  scp_decimal correct = {{0x2659, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_51) {
  // 120920.328996492159660 -> 120920
  scp_decimal d1 = {{0x17482aac, 0x8e1b4e8f, 0x6, sign_and_exp_bits(0, 15)}};
  scp_decimal correct = {{0x1d858, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_52) {
  //-978892.221546251 -> -978893
  scp_decimal d1 = {{0x1b237f0b, 0x37a4c, 0x0, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0xeefcd, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_53) {
  // 9111560383899131.8 -> 9111560383899131
  scp_decimal d1 = {{0xb0517bd6, 0x143b528, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x780825fb, 0x205eea, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_54) {
  //-8.54200000000000 -> -9
  scp_decimal d1 = {{0xef913000, 0x308e3, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {{0x9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_55) {
  //-54343937180.28704788 -> -54343937181
  scp_decimal d1 = {{0x3cb71c14, 0x4b6ad84b, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {{0xa726ac9d, 0xc, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_56) {
  //-4262663597103693384.08767627 -> -4262663597103693385
  scp_decimal d1 = {
      {0x44ab108b, 0xa9ab861d, 0x1609969, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {
      {0xfe5abe49, 0x3b2805f4, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_57) {
  // 8817419.9837302887519 -> 8817419
  scp_decimal d1 = {{0xc8be945f, 0xc7a9af95, 0x4, sign_and_exp_bits(0, 13)}};
  scp_decimal correct = {{0x868b0b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_58) {
  // 981.98788 -> 981
  scp_decimal d1 = {{0x5da6504, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {{0x3d5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_59) {
  // 51.4 -> 51
  scp_decimal d1 = {{0x202, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x33, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_60) {
  //-613890544.75 -> -613890545
  scp_decimal d1 = {{0x4b12a20b, 0xe, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x249739f1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_61) {
  //-646.4641 -> -647
  scp_decimal d1 = {{0x62a481, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x287, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_62) {
  // 332749082961.7748023404895995 -> 332749082961
  scp_decimal d1 = {
      {0x73d39efb, 0x51e2334e, 0xac06f97, sign_and_exp_bits(0, 16)}};
  scp_decimal correct = {{0x79641151, 0x4d, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_63) {
  //-98.848891445 -> -99
  scp_decimal d1 = {{0x3da6235, 0x17, 0x0, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0x63, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_64) {
  //-753195390381.4211225888787 -> -753195390382
  scp_decimal d1 = {{0xdb35a813, 0xa0e2cf2, 0x63af4, sign_and_exp_bits(1, 13)}};
  scp_decimal correct = {{0x5df195ae, 0xaf, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_65) {
  //-42 -> -42
  scp_decimal d1 = {{0x2a, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x2a, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_66) {
  // 22051405269676325050 -> 22051405269676325050
  scp_decimal d1 = {{0x693bf8ba, 0x32065442, 0x1, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x693bf8ba, 0x32065442, 0x1, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_67) {
  //-13291575528080.935100390 -> -13291575528081
  scp_decimal d1 = {{0x1b321fe6, 0x89aa3101, 0x2d0, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0xafa34a91, 0xc16, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_68) {
  //-6036973183863560863316.655 -> -6036973183863560863317
  scp_decimal d1 = {{0x83f97aaf, 0xf8d8dd27, 0x4fe60, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {
      {0x1a7ffe55, 0x43d53578, 0x147, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_69) {
  // 431392.573157513686 -> 431392
  scp_decimal d1 = {{0x79cb99d6, 0x5fc9d42, 0x0, sign_and_exp_bits(0, 12)}};
  scp_decimal correct = {{0x69520, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_70) {
  // 945.8062637911785 -> 945
  scp_decimal d1 = {{0xcfcbcee9, 0x219a0e, 0x0, sign_and_exp_bits(0, 13)}};
  scp_decimal correct = {{0x3b1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_71) {
  //-334914.3 -> -334915
  scp_decimal d1 = {{0x331a97, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x51c43, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_72) {
  //-99391358.56119 -> -99391359
  scp_decimal d1 = {{0x22a97df7, 0x90a, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {{0x5ec977f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_73) {
  //-682414.19 -> -682415
  scp_decimal d1 = {{0x411480b, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0xa69af, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_74) {
  // 408771530.766 -> 408771530
  scp_decimal d1 = {{0x2cae900e, 0x5f, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x185d5bca, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_75) {
  //-5793.50000000 -> -5794
  scp_decimal d1 = {{0xe3f37180, 0x86, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {{0x16a2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_76) {
  //-5.5358393635955934 -> -6
  scp_decimal d1 = {{0x6c01e4de, 0xc4ac2a, 0x0, sign_and_exp_bits(1, 16)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_77) {
  //-1.0702272292 -> -2
  scp_decimal d1 = {{0x7de7b724, 0x2, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_78) {
  // 29829891874910546089.38809 -> 29829891874910546089
  scp_decimal d1 = {{0xd59b7739, 0x2afa1d0b, 0x277ac, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {
      {0x5c5aa8a9, 0x9df9109d, 0x1, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_79) {
  //-86912620670735379.5968093 -> -86912620670735380
  scp_decimal d1 = {{0x53d03c5d, 0x6d132c57, 0xb80b, sign_and_exp_bits(1, 7)}};
  scp_decimal correct = {{0x6993d414, 0x134c691, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_80) {
  //-8.870617803643764899000 -> -9
  scp_decimal d1 = {{0xda647cb8, 0xe08d35dd, 0x1e0, sign_and_exp_bits(1, 21)}};
  scp_decimal correct = {{0x9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_81) {
  //-8565723301482.6166447403 -> -8565723301483
  scp_decimal d1 = {{0x77d0ed2b, 0x7ce76b83, 0x1223, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x5ce5066b, 0x7ca, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_82) {
  // 9178550057.110000 -> 9178550057
  scp_decimal d1 = {{0xb7b509f0, 0x209bd7, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {{0x23158f29, 0x2, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_83) {
  // 8476079787.064757767820747 -> 8476079787
  scp_decimal d1 = {
      {0xc756d5cb, 0x34ba1c01, 0x702e1, sign_and_exp_bits(0, 15)}};
  scp_decimal correct = {{0xf936b6ab, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_84) {
  // 310450129725831606229 -> 310450129725831606229
  scp_decimal d1 = {{0x7e216fd5, 0xd45c6c26, 0x10, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x7e216fd5, 0xd45c6c26, 0x10, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_85) {
  // 28969446521596454.8 -> 28969446521596454
  scp_decimal d1 = {{0xcc982584, 0x4053394, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0xe1426a26, 0x66eb8e, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_86) {
  // 15606064.240 -> 15606064
  scp_decimal d1 = {{0xa231a470, 0x3, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0xee2130, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_87) {
  // 9814565800.14492 -> 9814565800
  scp_decimal d1 = {{0x2ad0719c, 0x37ca1, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {{0x48fe63a8, 0x2, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_88) {
  // 89.49342900002394906317327900 -> 89
  scp_decimal d1 = {
      {0x8ea08e1c, 0xb99aa6e4, 0x1ceab912, sign_and_exp_bits(0, 26)}};
  scp_decimal correct = {{0x59, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_89) {
  //-28198415768.09 -> -28198415769
  scp_decimal d1 = {{0x8ba7cf69, 0x290, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x90c1ad99, 0x6, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_90) {
  // 294.87641664534 -> 294
  scp_decimal d1 = {{0xa0681c16, 0x1ad1, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0x126, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_91) {
  // 4083 -> 4083
  scp_decimal d1 = {{0xff3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0xff3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_92) {
  //-2678271034765664.555447934722 -> -2678271034765665
  scp_decimal d1 = {
      {0x613cdf02, 0xb84b2600, 0x8a769f3, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0x91a3b161, 0x983df, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_93) {
  //-55647929812161.84 -> -55647929812162
  scp_decimal d1 = {{0x54e4dbb8, 0x13c526, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x8b16c4c2, 0x329c, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_94) {
  // 452052632.813 -> 452052632
  scp_decimal d1 = {{0x406fc4ed, 0x69, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x1af1c698, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_95) {
  // 59970.01938 -> 59970
  scp_decimal d1 = {{0x6572fcd2, 0x1, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {{0xea42, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_96) {
  // 1469832631007578128.7520 -> 1469832631007578128
  scp_decimal d1 = {{0x8cfb0e60, 0xcc40eff1, 0x31c, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {
      {0x8a7c0810, 0x1465e4fd, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_97) {
  // 10.1 -> 10
  scp_decimal d1 = {{0x65, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0xa, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_98) {
  // 6647.903 -> 6647
  scp_decimal d1 = {{0x65705f, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x19f7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_99) {
  //-877.703127281776 -> -878
  scp_decimal d1 = {{0x2f1eb070, 0x31e44, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0x36e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_100) {
  // 5.5 -> 5
  scp_decimal d1 = {{0x37, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_101) {
  //-5.5 -> -6
  scp_decimal d1 = {{0x37, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_102) {
  // 79228162514264337593543950335 -> 79228162514264337593543950335
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_103) {
  //-79228162514264337593543950335 -> -79228162514264337593543950335
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_104) {
  // 7922816251426433759354395033.5 -> 7922816251426433759354395033
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0x99999999, 0x99999999, 0x19999999, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_floor_105) {
  // -0,0 => 0
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;
  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

START_TEST(scp_floor_106) {
  // 0,0 => 0
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;
  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

START_TEST(scp_floor_107) {
  // -0,0 / 10^5 => 0 / 10^0
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;
  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

START_TEST(scp_floor_108) {
  // 0,0 / 10^5  => 0 / 10^0
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;
  ck_assert_int_eq(scp_floor(d1, &result), SCP_OK);
  ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

START_TEST(scp_floor_109) {
  // Segmentation fault test
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  // scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  // scp_decimal result;
  ck_assert_int_eq(scp_floor(d1, NULL), SCP_ERROR);
  // ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

Suite *floor_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "SCP_FLOOR" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("SCP_FLOOR");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, scp_floor_0);
  tcase_add_test(tc1_1, scp_floor_1);
  tcase_add_test(tc1_1, scp_floor_2);
  tcase_add_test(tc1_1, scp_floor_3);
  tcase_add_test(tc1_1, scp_floor_4);
  tcase_add_test(tc1_1, scp_floor_5);
  tcase_add_test(tc1_1, scp_floor_6);
  tcase_add_test(tc1_1, scp_floor_7);
  tcase_add_test(tc1_1, scp_floor_8);
  tcase_add_test(tc1_1, scp_floor_9);
  tcase_add_test(tc1_1, scp_floor_10);
  tcase_add_test(tc1_1, scp_floor_11);
  tcase_add_test(tc1_1, scp_floor_12);
  tcase_add_test(tc1_1, scp_floor_13);
  tcase_add_test(tc1_1, scp_floor_14);
  tcase_add_test(tc1_1, scp_floor_15);
  tcase_add_test(tc1_1, scp_floor_16);
  tcase_add_test(tc1_1, scp_floor_17);
  tcase_add_test(tc1_1, scp_floor_18);
  tcase_add_test(tc1_1, scp_floor_19);
  tcase_add_test(tc1_1, scp_floor_20);
  tcase_add_test(tc1_1, scp_floor_21);
  tcase_add_test(tc1_1, scp_floor_22);
  tcase_add_test(tc1_1, scp_floor_23);
  tcase_add_test(tc1_1, scp_floor_24);
  tcase_add_test(tc1_1, scp_floor_25);
  tcase_add_test(tc1_1, scp_floor_26);
  tcase_add_test(tc1_1, scp_floor_27);
  tcase_add_test(tc1_1, scp_floor_28);
  tcase_add_test(tc1_1, scp_floor_29);
  tcase_add_test(tc1_1, scp_floor_30);
  tcase_add_test(tc1_1, scp_floor_31);
  tcase_add_test(tc1_1, scp_floor_32);
  tcase_add_test(tc1_1, scp_floor_33);
  tcase_add_test(tc1_1, scp_floor_34);
  tcase_add_test(tc1_1, scp_floor_35);
  tcase_add_test(tc1_1, scp_floor_36);
  tcase_add_test(tc1_1, scp_floor_37);
  tcase_add_test(tc1_1, scp_floor_38);
  tcase_add_test(tc1_1, scp_floor_39);
  tcase_add_test(tc1_1, scp_floor_40);
  tcase_add_test(tc1_1, scp_floor_41);
  tcase_add_test(tc1_1, scp_floor_42);
  tcase_add_test(tc1_1, scp_floor_43);
  tcase_add_test(tc1_1, scp_floor_44);
  tcase_add_test(tc1_1, scp_floor_45);
  tcase_add_test(tc1_1, scp_floor_46);
  tcase_add_test(tc1_1, scp_floor_47);
  tcase_add_test(tc1_1, scp_floor_48);
  tcase_add_test(tc1_1, scp_floor_49);
  tcase_add_test(tc1_1, scp_floor_50);
  tcase_add_test(tc1_1, scp_floor_51);
  tcase_add_test(tc1_1, scp_floor_52);
  tcase_add_test(tc1_1, scp_floor_53);
  tcase_add_test(tc1_1, scp_floor_54);
  tcase_add_test(tc1_1, scp_floor_55);
  tcase_add_test(tc1_1, scp_floor_56);
  tcase_add_test(tc1_1, scp_floor_57);
  tcase_add_test(tc1_1, scp_floor_58);
  tcase_add_test(tc1_1, scp_floor_59);
  tcase_add_test(tc1_1, scp_floor_60);
  tcase_add_test(tc1_1, scp_floor_61);
  tcase_add_test(tc1_1, scp_floor_62);
  tcase_add_test(tc1_1, scp_floor_63);
  tcase_add_test(tc1_1, scp_floor_64);
  tcase_add_test(tc1_1, scp_floor_65);
  tcase_add_test(tc1_1, scp_floor_66);
  tcase_add_test(tc1_1, scp_floor_67);
  tcase_add_test(tc1_1, scp_floor_68);
  tcase_add_test(tc1_1, scp_floor_69);
  tcase_add_test(tc1_1, scp_floor_70);
  tcase_add_test(tc1_1, scp_floor_71);
  tcase_add_test(tc1_1, scp_floor_72);
  tcase_add_test(tc1_1, scp_floor_73);
  tcase_add_test(tc1_1, scp_floor_74);
  tcase_add_test(tc1_1, scp_floor_75);
  tcase_add_test(tc1_1, scp_floor_76);
  tcase_add_test(tc1_1, scp_floor_77);
  tcase_add_test(tc1_1, scp_floor_78);
  tcase_add_test(tc1_1, scp_floor_79);
  tcase_add_test(tc1_1, scp_floor_80);
  tcase_add_test(tc1_1, scp_floor_81);
  tcase_add_test(tc1_1, scp_floor_82);
  tcase_add_test(tc1_1, scp_floor_83);
  tcase_add_test(tc1_1, scp_floor_84);
  tcase_add_test(tc1_1, scp_floor_85);
  tcase_add_test(tc1_1, scp_floor_86);
  tcase_add_test(tc1_1, scp_floor_87);
  tcase_add_test(tc1_1, scp_floor_88);
  tcase_add_test(tc1_1, scp_floor_89);
  tcase_add_test(tc1_1, scp_floor_90);
  tcase_add_test(tc1_1, scp_floor_91);
  tcase_add_test(tc1_1, scp_floor_92);
  tcase_add_test(tc1_1, scp_floor_93);
  tcase_add_test(tc1_1, scp_floor_94);
  tcase_add_test(tc1_1, scp_floor_95);
  tcase_add_test(tc1_1, scp_floor_96);
  tcase_add_test(tc1_1, scp_floor_97);
  tcase_add_test(tc1_1, scp_floor_98);
  tcase_add_test(tc1_1, scp_floor_99);
  tcase_add_test(tc1_1, scp_floor_100);
  tcase_add_test(tc1_1, scp_floor_101);
  tcase_add_test(tc1_1, scp_floor_102);
  tcase_add_test(tc1_1, scp_floor_103);
  tcase_add_test(tc1_1, scp_floor_104);
  tcase_add_test(tc1_1, scp_floor_105);
  tcase_add_test(tc1_1, scp_floor_106);
  tcase_add_test(tc1_1, scp_floor_107);
  tcase_add_test(tc1_1, scp_floor_108);
  tcase_add_test(tc1_1, scp_floor_109);

  return s1;
}
