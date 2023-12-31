#include "scp_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *             ROUND FUNCTION TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(scp_round_0) {
  //-876784151.0582042566254 -> -876784151
  scp_decimal d1 = {{0xeefd1e6e, 0x4e3e77db, 0x1db, sign_and_exp_bits(1, 13)}};
  scp_decimal correct = {{0x3442aa17, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_1) {
  //-67.1069999961259673328334445 -> -67
  scp_decimal d1 = {
      {0xad00b66d, 0x97a704d4, 0x22b1899, sign_and_exp_bits(1, 25)}};
  scp_decimal correct = {{0x43, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_2) {
  // 8225490026255436479 -> 8225490026255436479
  scp_decimal d1 = {{0x2e794abf, 0x7226cf99, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x2e794abf, 0x7226cf99, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_3) {
  //-83807.08061442236707 -> -83807
  scp_decimal d1 = {{0x38846123, 0x744e4194, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {{0x1475f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_4) {
  //-1323413.2882654000 -> -1323413
  scp_decimal d1 = {{0xad618330, 0x2f045f, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x143195, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_5) {
  // 967673.291694543 -> 967673
  scp_decimal d1 = {{0xfecf61cf, 0x37017, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal correct = {{0xec3f9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_6) {
  //-4 -> -4
  scp_decimal d1 = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_7) {
  //-6.1217499629 -> -6
  scp_decimal d1 = {{0x40d8e9ed, 0xe, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_8) {
  //-161195.09833500339604 -> -161195
  scp_decimal d1 = {{0xeb342d94, 0xdfb400c9, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {{0x275ab, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_9) {
  //-84577385272.6132149966709 -> -84577385273
  scp_decimal d1 = {{0x7c91d775, 0x7e0fc07e, 0xb319, sign_and_exp_bits(1, 13)}};
  scp_decimal correct = {{0xb1347b39, 0x13, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_10) {
  // 64.01933569744738209321172720 -> 64
  scp_decimal d1 = {
      {0xaca3bef0, 0x38a4408e, 0x14af8e2a, sign_and_exp_bits(0, 26)}};
  scp_decimal correct = {{0x40, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_11) {
  // 14.95201730787605010 -> 15
  scp_decimal d1 = {{0x5f24fa12, 0x14c0060d, 0x0, sign_and_exp_bits(0, 17)}};
  scp_decimal correct = {{0xf, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_12) {
  //-5138389775 -> -5138389775
  scp_decimal d1 = {{0x32459b0f, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x32459b0f, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_13) {
  //-59265.89 -> -59266
  scp_decimal d1 = {{0x5a6ebd, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0xe782, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_14) {
  //-179.129968095869 -> -179
  scp_decimal d1 = {{0xf21df27d, 0xa2ea, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0xb3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_15) {
  // 588977 -> 588977
  scp_decimal d1 = {{0x8fcb1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x8fcb1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_16) {
  //-4 -> -4
  scp_decimal d1 = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_17) {
  //-81361803522796 -> -81361803522796
  scp_decimal d1 = {{0x8565b2ec, 0x49ff, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x8565b2ec, 0x49ff, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_18) {
  // 6165.401 -> 6165
  scp_decimal d1 = {{0x5e1399, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x1815, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_19) {
  // 9673330063.706198 -> 9673330064
  scp_decimal d1 = {{0xaa3e0856, 0x225dd7, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {{0x40934d90, 0x2, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_20) {
  // 786483 -> 786483
  scp_decimal d1 = {{0xc0033, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0xc0033, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_21) {
  //-22.948865171000 -> -23
  scp_decimal d1 = {{0x32f4de38, 0x14df, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0x17, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_22) {
  // 25.478495103902529071 -> 25
  scp_decimal d1 = {{0x5fa3b62f, 0x6195cc4e, 0x1, sign_and_exp_bits(0, 18)}};
  scp_decimal correct = {{0x19, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_23) {
  // 760242204260 -> 760242204260
  scp_decimal d1 = {{0x1f76e64, 0xb1, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x1f76e64, 0xb1, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_24) {
  // 6.68 -> 7
  scp_decimal d1 = {{0x29c, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_25) {
  //-5793295701.76425999019900 -> -5793295702
  scp_decimal d1 = {{0xe65d2f7c, 0x84d87fd8, 0x7aad, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {{0x594ead56, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_26) {
  //-37786959.11019228473823 -> -37786959
  scp_decimal d1 = {{0xda2ca9df, 0xd7f0a6ae, 0xcc, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {{0x240954f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_27) {
  // 6340995905474.343305081209 -> 6340995905474
  scp_decimal d1 = {
      {0x3619f179, 0x13aa98bf, 0x53ec2, sign_and_exp_bits(0, 12)}};
  scp_decimal correct = {{0x60cef7c2, 0x5c4, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_28) {
  // 2.1112 -> 2
  scp_decimal d1 = {{0x5278, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_29) {
  // 6.4575 -> 6
  scp_decimal d1 = {{0xfc3f, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_30) {
  // 633331.434668173432979 -> 633331
  scp_decimal d1 = {{0x4fe1893, 0x553d404c, 0x22, sign_and_exp_bits(0, 15)}};
  scp_decimal correct = {{0x9a9f3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_31) {
  // 676888.3 -> 676888
  scp_decimal d1 = {{0x6748f3, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0xa5418, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_32) {
  //-69.11502 -> -69
  scp_decimal d1 = {{0x69760e, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {{0x45, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_33) {
  // 5400852.2596238 -> 5400852
  scp_decimal d1 = {{0xd6cddf8e, 0x311e, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {{0x526914, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_34) {
  // 17.62959646 -> 18
  scp_decimal d1 = {{0x6914a11e, 0x0, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0x12, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_35) {
  // 3257191014.33975078923 -> 3257191014
  scp_decimal d1 = {{0x3b83000b, 0xa842b505, 0x11, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0xc224ca66, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_36) {
  //-616238743286706.4905359464891 -> -616238743286706
  scp_decimal d1 = {
      {0x57c899bb, 0x1edf2007, 0x13e9684c, sign_and_exp_bits(1, 13)}};
  scp_decimal correct = {{0x4363f3b2, 0x23077, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_37) {
  //-9.900501908230754766958795560 -> -10
  scp_decimal d1 = {
      {0x7c9e9b28, 0xe149dd3d, 0x1ffd80d3, sign_and_exp_bits(1, 27)}};
  scp_decimal correct = {{0xa, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_38) {
  //-6747098262.91913102 -> -6747098263
  scp_decimal d1 = {{0x2298518e, 0x95d0d03, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {{0x92288c97, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_39) {
  //-5975901304204780.9583 -> -5975901304204781
  scp_decimal d1 = {{0xb331f82f, 0x3d52a9be, 0x3, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0xf2732ded, 0x153b0c, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_40) {
  //-59810.824 -> -59811
  scp_decimal d1 = {{0x390a408, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0xe9a3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_41) {
  // 7956127503637037.865 -> 7956127503637038
  scp_decimal d1 = {{0xaa004329, 0x6e69d7cf, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x49a45a2e, 0x1c440e, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_42) {
  // 223075.915 -> 223076
  scp_decimal d1 = {{0xd4bde4b, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x36764, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_43) {
  //-478697232741694.1 -> -478697232741694
  scp_decimal d1 = {{0xd920146d, 0x1101b9, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x6283353e, 0x1b35f, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_44) {
  // 8035831230652.80 -> 8035831230653
  scp_decimal d1 = {{0xc69909c0, 0x2dada, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0xfcddb0bd, 0x74e, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_45) {
  // 9511.7318372 -> 9512
  scp_decimal d1 = {{0x256f18e4, 0x16, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {{0x2528, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_46) {
  // 527600848.99932227623388 -> 527600849
  scp_decimal d1 = {{0x741d9dc, 0x21435194, 0xb2c, sign_and_exp_bits(0, 14)}};
  scp_decimal correct = {{0x1f728cd1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_47) {
  //-231281 -> -231281
  scp_decimal d1 = {{0x38771, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x38771, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_48) {
  // 19584.40925600 -> 19584
  scp_decimal d1 = {{0xfc2cf9a0, 0x1c7, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0x4c80, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_49) {
  // 86.7269 -> 87
  scp_decimal d1 = {{0xd3bc5, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x57, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_50) {
  //-593120670254.164556080677 -> -593120670254
  scp_decimal d1 = {{0xb3176625, 0x22ce642b, 0x7d99, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0x18bf322e, 0x8a, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_51) {
  //-0.36286131 -> 0
  scp_decimal d1 = {{0x229aeb3, 0x0, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_52) {
  //-93416404.423 -> -93416404
  scp_decimal d1 = {{0xc00d35c7, 0x15, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0x5916bd4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_53) {
  //-34.73 -> -35
  scp_decimal d1 = {{0xd91, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x23, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_54) {
  //-322.261 -> -322
  scp_decimal d1 = {{0x4ead5, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0x142, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_55) {
  // 823380055.4946 -> 823380055
  scp_decimal d1 = {{0x14c1d9c2, 0x77d, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x3113c857, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_56) {
  // 548055 -> 548055
  scp_decimal d1 = {{0x85cd7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x85cd7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_57) {
  //-40.1932260121278702217 -> -40
  scp_decimal d1 = {{0x4ab86289, 0xc9ee3d0d, 0x15, sign_and_exp_bits(1, 19)}};
  scp_decimal correct = {{0x28, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_58) {
  // 4322836512375026.0 -> 4322836512375026
  scp_decimal d1 = {{0x136c0974, 0x9993f8, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0xcebe00f2, 0xf5b98, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_59) {
  // 4402.07815580 -> 4402
  scp_decimal d1 = {{0x7e6e339c, 0x66, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0x1132, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_60) {
  // 655.57555750000 -> 656
  scp_decimal d1 = {{0xced2a470, 0x3b9f, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0x290, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_61) {
  //-241.518930 -> -242
  scp_decimal d1 = {{0xe654952, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal correct = {{0xf2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_62) {
  // 84566359089251523837856.505 -> 84566359089251523837857
  scp_decimal d1 = {
      {0x85008af9, 0x831ebd2c, 0x45f39f, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {
      {0xb3553fa1, 0x59fcb3e6, 0x11e8, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_63) {
  //-953102.32679050 -> -953102
  scp_decimal d1 = {{0x248ff28a, 0x56af, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {{0xe8b0e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_64) {
  //-1373280292306511868780.619 -> -1373280292306511868781
  scp_decimal d1 = {{0x62f8e04b, 0xac7f4df3, 0x122cd, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {
      {0xe63e336d, 0x7217ade6, 0x4a, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_65) {
  //-7877286621.72690000000000000 -> -7877286622
  scp_decimal d1 = {
      {0xc0db2000, 0x57c4226d, 0x28b9808, sign_and_exp_bits(1, 17)}};
  scp_decimal correct = {{0xd585dade, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_66) {
  //-13.21000000000 -> -13
  scp_decimal d1 = {{0x91bc5a00, 0x133, 0x0, sign_and_exp_bits(1, 11)}};
  scp_decimal correct = {{0xd, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_67) {
  //-62729815.4219 -> -62729815
  scp_decimal d1 = {{0xde236eb, 0x92, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x3bd2e57, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_68) {
  //-21626728.641 -> -21626729
  scp_decimal d1 = {{0x90db0c1, 0x5, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0x149ff69, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_69) {
  // 22359725294.480109625 -> 22359725294
  scp_decimal d1 = {{0x3ccdb039, 0x364db3b0, 0x1, sign_and_exp_bits(0, 9)}};
  scp_decimal correct = {{0x34be54ee, 0x5, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_70) {
  //-6.992262817 -> -7
  scp_decimal d1 = {{0xa0c576a1, 0x1, 0x0, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_71) {
  //-5.9748989195058 -> -6
  scp_decimal d1 = {{0x6546d332, 0x3657, 0x0, sign_and_exp_bits(1, 13)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_72) {
  // 1253015021850609.264153785927 -> 1253015021850609
  scp_decimal d1 = {
      {0x441ef647, 0x713f2b08, 0x40c7840, sign_and_exp_bits(0, 12)}};
  scp_decimal correct = {{0x4b468ff1, 0x4739c, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_73) {
  //-2116123188440444.1 -> -2116123188440444
  scp_decimal d1 = {{0x3d7ac6d9, 0x4b2e07, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x52f2ad7c, 0x7849a, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_74) {
  // 8.4 -> 8
  scp_decimal d1 = {{0x54, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_75) {
  // 3642813197.577 -> 3642813198
  scp_decimal d1 = {{0x28962d09, 0x350, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0xd920eb0e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_76) {
  //-576055461.582097530347 -> -576055462
  scp_decimal d1 = {{0x7c9abdeb, 0x3a601e3c, 0x1f, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0x2255e8a6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_77) {
  //-9667884619349264986 -> -9667884619349264986
  scp_decimal d1 = {{0xb1c68a5a, 0x862b39d6, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xb1c68a5a, 0x862b39d6, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_78) {
  // 82.6416792 -> 83
  scp_decimal d1 = {{0x31421e98, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {{0x53, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_79) {
  //-12502.3 -> -12502
  scp_decimal d1 = {{0x1e85f, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x30d6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_80) {
  // 2.2 -> 2
  scp_decimal d1 = {{0x16, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_81) {
  //-8969276158801620.0559116086 -> -8969276158801620
  scp_decimal d1 = {
      {0xce443f36, 0x59372325, 0x4a312e, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x575676d4, 0x1fdd82, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_82) {
  // 4091.3475253 -> 4091
  scp_decimal d1 = {{0x86a216b5, 0x9, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {{0xffb, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_83) {
  // 8961.7976158821102800 -> 8962
  scp_decimal d1 = {{0x3f534d0, 0xdbb30280, 0x4, sign_and_exp_bits(0, 16)}};
  scp_decimal correct = {{0x2302, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_84) {
  //-992 -> -992
  scp_decimal d1 = {{0x3e0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x3e0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_85) {
  // 240806064152.6032691772 -> 240806064153
  scp_decimal d1 = {{0xe70f23c, 0x8a8dfb04, 0x82, sign_and_exp_bits(0, 10)}};
  scp_decimal correct = {{0x1128f019, 0x38, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_86) {
  // 83779.729982042 -> 83780
  scp_decimal d1 = {{0x7d0b825a, 0x4c32, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal correct = {{0x14744, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_87) {
  //-50 -> -50
  scp_decimal d1 = {{0x32, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x32, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_88) {
  //-19024140152919664703031.9 -> -19024140152919664703032
  scp_decimal d1 = {{0x1cfc1e2f, 0x1cd7ca9, 0x2849, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {
      {0xb6193638, 0x4cfaf2dd, 0x407, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_89) {
  //-38020014420.23 -> -38020014420
  scp_decimal d1 = {{0x38f204e7, 0x375, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0xda2b6154, 0x8, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_90) {
  //-65752420149371.1692 -> -65752420149371
  scp_decimal d1 = {{0xd414b4c, 0x91ffec7, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x2da5687b, 0x3bcd, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_91) {
  // 61289735237.100153 -> 61289735237
  scp_decimal d1 = {{0x812f6279, 0xd9beb0, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {{0x45272445, 0xe, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_92) {
  // 665632.9776896532 -> 665633
  scp_decimal d1 = {{0x8bdc1a14, 0x17a5e5, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal correct = {{0xa2821, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_93) {
  //-504128.3023601931 -> -504128
  scp_decimal d1 = {{0x2bd5810b, 0x11e905, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x7b140, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_94) {
  //-9307587.736097160246 -> -9307588
  scp_decimal d1 = {{0x75da7c36, 0x812b31bb, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0x8e05c4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_95) {
  // 79330187542056372601.896 -> 79330187542056372602
  scp_decimal d1 = {{0x2cd10428, 0x7f826c27, 0x10cc, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {
      {0x9963897a, 0x4ced7142, 0x4, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_96) {
  //-73350142067632.7085 -> -73350142067633
  scp_decimal d1 = {{0xe5a826ad, 0xa2deba7, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x292983b1, 0x42b6, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_97) {
  // 3551478.251716 -> 3551478
  scp_decimal d1 = {{0xe49980c4, 0x33a, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {{0x3630f6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_98) {
  //-403693235321000 -> -403693235321000
  scp_decimal d1 = {{0x27e3b8a8, 0x16f28, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x27e3b8a8, 0x16f28, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_99) {
  //-73268.314032416454 -> -73268
  scp_decimal d1 = {{0xb731a6c6, 0x1044d24, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0x11e34, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_100) {
  // 5.5 -> 6
  scp_decimal d1 = {{0x37, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_101) {
  //-5.5 -> -6
  scp_decimal d1 = {{0x37, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_102) {
  // 79228162514264337593543950335 -> 79228162514264337593543950335
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_103) {
  //-79228162514264337593543950335 -> -79228162514264337593543950335
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_104) {
  // 7922816251426433759354395033.5 -> 7922816251426433759354395034
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0x9999999a, 0x99999999, 0x19999999, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_105) {
  // 7922816251426433759354395033.4 -> 7922816251426433759354395033
  scp_decimal d1 = {
      {0xfffffffe, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0x99999999, 0x99999999, 0x19999999, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_106) {
  // 7922816251426433759354395034 -> 7922816251426433759354395034
  scp_decimal d1 = {
      {0x9999999a, 0x99999999, 0x19999999, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x9999999a, 0x99999999, 0x19999999, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_round_107) {
  // -0,0 => 0
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;
  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

START_TEST(scp_round_108) {
  // 0,0 => 0
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;
  ck_assert_int_eq(scp_round(d1, &result), SCP_OK);
  ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

START_TEST(scp_round_109) {
  // 0,0 => 0
  scp_decimal d1 = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  // scp_decimal correct = {{0, 0, 0, sign_and_exp_bits(0, 0)}};
  // scp_decimal result;
  ck_assert_int_eq(scp_round(d1, NULL), SCP_ERROR);
  // ck_assert_int_eq(scp_is_equal(correct, result), SCP_EQUAL);
}
END_TEST

Suite *round_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "SCP_ROUND" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("SCP_ROUND");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, scp_round_0);
  tcase_add_test(tc1_1, scp_round_1);
  tcase_add_test(tc1_1, scp_round_2);
  tcase_add_test(tc1_1, scp_round_3);
  tcase_add_test(tc1_1, scp_round_4);
  tcase_add_test(tc1_1, scp_round_5);
  tcase_add_test(tc1_1, scp_round_6);
  tcase_add_test(tc1_1, scp_round_7);
  tcase_add_test(tc1_1, scp_round_8);
  tcase_add_test(tc1_1, scp_round_9);
  tcase_add_test(tc1_1, scp_round_10);
  tcase_add_test(tc1_1, scp_round_11);
  tcase_add_test(tc1_1, scp_round_12);
  tcase_add_test(tc1_1, scp_round_13);
  tcase_add_test(tc1_1, scp_round_14);
  tcase_add_test(tc1_1, scp_round_15);
  tcase_add_test(tc1_1, scp_round_16);
  tcase_add_test(tc1_1, scp_round_17);
  tcase_add_test(tc1_1, scp_round_18);
  tcase_add_test(tc1_1, scp_round_19);
  tcase_add_test(tc1_1, scp_round_20);
  tcase_add_test(tc1_1, scp_round_21);
  tcase_add_test(tc1_1, scp_round_22);
  tcase_add_test(tc1_1, scp_round_23);
  tcase_add_test(tc1_1, scp_round_24);
  tcase_add_test(tc1_1, scp_round_25);
  tcase_add_test(tc1_1, scp_round_26);
  tcase_add_test(tc1_1, scp_round_27);
  tcase_add_test(tc1_1, scp_round_28);
  tcase_add_test(tc1_1, scp_round_29);
  tcase_add_test(tc1_1, scp_round_30);
  tcase_add_test(tc1_1, scp_round_31);
  tcase_add_test(tc1_1, scp_round_32);
  tcase_add_test(tc1_1, scp_round_33);
  tcase_add_test(tc1_1, scp_round_34);
  tcase_add_test(tc1_1, scp_round_35);
  tcase_add_test(tc1_1, scp_round_36);
  tcase_add_test(tc1_1, scp_round_37);
  tcase_add_test(tc1_1, scp_round_38);
  tcase_add_test(tc1_1, scp_round_39);
  tcase_add_test(tc1_1, scp_round_40);
  tcase_add_test(tc1_1, scp_round_41);
  tcase_add_test(tc1_1, scp_round_42);
  tcase_add_test(tc1_1, scp_round_43);
  tcase_add_test(tc1_1, scp_round_44);
  tcase_add_test(tc1_1, scp_round_45);
  tcase_add_test(tc1_1, scp_round_46);
  tcase_add_test(tc1_1, scp_round_47);
  tcase_add_test(tc1_1, scp_round_48);
  tcase_add_test(tc1_1, scp_round_49);
  tcase_add_test(tc1_1, scp_round_50);
  tcase_add_test(tc1_1, scp_round_51);
  tcase_add_test(tc1_1, scp_round_52);
  tcase_add_test(tc1_1, scp_round_53);
  tcase_add_test(tc1_1, scp_round_54);
  tcase_add_test(tc1_1, scp_round_55);
  tcase_add_test(tc1_1, scp_round_56);
  tcase_add_test(tc1_1, scp_round_57);
  tcase_add_test(tc1_1, scp_round_58);
  tcase_add_test(tc1_1, scp_round_59);
  tcase_add_test(tc1_1, scp_round_60);
  tcase_add_test(tc1_1, scp_round_61);
  tcase_add_test(tc1_1, scp_round_62);
  tcase_add_test(tc1_1, scp_round_63);
  tcase_add_test(tc1_1, scp_round_64);
  tcase_add_test(tc1_1, scp_round_65);
  tcase_add_test(tc1_1, scp_round_66);
  tcase_add_test(tc1_1, scp_round_67);
  tcase_add_test(tc1_1, scp_round_68);
  tcase_add_test(tc1_1, scp_round_69);
  tcase_add_test(tc1_1, scp_round_70);
  tcase_add_test(tc1_1, scp_round_71);
  tcase_add_test(tc1_1, scp_round_72);
  tcase_add_test(tc1_1, scp_round_73);
  tcase_add_test(tc1_1, scp_round_74);
  tcase_add_test(tc1_1, scp_round_75);
  tcase_add_test(tc1_1, scp_round_76);
  tcase_add_test(tc1_1, scp_round_77);
  tcase_add_test(tc1_1, scp_round_78);
  tcase_add_test(tc1_1, scp_round_79);
  tcase_add_test(tc1_1, scp_round_80);
  tcase_add_test(tc1_1, scp_round_81);
  tcase_add_test(tc1_1, scp_round_82);
  tcase_add_test(tc1_1, scp_round_83);
  tcase_add_test(tc1_1, scp_round_84);
  tcase_add_test(tc1_1, scp_round_85);
  tcase_add_test(tc1_1, scp_round_86);
  tcase_add_test(tc1_1, scp_round_87);
  tcase_add_test(tc1_1, scp_round_88);
  tcase_add_test(tc1_1, scp_round_89);
  tcase_add_test(tc1_1, scp_round_90);
  tcase_add_test(tc1_1, scp_round_91);
  tcase_add_test(tc1_1, scp_round_92);
  tcase_add_test(tc1_1, scp_round_93);
  tcase_add_test(tc1_1, scp_round_94);
  tcase_add_test(tc1_1, scp_round_95);
  tcase_add_test(tc1_1, scp_round_96);
  tcase_add_test(tc1_1, scp_round_97);
  tcase_add_test(tc1_1, scp_round_98);
  tcase_add_test(tc1_1, scp_round_99);
  tcase_add_test(tc1_1, scp_round_100);
  tcase_add_test(tc1_1, scp_round_101);
  tcase_add_test(tc1_1, scp_round_102);
  tcase_add_test(tc1_1, scp_round_103);
  tcase_add_test(tc1_1, scp_round_104);
  tcase_add_test(tc1_1, scp_round_105);
  tcase_add_test(tc1_1, scp_round_106);
  tcase_add_test(tc1_1, scp_round_107);
  tcase_add_test(tc1_1, scp_round_108);
  tcase_add_test(tc1_1, scp_round_109);

  return s1;
}
