#include "scp_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *              NEGATE FUNCTION TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(scp_negate_0) {
  // 181426665190439.6003055687421 -> -181426665190439.6003055687421
  scp_decimal d1 = {
      {0x55f6d6fd, 0x45ec55a6, 0x5dcb9e8, sign_and_exp_bits(0, 13)}};
  scp_decimal correct = {
      {0x55f6d6fd, 0x45ec55a6, 0x5dcb9e8, sign_and_exp_bits(1, 13)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_1) {
  // 83829892853117.21470 -> -83829892853117.21470
  scp_decimal d1 = {{0xae92ffe, 0x74565c57, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {{0xae92ffe, 0x74565c57, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_2) {
  //-728.99 -> 728.99
  scp_decimal d1 = {{0x11cc3, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x11cc3, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_3) {
  //-36269 -> 36269
  scp_decimal d1 = {{0x8dad, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x8dad, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_4) {
  //-7 -> 7
  scp_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_5) {
  // 2 -> -2
  scp_decimal d1 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_6) {
  // 776542857465842142716.71351 -> -776542857465842142716.71351
  scp_decimal d1 = {
      {0xaaa7bc37, 0x43f55f5c, 0x403bef, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {
      {0xaaa7bc37, 0x43f55f5c, 0x403bef, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_7) {
  // 330043407205616202767.21262830 -> -330043407205616202767.21262830
  scp_decimal d1 = {
      {0x6660a0ee, 0x88c3a64d, 0x6aa48cff, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {
      {0x6660a0ee, 0x88c3a64d, 0x6aa48cff, sign_and_exp_bits(1, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_8) {
  //-2.1404662323851818855511 -> 2.1404662323851818855511
  scp_decimal d1 = {{0x26de6c57, 0x595ca0c8, 0x488, sign_and_exp_bits(1, 22)}};
  scp_decimal correct = {
      {0x26de6c57, 0x595ca0c8, 0x488, sign_and_exp_bits(0, 22)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_9) {
  //-35882.6 -> 35882.6
  scp_decimal d1 = {{0x579aa, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x579aa, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_10) {
  // 3906.27 -> -3906.27
  scp_decimal d1 = {{0x5f5e3, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x5f5e3, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_11) {
  //-9019812153405.50505058916 -> 9019812153405.50505058916
  scp_decimal d1 = {{0xf5eb5264, 0x7fe9c2ef, 0xbf00, sign_and_exp_bits(1, 11)}};
  scp_decimal correct = {
      {0xf5eb5264, 0x7fe9c2ef, 0xbf00, sign_and_exp_bits(0, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_12) {
  // 420.02500925 -> -420.02500925
  scp_decimal d1 = {{0xc78b4d3d, 0x9, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0xc78b4d3d, 0x9, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_13) {
  //-4.9000000 -> 4.9000000
  scp_decimal d1 = {{0x2ebae40, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  scp_decimal correct = {{0x2ebae40, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_14) {
  //-9566180821877544.531993656967 -> 9566180821877544.531993656967
  scp_decimal d1 = {
      {0xb2457e87, 0x79335ee8, 0x1ee8f595, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {
      {0xb2457e87, 0x79335ee8, 0x1ee8f595, sign_and_exp_bits(0, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_15) {
  //-50603760766053737.1 -> 50603760766053737.1
  scp_decimal d1 = {{0xe798461b, 0x705ce85, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0xe798461b, 0x705ce85, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_16) {
  // 152612000461051226 -> -152612000461051226
  scp_decimal d1 = {{0x4bf1555a, 0x21e2fce, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x4bf1555a, 0x21e2fce, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_17) {
  //-96.189760546173048665 -> 96.189760546173048665
  scp_decimal d1 = {{0xe0875759, 0x36e6ad94, 0x5, sign_and_exp_bits(1, 18)}};
  scp_decimal correct = {
      {0xe0875759, 0x36e6ad94, 0x5, sign_and_exp_bits(0, 18)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_18) {
  //-6.1476198856 -> 6.1476198856
  scp_decimal d1 = {{0x504459c8, 0xe, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {{0x504459c8, 0xe, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_19) {
  // 5592548.320412405662408769591 -> -5592548.320412405662408769591
  scp_decimal d1 = {
      {0x76bc0037, 0xefa1eb9a, 0x12120c2b, sign_and_exp_bits(0, 21)}};
  scp_decimal correct = {
      {0x76bc0037, 0xefa1eb9a, 0x12120c2b, sign_and_exp_bits(1, 21)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_20) {
  // 16657.627 -> -16657.627
  scp_decimal d1 = {{0xfe2cdb, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0xfe2cdb, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_21) {
  //-54745 -> 54745
  scp_decimal d1 = {{0xd5d9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0xd5d9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_22) {
  // 9943246.5 -> -9943246.5
  scp_decimal d1 = {{0x5ed3811, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x5ed3811, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_23) {
  //-67551.7014 -> 67551.7014
  scp_decimal d1 = {{0x28439256, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x28439256, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_24) {
  // 16285847173.0207 -> -16285847173.0207
  scp_decimal d1 = {{0x715b2c1f, 0x941e, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x715b2c1f, 0x941e, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_25) {
  // 858672 -> -858672
  scp_decimal d1 = {{0xd1a30, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0xd1a30, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_26) {
  //-55.66434 -> 55.66434
  scp_decimal d1 = {{0x54efe2, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {{0x54efe2, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_27) {
  // 35914749.7526 -> -35914749.7526
  scp_decimal d1 = {{0x9edbe836, 0x53, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x9edbe836, 0x53, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_28) {
  //-9801072156730911148274 -> 9801072156730911148274
  scp_decimal d1 = {{0xada0c8f2, 0x51331e3d, 0x213, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xada0c8f2, 0x51331e3d, 0x213, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_29) {
  //-287964089.4268285827 -> 287964089.4268285827
  scp_decimal d1 = {{0xe78ca383, 0x27f68a22, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {
      {0xe78ca383, 0x27f68a22, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_30) {
  // 8424.4955964260732 -> -8424.4955964260732
  scp_decimal d1 = {{0x525e417c, 0x12b4c57, 0x0, sign_and_exp_bits(0, 13)}};
  scp_decimal correct = {
      {0x525e417c, 0x12b4c57, 0x0, sign_and_exp_bits(1, 13)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_31) {
  //-10409.14520911879300000000 -> 10409.14520911879300000000
  scp_decimal d1 = {{0x31fd2900, 0x16d8e7dc, 0xdc6c, sign_and_exp_bits(1, 20)}};
  scp_decimal correct = {
      {0x31fd2900, 0x16d8e7dc, 0xdc6c, sign_and_exp_bits(0, 20)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_32) {
  //-1 -> 1
  scp_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_33) {
  // 7354780517397309776.96 -> -7354780517397309776.96
  scp_decimal d1 = {{0xdb0823a0, 0xdeceef53, 0x27, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {
      {0xdb0823a0, 0xdeceef53, 0x27, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_34) {
  // 32613905739340.49198555702 -> -32613905739340.49198555702
  scp_decimal d1 = {
      {0xf5734236, 0x5657ed2f, 0x2b2a0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {
      {0xf5734236, 0x5657ed2f, 0x2b2a0, sign_and_exp_bits(1, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_35) {
  // 2.14496366071229000000 -> -2.14496366071229000000
  scp_decimal d1 = {{0xc7c12940, 0xa0bc2c7d, 0xb, sign_and_exp_bits(0, 20)}};
  scp_decimal correct = {
      {0xc7c12940, 0xa0bc2c7d, 0xb, sign_and_exp_bits(1, 20)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_36) {
  // 29294.1 -> -29294.1
  scp_decimal d1 = {{0x4784d, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x4784d, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_37) {
  // 2298.89169 -> -2298.89169
  scp_decimal d1 = {{0xdb3d491, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {{0xdb3d491, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_38) {
  // 942603130000 -> -942603130000
  scp_decimal d1 = {{0x77865490, 0xdb, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x77865490, 0xdb, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_39) {
  // 1.46 -> -1.46
  scp_decimal d1 = {{0x92, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x92, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_40) {
  //-291693176091879978.7 -> 291693176091879978.7
  scp_decimal d1 = {{0x639ea5ab, 0x287b05fb, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {
      {0x639ea5ab, 0x287b05fb, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_41) {
  // 0.57265218 -> -0.57265218
  scp_decimal d1 = {{0x369cc42, 0x0, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0x369cc42, 0x0, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_42) {
  //-8.18260773 -> 8.18260773
  scp_decimal d1 = {{0x30c5ab25, 0x0, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {{0x30c5ab25, 0x0, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_43) {
  // 71458490.9 -> -71458490.9
  scp_decimal d1 = {{0x2a97b34d, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x2a97b34d, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_44) {
  // 6613.392 -> -6613.392
  scp_decimal d1 = {{0x64e990, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x64e990, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_45) {
  // 8.995256 -> -8.995256
  scp_decimal d1 = {{0x8941b8, 0x0, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {{0x8941b8, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_46) {
  // 71.52000 -> -71.52000
  scp_decimal d1 = {{0x6d2180, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {{0x6d2180, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_47) {
  // 6899875.5 -> -6899875.5
  scp_decimal d1 = {{0x41cd663, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x41cd663, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_48) {
  // 75833.12311795651 -> -75833.12311795651
  scp_decimal d1 = {{0x7c90bfc3, 0x1af0fb, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0x7c90bfc3, 0x1af0fb, 0x0, sign_and_exp_bits(1, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_49) {
  // 618526.744 -> -618526.744
  scp_decimal d1 = {{0x24ddf818, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0x24ddf818, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_50) {
  // 2341212035.8601676688730126300 -> -2341212035.8601676688730126300
  scp_decimal d1 = {
      {0x1a3c77dc, 0xc3afdda7, 0x4ba60d53, sign_and_exp_bits(0, 19)}};
  scp_decimal correct = {
      {0x1a3c77dc, 0xc3afdda7, 0x4ba60d53, sign_and_exp_bits(1, 19)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_51) {
  // 246820451686.79056276 -> -246820451686.79056276
  scp_decimal d1 = {{0x5142f394, 0x56883d4f, 0x1, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {
      {0x5142f394, 0x56883d4f, 0x1, sign_and_exp_bits(1, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_52) {
  // 7.13367821658 -> -7.13367821658
  scp_decimal d1 = {{0x18091d5a, 0xa6, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0x18091d5a, 0xa6, 0x0, sign_and_exp_bits(1, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_53) {
  // 87018.98132335 -> -87018.98132335
  scp_decimal d1 = {{0x118c0b6f, 0x7ea, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0x118c0b6f, 0x7ea, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_54) {
  // 40298248802577084.723610 -> -40298248802577084.723610
  scp_decimal d1 = {{0xcdbe319a, 0x928bc0ab, 0x888, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {
      {0xcdbe319a, 0x928bc0ab, 0x888, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_55) {
  //-702226180271280.2 -> 702226180271280.2
  scp_decimal d1 = {{0xbc453ee2, 0x18f2b5, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0xbc453ee2, 0x18f2b5, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_56) {
  //-614062467.83929679837571175 -> 614062467.83929679837571175
  scp_decimal d1 = {
      {0x3872a867, 0x4ef110f5, 0x32cb47, sign_and_exp_bits(1, 17)}};
  scp_decimal correct = {
      {0x3872a867, 0x4ef110f5, 0x32cb47, sign_and_exp_bits(0, 17)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_57) {
  // 571.5064 -> -571.5064
  scp_decimal d1 = {{0x573478, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x573478, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_58) {
  //-27.223653627750485583 -> 27.223653627750485583
  scp_decimal d1 = {{0xc2578e4f, 0x79cdd8bc, 0x1, sign_and_exp_bits(1, 18)}};
  scp_decimal correct = {
      {0xc2578e4f, 0x79cdd8bc, 0x1, sign_and_exp_bits(0, 18)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_59) {
  // 9.02726067888245 -> -9.02726067888245
  scp_decimal d1 = {{0x4a9b2075, 0x33506, 0x0, sign_and_exp_bits(0, 14)}};
  scp_decimal correct = {{0x4a9b2075, 0x33506, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_60) {
  //-390736206965530.2316101701 -> 390736206965530.2316101701
  scp_decimal d1 = {
      {0x368e1045, 0x85b0e400, 0x33b6a, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {
      {0x368e1045, 0x85b0e400, 0x33b6a, sign_and_exp_bits(0, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_61) {
  //-9370.516 -> 9370.516
  scp_decimal d1 = {{0x8efb94, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0x8efb94, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_62) {
  // 60.34 -> -60.34
  scp_decimal d1 = {{0x1792, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x1792, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_63) {
  // 3993638254545.8125 -> -3993638254545.8125
  scp_decimal d1 = {{0xa73c73cd, 0x8de1ed, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0xa73c73cd, 0x8de1ed, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_64) {
  //-21587846.58253 -> 21587846.58253
  scp_decimal d1 = {{0xa197bb4d, 0x1f6, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {{0xa197bb4d, 0x1f6, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_65) {
  //-25691522813.5 -> 25691522813.5
  scp_decimal d1 = {{0xd15745e7, 0x3b, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0xd15745e7, 0x3b, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_66) {
  // 5.93 -> -5.93
  scp_decimal d1 = {{0x251, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x251, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_67) {
  //-69982 -> 69982
  scp_decimal d1 = {{0x1115e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x1115e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_68) {
  // 45561831.91330795125782689400 -> -45561831.91330795125782689400
  scp_decimal d1 = {
      {0x61b13678, 0xb6d1d5f3, 0xeb8c951, sign_and_exp_bits(0, 20)}};
  scp_decimal correct = {
      {0x61b13678, 0xb6d1d5f3, 0xeb8c951, sign_and_exp_bits(1, 20)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_69) {
  //-6420979787501373400.2096973290 -> 6420979787501373400.2096973290
  scp_decimal d1 = {
      {0x3841a5ea, 0x8c18a14e, 0xcf791995, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {
      {0x3841a5ea, 0x8c18a14e, 0xcf791995, sign_and_exp_bits(0, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_70) {
  //-616.23 -> 616.23
  scp_decimal d1 = {{0xf0b7, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0xf0b7, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_71) {
  // 50875115.759 -> -50875115.759
  scp_decimal d1 = {{0xd864a8ef, 0xb, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0xd864a8ef, 0xb, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_72) {
  // 633413.00797846 -> -633413.00797846
  scp_decimal d1 = {{0xcbbbd196, 0x399b, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0xcbbbd196, 0x399b, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_73) {
  // 5270.7306602 -> -5270.7306602
  scp_decimal d1 = {{0x4599ac6a, 0xc, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {{0x4599ac6a, 0xc, 0x0, sign_and_exp_bits(1, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_74) {
  // 18 -> -18
  scp_decimal d1 = {{0x12, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x12, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_75) {
  // 1687072042.8 -> -1687072042.8
  scp_decimal d1 = {{0xed92c3ac, 0x3, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0xed92c3ac, 0x3, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_76) {
  //-101409336830735.2843724 -> 101409336830735.2843724
  scp_decimal d1 = {{0x1f23b5cc, 0xf95f6194, 0x36, sign_and_exp_bits(1, 7)}};
  scp_decimal correct = {
      {0x1f23b5cc, 0xf95f6194, 0x36, sign_and_exp_bits(0, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_77) {
  // 1141453.4219611150504100090 -> -1141453.4219611150504100090
  scp_decimal d1 = {
      {0xa2db00fa, 0x23d32620, 0x9711f, sign_and_exp_bits(0, 19)}};
  scp_decimal correct = {
      {0xa2db00fa, 0x23d32620, 0x9711f, sign_and_exp_bits(1, 19)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_78) {
  //-762.4140141436963657000000 -> 762.4140141436963657000000
  scp_decimal d1 = {
      {0xe092a440, 0x77199338, 0x64e79, sign_and_exp_bits(1, 22)}};
  scp_decimal correct = {
      {0xe092a440, 0x77199338, 0x64e79, sign_and_exp_bits(0, 22)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_79) {
  //-238797.18615084913244856 -> 238797.18615084913244856
  scp_decimal d1 = {{0x8339bab8, 0x85aaf83f, 0x50e, sign_and_exp_bits(1, 17)}};
  scp_decimal correct = {
      {0x8339bab8, 0x85aaf83f, 0x50e, sign_and_exp_bits(0, 17)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_80) {
  // 7.1478443579697784 -> -7.1478443579697784
  scp_decimal d1 = {{0x6aa6a78, 0xfdf144, 0x0, sign_and_exp_bits(0, 16)}};
  scp_decimal correct = {{0x6aa6a78, 0xfdf144, 0x0, sign_and_exp_bits(1, 16)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_81) {
  //-4302693547358206393193589.070 -> 4302693547358206393193589.070
  scp_decimal d1 = {
      {0xf65fe94e, 0x944a269a, 0xde71acc, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {
      {0xf65fe94e, 0x944a269a, 0xde71acc, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_82) {
  // 79 -> -79
  scp_decimal d1 = {{0x4f, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x4f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_83) {
  // 2.10 -> -2.10
  scp_decimal d1 = {{0xd2, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0xd2, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_84) {
  //-5251928703.112552 -> 5251928703.112552
  scp_decimal d1 = {{0xf0bc1568, 0x12a899, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal correct = {{0xf0bc1568, 0x12a899, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_85) {
  //-5 -> 5
  scp_decimal d1 = {{0x5, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_86) {
  //-74892827 -> 74892827
  scp_decimal d1 = {{0x476c61b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x476c61b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_87) {
  // 46182211 -> -46182211
  scp_decimal d1 = {{0x2c0af43, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x2c0af43, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_88) {
  // 979492764555211310.6578 -> -979492764555211310.6578
  scp_decimal d1 = {{0xfaf43e92, 0xfbed6de0, 0x212, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {
      {0xfaf43e92, 0xfbed6de0, 0x212, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_89) {
  //-409760974067518.5086936675 -> 409760974067518.5086936675
  scp_decimal d1 = {
      {0x2891b663, 0xde801539, 0x363b3, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {
      {0x2891b663, 0xde801539, 0x363b3, sign_and_exp_bits(0, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_90) {
  //-50702.222 -> 50702.222
  scp_decimal d1 = {{0x305a78e, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0x305a78e, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_91) {
  //-783276301055730247.08838810 -> 783276301055730247.08838810
  scp_decimal d1 = {
      {0xa81a459a, 0x5618185f, 0x40ca85, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {
      {0xa81a459a, 0x5618185f, 0x40ca85, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_92) {
  //-24.2 -> 24.2
  scp_decimal d1 = {{0xf2, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0xf2, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_93) {
  //-4 -> 4
  scp_decimal d1 = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_94) {
  //-82437417735.99093100202400000 -> 82437417735.99093100202400000
  scp_decimal d1 = {
      {0xa079900, 0x46c99ad, 0x1aa31039, sign_and_exp_bits(1, 17)}};
  scp_decimal correct = {
      {0xa079900, 0x46c99ad, 0x1aa31039, sign_and_exp_bits(0, 17)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_95) {
  // 1026073.5262613 -> -1026073.5262613
  scp_decimal d1 = {{0x37aff95, 0x955, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {{0x37aff95, 0x955, 0x0, sign_and_exp_bits(1, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_96) {
  //-97 -> 97
  scp_decimal d1 = {{0x61, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x61, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_97) {
  //-4910771773.834047708171250 -> 4910771773.834047708171250
  scp_decimal d1 = {
      {0x6bab8bf2, 0x78a65e1c, 0x40fe5, sign_and_exp_bits(1, 15)}};
  scp_decimal correct = {
      {0x6bab8bf2, 0x78a65e1c, 0x40fe5, sign_and_exp_bits(0, 15)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_98) {
  //-805176.783258897 -> 805176.783258897
  scp_decimal d1 = {{0xd425c511, 0x2dc4d, 0x0, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0xd425c511, 0x2dc4d, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_99) {
  // 74236.70057881783193445307 -> -74236.70057881783193445307
  scp_decimal d1 = {
      {0x2f4e23bb, 0xf5d189cf, 0x62405, sign_and_exp_bits(0, 20)}};
  scp_decimal correct = {
      {0x2f4e23bb, 0xf5d189cf, 0x62405, sign_and_exp_bits(1, 20)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_100) {
  //-0 -> 0
  scp_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_101) {
  // 0 -> -0
  scp_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_102) {
  // 79228162514264337593543950335 -> -79228162514264337593543950335
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_103) {
  //-79228162514264337593543950335 -> 79228162514264337593543950335
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_negate(d1, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_negate_104) {
  // Segmentation fault test
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(scp_negate(d1, NULL), SCP_ERROR);
  // ASSERT_BITS_EQ
}
END_TEST

Suite *negate_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "SCP_NEGATE" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("SCP_NEGATE");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, scp_negate_0);
  tcase_add_test(tc1_1, scp_negate_1);
  tcase_add_test(tc1_1, scp_negate_2);
  tcase_add_test(tc1_1, scp_negate_3);
  tcase_add_test(tc1_1, scp_negate_4);
  tcase_add_test(tc1_1, scp_negate_5);
  tcase_add_test(tc1_1, scp_negate_6);
  tcase_add_test(tc1_1, scp_negate_7);
  tcase_add_test(tc1_1, scp_negate_8);
  tcase_add_test(tc1_1, scp_negate_9);
  tcase_add_test(tc1_1, scp_negate_10);
  tcase_add_test(tc1_1, scp_negate_11);
  tcase_add_test(tc1_1, scp_negate_12);
  tcase_add_test(tc1_1, scp_negate_13);
  tcase_add_test(tc1_1, scp_negate_14);
  tcase_add_test(tc1_1, scp_negate_15);
  tcase_add_test(tc1_1, scp_negate_16);
  tcase_add_test(tc1_1, scp_negate_17);
  tcase_add_test(tc1_1, scp_negate_18);
  tcase_add_test(tc1_1, scp_negate_19);
  tcase_add_test(tc1_1, scp_negate_20);
  tcase_add_test(tc1_1, scp_negate_21);
  tcase_add_test(tc1_1, scp_negate_22);
  tcase_add_test(tc1_1, scp_negate_23);
  tcase_add_test(tc1_1, scp_negate_24);
  tcase_add_test(tc1_1, scp_negate_25);
  tcase_add_test(tc1_1, scp_negate_26);
  tcase_add_test(tc1_1, scp_negate_27);
  tcase_add_test(tc1_1, scp_negate_28);
  tcase_add_test(tc1_1, scp_negate_29);
  tcase_add_test(tc1_1, scp_negate_30);
  tcase_add_test(tc1_1, scp_negate_31);
  tcase_add_test(tc1_1, scp_negate_32);
  tcase_add_test(tc1_1, scp_negate_33);
  tcase_add_test(tc1_1, scp_negate_34);
  tcase_add_test(tc1_1, scp_negate_35);
  tcase_add_test(tc1_1, scp_negate_36);
  tcase_add_test(tc1_1, scp_negate_37);
  tcase_add_test(tc1_1, scp_negate_38);
  tcase_add_test(tc1_1, scp_negate_39);
  tcase_add_test(tc1_1, scp_negate_40);
  tcase_add_test(tc1_1, scp_negate_41);
  tcase_add_test(tc1_1, scp_negate_42);
  tcase_add_test(tc1_1, scp_negate_43);
  tcase_add_test(tc1_1, scp_negate_44);
  tcase_add_test(tc1_1, scp_negate_45);
  tcase_add_test(tc1_1, scp_negate_46);
  tcase_add_test(tc1_1, scp_negate_47);
  tcase_add_test(tc1_1, scp_negate_48);
  tcase_add_test(tc1_1, scp_negate_49);
  tcase_add_test(tc1_1, scp_negate_50);
  tcase_add_test(tc1_1, scp_negate_51);
  tcase_add_test(tc1_1, scp_negate_52);
  tcase_add_test(tc1_1, scp_negate_53);
  tcase_add_test(tc1_1, scp_negate_54);
  tcase_add_test(tc1_1, scp_negate_55);
  tcase_add_test(tc1_1, scp_negate_56);
  tcase_add_test(tc1_1, scp_negate_57);
  tcase_add_test(tc1_1, scp_negate_58);
  tcase_add_test(tc1_1, scp_negate_59);
  tcase_add_test(tc1_1, scp_negate_60);
  tcase_add_test(tc1_1, scp_negate_61);
  tcase_add_test(tc1_1, scp_negate_62);
  tcase_add_test(tc1_1, scp_negate_63);
  tcase_add_test(tc1_1, scp_negate_64);
  tcase_add_test(tc1_1, scp_negate_65);
  tcase_add_test(tc1_1, scp_negate_66);
  tcase_add_test(tc1_1, scp_negate_67);
  tcase_add_test(tc1_1, scp_negate_68);
  tcase_add_test(tc1_1, scp_negate_69);
  tcase_add_test(tc1_1, scp_negate_70);
  tcase_add_test(tc1_1, scp_negate_71);
  tcase_add_test(tc1_1, scp_negate_72);
  tcase_add_test(tc1_1, scp_negate_73);
  tcase_add_test(tc1_1, scp_negate_74);
  tcase_add_test(tc1_1, scp_negate_75);
  tcase_add_test(tc1_1, scp_negate_76);
  tcase_add_test(tc1_1, scp_negate_77);
  tcase_add_test(tc1_1, scp_negate_78);
  tcase_add_test(tc1_1, scp_negate_79);
  tcase_add_test(tc1_1, scp_negate_80);
  tcase_add_test(tc1_1, scp_negate_81);
  tcase_add_test(tc1_1, scp_negate_82);
  tcase_add_test(tc1_1, scp_negate_83);
  tcase_add_test(tc1_1, scp_negate_84);
  tcase_add_test(tc1_1, scp_negate_85);
  tcase_add_test(tc1_1, scp_negate_86);
  tcase_add_test(tc1_1, scp_negate_87);
  tcase_add_test(tc1_1, scp_negate_88);
  tcase_add_test(tc1_1, scp_negate_89);
  tcase_add_test(tc1_1, scp_negate_90);
  tcase_add_test(tc1_1, scp_negate_91);
  tcase_add_test(tc1_1, scp_negate_92);
  tcase_add_test(tc1_1, scp_negate_93);
  tcase_add_test(tc1_1, scp_negate_94);
  tcase_add_test(tc1_1, scp_negate_95);
  tcase_add_test(tc1_1, scp_negate_96);
  tcase_add_test(tc1_1, scp_negate_97);
  tcase_add_test(tc1_1, scp_negate_98);
  tcase_add_test(tc1_1, scp_negate_99);
  tcase_add_test(tc1_1, scp_negate_100);
  tcase_add_test(tc1_1, scp_negate_101);
  tcase_add_test(tc1_1, scp_negate_102);
  tcase_add_test(tc1_1, scp_negate_103);
  tcase_add_test(tc1_1, scp_negate_104);

  return s1;
}
