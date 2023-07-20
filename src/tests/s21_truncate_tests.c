#include "s21_decimal_tests.h"

START_TEST(s21_truncate_1) {
  //-38344221243.3684 -> -38344221243
  s21_decimal d1 = {{0x18dd2f14, 0x15cbd, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0xed7e623b, 0x8, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_2) {
  // 35.504111315912799727 -> 35
  s21_decimal d1 = {{0xae8b5ef, 0xecb7f122, 0x1, sign_and_exp_bits(0, 18)}};
  s21_decimal correct = {{0x23, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_3) {
  // 0.0512 -> 0
  s21_decimal d1 = {{0x200, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_4) {
  //-599.6857 -> -599
  s21_decimal d1 = {{0x5b8139, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x257, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_5) {
  //-724704.36 -> -724704
  s21_decimal d1 = {{0x451cfa4, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0xb0ee0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_6) {
  // 0.1 -> 0
  s21_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_7) {
  //-120687396607452713898775 -> -120687396607452713898775
  s21_decimal d1 = {{0xea4d317, 0x7a14c93f, 0x198e, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xea4d317, 0x7a14c93f, 0x198e, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_8) {
  //-31625973.93736593201289169 -> -31625973
  s21_decimal d1 = {
      {0x8d49d7d1, 0xbf8d444d, 0x29db4, sign_and_exp_bits(1, 17)}};
  s21_decimal correct = {{0x1e292f5, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_9) {
  //-3655.13126414151 -> -3655
  s21_decimal d1 = {{0xa80f8747, 0x14c6e, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {{0xe47, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_10) {
  // 987.112569781283860688375201 -> 987
  s21_decimal d1 = {
      {0x57578da1, 0xa1d9e194, 0x3308537, sign_and_exp_bits(0, 24)}};
  s21_decimal correct = {{0x3db, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_11) {
  // 618149 -> 618149
  s21_decimal d1 = {{0x96ea5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x96ea5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_12) {
  //-4690726.8 -> -4690726
  s21_decimal d1 = {{0x2cbbf84, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x479326, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_13) {
  //-948.82738158336962433214929 -> -948
  s21_decimal d1 = {
      {0x902d69d1, 0x8ac92b83, 0x4e7c33, sign_and_exp_bits(1, 23)}};
  s21_decimal correct = {{0x3b4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_14) {
  //-0.04970 -> 0
  s21_decimal d1 = {{0x136a, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_15) {
  //-337458.71714 -> -337458
  s21_decimal d1 = {{0xdb692362, 0x7, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0x52632, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_16) {
  //-363.633 -> -363
  s21_decimal d1 = {{0x58c71, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {{0x16b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_17) {
  //-62097595.0897070 -> -62097595
  s21_decimal d1 = {{0x3af79fae, 0x234c6, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x3b388bb, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_18) {
  // 79549608175 -> 79549608175
  s21_decimal d1 = {{0x8586b0ef, 0x12, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x8586b0ef, 0x12, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_19) {
  // 79606317106966.605949 -> 79606317106966
  s21_decimal d1 = {{0xedd8b07d, 0x50c273a2, 0x4, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {{0xca40c716, 0x4866, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_20) {
  //-889095048147.144120 -> -889095048147
  s21_decimal d1 = {{0x545e8db8, 0xc56b33c, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {{0x231cbd3, 0xcf, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_21) {
  //-292197218445.111 -> -292197218445
  s21_decimal d1 = {{0x7768e737, 0x109c0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {{0x84fb88d, 0x44, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_22) {
  //-610684.648 -> -610684
  s21_decimal d1 = {{0x24664ee8, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {{0x9517c, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_23) {
  // 306.9661004655658943828456 -> 306
  s21_decimal d1 = {
      {0x2aded1e8, 0xa8108549, 0x28a06, sign_and_exp_bits(0, 22)}};
  s21_decimal correct = {{0x132, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_24) {
  //-37649303633561955289.3 -> -37649303633561955289
  s21_decimal d1 = {{0x38d6b67d, 0x68e3f5cd, 0x14, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x1f48abd9, 0xa7d322e, 0x2, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_25) {
  //-6290397632861307990.3 -> -6290397632861307990
  s21_decimal d1 = {{0xfa902b5f, 0x68f7d130, 0x3, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0xb2a80456, 0x574bfb51, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_26) {
  // 2648.5 -> 2648
  s21_decimal d1 = {{0x6775, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0xa58, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_27) {
  // 95036269393109.4157 -> 95036269393109
  s21_decimal d1 = {{0xbb8bd08d, 0xd305dd5, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x5b13f4d5, 0x566f, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_28) {
  // 2249.16140233908445395 -> 2249
  s21_decimal d1 = {{0xce0e60d3, 0x3156a5e2, 0xc, sign_and_exp_bits(0, 17)}};
  s21_decimal correct = {{0x8c9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_29) {
  //-2.8084867933716401551057177 -> -2
  s21_decimal d1 = {
      {0x53942119, 0xbdcb6b79, 0x173b33, sign_and_exp_bits(1, 25)}};
  s21_decimal correct = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_30) {
  // 7322.094439875875373180 -> 7322
  s21_decimal d1 = {{0xb857007c, 0xee7912f2, 0x18c, sign_and_exp_bits(0, 18)}};
  s21_decimal correct = {{0x1c9a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_31) {
  //-8928436980885.605928633696 -> -8928436980885
  s21_decimal d1 = {
      {0x1cfb8560, 0x89e04cf0, 0x762ab, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {{0xd0508c95, 0x81e, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_32) {
  //-459.563047721797743308 -> -459
  s21_decimal d1 = {{0x99a4f2cc, 0xe9b7ed08, 0x18, sign_and_exp_bits(1, 18)}};
  s21_decimal correct = {{0x1cb, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_33) {
  // 442.369083135305907 -> 442
  s21_decimal d1 = {{0x5be528b3, 0x6239c56, 0x0, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {{0x1ba, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_34) {
  //-26361002850648.421604743 -> -26361002850648
  s21_decimal d1 = {{0xf6d09d87, 0x8676a15, 0x595, sign_and_exp_bits(1, 9)}};
  s21_decimal correct = {{0xa635f958, 0x17f9, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_35) {
  //-2 -> -2
  s21_decimal d1 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_36) {
  //-6.5137145387 -> -6
  s21_decimal d1 = {{0x2a79f62b, 0xf, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_37) {
  //-822927371695654922590.532068 -> -822927371695654922590
  s21_decimal d1 = {
      {0x148eb1e4, 0x35a27f57, 0x2a8b5a6, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {
      {0x495b695e, 0x9c695480, 0x2c, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_38) {
  //-73.660770 -> -73
  s21_decimal d1 = {{0x463f962, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {{0x49, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_39) {
  // 8365709913.75 -> 8365709913
  s21_decimal d1 = {{0xc7844b0f, 0xc2, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0xf2a29a59, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_40) {
  //-65484998726186258.4168 -> -65484998726186258
  s21_decimal d1 = {{0xe8651f68, 0x7fde81de, 0x23, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x6730f512, 0xe8a642, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_41) {
  //-7.4073 -> -7
  s21_decimal d1 = {{0x12159, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_42) {
  //-1958.2270641550 -> -1958
  s21_decimal d1 = {{0x5a49158e, 0x11cf, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {{0x7a6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_43) {
  // 285961.5995450649533333955935 -> 285961
  s21_decimal d1 = {
      {0x5f9ce55f, 0xbcb23bcf, 0x93d6b3d, sign_and_exp_bits(0, 22)}};
  s21_decimal correct = {{0x45d09, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_44) {
  //-62475444991817.90321390952516 -> -62475444991817
  s21_decimal d1 = {
      {0xad08a044, 0xef85f8b1, 0x142fd901, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {{0x32b4b749, 0x38d2, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_45) {
  //-6.0119692 -> -6
  s21_decimal d1 = {{0x3955a8c, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_46) {
  //-0.58009934416273134710091 -> 0
  s21_decimal d1 = {{0xa34ded4b, 0xb98f81cb, 0xc48, sign_and_exp_bits(1, 23)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_47) {
  //-1724108384484012.94890214811 -> -1724108384484012
  s21_decimal d1 = {
      {0xc459a59b, 0x47c1193e, 0x8e9d6a, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {{0x43cfbaac, 0x62011, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_48) {
  //-6 -> -6
  s21_decimal d1 = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_49) {
  //-2727828.81 -> -2727828
  s21_decimal d1 = {{0x10425621, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x299f94, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_50) {
  // 614.8 -> 614
  s21_decimal d1 = {{0x1804, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x266, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_51) {
  // 52223154007296896142.216 -> 52223154007296896142
  s21_decimal d1 = {{0x18ec0b88, 0x5d99782, 0xb0f, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {
      {0x2772ec8e, 0xd4bde9e1, 0x2, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_52) {
  // 24766.0559089158490 -> 24766
  s21_decimal d1 = {{0x6162495a, 0x36fddf7, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal correct = {{0x60be, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_53) {
  //-161793.2783445 -> -161793
  s21_decimal d1 = {{0xb44f0f55, 0x178, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x27801, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_54) {
  //-87085.383012991020588 -> -87085
  s21_decimal d1 = {{0xc22aae2c, 0xb88d6e73, 0x4, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {{0x1542d, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_55) {
  // 286.91324830597170132543332 -> 286
  s21_decimal d1 = {
      {0x1da1e764, 0xd5ec922f, 0x17bb9f, sign_and_exp_bits(0, 23)}};
  s21_decimal correct = {{0x11e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_56) {
  // 44810.9 -> 44810
  s21_decimal d1 = {{0x6d66d, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0xaf0a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_57) {
  //-0.4844591 -> 0
  s21_decimal d1 = {{0x49ec2f, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_58) {
  //-1.97209428589120893552603 -> -1
  s21_decimal d1 = {{0xdb3907db, 0xbe9a8978, 0x29c2, sign_and_exp_bits(1, 23)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_59) {
  // 144329148 -> 144329148
  s21_decimal d1 = {{0x89a49bc, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x89a49bc, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_60) {
  //-88 -> -88
  s21_decimal d1 = {{0x58, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x58, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_61) {
  //-315222 -> -315222
  s21_decimal d1 = {{0x4cf56, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x4cf56, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_62) {
  //-758.85 -> -758
  s21_decimal d1 = {{0x1286d, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x2f6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_63) {
  //-9033140033.1 -> -9033140033
  s21_decimal d1 = {{0x82bc88b, 0x15, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x1a6ac741, 0x2, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_64) {
  // 58930792.9 -> 58930792
  s21_decimal d1 = {{0x23202019, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x3833668, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_65) {
  //-9.7252131800620 -> -9
  s21_decimal d1 = {{0x46c5062c, 0x5873, 0x0, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {{0x9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_66) {
  // 8843.33069597 -> 8843
  s21_decimal d1 = {{0xe65bc51d, 0xcd, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal correct = {{0x228b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_67) {
  //-74471338867.78448569415560 -> -74471338867
  s21_decimal d1 = {{0xcc7b788, 0xefdb6aa2, 0x628fd, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {{0x56d67373, 0x11, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_68) {
  //-680.599448781376716 -> -680
  s21_decimal d1 = {{0xbaf0cccc, 0x971f997, 0x0, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {{0x2a8, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_69) {
  //-1304249.711387944971294 -> -1304249
  s21_decimal d1 = {{0xd4346c1e, 0xb419ca4b, 0x46, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {{0x13e6b9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_70) {
  // 666902272059203104.5022 -> 666902272059203104
  s21_decimal d1 = {{0xb92cd59e, 0x87483e61, 0x169, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x41fd5e20, 0x9415015, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_71) {
  // 4.2 -> 4
  s21_decimal d1 = {{0x2a, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_72) {
  // 569015.230153269096 -> 569015
  s21_decimal d1 = {{0x49129f68, 0x7e58c56, 0x0, sign_and_exp_bits(0, 12)}};
  s21_decimal correct = {{0x8aeb7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_73) {
  //-80.53430189137750000000000000 -> -80
  s21_decimal d1 = {
      {0x44636000, 0x59e696fd, 0x1a05a42d, sign_and_exp_bits(1, 26)}};
  s21_decimal correct = {{0x50, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_74) {
  // 38.3560577969626086411 -> 38
  s21_decimal d1 = {{0xeb14fc0b, 0xcaf8e978, 0x14, sign_and_exp_bits(0, 19)}};
  s21_decimal correct = {{0x26, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_75) {
  //-1.47015 -> -1
  s21_decimal d1 = {{0x23e47, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_76) {
  //-6.23075876000 -> -6
  s21_decimal d1 = {{0x12375ca0, 0x91, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_77) {
  // 527684172347968.33071594967 -> 527684172347968
  s21_decimal d1 = {
      {0x3827dd7, 0xa156b6fe, 0x2ba625, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {{0xba57a40, 0x1dfed, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_78) {
  //-0.97156826096 -> 0
  s21_decimal d1 = {{0x9eff83f0, 0x16, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_79) {
  // 4804607176138328588.7893 -> 4804607176138328588
  s21_decimal d1 = {{0xe1509395, 0x95305bfa, 0xa2c, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {
      {0x53048a0c, 0x42ad64c5, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_80) {
  //-31 -> -31
  s21_decimal d1 = {{0x1f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_81) {
  // 5.5633 -> 5
  s21_decimal d1 = {{0xd951, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_82) {
  // 46516 -> 46516
  s21_decimal d1 = {{0xb5b4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xb5b4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_83) {
  // 8.985259223841966542762904 -> 8
  s21_decimal d1 = {
      {0x1d673398, 0xe0e81c9a, 0x76eb3, sign_and_exp_bits(0, 24)}};
  s21_decimal correct = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_84) {
  // 708334.8611412548607992 -> 708334
  s21_decimal d1 = {{0xed675ff8, 0xfd3580e3, 0x17f, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {{0xaceee, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_85) {
  //-473803427.8579534 -> -473803427
  s21_decimal d1 = {{0x921bbd4e, 0x10d537, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x1c3daaa3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_86) {
  // 479.8 -> 479
  s21_decimal d1 = {{0x12be, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x1df, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_87) {
  // 4640.8376202787344152 -> 4640
  s21_decimal d1 = {{0x39d4cf18, 0x840bac46, 0x2, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {{0x1220, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_88) {
  //-542.10 -> -542
  s21_decimal d1 = {{0xd3c2, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x21e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_89) {
  // 224559058.688919641 -> 224559058
  s21_decimal d1 = {{0x2c3fc859, 0x31dcb46, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal correct = {{0xd627fd2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_90) {
  // 6964741742861582460.9475786 -> 6964741742861582460
  s21_decimal d1 = {{0x8397cca, 0x106fc598, 0x399c6a, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0xdf99807c, 0x60a7bbb6, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_91) {
  // 97.5763 -> 97
  s21_decimal d1 = {{0xee393, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x61, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_92) {
  // 37390.5505282542863531119 -> 37390
  s21_decimal d1 = {{0xce3a3c6f, 0x75433233, 0x4f2d, sign_and_exp_bits(0, 19)}};
  s21_decimal correct = {{0x920e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_93) {
  // 83 -> 83
  s21_decimal d1 = {{0x53, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x53, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_94) {
  //-204217.64735400217 -> -204217
  s21_decimal d1 = {{0xa0bd7919, 0x488d7c, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {{0x31db9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_95) {
  //-82822878331456 -> -82822878331456
  s21_decimal d1 = {{0xb43e0240, 0x4b53, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xb43e0240, 0x4b53, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_96) {
  //-52.39297604177138036 -> -52
  s21_decimal d1 = {{0x79889174, 0x48b5b969, 0x0, sign_and_exp_bits(1, 17)}};
  s21_decimal correct = {{0x34, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_97) {
  //-24382842011369219.370049 -> -24382842011369219
  s21_decimal d1 = {{0xb5612c41, 0xcbe85781, 0x529, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {{0xccb3bf03, 0x56a010, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_98) {
  // 6.08059869333069075468224889 -> 6
  s21_decimal d1 = {
      {0x1e478979, 0x910d3d5f, 0x1f6f9af, sign_and_exp_bits(0, 26)}};
  s21_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_99) {
  //-7050061574.3082500000 -> -7050061574
  s21_decimal d1 = {{0x74be8fa0, 0xd264807d, 0x3, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {{0xa4376706, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_100) {
  //-475036427182469249 -> -475036427182469249
  s21_decimal d1 = {{0x1994f081, 0x697ab1d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1994f081, 0x697ab1d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_101) {
  // 4.0000000 -> 4
  s21_decimal d1 = {{0x2625a00, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_102) {
  //-147.0000000000 -> -147
  s21_decimal d1 = {{0x42d3ec00, 0x156, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {{0x93, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_103) {
  // 99999999999999999999999 -> 99999999999999999999999
  s21_decimal d1 = {{0xf67fffff, 0x2c7e14a, 0x152d, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xf67fffff, 0x2c7e14a, 0x152d, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_104) {
  // 0 -> 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_105) {
  // 0 -> 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_106) {
  // 0.00000 -> 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_107) {
  // 0.00000 -> 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_108) {
  // 79228162514264337593543950335 -> 79228162514264337593543950335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_109) {
  //-79228162514264337593543950335 -> -79228162514264337593543950335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_110) {
  // 7922816251426433759354.3950335 -> 7922816251426433759354
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0xf485787a, 0x7f29abca, 0x1ad, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_111) {
  //-79228162514264.337593543950335 -> -79228162514264
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {{0xbe7b9d58, 0x480e, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_truncate_112) {
  // Segmentation fault test
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 15)}};
  // s21_decimal correct = {{0xbe7b9d58, 0x480e, 0x0, sign_and_exp_bits(1, 0)}};
  // s21_decimal result;

  ck_assert_int_eq(s21_truncate(d1, NULL), S21_OK);
  // ASSERT_BITS_EQ
}
END_TEST

Suite *truncate_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "S21_TRUNCATE" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("tc");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_truncate_1);
  tcase_add_test(tc1_1, s21_truncate_2);
  tcase_add_test(tc1_1, s21_truncate_3);
  tcase_add_test(tc1_1, s21_truncate_4);
  tcase_add_test(tc1_1, s21_truncate_5);
  tcase_add_test(tc1_1, s21_truncate_6);
  tcase_add_test(tc1_1, s21_truncate_7);
  tcase_add_test(tc1_1, s21_truncate_8);
  tcase_add_test(tc1_1, s21_truncate_9);
  tcase_add_test(tc1_1, s21_truncate_10);
  tcase_add_test(tc1_1, s21_truncate_11);
  tcase_add_test(tc1_1, s21_truncate_12);
  tcase_add_test(tc1_1, s21_truncate_13);
  tcase_add_test(tc1_1, s21_truncate_14);
  tcase_add_test(tc1_1, s21_truncate_15);
  tcase_add_test(tc1_1, s21_truncate_16);
  tcase_add_test(tc1_1, s21_truncate_17);
  tcase_add_test(tc1_1, s21_truncate_18);
  tcase_add_test(tc1_1, s21_truncate_19);
  tcase_add_test(tc1_1, s21_truncate_20);
  tcase_add_test(tc1_1, s21_truncate_21);
  tcase_add_test(tc1_1, s21_truncate_22);
  tcase_add_test(tc1_1, s21_truncate_23);
  tcase_add_test(tc1_1, s21_truncate_24);
  tcase_add_test(tc1_1, s21_truncate_25);
  tcase_add_test(tc1_1, s21_truncate_26);
  tcase_add_test(tc1_1, s21_truncate_27);
  tcase_add_test(tc1_1, s21_truncate_28);
  tcase_add_test(tc1_1, s21_truncate_29);
  tcase_add_test(tc1_1, s21_truncate_30);
  tcase_add_test(tc1_1, s21_truncate_31);
  tcase_add_test(tc1_1, s21_truncate_32);
  tcase_add_test(tc1_1, s21_truncate_33);
  tcase_add_test(tc1_1, s21_truncate_34);
  tcase_add_test(tc1_1, s21_truncate_35);
  tcase_add_test(tc1_1, s21_truncate_36);
  tcase_add_test(tc1_1, s21_truncate_37);
  tcase_add_test(tc1_1, s21_truncate_38);
  tcase_add_test(tc1_1, s21_truncate_39);
  tcase_add_test(tc1_1, s21_truncate_40);
  tcase_add_test(tc1_1, s21_truncate_41);
  tcase_add_test(tc1_1, s21_truncate_42);
  tcase_add_test(tc1_1, s21_truncate_43);
  tcase_add_test(tc1_1, s21_truncate_44);
  tcase_add_test(tc1_1, s21_truncate_45);
  tcase_add_test(tc1_1, s21_truncate_46);
  tcase_add_test(tc1_1, s21_truncate_47);
  tcase_add_test(tc1_1, s21_truncate_48);
  tcase_add_test(tc1_1, s21_truncate_49);
  tcase_add_test(tc1_1, s21_truncate_50);
  tcase_add_test(tc1_1, s21_truncate_51);
  tcase_add_test(tc1_1, s21_truncate_52);
  tcase_add_test(tc1_1, s21_truncate_53);
  tcase_add_test(tc1_1, s21_truncate_54);
  tcase_add_test(tc1_1, s21_truncate_55);
  tcase_add_test(tc1_1, s21_truncate_56);
  tcase_add_test(tc1_1, s21_truncate_57);
  tcase_add_test(tc1_1, s21_truncate_58);
  tcase_add_test(tc1_1, s21_truncate_59);
  tcase_add_test(tc1_1, s21_truncate_60);
  tcase_add_test(tc1_1, s21_truncate_61);
  tcase_add_test(tc1_1, s21_truncate_62);
  tcase_add_test(tc1_1, s21_truncate_63);
  tcase_add_test(tc1_1, s21_truncate_64);
  tcase_add_test(tc1_1, s21_truncate_65);
  tcase_add_test(tc1_1, s21_truncate_66);
  tcase_add_test(tc1_1, s21_truncate_67);
  tcase_add_test(tc1_1, s21_truncate_68);
  tcase_add_test(tc1_1, s21_truncate_69);
  tcase_add_test(tc1_1, s21_truncate_70);
  tcase_add_test(tc1_1, s21_truncate_71);
  tcase_add_test(tc1_1, s21_truncate_72);
  tcase_add_test(tc1_1, s21_truncate_73);
  tcase_add_test(tc1_1, s21_truncate_74);
  tcase_add_test(tc1_1, s21_truncate_75);
  tcase_add_test(tc1_1, s21_truncate_76);
  tcase_add_test(tc1_1, s21_truncate_77);
  tcase_add_test(tc1_1, s21_truncate_78);
  tcase_add_test(tc1_1, s21_truncate_79);
  tcase_add_test(tc1_1, s21_truncate_80);
  tcase_add_test(tc1_1, s21_truncate_81);
  tcase_add_test(tc1_1, s21_truncate_82);
  tcase_add_test(tc1_1, s21_truncate_83);
  tcase_add_test(tc1_1, s21_truncate_84);
  tcase_add_test(tc1_1, s21_truncate_85);
  tcase_add_test(tc1_1, s21_truncate_86);
  tcase_add_test(tc1_1, s21_truncate_87);
  tcase_add_test(tc1_1, s21_truncate_88);
  tcase_add_test(tc1_1, s21_truncate_89);
  tcase_add_test(tc1_1, s21_truncate_90);
  tcase_add_test(tc1_1, s21_truncate_91);
  tcase_add_test(tc1_1, s21_truncate_92);
  tcase_add_test(tc1_1, s21_truncate_93);
  tcase_add_test(tc1_1, s21_truncate_94);
  tcase_add_test(tc1_1, s21_truncate_95);
  tcase_add_test(tc1_1, s21_truncate_96);
  tcase_add_test(tc1_1, s21_truncate_97);
  tcase_add_test(tc1_1, s21_truncate_98);
  tcase_add_test(tc1_1, s21_truncate_99);
  tcase_add_test(tc1_1, s21_truncate_100);
  tcase_add_test(tc1_1, s21_truncate_101);
  tcase_add_test(tc1_1, s21_truncate_102);
  tcase_add_test(tc1_1, s21_truncate_103);
  tcase_add_test(tc1_1, s21_truncate_104);
  tcase_add_test(tc1_1, s21_truncate_105);
  tcase_add_test(tc1_1, s21_truncate_106);
  tcase_add_test(tc1_1, s21_truncate_107);
  tcase_add_test(tc1_1, s21_truncate_108);
  tcase_add_test(tc1_1, s21_truncate_109);
  tcase_add_test(tc1_1, s21_truncate_110);
  tcase_add_test(tc1_1, s21_truncate_111);
  tcase_add_test(tc1_1, s21_truncate_112);

  return s1;
}
