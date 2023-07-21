#include "s21_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *             DIVISON FUNCTION TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(s21_div_0) {
  // 1.23 / 82984562288374516122014 = 0.000000000000000000000014822
  s21_decimal d1 = {{0x7b, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xdffd819e, 0x9a259238, 0x1192, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x39e6, 0x0, 0x0, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_1) {
  // 10915375798337 / 3446 = 3167549564.2301218804410911201
  s21_decimal d1 = {{0x6f18d841, 0x9ed, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xd76, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xf7bc89e1, 0x7f3532fa, 0x66595b1b, sign_and_exp_bits(0, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_2) {
  // 1604.4 / -90945925 = -0.0000176412522056375807932021
  s21_decimal d1 = {{0x3eac, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x56bb985, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x73b27675, 0x578c38ac, 0x255b, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_3) {
  //-936363361185715136 / 1920022760998376.595 = -487.68346928284505049284210911
  s21_decimal d1 = {{0x142a53c0, 0xcfea184, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x45f91493, 0x1aa54a87, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {
      {0xee23f0df, 0x689cc0d1, 0x9d943b28, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_4) {
  //-1553804936379786 / 1553804936379786 = -1
  s21_decimal d1 = {{0x67487d8a, 0x5852d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x67487d8a, 0x5852d, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_5) {
  //-17802741411947065606920 / -489970601828869254062
  //= 36.334305253205747164480067067
  s21_decimal d1 = {{0x8fb8308, 0x16aaef33, 0x3c5, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x4a1cabae, 0x8fb54263, 0x1a, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x14d4d5fb, 0x9058f4d8, 0x7567086a, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_6) {
  //-807.824147 / 2387.6445 = -0.3383351864148955173184282669
  s21_decimal d1 = {{0x30266b13, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x16c535d, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {
      {0x9efb202d, 0x11d52acc, 0xaeea4a0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_7) {
  //-692477181582072618875554101 / 8.65 = -80055165500817643800642092.6
  s21_decimal d1 = {
      {0xdf630935, 0x3bbfd902, 0x23ccdbf, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x361, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {
      {0xe62295be, 0x2d65ed8f, 0x2963368, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_8) {
  // 978946520 / 978946520 = 1
  s21_decimal d1 = {{0x3a5989d8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3a5989d8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_9) {
  //-433351160758.015891530 / 23175946207308 = -0.0186983157831704234706322603
  s21_decimal d1 = {{0x70bc184a, 0x7df498b7, 0x17, sign_and_exp_bits(1, 9)}};
  s21_decimal d2 = {{0x120a804c, 0x1514, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xc68fc4ab, 0x4c060236, 0x9aab39, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_10) {
  //-374674376532809.3309 / -9285897 = 40348754.302660187906456425265
  s21_decimal d1 = {{0x7cca607d, 0x33ff1b9a, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x8db109, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x78901331, 0x99f56aab, 0x825fb511, sign_and_exp_bits(0, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_11) {
  // 8660899 / 9436320389.8 = 0.0009178258730343475731229246
  s21_decimal d1 = {{0x8427a3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf87c393a, 0x15, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0xb203ea3e, 0x671adc83, 0x79792, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_12) {
  // 36.34811400000 / -45 = -0.8077358666666666666666666667
  s21_decimal d1 = {{0x4ba46f40, 0x34e, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0x2d, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x952aaaab, 0xb79c7144, 0x1a196f3a, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_13) {
  // 822461629542055259728472707 / -90592553 = -9078689167111288493.309960113
  s21_decimal d1 = {
      {0x29936a83, 0x46da9c22, 0x2a85306, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5665529, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x1c301fb1, 0xea463395, 0x1d55b735, sign_and_exp_bits(1, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_14) {
  //-76873749702186 / -76873749702186 = 1
  s21_decimal d1 = {{0x908b262a, 0x45ea, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x908b262a, 0x45ea, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_15) {
  // 0.1636916193927 / 2124807094541953951103 = 0.0000000000000000000000770383
  s21_decimal d1 = {{0x1fceea87, 0x17d, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {{0x8302657f, 0x2f9f3ac6, 0x73, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xbc14f, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_16) {
  //-2.2 / 4855973805776 = -0.0000000000004530502197897324
  s21_decimal d1 = {{0x16, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x9e97fed0, 0x46a, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xbe28e86c, 0x101877, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_17) {
  // 70069163675002884865606757 / 50773.4441 = 1380035664647828861103.5302409
  s21_decimal d1 = {
      {0xc2934465, 0xf95a4b3e, 0x39f5b8, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1e4369a9, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {
      {0xdb7ca09, 0xdbfcd326, 0x2c976330, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_18) {
  //-917284060949.3779823 / -21321453874 = 43.021646946315457545050522853
  s21_decimal d1 = {{0x3e27856f, 0x7f4c79ef, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0xf6db9132, 0x4, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xc6bc04e5, 0x27acb9e0, 0x8b02ac1a, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_19) {
  // 6944746.0679914679580636 / -9321 = -745.0644853547331786357257805
  s21_decimal d1 = {{0x565e37dc, 0xc11f83f7, 0xeb4, sign_and_exp_bits(0, 16)}};
  s21_decimal d2 = {{0x2469, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x40ceb64d, 0xd4ea291c, 0x1813076a, sign_and_exp_bits(1, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_20) {
  //-62057203626488541.72 / -62057203626488541.72 = 1
  s21_decimal d1 = {{0x5f17de9c, 0x561f25ca, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x5f17de9c, 0x561f25ca, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_21) {
  // 1.09247 / 3701850 = 0.0000002951146048597322960142
  s21_decimal d1 = {{0x1aabf, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0x387c5a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x7d1d0d0e, 0xfb60ef5b, 0x9f, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_22) {
  // 9976319617600274904647 / -586143686173546758 =
  // -17020.262868866702188526866945
  s21_decimal d1 = {{0x99393647, 0xd13f2b66, 0x21c, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xb9b65906, 0x8226693, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xcc029201, 0xef5afd4d, 0x36fed4da, sign_and_exp_bits(1, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_23) {
  //-8.39401383800980 / -904448 = 0.0000092808141960729638409284
  s21_decimal d1 = {{0x5d4e3094, 0x2fb6e, 0x0, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0xdcd00, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x63471444, 0x23b372ac, 0x13a7, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_24) {
  // 2.544 / -2.544 = -1
  s21_decimal d1 = {{0x9f0, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x9f0, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_25) {
  // 882.6 / -698010792541129928663 = -0.000000000000000001264450363
  s21_decimal d1 = {{0x227a, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xb2edefd7, 0xd6d87d98, 0x25, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x4b5dfb3b, 0x0, 0x0, sign_and_exp_bits(1, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_26) {
  // 54604787499249502186.9700868 / -709.63574314793127 =
  // -76947628450934075.606075096346
  s21_decimal d1 = {
      {0x80ab1704, 0x9e0dc875, 0x1c3ae22, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0xaf0678a7, 0xfc1cfe, 0x0, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {
      {0x66bebd1a, 0xb49c1722, 0xf8a19620, sign_and_exp_bits(1, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_27) {
  //-50672181748528124 / -2926219.5423 = 17316602878.231049396952829584
  s21_decimal d1 = {{0xb11d73fc, 0xb40614, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xd029aadf, 0x6, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {
      {0x90290e90, 0x8479307, 0x37f3f54b, sign_and_exp_bits(0, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_28) {
  //-3726057363.3272019475 / -671084298455941669776619307 =
  // 0.0000000000000000055522940589
  s21_decimal d1 = {{0xf276fa13, 0x518264d, 0x2, sign_and_exp_bits(1, 10)}};
  s21_decimal d2 = {
      {0x573d772b, 0xb720a96f, 0x22b1ba0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xed6cd6ad, 0xc, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_29) {
  //-3379000 / -1.4006398969023 = 2412468.7633653050211383420992
  s21_decimal d1 = {{0x338f38, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1e6f64bf, 0xcbd, 0x0, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {
      {0x1fa4a840, 0x25a47abe, 0x4df37951, sign_and_exp_bits(0, 22)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_30) {
  //-6735927200 / 5218641.350001250429647232388 =
  //-1290.7434614180539569190497276
  s21_decimal d1 = {{0x917e17a0, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x42489d84, 0x74675adf, 0x10dcc24a, sign_and_exp_bits(0, 21)}};
  s21_decimal correct = {
      {0x49986bfc, 0x7ed644e3, 0x29b4c798, sign_and_exp_bits(1, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_31) {
  // 6264.15 / -806358007670502238109107117 = -0.0000000000000000000000077684
  s21_decimal d1 = {{0x98eef, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0x791503ad, 0x2f955003, 0x29b00f3, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x12f74, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_32) {
  //-57849229300709000 / 5270000000 = -10977083.358768311195445920304
  s21_decimal d1 = {{0x4affb688, 0xcd8591, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3a1dd180, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xee3a8230, 0x41ad869d, 0x237807d1, sign_and_exp_bits(1, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_33) {
  //-7189003920673850117967786400 / -588904088810569509669 =
  // 12207427.418603488554744843737
  s21_decimal d1 = {
      {0x119331a0, 0x70a86b2a, 0x173a9acb, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2916ab25, 0xecaf9ca0, 0x1f, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x58bc8dd9, 0x62ace706, 0x2771bf4e, sign_and_exp_bits(0, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_34) {
  //-6619981505450.538457 / -776 = 8530904001.869250588917525773
  s21_decimal d1 = {{0xe408f5d9, 0x5bdee61a, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x308, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x7b9e6d0d, 0x9ac6d21a, 0x1b909930, sign_and_exp_bits(0, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_35) {
  //-5567777603666819990 / 658.2273986189159 = -8458744827925817.092703193404
  s21_decimal d1 = {{0x2eefbb96, 0x4d44b83b, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x16c2d767, 0x17628b, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal correct = {
      {0xa49b093c, 0xf2670a33, 0x1b54e8e3, sign_and_exp_bits(1, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_36) {
  // 65432149 / 145 = 451256.2
  s21_decimal d1 = {{0x3e66a55, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x91, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x44db32, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_37) {
  //-9087809410.9 / 178172724275663.57261030 = -0.0000510056151851818233124539
  s21_decimal d1 = {{0x28c1ab1d, 0x15, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x9e83aae6, 0xe05378ea, 0x3c5, sign_and_exp_bits(0, 8)}};
  s21_decimal correct = {
      {0xb4e856bb, 0x330ba3ea, 0x6c02, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_38) {
  // 7549042424598758983308753503 / 962735015663962075 =
  // 7841246346.890653798689419444
  s21_decimal d1 = {
      {0xdb113a5f, 0xd8c54f67, 0x18646be9, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5d7b07db, 0xd5c5265, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xa4a430b4, 0x36f2e22d, 0x19562080, sign_and_exp_bits(0, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_39) {
  //-3.14 / 485668 = -0.000006465321989507235395373
  s21_decimal d1 = {{0x13a, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x76924, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x7c8f372d, 0x7c5ddeb6, 0x15e, sign_and_exp_bits(1, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_40) {
  // 384514966691793927157 / 3 = 128171655563931309052.33333333
  s21_decimal d1 = {{0x6588fbf5, 0xd83794f5, 0x14, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x6ff91c55, 0x1140826b, 0x296a1c61, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_41) {
  //-484977.251 / -74.59 = 6501.9071055101220002681324574
  s21_decimal d1 = {{0x1ce82a63, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x1d23, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {
      {0xefd8041e, 0x8be7d2a1, 0xd21683d8, sign_and_exp_bits(0, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_42) {
  //-51197552.603 / -7025.7093302492695877256540000 =
  // 7287.1720414860273801752720032
  s21_decimal d1 = {{0xeb9ca7db, 0xb, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {
      {0xa344ef60, 0x8dd0dc51, 0xe3034e33, sign_and_exp_bits(1, 25)}};
  s21_decimal correct = {
      {0xd7c3b2a0, 0x53cfcf21, 0xeb761307, sign_and_exp_bits(0, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_43) {
  // 32376629511058 / 32376629511058 = 1
  s21_decimal d1 = {{0x45804392, 0x1d72, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x45804392, 0x1d72, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_44) {
  // 6820679168.086 / -6820679168.086 = -1
  s21_decimal d1 = {{0x1028b056, 0x634, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x1028b056, 0x634, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_45) {
  // 333013841522836206455.36 / -4697075680484921684121870774 =
  // -0.0000000708981213367326817386
  s21_decimal d1 = {{0xf8111aa0, 0x458b0034, 0x70d, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0xa977e1b6, 0xdb03f3cf, 0xf2d5476, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xd0f13c6a, 0x6f174136, 0x26, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_46) {
  // 2864.8408877934708 / 2864.8408877934708 = 1
  s21_decimal d1 = {{0x7a8ca874, 0x65c793, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {{0x7a8ca874, 0x65c793, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_47) {
  // 868245097.84784849637 / -868245097.84784849637 = -1
  s21_decimal d1 = {{0x1f874ae5, 0xb4ee9fa2, 0x4, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0x1f874ae5, 0xb4ee9fa2, 0x4, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_48) {
  //-475019509.70566342 / 87265554396042156527000 =
  //-0.0000000000000054433792690969
  s21_decimal d1 = {{0xd1bd16c6, 0xa8c2c5, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0x44834d98, 0xacd8ca7a, 0x127a, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xdae08b19, 0x3181, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_49) {
  // 7303765576514.9 / -11053282515996 = -0.6607779694353324997268839672
  s21_decimal d1 = {{0x6786f09d, 0x426d, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x8afa5c1c, 0xa0d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xf1719cf8, 0xff054038, 0x1559d3c6, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_50) {
  // 30 / -6159080.41054072 = -0.000004870857011163169762371
  s21_decimal d1 = {{0x1e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x44005778, 0x2302a, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal correct = {
      {0x159f2c43, 0xcb854bf, 0x108, sign_and_exp_bits(1, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_51) {
  // 81 / -937271.07420505546015901417 = -0.0000864211029543400599667373
  s21_decimal d1 = {{0x51, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x9c8806e9, 0xac9f3be6, 0x4d877c, sign_and_exp_bits(1, 20)}};
  s21_decimal correct = {
      {0x4d9f42ad, 0xf94a0773, 0xb700, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_52) {
  // 31149003085871019300000 / 2.4 = 12978751285779591375000
  s21_decimal d1 = {{0xb88194a0, 0x9741581b, 0x698, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x18, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x8ce0a898, 0x945b3a0b, 0x2bf, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_53) {
  //-69081218537552794 / -4449929037343 = 15524.116892165177668200047762
  s21_decimal d1 = {{0x9394fb9a, 0xf56d00, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1470861f, 0x40c, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x12d42492, 0x52d25d2, 0x32293f9f, sign_and_exp_bits(0, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_54) {
  //-7645.97448046 / 7645.97448046 = -1
  s21_decimal d1 = {{0x58f2d6e, 0xb2, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0x58f2d6e, 0xb2, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_55) {
  //-2.90933841559 / 237469571453289065303746 = -0.0000000000000000000000122514
  s21_decimal d1 = {{0xbd021e97, 0x43, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {{0xe0cb4ec2, 0x4052cd0d, 0x3249, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1de92, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_56) {
  // 702004859296161.9 / 201208700674 = 3488.93888258617591156305585
  s21_decimal d1 = {{0x6eb08053, 0x18f0b2, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xd8f91f02, 0x2e, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x4889eeb1, 0x94b248c1, 0x1209927, sign_and_exp_bits(0, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_57) {
  // 45885056282 / 45885056282 = 1
  s21_decimal d1 = {{0xaef6651a, 0xa, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xaef6651a, 0xa, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_58) {
  // 44735760 / 844.687461036 = 52961.316538465098163230881044
  s21_decimal d1 = {{0x2aa9d10, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xab4bcaac, 0xc4, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal correct = {
      {0xcbb83514, 0x6f502685, 0xab209302, sign_and_exp_bits(0, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_59) {
  //-455 / -944011134 = 0.0000004819858406458159422514
  s21_decimal d1 = {{0x1c7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3844777e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x2aea5c32, 0x48f8e3f8, 0x105, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_60) {
  //-52.4061248494870651 / -749408283969568.964452471 =
  // 0.0000000000000699300047390657
  s21_decimal d1 = {{0xcd15a07b, 0x745d6ed, 0x0, sign_and_exp_bits(1, 16)}};
  s21_decimal d2 = {{0xa6a5a077, 0x81257710, 0x9eb1, sign_and_exp_bits(1, 9)}};
  s21_decimal correct = {{0x7aea87c1, 0x27c02, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_61) {
  // 8.57 / -76139016803877803901679417 = -0.0000000000000000000000001126
  s21_decimal d1 = {{0x359, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0xa3817739, 0x5f198ed0, 0x3efb10, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x466, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_62) {
  //-3777702720971907342845018 / 138856595031575508 =
  //-27205785.365202645574016696456
  s21_decimal d1 = {{0xd90cc45a, 0xacc33d1f, 0x31ff5, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x6593cbd4, 0x1ed5156, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x25c60088, 0xdb39ebaf, 0x57e81923, sign_and_exp_bits(1, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_63) {
  //-388527.0120521570 / -923113308451225384690366 =
  // 0.0000000000000000004208876727
  s21_decimal d1 = {{0xf163df62, 0xdcda1, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal d2 = {{0xe59aa2be, 0x129e0477, 0xc37a, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xfade5cb7, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_64) {
  //-930563.633030238060000 / -930563.633030238060000 = 1
  s21_decimal d1 = {{0x504c3de0, 0x722a25e7, 0x32, sign_and_exp_bits(1, 15)}};
  s21_decimal d2 = {{0x504c3de0, 0x722a25e7, 0x32, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_65) {
  // 15765583408 / -49243.862542370921877336 = -320153.26568736989286302336797
  s21_decimal d1 = {{0xabb3b630, 0x3, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xe7118f58, 0x83e00d1e, 0xa6d, sign_and_exp_bits(1, 18)}};
  s21_decimal correct = {
      {0x39f1c71d, 0xeed101f8, 0x6772751a, sign_and_exp_bits(1, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_66) {
  // 975090 / -619926853067460 = -0.00000000157291137684253758
  s21_decimal d1 = {{0xee0f2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf7dd22c4, 0x233d1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xd3fcac3e, 0x22ecf74, 0x0, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_67) {
  //-2215 / 71543130565596321.09172777904 = -0.0000000000000309603449344325
  s21_decimal d1 = {{0x8a7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x31a563b0, 0xed9c6d47, 0x171de8b7, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {{0x2b9e9145, 0x11995, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_68) {
  //-90 / -2125.300 = 0.0423469627817249329506422623
  s21_decimal d1 = {{0x5a, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x206df4, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {
      {0x46340f5f, 0x85e6e618, 0x15e492e, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_69) {
  // 1866903863351 / -8549 = -218376870.20131009474792373377
  s21_decimal d1 = {{0xac244037, 0x1b2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2165, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x4765bc81, 0x76d79664, 0x468fb619, sign_and_exp_bits(1, 20)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_70) {
  //-27660894804812225586642203 / 7.07 = -3912432079888575047615587.4116
  s21_decimal d1 = {
      {0xffb3bd1b, 0x1caceb08, 0x16e16c, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2c3, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {
      {0xe09f6b44, 0x5bcc5918, 0x7e6ae130, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_71) {
  //-89 / 94501 = -0.0009417889757780340948773029
  s21_decimal d1 = {{0x59, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x17125, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x1deaa8a5, 0xd3a7e6bf, 0x7ca50, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_72) {
  //-40899438211107044307233.9794 / -40899438211107044307233.9794 = 1
  s21_decimal d1 = {
      {0x88d73f52, 0xe1868f11, 0x1524fed, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {
      {0x88d73f52, 0xe1868f11, 0x1524fed, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_73) {
  //-567.1 / -567.1 = 1
  s21_decimal d1 = {{0x1627, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x1627, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_74) {
  // 766400906472616335859474 / 8 = 95800113309077041982434.25
  s21_decimal d1 = {{0x66515f12, 0xad27ded0, 0xa24a, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xfef92461, 0x7472612c, 0x7eca5, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_75) {
  //-710710810054031521047517 / -710710810054031521047517 = 1
  s21_decimal d1 = {{0x3cc763dd, 0xb5d08ce3, 0x967f, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3cc763dd, 0xb5d08ce3, 0x967f, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_76) {
  //-918583888167 / -81371826493790230895 = 0.0000000112887215114570440922
  s21_decimal d1 = {{0xdfddc927, 0xd5, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xd716196f, 0x6942cd11, 0x4, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x6b1420da, 0x1e9ff40b, 0x6, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_77) {
  //-2967008198310386340146958957 / -4878161764793.574 =
  // 608222593134104.33759103918912
  s21_decimal d1 = {
      {0xbeefd26d, 0xb83289f2, 0x996406c, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8b25bce6, 0x1154a9, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {
      {0x8a5ba340, 0x27606975, 0xc486fe64, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_78) {
  //-4108005.171379081890126546 / 4678159.89268923467126327327 =
  //-0.8781241483000274248524198951
  s21_decimal d1 = {
      {0xa6725ad2, 0x6814f110, 0x365e7, sign_and_exp_bits(1, 18)}};
  s21_decimal d2 = {
      {0x1188c81f, 0x982d4af2, 0x182f7e3, sign_and_exp_bits(0, 20)}};
  s21_decimal correct = {
      {0x49297427, 0xa6417884, 0x1c5fac36, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_79) {
  //-387619030.74726455920907465 / -88114326471.0 =
  // 0.004399046628074004644672859
  s21_decimal d1 = {
      {0xf5d954c9, 0xf9e5eb7c, 0x201026, sign_and_exp_bits(1, 17)}};
  s21_decimal d2 = {{0x283b35c6, 0xcd, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0x56d8b55b, 0xcba93d5f, 0x3a388, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_80) {
  // 42.78008008080525353598654224 / -9414466 = -0.0000045440793010251727008188
  s21_decimal d1 = {
      {0x8ec91710, 0xd045c42e, 0xdd2af6e, sign_and_exp_bits(0, 26)}};
  s21_decimal d2 = {{0x8fa742, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x2b6e71bc, 0x59aee72f, 0x99f, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_81) {
  //-81520069116.7 / -38.58385658 = 2112802512.3065601028107491478
  s21_decimal d1 = {{0xcdbf63df, 0xbd, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0xe5fa4afa, 0x0, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal correct = {
      {0x4beb5896, 0xf013cc3d, 0x4444b158, sign_and_exp_bits(0, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_82) {
  //-1894527293756257 / -134219040753750 = 14.115190237666223498239028071
  s21_decimal d1 = {{0x25c9361, 0x6bb10, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x4e3f0856, 0x7a12, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x1ee22b67, 0x94415ff, 0x2d9bcfcc, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_83) {
  // 21157806922268416922217 / 86523217.150337 = 244533289666125.28696986292977
  s21_decimal d1 = {{0xdcbd269, 0xf78e10f0, 0x47a, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x419f8181, 0x4eb1, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {
      {0x4bf1d2f1, 0x8154d93d, 0x4f0351d3, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_84) {
  //-871898855958966111 / 814903608 = -1069941091.6818104344434317439
  s21_decimal d1 = {{0xd580ef5f, 0xc199b63, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x30927138, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x4046187f, 0x4371682, 0x22925864, sign_and_exp_bits(1, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_85) {
  //-36071.76761 / 57.86960913 = -623.32834370744262879039770698
  s21_decimal d1 = {{0xd7012639, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {{0x58ee0411, 0x1, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal correct = {
      {0x5c74d04a, 0x18d52859, 0xc968831a, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_86) {
  // 8946172666 / 1151207336292921 = 0.0000077711220072729584920814
  s21_decimal d1 = {{0x153bc2fa, 0x2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5857b239, 0x41704, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2484e8ee, 0xbbd28c75, 0x1074, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_87) {
  // 6075392.54756896 / 35923689.686247 = 0.1691193917058820100578642757
  s21_decimal d1 = {{0xc1778620, 0x2288d, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0x22c344e7, 0x20ac, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {
      {0xcb788b45, 0xf2cf11eb, 0x576ec3d, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_88) {
  // 189154947021315818458657575 / 189154947021315818458657575 = 1
  s21_decimal d1 = {
      {0xbb7f3327, 0x398f69ab, 0x9c771e, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xbb7f3327, 0x398f69ab, 0x9c771e, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_89) {
  // 428.61644232325 / 24898552151474733 = 0.0000000000000172145127040193
  s21_decimal d1 = {{0x81143685, 0x26fb, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0xec69022d, 0x587519, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xa925a4c1, 0x9c90, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_90) {
  // 59.9322024137560092811804416 / -2.5 = -23.97288096550240371247217664
  s21_decimal d1 = {
      {0x60f13f00, 0x787e9ea, 0x1efbf60, sign_and_exp_bits(0, 25)}};
  s21_decimal d2 = {{0x19, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0x83c4fc00, 0x1e1fa7a9, 0x7befd80, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_91) {
  //-248695522.0998138645688349012 / -6.29 = 39538238.807601568293932416725
  s21_decimal d1 = {
      {0x23a7f154, 0xac8c68f2, 0x8092940, sign_and_exp_bits(1, 19)}};
  s21_decimal d2 = {{0x275, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {
      {0x6af6bed5, 0x9296e622, 0x7fc143bc, sign_and_exp_bits(0, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_92) {
  // 779422535088488462119075 / -2520.895 = -309184847083471728143.80408545
  s21_decimal d1 = {{0x8de770a3, 0x948df967, 0xa50c, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x26773f, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {
      {0x31e11ee1, 0x89991e0c, 0x63e72bce, sign_and_exp_bits(1, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_93) {
  // 1407494087221.613932 / 1407494087221.613932 = 1
  s21_decimal d1 = {{0x444e956c, 0x13886c6a, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0x444e956c, 0x13886c6a, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_94) {
  //-653057679229472846459 / 7244318711 = -90147563253.65001551751855275
  s21_decimal d1 = {{0x19b9b27b, 0x66fef336, 0x23, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xafcb87f7, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2316bcab, 0x9e919486, 0x1d20d4e7, sign_and_exp_bits(1, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_95) {
  // 91416429242.65 / -391679877625781977034174 = -0.000000000000233395776665328
  s21_decimal d1 = {{0x746110e9, 0x850, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xb5132dbe, 0x23af3b7, 0x52f1, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xb05c36f0, 0xd445, 0x0, sign_and_exp_bits(1, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_96) {
  //-915.52314243237355 / -1213198570383861591850029 =
  // 0.0000000000000000000007546359
  s21_decimal d1 = {{0x40d545eb, 0x1454258, 0x0, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0xf3443c2d, 0xa0541a9c, 0x100e7, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x7325f7, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_97) {
  //-2318703012640041692433170230 / 8836658.430518246277586 =
  //-262395908008866649138.2961154
  s21_decimal d1 = {
      {0x36fb3f36, 0x2ec234f9, 0x77dfc76, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xf4e881d2, 0x94547ee, 0x1df, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {
      {0x29fc9402, 0xc1dbc8da, 0x87a7cf2, sign_and_exp_bits(1, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_98) {
  //-386387 / -9677 = 39.928386896765526506148599773
  s21_decimal d1 = {{0x5e553, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x25cd, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xac6217dd, 0xdda1921f, 0x8103fcce, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_99) {
  //-823104377751102162198841 / 42.3333230261318458 =
  //-19443415232085840120053.949311
  s21_decimal d1 = {{0xf6e3e139, 0x93e5eaba, 0xae4c, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x7b58333a, 0x5dffb54, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0xd24ae37f, 0xc21d6170, 0x3ed33753, sign_and_exp_bits(1, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_100) {
  // 73946.9 / 4409125650071275113355380539 = 0.0000000000000000000000167713
  s21_decimal d1 = {{0xb488d, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {
      {0x15e7873b, 0x6dae5eb5, 0xe3f24ac, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x28f21, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_101) {
  // 0.9454815926846 / -0.9454815926846 = -1
  s21_decimal d1 = {{0x5ef1da3e, 0x899, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {{0x5ef1da3e, 0x899, 0x0, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_102) {
  // 0.33506 / 0.33506 = 1
  s21_decimal d1 = {{0x82e2, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0x82e2, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_103) {
  // 1176324195.20080000 / 380958021.79541 = 3.087805290611609917499595987
  s21_decimal d1 = {{0xf3906880, 0x1a1ea0f, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0xdec19fd5, 0x22a5, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0xdd135cd3, 0x36f46c2b, 0x9fa2c34, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_104) {
  //-4068287766001617741159681111 / -7.892 = 515495155347392009776948949.7
  s21_decimal d1 = {
      {0x8dc14c57, 0xb5b2adc9, 0xd253571, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1ed4, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {
      {0x64dc0459, 0xaaacb017, 0x10a81373, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_105) {
  // 5097509.55604 / 5097509.55604 = 1
  s21_decimal d1 = {{0xaf864e54, 0x76, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0xaf864e54, 0x76, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_106) {
  //-549615474704400 / -590453736444.689 = 930.8357975915450215811885995
  s21_decimal d1 = {{0x53220010, 0x1f3df, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xb9379311, 0x21903, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {
      {0xd201abab, 0xfcee9052, 0x1e13b178, sign_and_exp_bits(0, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_107) {
  // 517651129 / 723.268581296246453517165 = 715710.79179502367487294759404
  s21_decimal d1 = {{0x1edabab9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x31b13b6d, 0x77e637c2, 0x9928, sign_and_exp_bits(0, 21)}};
  s21_decimal correct = {
      {0x9c34e1ec, 0xad6bcb29, 0xe7423588, sign_and_exp_bits(0, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_108) {
  // 39 / 5.1535279 = 7.567631485996224062355420643
  s21_decimal d1 = {{0x27, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3125daf, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0x753835e3, 0xe264258f, 0x1873cc4c, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_109) {
  // 921777766852201127 / -6953560234182683 = -132.56198778876994845987036854
  s21_decimal d1 = {{0xc3140aa7, 0xccacffe, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xe7aec81b, 0x18b439, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x268fdeb6, 0xbf76cbe8, 0x2ad54547, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_110) {
  //-62514801612409.881335766469 / 57786 = -1081832997.8266341559506882117
  s21_decimal d1 = {
      {0x95191dc5, 0x2f9fe87f, 0x33b606, sign_and_exp_bits(1, 12)}};
  s21_decimal d2 = {{0xe1ba, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xd4fcce45, 0x414c5b8a, 0x22f4b67b, sign_and_exp_bits(1, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_111) {
  // 97774541505943947333485 / -215.24741068 = -454242590872796032899.92524244
  s21_decimal d1 = {{0xebb64f6d, 0x5e570bee, 0x14b4, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2f97bcc, 0x5, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal correct = {
      {0x88e4f1d4, 0x4c74343b, 0x92c61103, sign_and_exp_bits(1, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_112) {
  //-79191144919106808564140 / -860885727535902 = 91987986.77470728060473561424
  s21_decimal d1 = {{0x8179c9ac, 0xf5e7cb42, 0x10c4, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x93fb631e, 0x30ef8, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x9e89d150, 0x84be3681, 0x1db91163, sign_and_exp_bits(0, 20)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_113) {
  //-467215.056 / -50590 = 9.235324293338604467286024906
  s21_decimal d1 = {{0x1bd922d0, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0xc59e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x5ae5a2ca, 0x1f4ea14b, 0x1dd747fd, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_114) {
  //-545.1527983112216438576 / -6293.6 = 0.0866201853170239042610906318
  s21_decimal d1 = {{0x195ce730, 0x87260935, 0x127, sign_and_exp_bits(1, 19)}};
  s21_decimal d2 = {{0xf5d8, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0xb8dc4ce, 0x8d084055, 0x2cc8160, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_115) {
  // 133338499259792558 / -133338499259792558 = -1
  s21_decimal d1 = {{0x9b437cae, 0x1d9b6a8, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x9b437cae, 0x1d9b6a8, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_116) {
  //-17791162113763129117.20973 / -17791162113763129117.20973 = 1
  s21_decimal d1 = {{0xe838f20d, 0x15445514, 0x178be, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {{0xe838f20d, 0x15445514, 0x178be, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_117) {
  //-7 / -7 = 1
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_118) {
  // 83439 / 30252036180551702598931 = 0.0000000000000000027581283951
  s21_decimal d1 = {{0x145ef, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x132d513, 0xf756c00e, 0x667, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x6bf8fe6f, 0x6, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_119) {
  // 29.83764054612909894 / 29.83764054612909894 = 1
  s21_decimal d1 = {{0x58c81f46, 0x29687599, 0x0, sign_and_exp_bits(0, 17)}};
  s21_decimal d2 = {{0x58c81f46, 0x29687599, 0x0, sign_and_exp_bits(0, 17)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_120) {
  // 9.150000000 / -88300 = -0.0001036240090600226500566251
  s21_decimal d1 = {{0x2161eb80, 0x2, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x158ec, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xea62dceb, 0xb018659a, 0xdb6e, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_121) {
  //-90958491 / -90958491 = 1
  s21_decimal d1 = {{0x56bea9b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x56bea9b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_122) {
  //-297937189948821707571041290 / 327962173975534167201715266 =
  //-0.9084498566930700059041554851
  s21_decimal d1 = {
      {0x1867940a, 0x6e2a8fdf, 0xf672a7, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x69249442, 0x136c07a7, 0x10f48b1, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xf1f361a3, 0x1c423f01, 0x1d5a8566, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_123) {
  // 9 / 4120234183767088970427 = 0.0000000000000000000021843419
  s21_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2ae03abb, 0x5bbc5833, 0xdf, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x14d4ddb, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_124) {
  //-610143740526 / -275752772575 = 2.2126477091360937153035985209
  s21_decimal d1 = {{0xf66a26e, 0x8e, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x342563df, 0x40, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x279f6139, 0x985fec2b, 0x477e97c6, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_125) {
  // 489631.373315 / 7 = 69947.339045
  s21_decimal d1 = {{0x4dd803, 0x72, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x492fb125, 0x10, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_126) {
  // 5095497 / 366568481007761563600000000 = 0.0000000000000000000139005323
  s21_decimal d1 = {{0x4dc049, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x7d2b9400, 0x2c756569, 0x12f37e5, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x8490d8b, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_127) {
  // 723127275483807867 / 4197000000 = 172296229.56488155039313795568
  s21_decimal d1 = {{0xfe9bc07b, 0xa09106c, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xfa292340, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x70cd99f0, 0x6ca98b0, 0x37ac0294, sign_and_exp_bits(0, 20)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_128) {
  //-96.93566 / -2756470738691787 = 0.0000000000000351665840813552
  s21_decimal d1 = {{0x93e97e, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {{0xdb36a6cb, 0x9cafe, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x958575f0, 0x13fd6, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_129) {
  //-5692.2962188745978564 / -96 = 59.294752279943727670833333333
  s21_decimal d1 = {{0x173232c4, 0x15f6fc85, 0x3, sign_and_exp_bits(1, 16)}};
  s21_decimal d2 = {{0x60, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xcab64455, 0xf1fb454a, 0xbf977831, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_130) {
  // 61505536436836500 / 696322457737333258338934985 =
  // 0.0000000000883291006248682806
  s21_decimal d1 = {{0xa3099894, 0xda82f5, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xaf23a0c9, 0x124b6856, 0x23ffc04, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x84c00536, 0xc42147d, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_131) {
  // 0.3 / 729966335675 = 0.0000000000004109778565645633
  s21_decimal d1 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xf56256bb, 0xa9, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x6382c541, 0xe99d2, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_132) {
  // 1012227.8885646866120306059 / 935481726591617000000000 =
  // 0.0000000000000000010820391888
  s21_decimal d1 = {{0xc61ed8b, 0xd681abce, 0x85f79, sign_and_exp_bits(0, 19)}};
  s21_decimal d2 = {{0x7953ca00, 0x90e65477, 0xc618, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x84f213d0, 0x2, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_133) {
  // 9820358114650574345385 / 979 = 10031009310164018738.901940756
  s21_decimal d1 = {{0x9848d4a9, 0x5cd89ac9, 0x214, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3d3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xa279fa14, 0x50aae2d5, 0x206974d8, sign_and_exp_bits(0, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_134) {
  //-528572415668615759 / 498817067379.77553460017552 =
  //-1059651.8247564009688607673827
  s21_decimal d1 = {{0xc1ff7a4f, 0x755ddcf, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x5d9a3990, 0xbd99ed8f, 0x2942dc, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {
      {0xb092cde3, 0x3d53c525, 0x223d3c05, sign_and_exp_bits(1, 22)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_135) {
  //-5264571.0369346352431 / 5264571.0369346352431 = -1
  s21_decimal d1 = {{0xe8fcf52f, 0xda9b22a6, 0x2, sign_and_exp_bits(1, 13)}};
  s21_decimal d2 = {{0xe8fcf52f, 0xda9b22a6, 0x2, sign_and_exp_bits(0, 13)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_136) {
  // 730.053 / -3730085771976014268215 = -0.0000000000000000001957201643
  s21_decimal d1 = {{0xb23c5, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x510b8737, 0x3556bec5, 0xca, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x74a886eb, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_137) {
  //-638953021.3017551354041748623 / 7969354531016647966 =
  //-0.0000000000801762575394225944
  s21_decimal d1 = {
      {0x51704c8f, 0xe7e08881, 0x14a54ba6, sign_and_exp_bits(1, 19)}};
  s21_decimal d2 = {{0xf665a51e, 0x6e98d5b8, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x7c933f18, 0xb206ed0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_138) {
  //-85213.5012 / 6221476135.19553763428640 = -0.000013696669302955027036666
  s21_decimal d1 = {{0x32ca8c64, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x9fff4920, 0xb090c8b4, 0x83be, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {
      {0x378179fa, 0x7f7862f9, 0x2e6, sign_and_exp_bits(1, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_139) {
  //-8831.64084 / 3585890161864428233930.20626 = -0.0000000000000000024628866031
  s21_decimal d1 = {{0x34a403b4, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {
      {0x65a30ad2, 0x84d9308d, 0x1289e2d, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0xbbfeabef, 0x5, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_140) {
  //-260239314513885152892057 / 709451535024602.29279600 =
  //-366817607.21662347057517538077
  s21_decimal d1 = {{0xb2535499, 0x99fc6f65, 0x371b, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x66015f70, 0xf1c94af4, 0xf05, sign_and_exp_bits(0, 8)}};
  s21_decimal correct = {
      {0xfdffab1d, 0x4040c13c, 0x768670f9, sign_and_exp_bits(1, 20)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_141) {
  //-750958671879459302653 / -750958671879459302653 = 1
  s21_decimal d1 = {{0x264becfd, 0xb5a52553, 0x28, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x264becfd, 0xb5a52553, 0x28, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_142) {
  // 29.7378 / 29.7378 = 1
  s21_decimal d1 = {{0x489a2, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x489a2, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_143) {
  // 376423 / 247356446835773768118818574 = 0.0000000000000000000015217837
  s21_decimal d1 = {{0x5be67, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xef07d70e, 0xda14f13d, 0xcc9bc3, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xe834ad, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_144) {
  // 30223.4 / 350108784315157009 = 0.0000000000000863257403241669
  s21_decimal d1 = {{0x49c9a, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x99d94a11, 0x4dbd615, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xc6deb4c5, 0x31120, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_145) {
  // 6199.63 / 281559327265153767420357484 = 0.0000000000000000000000220189
  s21_decimal d1 = {{0x975bb, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0xff0e6b6c, 0xb718c753, 0xe8e681, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x35c1d, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_146) {
  //-164063530839.32815046325590000 / 164063530839.32815046325590000 = -1
  s21_decimal d1 = {
      {0xbb6c57f0, 0xcee6e51a, 0x35030466, sign_and_exp_bits(1, 17)}};
  s21_decimal d2 = {
      {0xbb6c57f0, 0xcee6e51a, 0x35030466, sign_and_exp_bits(0, 17)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_147) {
  //-2700789.362910 / 4.5 = -600175.41398
  s21_decimal d1 = {{0xd39730de, 0x274, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x2d, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0xf9530116, 0xd, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_148) {
  // 501699626887378889271040 / -95.6099 = -5247360648712935472906.4667989
  s21_decimal d1 = {{0xaa0ae700, 0x30f71786, 0x6a3d, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xe96c3, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {
      {0xdae69b55, 0x93232906, 0xa98d2663, sign_and_exp_bits(1, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_149) {
  //-9 / 630906315420510079 = -0.0000000000000000142651924383
  s21_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8130a77f, 0x8c16df3, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x36b79f9f, 0x21, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_150) {
  // 79282.2524941 / 5.4897 = 14442.000927937774377470535731
  s21_decimal d1 = {{0x97e7ac0d, 0xb8, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0xd671, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {
      {0xb5b42833, 0xe2e0efb, 0x2eaa24a7, sign_and_exp_bits(0, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_151) {
  // 196044172000000 / 8870785963800000 = 0.0220999777020907947520869932
  s21_decimal d1 = {{0x173b7b00, 0xb24d, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xce4035c0, 0x1f83ee, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xddac62c, 0xeb120a50, 0xb6ce85, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_152) {
  // 6237389980802080 / 4065088752958712008284007961 =
  // 0.0000000000015343797786117934
  s21_decimal d1 = {{0x86219c20, 0x1628df, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xb56b6e19, 0xdd7e7c87, 0xd229006, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x508c072e, 0x36831a, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_153) {
  // 5.863000 / 3664530562.869007368335262 = 0.0000000015999320784514846775
  s21_decimal d1 = {{0x597658, 0x0, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {
      {0x264c2f9e, 0x99911654, 0x307fe, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {
      {0x48881037, 0xde09017c, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_154) {
  // 33097889370036758917547 / -3739016020 = -8852031976593.873731930947972
  s21_decimal d1 = {{0x3a6831ab, 0x3d7c4dea, 0x702, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xdedcdb54, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x77ce0184, 0xff287daa, 0x1c9a3aae, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_155) {
  //-83167282543744 / -91143953 = 912482.7243749675856170074168
  s21_decimal d1 = {{0xe4553c80, 0x4ba3, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x56ebf11, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x56804038, 0xfb8f234, 0x1d7be154, sign_and_exp_bits(0, 22)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_156) {
  // 17129875452 / -6052284502568759719197 = -0.0000000000028303156344896872
  s21_decimal d1 = {{0xfd0527fc, 0x3, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x6cabf51d, 0x1851f0b5, 0x148, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1bf5bd68, 0x648d92, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_157) {
  //-6.80 / 97.97225252531 = -0.0694074069415041624189515256
  s21_decimal d1 = {{0x2a8, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x182186b3, 0x8e9, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {
      {0x6f0535f8, 0xb23f8bf9, 0x23e1fe6, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_158) {
  // 234996 / -6648170.7585912280992184 = -0.0353474675265104831656186362
  s21_decimal d1 = {{0x395f4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x4db849b8, 0xfb07ee34, 0xe13, sign_and_exp_bits(1, 16)}};
  s21_decimal correct = {
      {0x290751fa, 0x8ac3e72c, 0x124632c, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_159) {
  //-67103952322898 / -67103952322898 = 1
  s21_decimal d1 = {{0xdb3dc152, 0x3d07, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xdb3dc152, 0x3d07, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_160) {
  //-2188880310727408653614365 / -128280.7912926337778169848358 =
  // 17063196201636619838.87373136
  s21_decimal d1 = {{0xb606bd1d, 0x707d2da8, 0x1cf83, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x8276a226, 0x4dc6ec12, 0x4251d24, sign_and_exp_bits(1, 22)}};
  s21_decimal correct = {
      {0xc667b350, 0xf4f11df1, 0x5836f3b, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_161) {
  //-3038218461405263537 / -6599.10191 = 460398778931005.10354143023077
  s21_decimal d1 = {{0xee1836b1, 0x2a29eb97, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x27556e2f, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0x3be58fe5, 0xa222f852, 0x94c34b5d, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_162) {
  // 67431220997209412996240 / 486216 = 138685730204702052.16660907909
  s21_decimal d1 = {{0x98a60c90, 0x742d370a, 0xe47, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x76b48, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x4a8be785, 0xe74413e1, 0x2ccfd091, sign_and_exp_bits(0, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_163) {
  //-96954927 / 7905.6696055 = -12263.974063948756807175680294
  s21_decimal d1 = {{0x5c76a2f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x682572f7, 0x12, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0x934cb126, 0x2c055150, 0x27a08586, sign_and_exp_bits(1, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_164) {
  //-316107792.257 / -6379953029368079 = 0.0000000495470406759890856894
  s21_decimal d1 = {{0x997e1f81, 0x49, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x91ffc90f, 0x16aa88, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x5998abbe, 0xdc087dd5, 0x1a, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_165) {
  // 3564.2 / -36423364982654467406665570.0 = -0.0000000000000000000000978548
  s21_decimal d1 = {{0x8b3a, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {
      {0x60dfe9d4, 0xb8c2326c, 0x12d4979, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0xeee74, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_166) {
  // 890768872200000000000000 / 890768872200000000000000 = 1
  s21_decimal d1 = {{0x89588000, 0xad64ea25, 0xbca0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x89588000, 0xad64ea25, 0xbca0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_167) {
  // 2 / -9493358674892775.185007042327 = -0.00000000000000021067359493
  s21_decimal d1 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x34a8df17, 0xf9a2f5c4, 0x1eacb8e4, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {{0xe7b66505, 0x4, 0x0, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_168) {
  // 921394426791 / 921394426791 = 1
  s21_decimal d1 = {{0x876333a7, 0xd6, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x876333a7, 0xd6, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_169) {
  // 92.8 / -44748597292800519.800000 = -0.0000000000000020738080211272
  s21_decimal d1 = {{0x3a0, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x8d9184c0, 0xd389b592, 0x979, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {{0x75e78148, 0x12dc, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_170) {
  // 6903654960075556.545705926 / 41857182756951247086049 =
  // 0.0000001649335790266262601036
  s21_decimal d1 = {{0x774937c6, 0xe2a2611d, 0x5b5e7, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x9cb4e1e1, 0x1519bc96, 0x8dd, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xec1bd4c, 0x6921d2b1, 0x59, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_171) {
  // 7.9 / 7.9 = 1
  s21_decimal d1 = {{0x4f, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x4f, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_172) {
  //-5.6000000 / -57758399.408809 = 0.0000000969555953301905066423
  s21_decimal d1 = {{0x3567e00, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0xece12aa9, 0x3487, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {
      {0xb945c9b7, 0x8f4ab299, 0x34, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_173) {
  // 466340.601371002127515638168 / 33052.692 = 14.10900514157824504931816652
  s21_decimal d1 = {
      {0xddbfd998, 0xa7fecf96, 0x181bf76, sign_and_exp_bits(0, 21)}};
  s21_decimal d2 = {{0x1f85814, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {
      {0x949814cc, 0x216b29b6, 0x48f11ce, sign_and_exp_bits(0, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_174) {
  //-9620.8 / -61770.08443471440352932801 = 0.1557517702629716691253867041
  s21_decimal d1 = {{0x177d0, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {
      {0xd40473c1, 0x4c772fea, 0x51c08, sign_and_exp_bits(1, 20)}};
  s21_decimal correct = {
      {0x5daa3221, 0xd8028682, 0x5085933, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_175) {
  // 6.15346243 / -83.567803816000000 = -0.0736343681299645463450670132
  s21_decimal d1 = {{0x24ad7043, 0x0, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0x8d1cba00, 0x128e479, 0x0, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {
      {0x90ecd434, 0xf2b3912a, 0x26116d6, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_176) {
  //-92188575213600.6 / -94.7709820845989186 = 972751080402.5108712175835381
  s21_decimal d1 = {{0x40c79146, 0x34673, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x95ac9d42, 0xd26f10f, 0x0, sign_and_exp_bits(1, 16)}};
  s21_decimal correct = {
      {0x35d218f5, 0x547ba9a1, 0x1f6e6889, sign_and_exp_bits(0, 16)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_177) {
  // 52750606813.365166 / -31.8 = -1658824113.6278354088050314465
  s21_decimal d1 = {{0xbccc03ae, 0xbb6865, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0x13e, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0x49c44ce1, 0xe22145e5, 0x359978b1, sign_and_exp_bits(1, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_178) {
  //-736493911249033063 / 736493911249033063 = -1
  s21_decimal d1 = {{0x673c9767, 0xa388d4f, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x673c9767, 0xa388d4f, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_179) {
  //-468630759469.175606339682 / -468630759469.175606339682 = 1
  s21_decimal d1 = {{0xea77e862, 0x863d7909, 0x633c, sign_and_exp_bits(1, 12)}};
  s21_decimal d2 = {{0xea77e862, 0x863d7909, 0x633c, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_180) {
  //-4.99 / -4.99 = 1
  s21_decimal d1 = {{0x1f3, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x1f3, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_181) {
  //-4.71 / 14.02122 = -0.3359194135745676909712564242
  s21_decimal d1 = {{0x1d7, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x15650a, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0x529ce012, 0xfd2217d6, 0xadaa906, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_182) {
  //-5.84 / -684124136.513236467124 = 0.000000008536462446369201294
  s21_decimal d1 = {{0x248, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x864d7db4, 0x16212d83, 0x25, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {
      {0xea4c5c8e, 0x76779b5d, 0x0, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_183) {
  // 316.8455080162273339637400000 / -4026277397294619128372033 =
  // -0.0000000000000000000000786944
  s21_decimal d1 = {
      {0x7b3a81c0, 0x11157239, 0xa3ce276, sign_and_exp_bits(0, 25)}};
  s21_decimal d2 = {{0x23c61b41, 0xef60038d, 0x35498, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xc0200, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_184) {
  //-4575603657313318465 / -86.213725598170905 = 53072798160231619.25333718386
  s21_decimal d1 = {{0xa3237641, 0x3f7fcf48, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x390abf19, 0x1324aed, 0x0, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {
      {0xc5f49572, 0x53774b19, 0x11261437, sign_and_exp_bits(0, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_185) {
  // 4 / -8495135416841.160962355815926 = -0.0000000000004708577089978118
  s21_decimal d1 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x4004e5f6, 0xb992301a, 0x1b7302e5, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {{0x8d87f06, 0x10ba6d, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_186) {
  // 20786085820010973 / 93447 = 222437165666.21692510192943594
  s21_decimal d1 = {{0xbd9291dd, 0x49d8d5, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x16d07, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xcf2a41ea, 0x48be3375, 0x47df9233, sign_and_exp_bits(0, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_187) {
  //-519252549525161.82 / -519252549525161.82 = 1
  s21_decimal d1 = {{0x8850fa56, 0xb879be, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x8850fa56, 0xb879be, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_188) {
  // 28.017 / 69476072765597075677228 = 0.0000000000000000000004032611
  s21_decimal d1 = {{0x6d71, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0xca0a02c, 0x4e32104d, 0xeb6, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x3d8863, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_189) {
  //-65.56 / 65.56 = -1
  s21_decimal d1 = {{0x199c, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x199c, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_190) {
  // 186280381659280255280997398 / 4526615478501.05602945 =
  // 41152243335889.701482648507281
  s21_decimal d1 = {
      {0xc847e416, 0xb96d1a58, 0x9a1667, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x4c07c381, 0x89f0df77, 0x18, sign_and_exp_bits(0, 8)}};
  s21_decimal correct = {
      {0xfb231391, 0x5f06198b, 0x84f8567d, sign_and_exp_bits(0, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_191) {
  // 988944163 / 161118261419713706702956062 = 0.0000000000000000061380017031
  s21_decimal d1 = {{0x3af21723, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x318661e, 0x73f25f35, 0x85461e, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x4a88bb87, 0xe, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_192) {
  // 3254119120518051336861662642 / -58.5943 = -55536445021410808506316529.799
  s21_decimal d1 = {
      {0x9e4e3db2, 0xffe6bc9f, 0xa83be86, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x8f0d7, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {
      {0x9908a087, 0x377e2878, 0xb372abad, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_193) {
  //-3.58 / -87020617432 = 0.0000000000411396759256218558
  s21_decimal d1 = {{0x166, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x42d53ed8, 0x14, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x4136bbbe, 0x5b5932c, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_194) {
  //-87438322 / -87438322 = 1
  s21_decimal d1 = {{0x53633f2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x53633f2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_195) {
  // 998012080670248973972000000 / -296355691768141818 =
  // -3367615700.9700972035778626921
  s21_decimal d1 = {
      {0x696bcd00, 0x4d2d57b0, 0x3398947, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x770157fa, 0x41cddee, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xbcb54569, 0x8b46045b, 0x6cd043a1, sign_and_exp_bits(1, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_196) {
  //-66660030.573 / 73942328.68581328189842475 = -0.9015138116117990521173998327
  s21_decimal d1 = {{0x853f586d, 0xf, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {
      {0x712ae42b, 0x2ac071f5, 0x61dca, sign_and_exp_bits(0, 17)}};
  s21_decimal correct = {
      {0x70007af7, 0x89a029e3, 0x1d2125c0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_197) {
  // 35.51654940330176635 / -3422669961171885988101.8 =
  // -0.0000000000000000000103768549
  s21_decimal d1 = {{0xcb24307b, 0x314a0359, 0x0, sign_and_exp_bits(0, 17)}};
  s21_decimal d2 = {{0x26dffa3a, 0x6edfe408, 0x73f, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x62f61e5, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_198) {
  // 6606221.45100000 / -638874 = -10.34041368251016632387606946
  s21_decimal d1 = {{0x144a18e0, 0x258d5, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0x9bf9a, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xa78d99a2, 0xe516f909, 0x35756c6, sign_and_exp_bits(1, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_199) {
  // 74474357367458226149 / 169516196263152810207317351 =
  // 0.0000004393347597998603595724
  s21_decimal d1 = {{0x92d7dfe5, 0x98a1171, 0x4, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x5a1d8d67, 0x69ba5556, 0x8c3873, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x326b6fcc, 0x29f21b6d, 0xee, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_200) {
  // 442320 / 40 = 11058
  s21_decimal d1 = {{0x6bfd0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x28, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x2b32, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_201) {
  // 38410781346 / 3 = 12803593782
  s21_decimal d1 = {{0xf17602a2, 0x8, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xfb275636, 0x2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_202) {
  // 32768 / -2 = -16384
  s21_decimal d1 = {{0x8000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x4000, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_203) {
  // 32768 / 2 = 16384
  s21_decimal d1 = {{0x8000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x4000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_204) {
  // 30064771176 / -2 = -15032385588
  s21_decimal d1 = {{0x68, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x80000034, 0x3, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_205) {
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

START_TEST(s21_div_206) {
  // 2.25 / -1.5 = -1.5
  s21_decimal d1 = {{0xe1, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xf, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0xf, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_207) {
  // 0 / 0.015 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_208) {
  // 0.0000 / 5.7 = 0.000
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x39, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_209) {
  // 0.00 / 5.00007 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0x7a127, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_210) {
  // 0.0 / 5.7 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x39, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_211) {
  // 101 / 0 = S21_DIV_ZERO_ERR
  s21_decimal d1 = {{0x65, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_DIV_ZERO_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_212) {
  //-579 / 0 = S21_DIV_ZERO_ERR
  s21_decimal d1 = {{0x243, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_DIV_ZERO_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_213) {
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

START_TEST(s21_div_214) {
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

START_TEST(s21_div_215) {
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

START_TEST(s21_div_216) {
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

START_TEST(s21_div_217) {
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

START_TEST(s21_div_218) {
  // 7.0 / 7 = 1.0
  s21_decimal d1 = {{0x46, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xa, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_219) {
  // 7 / 7.0 = 1
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x46, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_220) {
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

START_TEST(s21_div_221) {
  // 7922816251426433759354395033.5 / 0.01 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_222) {
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

START_TEST(s21_div_223) {
  // 79228162514264337593543950335 / 0.4 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_224) {
  // 0.0000000000000000000000000001 / 8 = 0
  s21_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal d2 = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_225) {
  // 20 / 0.00005 = 400000
  s21_decimal d1 = {{0x14, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x61a80, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_226) {
  // 936582642837 / 0.1041747302401649 = 8990497414083.03230156190427
  s21_decimal d1 = {{0x10acfc95, 0xda, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xb1e7c671, 0x3b376, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0x662eb2db, 0x23ef54ff, 0x2e7ad30, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_227) {
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

START_TEST(s21_div_228) {
  //-75384834.34934734873487 / -1349.34984 = 55867.52383603302516037649658
  s21_decimal d1 = {{0xe36ae38f, 0xa9793779, 0x198, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0x80af1c8, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0x972204fa, 0x9272c199, 0x120d40d5, sign_and_exp_bits(0, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_229) {
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

START_TEST(s21_div_230) {
  //-0.3183718237812378127 / -0.3183718237812378127 = 1
  s21_decimal d1 = {{0x85bd4a0f, 0x2c2ed6de, 0x0, sign_and_exp_bits(1, 19)}};
  s21_decimal d2 = {{0x85bd4a0f, 0x2c2ed6de, 0x0, sign_and_exp_bits(1, 19)}};
  s21_decimal correct = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_231) {
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

START_TEST(s21_div_232) {
  //-184838746726726348023 / 0.00000000193289 = S21_SMALL_ERR
  s21_decimal d1 = {{0x8eebacf7, 0x52724d4, 0xa, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2f309, 0x0, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_233) {
  // 45284674874386437639 / 0.00000000048934 = S21_HUGE_ERR
  s21_decimal d1 = {{0xa8dc5607, 0x74737bde, 0x2, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xbf26, 0x0, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_234) {
  // 75384834.34934734873487 / 1349.34984 = 55867.52383603302516037649658
  s21_decimal d1 = {{0xe36ae38f, 0xa9793779, 0x198, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {{0x80af1c8, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0x972204fa, 0x9272c199, 0x120d40d5, sign_and_exp_bits(0, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_235) {
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

START_TEST(s21_div_236) {
  // 1254349872542492751.624234 / -6452.73638897036035407893144 =
  // -194390379047027.023007936205
  s21_decimal d1 = {{0xeaf8f82a, 0x715e2ef1, 0x1099e, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {
      {0xba0e5298, 0xe96dff9, 0x215c202, sign_and_exp_bits(1, 23)}};
  s21_decimal correct = {
      {0x4076ecd, 0x904b9652, 0xa0cbc3, sign_and_exp_bits(1, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_237) {
  //-23.1 / 557287113874425267883810734 = -0.0000000000000000000000000415
  s21_decimal d1 = {{0xe7, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {
      {0xb85b1fae, 0xfa60ec4e, 0x1ccfa22, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x19f, 0x0, 0x0, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_238) {
  // 4.7371696578 / -71 = -0.0667206994056338028169014085
  s21_decimal d1 = {{0x792b9c2, 0xb, 0x0, sign_and_exp_bits(0, 10)}};
  s21_decimal d2 = {{0x47, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xee642b45, 0x9f67510e, 0x227e693, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_239) {
  // 56.8647416427586824 / 90132950370.98 = 0.0000000006308984828379406559
  s21_decimal d1 = {{0xfa9c2508, 0x7e43dcf, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal d2 = {{0x923fbaaa, 0x832, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {
      {0x64e220df, 0x578e0446, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_div_240) {
  // Segmentation fault test
  s21_decimal d1 = {{0xfa9c2508, 0x7e43dcf, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal d2 = {{0x923fbaaa, 0x832, 0x0, sign_and_exp_bits(0, 2)}};
  // s21_decimal correct = {
  // {0x64e220df, 0x578e0446, 0x0, sign_and_exp_bits(0, 28)}};
  // s21_decimal result;

  ck_assert_int_eq(s21_div(d1, d2, NULL), S21_OK);
  // ASSERT_BITS_EQ
}
END_TEST

Suite *div_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "S21_DIV" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("S21_DIV");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_div_0);
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
  tcase_add_test(tc1_1, s21_div_34);
  tcase_add_test(tc1_1, s21_div_35);
  tcase_add_test(tc1_1, s21_div_36);
  tcase_add_test(tc1_1, s21_div_37);
  tcase_add_test(tc1_1, s21_div_38);
  tcase_add_test(tc1_1, s21_div_39);
  tcase_add_test(tc1_1, s21_div_40);
  tcase_add_test(tc1_1, s21_div_41);
  tcase_add_test(tc1_1, s21_div_42);
  tcase_add_test(tc1_1, s21_div_43);
  tcase_add_test(tc1_1, s21_div_44);
  tcase_add_test(tc1_1, s21_div_45);
  tcase_add_test(tc1_1, s21_div_46);
  tcase_add_test(tc1_1, s21_div_47);
  tcase_add_test(tc1_1, s21_div_48);
  tcase_add_test(tc1_1, s21_div_49);
  tcase_add_test(tc1_1, s21_div_50);
  tcase_add_test(tc1_1, s21_div_51);
  tcase_add_test(tc1_1, s21_div_52);
  tcase_add_test(tc1_1, s21_div_53);
  tcase_add_test(tc1_1, s21_div_54);
  tcase_add_test(tc1_1, s21_div_55);
  tcase_add_test(tc1_1, s21_div_56);
  tcase_add_test(tc1_1, s21_div_57);
  tcase_add_test(tc1_1, s21_div_58);
  tcase_add_test(tc1_1, s21_div_59);
  tcase_add_test(tc1_1, s21_div_60);
  tcase_add_test(tc1_1, s21_div_61);
  tcase_add_test(tc1_1, s21_div_62);
  tcase_add_test(tc1_1, s21_div_63);
  tcase_add_test(tc1_1, s21_div_64);
  tcase_add_test(tc1_1, s21_div_65);
  tcase_add_test(tc1_1, s21_div_66);
  tcase_add_test(tc1_1, s21_div_67);
  tcase_add_test(tc1_1, s21_div_68);
  tcase_add_test(tc1_1, s21_div_69);
  tcase_add_test(tc1_1, s21_div_70);
  tcase_add_test(tc1_1, s21_div_71);
  tcase_add_test(tc1_1, s21_div_72);
  tcase_add_test(tc1_1, s21_div_73);
  tcase_add_test(tc1_1, s21_div_74);
  tcase_add_test(tc1_1, s21_div_75);
  tcase_add_test(tc1_1, s21_div_76);
  tcase_add_test(tc1_1, s21_div_77);
  tcase_add_test(tc1_1, s21_div_78);
  tcase_add_test(tc1_1, s21_div_79);
  tcase_add_test(tc1_1, s21_div_80);
  tcase_add_test(tc1_1, s21_div_81);
  tcase_add_test(tc1_1, s21_div_82);
  tcase_add_test(tc1_1, s21_div_83);
  tcase_add_test(tc1_1, s21_div_84);
  tcase_add_test(tc1_1, s21_div_85);
  tcase_add_test(tc1_1, s21_div_86);
  tcase_add_test(tc1_1, s21_div_87);
  tcase_add_test(tc1_1, s21_div_88);
  tcase_add_test(tc1_1, s21_div_89);
  tcase_add_test(tc1_1, s21_div_90);
  tcase_add_test(tc1_1, s21_div_91);
  tcase_add_test(tc1_1, s21_div_92);
  tcase_add_test(tc1_1, s21_div_93);
  tcase_add_test(tc1_1, s21_div_94);
  tcase_add_test(tc1_1, s21_div_95);
  tcase_add_test(tc1_1, s21_div_96);
  tcase_add_test(tc1_1, s21_div_97);
  tcase_add_test(tc1_1, s21_div_98);
  tcase_add_test(tc1_1, s21_div_99);
  tcase_add_test(tc1_1, s21_div_100);
  tcase_add_test(tc1_1, s21_div_101);
  tcase_add_test(tc1_1, s21_div_102);
  tcase_add_test(tc1_1, s21_div_103);
  tcase_add_test(tc1_1, s21_div_104);
  tcase_add_test(tc1_1, s21_div_105);
  tcase_add_test(tc1_1, s21_div_106);
  tcase_add_test(tc1_1, s21_div_107);
  tcase_add_test(tc1_1, s21_div_108);
  tcase_add_test(tc1_1, s21_div_109);
  tcase_add_test(tc1_1, s21_div_110);
  tcase_add_test(tc1_1, s21_div_111);
  tcase_add_test(tc1_1, s21_div_112);
  tcase_add_test(tc1_1, s21_div_113);
  tcase_add_test(tc1_1, s21_div_114);
  tcase_add_test(tc1_1, s21_div_115);
  tcase_add_test(tc1_1, s21_div_116);
  tcase_add_test(tc1_1, s21_div_117);
  tcase_add_test(tc1_1, s21_div_118);
  tcase_add_test(tc1_1, s21_div_119);
  tcase_add_test(tc1_1, s21_div_120);
  tcase_add_test(tc1_1, s21_div_121);
  tcase_add_test(tc1_1, s21_div_122);
  tcase_add_test(tc1_1, s21_div_123);
  tcase_add_test(tc1_1, s21_div_124);
  tcase_add_test(tc1_1, s21_div_125);
  tcase_add_test(tc1_1, s21_div_126);
  tcase_add_test(tc1_1, s21_div_127);
  tcase_add_test(tc1_1, s21_div_128);
  tcase_add_test(tc1_1, s21_div_129);
  tcase_add_test(tc1_1, s21_div_130);
  tcase_add_test(tc1_1, s21_div_131);
  tcase_add_test(tc1_1, s21_div_132);
  tcase_add_test(tc1_1, s21_div_133);
  tcase_add_test(tc1_1, s21_div_134);
  tcase_add_test(tc1_1, s21_div_135);
  tcase_add_test(tc1_1, s21_div_136);
  tcase_add_test(tc1_1, s21_div_137);
  tcase_add_test(tc1_1, s21_div_138);
  tcase_add_test(tc1_1, s21_div_139);
  tcase_add_test(tc1_1, s21_div_140);
  tcase_add_test(tc1_1, s21_div_141);
  tcase_add_test(tc1_1, s21_div_142);
  tcase_add_test(tc1_1, s21_div_143);
  tcase_add_test(tc1_1, s21_div_144);
  tcase_add_test(tc1_1, s21_div_145);
  tcase_add_test(tc1_1, s21_div_146);
  tcase_add_test(tc1_1, s21_div_147);
  tcase_add_test(tc1_1, s21_div_148);
  tcase_add_test(tc1_1, s21_div_149);
  tcase_add_test(tc1_1, s21_div_150);
  tcase_add_test(tc1_1, s21_div_151);
  tcase_add_test(tc1_1, s21_div_152);
  tcase_add_test(tc1_1, s21_div_153);
  tcase_add_test(tc1_1, s21_div_154);
  tcase_add_test(tc1_1, s21_div_155);
  tcase_add_test(tc1_1, s21_div_156);
  tcase_add_test(tc1_1, s21_div_157);
  tcase_add_test(tc1_1, s21_div_158);
  tcase_add_test(tc1_1, s21_div_159);
  tcase_add_test(tc1_1, s21_div_160);
  tcase_add_test(tc1_1, s21_div_161);
  tcase_add_test(tc1_1, s21_div_162);
  tcase_add_test(tc1_1, s21_div_163);
  tcase_add_test(tc1_1, s21_div_164);
  tcase_add_test(tc1_1, s21_div_165);
  tcase_add_test(tc1_1, s21_div_166);
  tcase_add_test(tc1_1, s21_div_167);
  tcase_add_test(tc1_1, s21_div_168);
  tcase_add_test(tc1_1, s21_div_169);
  tcase_add_test(tc1_1, s21_div_170);
  tcase_add_test(tc1_1, s21_div_171);
  tcase_add_test(tc1_1, s21_div_172);
  tcase_add_test(tc1_1, s21_div_173);
  tcase_add_test(tc1_1, s21_div_174);
  tcase_add_test(tc1_1, s21_div_175);
  tcase_add_test(tc1_1, s21_div_176);
  tcase_add_test(tc1_1, s21_div_177);
  tcase_add_test(tc1_1, s21_div_178);
  tcase_add_test(tc1_1, s21_div_179);
  tcase_add_test(tc1_1, s21_div_180);
  tcase_add_test(tc1_1, s21_div_181);
  tcase_add_test(tc1_1, s21_div_182);
  tcase_add_test(tc1_1, s21_div_183);
  tcase_add_test(tc1_1, s21_div_184);
  tcase_add_test(tc1_1, s21_div_185);
  tcase_add_test(tc1_1, s21_div_186);
  tcase_add_test(tc1_1, s21_div_187);
  tcase_add_test(tc1_1, s21_div_188);
  tcase_add_test(tc1_1, s21_div_189);
  tcase_add_test(tc1_1, s21_div_190);
  tcase_add_test(tc1_1, s21_div_191);
  tcase_add_test(tc1_1, s21_div_192);
  tcase_add_test(tc1_1, s21_div_193);
  tcase_add_test(tc1_1, s21_div_194);
  tcase_add_test(tc1_1, s21_div_195);
  tcase_add_test(tc1_1, s21_div_196);
  tcase_add_test(tc1_1, s21_div_197);
  tcase_add_test(tc1_1, s21_div_198);
  tcase_add_test(tc1_1, s21_div_199);
  tcase_add_test(tc1_1, s21_div_200);
  tcase_add_test(tc1_1, s21_div_201);
  tcase_add_test(tc1_1, s21_div_202);
  tcase_add_test(tc1_1, s21_div_203);
  tcase_add_test(tc1_1, s21_div_204);
  tcase_add_test(tc1_1, s21_div_205);
  tcase_add_test(tc1_1, s21_div_206);
  tcase_add_test(tc1_1, s21_div_207);
  tcase_add_test(tc1_1, s21_div_208);
  tcase_add_test(tc1_1, s21_div_209);
  tcase_add_test(tc1_1, s21_div_210);
  tcase_add_test(tc1_1, s21_div_211);
  tcase_add_test(tc1_1, s21_div_212);
  tcase_add_test(tc1_1, s21_div_213);
  tcase_add_test(tc1_1, s21_div_214);
  tcase_add_test(tc1_1, s21_div_215);
  tcase_add_test(tc1_1, s21_div_216);
  tcase_add_test(tc1_1, s21_div_217);
  tcase_add_test(tc1_1, s21_div_218);
  tcase_add_test(tc1_1, s21_div_219);
  tcase_add_test(tc1_1, s21_div_220);
  tcase_add_test(tc1_1, s21_div_221);
  tcase_add_test(tc1_1, s21_div_222);
  tcase_add_test(tc1_1, s21_div_223);
  tcase_add_test(tc1_1, s21_div_224);
  tcase_add_test(tc1_1, s21_div_225);
  tcase_add_test(tc1_1, s21_div_226);
  tcase_add_test(tc1_1, s21_div_227);
  tcase_add_test(tc1_1, s21_div_228);
  tcase_add_test(tc1_1, s21_div_229);
  tcase_add_test(tc1_1, s21_div_230);
  tcase_add_test(tc1_1, s21_div_231);
  tcase_add_test(tc1_1, s21_div_232);
  tcase_add_test(tc1_1, s21_div_233);
  tcase_add_test(tc1_1, s21_div_234);
  tcase_add_test(tc1_1, s21_div_235);
  tcase_add_test(tc1_1, s21_div_236);
  tcase_add_test(tc1_1, s21_div_237);
  tcase_add_test(tc1_1, s21_div_238);
  tcase_add_test(tc1_1, s21_div_239);
  tcase_add_test(tc1_1, s21_div_240);

  return s1;
}
