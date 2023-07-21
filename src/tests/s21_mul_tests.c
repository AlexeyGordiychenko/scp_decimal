#include "s21_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *          MULTIPLICATION FUNCTION TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(s21_mul_0) {
  //-148744042013915655 * -98.4545 = 14644520284459058855.1975
  s21_decimal d1 = {{0xab1fa07, 0x21071eb, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xf05e1, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {
      {0x86b7e327, 0xcf735737, 0x1f02, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_1) {
  //-3578854.74 * 16.455 = -58890054.74670
  s21_decimal d1 = {{0x1554e622, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x4047, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0x2414536e, 0x55b, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_2) {
  //-363658373806220017 * 35467.31048 = -12897984452437104698129.87816
  s21_decimal d1 = {{0x3e50e2f1, 0x50bf95d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xd366d228, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0x25d327a8, 0xd1f0f2f7, 0x42ae571, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_3) {
  // 3.650270000000 * 491954481703629183 = 1795766685928306497.8294100000
  s21_decimal d1 = {{0xe50bf380, 0x351, 0x0, sign_and_exp_bits(0, 12)}};
  s21_decimal d2 = {{0x9f9b317f, 0x6d3c5fe, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x355ed020, 0x148d600f, 0x3a063bdf, sign_and_exp_bits(0, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_4) {
  //-27002547049381 * 3230558244689839810278627 = S21_SMALL_ERR
  s21_decimal d1 = {{0x53993a5, 0x188f, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xa8c1f4e3, 0xe9d21242, 0x2ac18, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_5) {
  // 21 * 7765.4079999 = 163073.5679979
  s21_decimal d1 = {{0x15, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x148b39ff, 0x12, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {{0xaf6bc1eb, 0x17b, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_6) {
  // 28477137719088160.2600 * 916203082788088317131135 = S21_HUGE_ERR
  s21_decimal d1 = {{0x8d462c28, 0x6fff2ac5, 0xf, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x3492b97f, 0x77f8c7ca, 0xc203, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_7) {
  // 196055.356179 * -3012249817808483124760 = -590567710930570016232532693.89
  s21_decimal d1 = {{0xa5cf5313, 0x2d, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0x99c40618, 0x4b5d21b6, 0xa3, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x9cd5bb8d, 0xf41d9ee2, 0xbed29db7, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_8) {
  // 6494475301610533614600 * 6494475301610533614600 = S21_HUGE_ERR
  s21_decimal d1 = {{0x23bef408, 0x10f33d9c, 0x160, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x23bef408, 0x10f33d9c, 0x160, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_9) {
  // 6865.107737914675627 * -462267523.957 = -3173516355703.8583926261064960
  s21_decimal d1 = {{0x5f3091ab, 0x5f45c31d, 0x0, sign_and_exp_bits(0, 15)}};
  s21_decimal d2 = {{0xa14aa375, 0x6b, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {
      {0xae48a500, 0xa2de2361, 0x668ab647, sign_and_exp_bits(1, 16)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_10) {
  // 393125658.637256439886900 * 393125658.637256439886900 =
  // 154547783478976678.89664578634
  s21_decimal d1 = {{0xd963f434, 0x6278ed93, 0x533f, sign_and_exp_bits(0, 15)}};
  s21_decimal d2 = {{0xd963f434, 0x6278ed93, 0x533f, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {
      {0x1e87544a, 0xedda08, 0x31efe49d, sign_and_exp_bits(0, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_11) {
  // 3627.8 * 64.78327000000000 = 235020.746906000000000
  s21_decimal d1 = {{0x8db6, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xb92e600, 0x170401, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {
      {0x231d8400, 0xbd916c1e, 0xc, sign_and_exp_bits(0, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_12) {
  // 7.2666659280043079877 * 7687018427 = 55858994891.422170836833189348
  s21_decimal d1 = {{0x594f78c5, 0xf073d59c, 0x3, sign_and_exp_bits(0, 19)}};
  s21_decimal d2 = {{0xca2e97bb, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2044bde4, 0xb4f2d939, 0xb47d7a44, sign_and_exp_bits(0, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_13) {
  // 67109596002412044905791686.0 * 5.6 = 375813737613507451472433441.60
  s21_decimal d1 = {
      {0x14b87bc, 0xe3e57266, 0x22b1e18, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x38, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x4885b120, 0xda310650, 0x796e9571, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_14) {
  // 7 * 4098.428539774636 = 28688.999778422452
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xc14026ac, 0xe8f7f, 0x0, sign_and_exp_bits(0, 12)}};
  s21_decimal correct = {{0x48c10eb4, 0x65ec7e, 0x0, sign_and_exp_bits(0, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_15) {
  //-758276 * -71740844885813646920.45662 = 54399360896635228932256163.987
  s21_decimal d1 = {{0xb9204, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x42e84f5e, 0xe63f7419, 0x5ef2b, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0xf82de893, 0x4c390f9a, 0xafc618bf, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_16) {
  //-5378020830902928544.41156053 * -3236650309203965257863875959 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0xda649dd5, 0x57ba4978, 0x1bcdc05, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {
      {0xb7734d77, 0xd73acc59, 0xa754b5c, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_17) {
  //-583190078006248434127 * -5500228512 = S21_HUGE_ERR
  s21_decimal d1 = {{0xbec969cf, 0x9d635e12, 0x1f, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x47d6d3a0, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_18) {
  // 95897.2857568662593151619256 * -58266283.3233543538769228605 =
  // -5587578421850.2435328707376763
  s21_decimal d1 = {
      {0xb91ed0b8, 0xc6ca9792, 0x3193e66, sign_and_exp_bits(0, 22)}};
  s21_decimal d2 = {
      {0xd811733d, 0x7b1d7719, 0x1e1f7a7, sign_and_exp_bits(1, 19)}};
  s21_decimal correct = {
      {0x725db67b, 0xf39ac286, 0xb48b5d8b, sign_and_exp_bits(1, 16)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_19) {
  //-80519179146640326135145 * -80519179146640326135145 = S21_HUGE_ERR
  s21_decimal d1 = {{0x81140d69, 0xf41528f9, 0x110c, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x81140d69, 0xf41528f9, 0x110c, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_20) {
  // 3336155319262.9211600 * 3336155319262.9211600 =
  // 11129932314246283413892427.616
  s21_decimal d1 = {{0x21f691d0, 0xcefc0bdf, 0x1, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0x21f691d0, 0xcefc0bdf, 0x1, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0xaf48ef60, 0xbc727c8b, 0x23f676d7, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_21) {
  //-2076.1181581 * -382657196668312 = 794441554330725366.0761272
  s21_decimal d1 = {{0xd5767d8d, 0x4, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0x52473598, 0x15c06, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x4273bcb8, 0xa12ac872, 0x6924b, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_22) {
  //-31083050047292018856118 * 696641671126667089817878230 = S21_SMALL_ERR
  s21_decimal d1 = {{0x718d10b6, 0x3f914f4, 0x695, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xf30fbed6, 0xa9fa266f, 0x2403f9c, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_23) {
  //-857700150727955507723212 * -5543988658 = S21_HUGE_ERR
  s21_decimal d1 = {{0xe0d23bcc, 0x4b1ccea, 0xb5a0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x4a728db2, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_24) {
  //-43177948552 * -43177948552 = 1864335241159158896704
  s21_decimal d1 = {{0xd9b3588, 0xa, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xd9b3588, 0xa, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xade19840, 0x10d95029, 0x65, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_25) {
  // 84331461600915286994285 * -660819082138283726845505 = S21_SMALL_ERR
  s21_decimal d1 = {{0xb2792d6d, 0x9e212ecc, 0x11db, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf16bb641, 0x13005337, 0x8bef, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_26) {
  // 39561154525098625720992075 * 7383578256460268845462444 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0x17ed414b, 0x7bee754e, 0x20b966, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xdfb0f3ac, 0x944e3868, 0x61b88, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_27) {
  //-5966304371319 * -5966304371319 = 35596787851220207829799761
  s21_decimal d1 = {{0x2373e277, 0x56d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2373e277, 0x56d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xc9405351, 0xbc7063b7, 0x1d71e9, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_28) {
  // 36516830250045 * 249.0000 = 9092690732261205.0000
  s21_decimal d1 = {{0x3cb2043d, 0x2136, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x25fe90, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {
      {0x6127e850, 0xeddd4475, 0x4, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_29) {
  // 77419 * 77419 = 5993701561
  s21_decimal d1 = {{0x12e6b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x12e6b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x6540a0b9, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_30) {
  //-7356295891799 * 3512309661095135933550237671 = S21_SMALL_ERR
  s21_decimal d1 = {{0xc5674b57, 0x6b0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x48f717e7, 0x4003d74e, 0xb595080, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_31) {
  // 214003.1051137047 * 214003.1051137047 = 45797328998.307342719115758802
  s21_decimal d1 = {{0xce9c8017, 0x79a58, 0x0, sign_and_exp_bits(0, 10)}};
  s21_decimal d2 = {{0xce9c8017, 0x79a58, 0x0, sign_and_exp_bits(0, 10)}};
  s21_decimal correct = {
      {0xef0a8cd2, 0xb32d56f9, 0x93faa9a3, sign_and_exp_bits(0, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_32) {
  //-87.869 * -980646267174106564.1645010417 = 86168406850321569686.57054203
  s21_decimal d1 = {{0x1573d, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {
      {0xe75b6df1, 0xa7acfd8e, 0x1fafb73e, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {
      {0xc16f69fb, 0x889e6c43, 0x1bd7aefd, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_33) {
  // 37485417 * 204393983963906898943 = 7661793721178363056055214231
  s21_decimal d1 = {{0x23bfb69, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x4b8efbff, 0x14894d7d, 0xb, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x407d6097, 0xe1c22965, 0x18c1afed, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_34) {
  // 1629519395036491186 * 1629519395036491186 = S21_HUGE_ERR
  s21_decimal d1 = {{0x97c26db2, 0x169d3741, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x97c26db2, 0x169d3741, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_35) {
  // 223702115777231463162376 * 27 = 6039957125985249505384152
  s21_decimal d1 = {{0x4408a208, 0xea7eb2c9, 0x2f5e, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2ce916d8, 0xbb5cdb3a, 0x4ff02, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_36) {
  // 18.68889 * 396964953959515195583943511 = 7418834358404443943596806043.3
  s21_decimal d1 = {{0x1c8459, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {
      {0x1722d357, 0x46306176, 0x1485c99, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xeb651c11, 0x589a0f7e, 0xefb728d4, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_37) {
  //-355836802643853680082 * -25236462449609498.5 = S21_HUGE_ERR
  s21_decimal d1 = {{0x4dad9dd2, 0x4a3a46b3, 0x13, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xf4f6ef09, 0x3809449, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_38) {
  // 973447859133 * -973447859133 = -947600734450621011511689
  s21_decimal d1 = {{0xa6038bbd, 0xe2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xa6038bbd, 0xe2, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xaeb4c989, 0x89eb52f9, 0xc8a9, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_39) {
  //-2176.7489 * -9749938749992 = 21223168449112461.0088
  s21_decimal d1 = {{0x14c2541, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x15a2c228, 0x8de, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xd0431428, 0x814e6897, 0xb, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_40) {
  //-7382130867544692282066.7414900 * 590912 = -4362189715202569205780622347.3
  s21_decimal d1 = {
      {0xb2119974, 0x15065f25, 0xee878e2a, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0x90440, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x5216b871, 0x21e4a71, 0x8cf33007, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_41) {
  //-9355075134986142657923 * -9355075134986142657923 = S21_HUGE_ERR
  s21_decimal d1 = {{0x2288ad83, 0x23bf65f5, 0x1fb, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2288ad83, 0x23bf65f5, 0x1fb, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_42) {
  //-4779201966624785595957426.32 * -7431.4142800000000 =
  // 35516229741779515079736328226
  s21_decimal d1 = {
      {0xa49445a8, 0xc659d026, 0x18b5389, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0xb361b400, 0x1080451, 0x0, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {
      {0xa6528022, 0x3a014425, 0x72c25630, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_43) {
  // 968259703.76100000 * 3967920528966970384123 = S21_HUGE_ERR
  s21_decimal d1 = {{0x14cc8a0, 0x157feb5, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0xc8561efb, 0x19f58a26, 0xd7, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_44) {
  //-935719784466663587270893 * -626.551265837514421119924130 =
  // 586276415426794234552073836.00
  s21_decimal d1 = {{0x717d50ed, 0x789dcc89, 0xc625, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xe002b7a2, 0x2e02b4db, 0x2064564, sign_and_exp_bits(1, 24)}};
  s21_decimal correct = {
      {0x1b0c6230, 0x69e9b0a5, 0xbd6fa600, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_45) {
  // 29651594642050001889365.4 * -91444066822469222 = S21_SMALL_ERR
  s21_decimal d1 = {{0x56f21356, 0x2962d4a1, 0x3eca, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xefc53666, 0x144dfe4, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_46) {
  //-205604.09146817678225837 * -607935231.886691594 =
  // 124993971023558.60086791833897
  s21_decimal d1 = {{0x77f131ad, 0x94fed150, 0x45a, sign_and_exp_bits(1, 17)}};
  s21_decimal d2 = {{0x570d0d0a, 0x86fd1df, 0x0, sign_and_exp_bits(1, 9)}};
  s21_decimal correct = {
      {0xb1ef8929, 0xa81b0257, 0x2863424a, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_47) {
  // 285372853667450408584 * 85899760.74624706599983000 =
  // 24513459853507764674601233561
  s21_decimal d1 = {{0xbbe94e88, 0x78580a70, 0xf, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xe3bc1798, 0x893ce362, 0x71aff, sign_and_exp_bits(0, 17)}};
  s21_decimal correct = {
      {0x4d2d2c99, 0x6a5bf590, 0x4f350f09, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_48) {
  //-22134243 * 65.03975 = -1439605631.15925
  s21_decimal d1 = {{0x151bde3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x633e27, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x6e39e795, 0x82ee, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_49) {
  // 77944788630010599661.6 * 77944788630010599661.6 = S21_HUGE_ERR
  s21_decimal d1 = {{0xe6e0f948, 0x41032ae5, 0x2a, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xe6e0f948, 0x41032ae5, 0x2a, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_50) {
  //-228.1 * -228.1 = 52029.61
  s21_decimal d1 = {{0x8e9, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x8e9, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x4f6411, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_51) {
  //-154590853658010563.2758 * 103911865824690288238441 = S21_SMALL_ERR
  s21_decimal d1 = {{0xf528fbf6, 0xcdca6771, 0x53, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x2da09f69, 0x12d31ae5, 0x1601, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_52) {
  // 840648550590282049387680098 * -516361.4661791 = S21_SMALL_ERR
  s21_decimal d1 = {
      {0xece2d162, 0x3e09e8f2, 0x2b75e41, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3f6aec9f, 0x4b2, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_53) {
  // 0 * -2066875583651.99966337918629 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x12e666a5, 0xfd81ec3e, 0xaaf7ca, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_54) {
  // 6 * -14 = -84
  s21_decimal d1 = {{0x6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xe, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x54, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_55) {
  // 5741945654450.0816399 * 659523719108.8282030975923536 =
  // 3786949352943692370858298.1168
  s21_decimal d1 = {{0x82f31a0f, 0x1cdae381, 0x3, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {
      {0xb91ab550, 0x882121fd, 0x154f73cc, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0xf8ccee30, 0xc6ed9e87, 0x7a5ce92d, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_56) {
  //-64734342351.9851 * 14438 = -934634434877960.8738
  s21_decimal d1 = {{0x62ce7c6b, 0x24cc1, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x3866, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x897cfaa2, 0x81b4e2aa, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_57) {
  //-5981729564147641348551.6916 * -4.40 = 26319610082249621933627.443040
  s21_decimal d1 = {
      {0xb9748874, 0x182653ab, 0x317ace, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x1b8, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {
      {0xc04a8760, 0x81dfcf26, 0x550b1239, sign_and_exp_bits(0, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_58) {
  //-8 * -92142315634064.60000000 = 737138525072516.80000000
  s21_decimal d1 = {{0x8, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xba3f1700, 0x812683d3, 0x1f3, sign_and_exp_bits(1, 8)}};
  s21_decimal correct = {
      {0xd1f8b800, 0x9341e9d, 0xf9c, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_59) {
  //-355.4 * 20966196131185915470 = -7451386105023474358038.0
  s21_decimal d1 = {{0xde2, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x3281764e, 0x22f6e44c, 0x1, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x294c66dc, 0x678d69d5, 0xfc7, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_60) {
  //-167647543249 * 22635 = -3794702141441115
  s21_decimal d1 = {{0x8927fd1, 0x27, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x586b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xf12b445b, 0xd7b42, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_61) {
  //-0 * -0 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_62) {
  // 222900769 * -6917978414712041841156333 = S21_SMALL_ERR
  s21_decimal d1 = {{0xd493221, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x572ce0ed, 0x5c7f9815, 0x5b8f0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_63) {
  //-870958718.41322265926 * -8672331155874682867 =
  // 7553242429175675700712770531.6
  s21_decimal d1 = {{0x68f5ed46, 0xb8b2b1fc, 0x4, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {{0x7697f3, 0x785a4f3d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x9ace76e4, 0x82cf7817, 0xf40ef4fd, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_64) {
  // 167251461181327450000 * 8849825020655614.388 = S21_HUGE_ERR
  s21_decimal d1 = {{0xe60e9f90, 0x11148dce, 0x9, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xc88ab9b4, 0x7ad0e4f7, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_65) {
  // 366423945.1 * 366423945.1 = 134266507542647814.01
  s21_decimal d1 = {{0xda67db5b, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xda67db5b, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x3b2ed259, 0xba550bb9, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_66) {
  //-34797379060138909835202.911130 * 44.609516447169485 =
  //-1552294253501657734188141.9668
  s21_decimal d1 = {
      {0x3663db9a, 0xb0b19fb3, 0x706fb7a2, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x6d6f7bcd, 0x9e7c1e, 0x0, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {
      {0x12e58794, 0xfddb84a9, 0x322846f0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_67) {
  //-680.5 * -393.020609543718697630 = 267450.5247945005737372150
  s21_decimal d1 = {{0x1a95, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x4cd9fa9e, 0x4e41b211, 0x15, sign_and_exp_bits(1, 18)}};
  s21_decimal correct = {
      {0xde52e9f6, 0x385265df, 0x23659, sign_and_exp_bits(0, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_68) {
  // 25988623606300000 * -54427.478489367 = -1414495252300148679744.2121000
  s21_decimal d1 = {{0xf6413d60, 0x5c5483, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x62857917, 0x3180, 0x0, sign_and_exp_bits(1, 9)}};
  s21_decimal correct = {
      {0x1daffd28, 0xc1d30a16, 0x2db46e34, sign_and_exp_bits(1, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_69) {
  //-1655.1725718037 * -66672528569128 = 110354540580419254.1990961736
  s21_decimal d1 = {{0xbfbb5a15, 0xf0d, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal d2 = {{0x6861b328, 0x3ca3, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x9f37c248, 0x520a012a, 0x390d4d4, sign_and_exp_bits(0, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_70) {
  // 74 * 25339006.161 = 1875086455.914
  s21_decimal d1 = {{0x4a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xe6528cd1, 0x5, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0x93dcb46a, 0x1b4, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_71) {
  //-38395.73114131355 * -209429419.0355604189840325 =
  // 8041195666370.871959910824211
  s21_decimal d1 = {{0x478e939b, 0xda412, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {
      {0x165583c5, 0xea61823f, 0x1bb7b, sign_and_exp_bits(1, 16)}};
  s21_decimal correct = {
      {0x3aab3913, 0x8b031b25, 0x19fb856a, sign_and_exp_bits(0, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_72) {
  // 750920406068725654420580 * 750920406068725654420580 = S21_HUGE_ERR
  s21_decimal d1 = {{0x8b26fc64, 0x7a0e54ae, 0x9f03, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x8b26fc64, 0x7a0e54ae, 0x9f03, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_73) {
  // 185.581830376 * 383981304155.461965001 = 71259953255334.206322735230670
  s21_decimal d1 = {{0x358a00e8, 0x2b, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x9188d4c9, 0xd0cfa1b5, 0x14, sign_and_exp_bits(0, 9)}};
  s21_decimal correct = {
      {0xf58eaece, 0x884e1ebc, 0xe640da0e, sign_and_exp_bits(0, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_74) {
  // 342620.95570888253 * 73915554793540 = 25325018025114948119.098262856
  s21_decimal d1 = {{0xc3c3663d, 0x79b931, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0xce630844, 0x4339, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x9b778548, 0xd9f1fc9, 0x51d45d2a, sign_and_exp_bits(0, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_75) {
  // 328368.54739406604082000000 * 2.76325884963 = 907367.2945268010622445218219
  s21_decimal d1 = {
      {0x16fab080, 0x76597993, 0x1b2979, sign_and_exp_bits(0, 20)}};
  s21_decimal d2 = {{0x564e6423, 0x40, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {
      {0x1804e9ab, 0xfbefb0ba, 0x1d5190fb, sign_and_exp_bits(0, 22)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_76) {
  // 32735309519 * 32735309519 = 1071600489304732011361
  s21_decimal d1 = {{0x9f2d2ecf, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x9f2d2ecf, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x9f550b61, 0x1771b770, 0x3a, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_77) {
  //-9 * 9 = -81
  s21_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x51, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_78) {
  // 4283700000 * -322570080140508831849053 = S21_SMALL_ERR
  s21_decimal d1 = {{0xff541320, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xfaf29a5d, 0x8f201642, 0x444e, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_79) {
  // 460282889.2531244792434 * 635.2 = 292371691253.58466921540768
  s21_decimal d1 = {{0xad79fa72, 0x85152aec, 0xf9, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {{0x18d0, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x62962ca0, 0x1d391090, 0x182f36, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_80) {
  // 15.04 * 1849000145167405 = 27808962183317771.20
  s21_decimal d1 = {{0x5e0, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xe4d7a42d, 0x691a7, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x72e48860, 0x2697ba60, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_81) {
  // 3857140828003982307.20 * -718753688740040728475288.2775 = S21_SMALL_ERR
  s21_decimal d1 = {{0xc757e4c0, 0xe8dbb2b4, 0x14, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0xe2a89c57, 0x682e9a4f, 0x17396423, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_82) {
  // 69646703.234032579692466987 * 33673834 = 2345271523350076.2391559043707
  s21_decimal d1 = {
      {0x2cc132b, 0x58fee819, 0x399c43, sign_and_exp_bits(0, 18)}};
  s21_decimal d2 = {{0x201d26a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x30a47a7b, 0x579f0aef, 0x4bc7a1a0, sign_and_exp_bits(0, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_83) {
  // 466124139356169274 * 772106224071529553620291 = S21_HUGE_ERR
  s21_decimal d1 = {{0x638f243a, 0x678016f, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1d3a6d43, 0xf657bef5, 0xa37f, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_84) {
  // 173020.087928136722289388757 * 47026.39 = 8136510132.742849475702488548
  s21_decimal d1 = {
      {0x8789ecd5, 0xc2c18e87, 0x8f1e6d, sign_and_exp_bits(0, 21)}};
  s21_decimal d2 = {{0x47c1af, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {
      {0x2b24fde4, 0x1e5666a2, 0x1a4a5d0a, sign_and_exp_bits(0, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_85) {
  //-84835247668 * -216 = 18324413496288
  s21_decimal d1 = {{0xc0932634, 0x13, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xd8, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x7c283be0, 0x10aa, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_86) {
  //-4148035114874877800000000 * -4148035114874877800000000 = S21_HUGE_ERR
  s21_decimal d1 = {{0xd80eaa00, 0x6f24c2c2, 0x36e61, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xd80eaa00, 0x6f24c2c2, 0x36e61, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_87) {
  // 717841041.848332 * -23 = -16510343962.511636
  s21_decimal d1 = {{0x644df80c, 0x28cdf, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0x17, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x3014914, 0x3aa812, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_88) {
  //-664115214469711247698139.60 * -664115214469711247698139.60 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0x4426f5c8, 0xcaa29b6e, 0x36ef2f, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {
      {0x4426f5c8, 0xcaa29b6e, 0x36ef2f, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_89) {
  // 60855032415328347 * 60855032415328347 = S21_HUGE_ERR
  s21_decimal d1 = {{0x5de9185b, 0xd83354, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5de9185b, 0xd83354, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_90) {
  //-888048464507885249 * 88714281531676114282290 = S21_SMALL_ERR
  s21_decimal d1 = {{0x9652d6c1, 0xc52fb5f, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xbfb7e732, 0x35f980a6, 0x12c9, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_91) {
  //-75908610974189069876 * -5669559467.1820023829416 = S21_HUGE_ERR
  s21_decimal d1 = {{0xfddba634, 0x1d718f7f, 0x4, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xc1f093a8, 0x796eb7e2, 0xc01, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_92) {
  //-269476375237671 * 3699959 = -997051539847997955489
  s21_decimal d1 = {{0x5b9f1427, 0xf516, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3874f7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xe4261da1, 0xcdea4e2, 0x36, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_93) {
  // 131825031686 * -131825031686 = -17377838979014904002596
  s21_decimal d1 = {{0xb1625a06, 0x1e, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xb1625a06, 0x1e, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x58403824, 0xdf63fad, 0x3ae, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_94) {
  //-428176175012 * -4088981699121088 = 1750804543623736102067853056
  s21_decimal d1 = {{0xb149efa4, 0x63, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3dab4fc0, 0xe86e8, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xeef35700, 0x7d5e1d97, 0x5a83b48, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_95) {
  // 207232400.54899656334 * 80803438.564697210000000 =
  // 16745090546375568.179677590538
  s21_decimal d1 = {{0x9370c68e, 0x1f97bd08, 0x1, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0x5ce69280, 0x5cf97ba0, 0x111c, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {
      {0x5327740a, 0x713d6f58, 0x361b36d9, sign_and_exp_bits(0, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_96) {
  // 7.3150831383310433609404553 * 39939317148080279779 =
  // 292159425426377949464.05252236
  s21_decimal d1 = {
      {0xb2595089, 0x83e71dae, 0x3c824a, sign_and_exp_bits(0, 25)}};
  s21_decimal d2 = {{0xaefe10e3, 0x2a44f556, 0x2, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xf97e3c8c, 0xcc06c80d, 0x5e66dc7a, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_97) {
  // 2942872501825539934471 * -2942872501825539934471 = S21_SMALL_ERR
  s21_decimal d1 = {{0x50680907, 0x888f6467, 0x9f, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x50680907, 0x888f6467, 0x9f, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_98) {
  // 529.763585782914084 * -240.871054409098502296615 =
  // -127604.71349507542011959901096
  s21_decimal d1 = {{0xa9871c24, 0x75a192c, 0x0, sign_and_exp_bits(0, 15)}};
  s21_decimal d2 = {{0xa8035427, 0xa561d388, 0x3301, sign_and_exp_bits(1, 21)}};
  s21_decimal correct = {
      {0xf728fba8, 0xf429550d, 0x293b36e9, sign_and_exp_bits(1, 23)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_99) {
  //-16327 * 16327 = -266570929
  s21_decimal d1 = {{0x3fc7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3fc7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xfe38cb1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_100) {
  // 2240387726950551980 * -926782817219950870007112013 = S21_SMALL_ERR
  s21_decimal d1 = {{0x800851ac, 0x1f1774c4, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x43b3e14d, 0x314e957a, 0x2fe9de5, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_101) {
  //-8264.49070000000 * -77065.30572245158 = 636905502.43585786411030600000
  s21_decimal d1 = {{0xab3e0780, 0x2efa6, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {{0x793598a6, 0x1b610c, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {
      {0x5966d940, 0xb6dccc0, 0xcdcb969f, sign_and_exp_bits(0, 20)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_102) {
  //-520836167586074493703602 * -67029660.1839768 = S21_HUGE_ERR
  s21_decimal d1 = {{0x6f0fd5b2, 0x95d0ff40, 0x6e4a, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x96d8c898, 0x261a1, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_103) {
  //-757570.686203525484286673 * 5.395395622768877378089824592 =
  //-4087393.5642805161618116212237
  s21_decimal d1 = {{0x87e492d1, 0xfd3b8896, 0xa06b, sign_and_exp_bits(1, 18)}};
  s21_decimal d2 = {
      {0xfdb8b150, 0xc7ff568d, 0x116ef776, sign_and_exp_bits(0, 27)}};
  s21_decimal correct = {
      {0xf6c0760d, 0x191d3e51, 0x8412208b, sign_and_exp_bits(1, 22)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_104) {
  // 72.825937261 * -9158385221.9960216410973 = -666967987589.15182922615022900
  s21_decimal d1 = {{0xf4c39d6d, 0x10, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x36ce5b5d, 0xc5448a02, 0x1364, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {
      {0xfd0e534, 0x9cba3e84, 0xd7824c81, sign_and_exp_bits(1, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_105) {
  // 567680763 * -3911.1953 = -2220310332146.0139
  s21_decimal d1 = {{0x21d61efb, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x254cd11, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0xd6630dab, 0x4ee19a, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_106) {
  // 33251812911258103.53 * -2157156549223542618421377300 = S21_SMALL_ERR
  s21_decimal d1 = {{0x475424b1, 0x2e256ac4, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0xeb1eb914, 0xda5c90e2, 0x6f85baa, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_107) {
  // 9.0 * 12638836924.529 = 113749532320.7610
  s21_decimal d1 = {{0x5a, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xb562a071, 0xb7e, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0xc4ac67ba, 0x40a8b, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_108) {
  //-494871941107550040 * -4506138343688882 = S21_HUGE_ERR
  s21_decimal d1 = {{0x93060758, 0x6de2368, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1748cab2, 0x10024f, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_109) {
  // 17411211411.86750 * 6.31 = 109864744008.8839250
  s21_decimal d1 = {{0x5b21a0be, 0x62f8a, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0x277, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0x9fe33452, 0xf3f2e06, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_110) {
  // 16.2874510000000 * -650967453981764107.80 = -10602600509322737799.351217800
  s21_decimal d1 = {{0x2d4fbf80, 0x9422, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {{0xd4596c9c, 0x8766190a, 0x3, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {
      {0xd0bfae88, 0x4f680c74, 0x224243fd, sign_and_exp_bits(1, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_111) {
  //-6432970469 * 6432970469 = -41383109055026079961
  s21_decimal d1 = {{0x7f6f56e5, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x7f6f56e5, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xae14a8d9, 0x3e4e566d, 0x2, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_112) {
  //-27258115.70890008914 * -705599797.12147923932699 =
  // 19233320914113709.152270164191
  s21_decimal d1 = {{0x878c6952, 0x25d4072e, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {{0x6240161b, 0x106d1967, 0xef1, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {
      {0xc8ce20df, 0xf5ab876d, 0x3e256e1f, sign_and_exp_bits(0, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_113) {
  // 247909661862418215750.92170 * -62679939785932436234640262 = S21_SMALL_ERR
  s21_decimal d1 = {
      {0xee6617ca, 0xf8488ac0, 0x1481b0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {
      {0x73651b86, 0x5827dfb8, 0x33d8fe, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_114) {
  // 929455565457248635.661 * -9924.4622505450 = -9224346672939421356655.798804
  s21_decimal d1 = {{0x15224b0d, 0x62c98051, 0x32, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x307865ea, 0x5a43, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {
      {0x74a26a14, 0x20c5c5d6, 0x1dce3363, sign_and_exp_bits(1, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_115) {
  //-976476622.8847707043213 * -369.50520592 = 360813195615.10338353222539034
  s21_decimal d1 = {{0x2e4c358d, 0x595a8d30, 0x211, sign_and_exp_bits(1, 13)}};
  s21_decimal d2 = {{0x9a6c3310, 0x8, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal correct = {
      {0xf9a571a, 0xbc95df0a, 0x7495c49c, sign_and_exp_bits(0, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_116) {
  // 44015176857986 * -79779752344.85 = -3511519909144896038948472.10
  s21_decimal d1 = {{0x14fb3982, 0x2808, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x84613fb5, 0x741, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {
      {0x7b08a6ea, 0x9233efba, 0x1227753, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_117) {
  // 998.59780 * 6 = 5991.58680
  s21_decimal d1 = {{0x5f3bd44, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0x6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x23b66f98, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_118) {
  //-455447399349 * -37008620 = 16855479732495388380
  s21_decimal d1 = {{0xac7cbb5, 0x6a, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x234b4ec, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x362f0edc, 0xe9eab183, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_119) {
  //-15136164539193300714 * -15136164539193300714 = S21_HUGE_ERR
  s21_decimal d1 = {{0x1c7b16ea, 0xd20e7574, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1c7b16ea, 0xd20e7574, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_120) {
  // 84402.06632 * 922786086840.10933 = 77885052500652186.9067107656
  s21_decimal d1 = {{0xf7135528, 0x1, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0xdafa4db5, 0x147d6e7, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0xba583d48, 0x900b9f31, 0x2844003, sign_and_exp_bits(0, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_121) {
  // 65182470013425764 * -65182470013425764 = S21_SMALL_ERR
  s21_decimal d1 = {{0x72bb9864, 0xe7931c, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x72bb9864, 0xe7931c, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_122) {
  //-197663640226192501 * -197663640226192501 = S21_HUGE_ERR
  s21_decimal d1 = {{0x94b15c75, 0x2be3e08, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x94b15c75, 0x2be3e08, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_123) {
  // 9.4000000000000000 * 9.4000000000000000 = 88.36000000000000000000000000
  s21_decimal d1 = {{0x80e30000, 0x14df480, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal d2 = {{0x80e30000, 0x14df480, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0x4000000, 0xcdd939e9, 0x1c8cf7c7, sign_and_exp_bits(0, 26)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_124) {
  // 3385463 * 3385463 = 11461359724369
  s21_decimal d1 = {{0x33a877, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x33a877, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x8e466751, 0xa6c, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_125) {
  //-8.1943000000000000000 * -8.1943000000000000000
  //= 67.146552490000000000000000000
  s21_decimal d1 = {{0xedd58000, 0x71300458, 0x4, sign_and_exp_bits(1, 19)}};
  s21_decimal d2 = {{0xedd58000, 0x71300458, 0x4, sign_and_exp_bits(1, 19)}};
  s21_decimal correct = {
      {0xf8680000, 0x3a7ed5fc, 0xd8f65390, sign_and_exp_bits(0, 27)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_126) {
  // 930772657277.381074044100000 * 930772657277.381074044100000 =
  // 866337739535197087656021.6446
  s21_decimal d1 = {
      {0xd5f49da0, 0xdb02d7a4, 0x301eac6, sign_and_exp_bits(0, 15)}};
  s21_decimal d2 = {
      {0xd5f49da0, 0xdb02d7a4, 0x301eac6, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {
      {0x1493917e, 0xa7b60091, 0x1bfe2d85, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_127) {
  //-117879201151537769220996255.3 * -117879201151537769220996255.3 =
  // S21_HUGE_ERR
  s21_decimal d1 = {
      {0x97a1de39, 0xfd5b709f, 0x3cf12ea, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {
      {0x97a1de39, 0xfd5b709f, 0x3cf12ea, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_128) {
  // 270663620169398 * -9383565744488010654 = S21_SMALL_ERR
  s21_decimal d1 = {{0xc8ef0eb6, 0xf62a, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xebb539e, 0x82391f54, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_129) {
  // 8093655849706375553.9 * 8093655849706375553.9 = S21_HUGE_ERR
  s21_decimal d1 = {{0x1bdf13, 0x63386b22, 0x4, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x1bdf13, 0x63386b22, 0x4, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_130) {
  //-3639859329953098481122 * -141.777419133605844407996 =
  // 516049861810126173011003.63429
  s21_decimal d1 = {{0x85c5bde2, 0x513207ca, 0xc5, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xe66cd6bc, 0xc4f04d0d, 0x1e05, sign_and_exp_bits(1, 21)}};
  s21_decimal correct = {
      {0x38107ea5, 0x6d4a5949, 0xa6bea4e2, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_131) {
  // 2 * -9143470.3643 = -18286940.7286
  s21_decimal d1 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x49eedb1b, 0x15, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x93ddb636, 0x2a, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_132) {
  // 5650352534147170444146144.30 * 5650352534147170444146144.30 = S21_HUGE_ERR
  s21_decimal d1 = {
      {0x95560b9e, 0x76d2f902, 0x1d362de, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0x95560b9e, 0x76d2f902, 0x1d362de, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_133) {
  //-5719.1339214625679 * -5719.1339214625679 = 32708492.811623809776525440862
  s21_decimal d1 = {{0x521ddb8f, 0xcb2f38, 0x0, sign_and_exp_bits(1, 13)}};
  s21_decimal d2 = {{0x521ddb8f, 0xcb2f38, 0x0, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {
      {0x3282f75e, 0x4123c3e9, 0x69afd4c4, sign_and_exp_bits(0, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_134) {
  //-7678420586042.102667 * -7678420586042.102667 =
  // 58958142696155147366038378.359
  s21_decimal d1 = {{0x4b16138b, 0x6a8f3ad7, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x4b16138b, 0x6a8f3ad7, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {
      {0xbb2e1777, 0xd8163cf2, 0xbe810857, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_135) {
  // 64851106703 * -64476792129505499171832200 = S21_SMALL_ERR
  s21_decimal d1 = {{0x196d5b8f, 0xf, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xc978c188, 0xe7b3abb0, 0x35557d, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_136) {
  //-15542878630.5 * 443034704621.58549679331 = -6886034643032720807137.4642744
  s21_decimal d1 = {{0x30471081, 0x24, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x9379fce3, 0xb229877c, 0x961, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {
      {0x68251e38, 0xe4acb7aa, 0xde7ff18b, sign_and_exp_bits(1, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_137) {
  //-963894325.7556572628586 * -5015.73 = 4834633686522.422803037765778
  s21_decimal d1 = {{0x60ee66a, 0x87358f70, 0x20a, sign_and_exp_bits(1, 13)}};
  s21_decimal d2 = {{0x7a745, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {
      {0xa7394092, 0x4e11e78d, 0xf9f1d81, sign_and_exp_bits(0, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_138) {
  //-0 * -9341592864483676 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1452e95c, 0x213021, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_139) {
  // 791239 * 791239 = 626059155121
  s21_decimal d1 = {{0xc12c7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xc12c7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xc40896b1, 0x91, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_140) {
  //-9.110000000000 * -9.110000000000 = 82.992100000000000000000000
  s21_decimal d1 = {{0x16505c00, 0x849, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal d2 = {{0x16505c00, 0x849, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {
      {0xa1100000, 0xc1866109, 0x44a642, sign_and_exp_bits(0, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_141) {
  //-646 * 79663451.611076081194 = -51462589740.755148451324
  s21_decimal d1 = {{0x286, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x4bb5b62a, 0x518d6f2a, 0x4, sign_and_exp_bits(0, 12)}};
  s21_decimal correct = {
      {0xc89adfc, 0xcae684bb, 0xae5, sign_and_exp_bits(1, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_142) {
  //-24846337485895196366 * -5631689.4382000 = 139926856397268718846517221.58
  s21_decimal d1 = {{0x48415ece, 0x58cfec4d, 0x1, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x4c7c07b0, 0x3338, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {
      {0xee9e75ae, 0x7994feeb, 0x2d367a70, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_143) {
  // 5 * 99715779840.14 = 498578899200.70
  s21_decimal d1 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xb05d140e, 0x911, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0x71d16446, 0x2d58, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_144) {
  //-90163419372522244 * -87711290470.12840000000 =
  // 7908349866363300663067646536.1
  s21_decimal d1 = {{0xf76f0b04, 0x1405326, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x26d34a00, 0x7bde24d3, 0x1db, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {
      {0xa42c06d1, 0xf17a1e35, 0xff88563c, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_145) {
  // 8797621605264196 * -925862 = -8145383534693119036952
  s21_decimal d1 = {{0xe6a66b44, 0x1f4163, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xe20a6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x3b0a0e18, 0x8fe780b6, 0x1b9, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_146) {
  // 88.7862223483934 * -969610272.62489398385227669 =
  // -86088033256.56017953148639308
  s21_decimal d1 = {{0x8870b41e, 0x32781, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {
      {0x523ab795, 0xd1f9fe8f, 0x50344b, sign_and_exp_bits(1, 17)}};
  s21_decimal correct = {
      {0xb988184c, 0x68a960dc, 0x1bd10903, sign_and_exp_bits(1, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_147) {
  // 353 * 48591048910 = 17152640265230
  s21_decimal d1 = {{0x161, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x504090ce, 0xb, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xa907ac0e, 0xf99, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_148) {
  //-882115753761587168588 * 882115753761587168588 = S21_SMALL_ERR
  s21_decimal d1 = {{0x8759854c, 0xd1d0b465, 0x2f, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8759854c, 0xd1d0b465, 0x2f, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_149) {
  // 1125889879928640927022021788 * -927996903042437770003 = S21_SMALL_ERR
  s21_decimal d1 = {
      {0x22057c9c, 0xb09d8943, 0x3a35074, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2b1e6b13, 0x4e8b4a94, 0x32, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_150) {
  //-8946745184332.430000 * 8946745184332.430000 =
  //-80044249393375526859144749.70
  s21_decimal d1 = {{0xe0123ab0, 0x7c293957, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0xe0123ab0, 0x7c293957, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {
      {0x99b549da, 0x6fb464ae, 0x19dd1ae9, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_151) {
  //-911495919477521 * -3.542415910 = 3228897647057249.277759110
  s21_decimal d1 = {{0x2e7ea311, 0x33d00, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xd324fa26, 0x0, 0x0, sign_and_exp_bits(1, 9)}};
  s21_decimal correct = {
      {0x836ece86, 0xe46625a4, 0x2abbe, sign_and_exp_bits(0, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_152) {
  //-45669.843307186955640 * 8726280010129 = -398527840717229230.12071587368
  s21_decimal d1 = {{0xc8a12578, 0x79cbe084, 0x2, sign_and_exp_bits(1, 15)}};
  s21_decimal d2 = {{0xbed1f991, 0x7ef, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x99377e28, 0x8204c096, 0x80c57349, sign_and_exp_bits(1, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_153) {
  // 767476656969 * 47 = 36071402877543
  s21_decimal d1 = {{0xb12c6b49, 0xb2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2f, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x8727b267, 0x20ce, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_154) {
  // 947805614051.89 * 8.2 = 7772006035225.498
  s21_decimal d1 = {{0xd1b1b505, 0x5633, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0x52, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x2aebfb9a, 0x1b9c99, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_155) {
  // 62995330.0068 * -7600000000000000 = -478764508051680000000000.0000
  s21_decimal d1 = {{0xac248664, 0x92, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0xe44b0000, 0x1b0028, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x6f4c0000, 0xde89f604, 0xf783f47, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_156) {
  //-325436282935229248729680872 * 31854866224.7559600819511426 = S21_SMALL_ERR
  s21_decimal d1 = {
      {0xe3be8be8, 0x3f89fa9e, 0x10d31d0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x9cada082, 0x95228176, 0x1077f4d, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_157) {
  //-952981347531894 * 0.67327 = -641613751852798.27338
  s21_decimal d1 = {{0x42b27c76, 0x362bb, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x106ff, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0x1b2abd8a, 0x7a6afeca, 0x3, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_158) {
  // 1.3 * 642087369590707.30 = 834713580467919.490
  s21_decimal d1 = {{0xd, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x8dec020a, 0xe41d81, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0x34fc1a82, 0xb957f94, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_159) {
  // 72.494118354 * -12482290.7060408639 = -904892659.7727606103270060206
  s21_decimal d1 = {{0xe0fc75d2, 0x10, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0xcb2ad13f, 0x1bb75c5, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {
      {0x54c570ae, 0xcbc08b48, 0x1d3d18bd, sign_and_exp_bits(1, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_160) {
  // 401707789 * -419830235653.8 = -168649075719836967448.2
  s21_decimal d1 = {{0x17f1930d, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x7e52143a, 0x3d1, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0xcc6254f2, 0x6cc2c842, 0x5b, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_161) {
  // 9170818501353399.36 * 5360698765287902844653430 = S21_HUGE_ERR
  s21_decimal d1 = {{0x734663a0, 0xcba2115, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0x9c9d8f76, 0xff75e06, 0x46f2c, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_162) {
  // 46.6661024047332907 * 46.6661024047332907 = 2177.7251136490542170127394009
  // bank_round error
  s21_decimal d1 = {{0x98dc7e2b, 0x679e9ba, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal d2 = {{0x98dc7e2b, 0x679e9ba, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0x1acae4d9, 0xa5b3b430, 0x465db84d, sign_and_exp_bits(0, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_163) {
  //-2271127.6617313 * -2271127.6617313 = 5158020855881.08223851339969
  s21_decimal d1 = {{0xe1933e61, 0x14a7, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0xe1933e61, 0x14a7, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {
      {0x349920c1, 0x169eb2e5, 0x1aaa957, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_164) {
  //-661094544 * -45641823712 = 30173560634213027328
  s21_decimal d1 = {{0x27678090, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xa076f5e0, 0xa, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xcafa4e00, 0xa2be0587, 0x1, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_165) {
  // 0.6775589 * -176587098220330.7491058406 = -119648160024359.26000032934051
  s21_decimal d1 = {{0x676325, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0xb2fe2e6, 0xec97877, 0x175f0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {
      {0x5519e8a3, 0x29593df0, 0x26a91057, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_166) {
  // 7469180.7 * -0.5637069 = -4210428.69793683
  s21_decimal d1 = {{0x473b4df, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x5603cd, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0xaeb07393, 0x17eef, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_167) {
  //-78.87811396 * -32980.2 = 2601415.974023592
  s21_decimal d1 = {{0xd6267344, 0x1, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0x5084a, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x5b0b71a8, 0x93df9, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_168) {
  //-28254625384860451695086.60 * -7647999050463 = S21_HUGE_ERR
  s21_decimal d1 = {{0x48ed6134, 0xa1916af2, 0x25650, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0xb04442df, 0x6f4, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_169) {
  //-313092181307951699171359 * -53.50306416 = 16751391064513692478946239.411
  s21_decimal d1 = {{0x718b981f, 0xc2db421c, 0x424c, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3ee73270, 0x1, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal correct = {
      {0x31c163b3, 0x370a47a1, 0x36206d09, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_170) {
  //-2 * 2 = -4
  s21_decimal d1 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_171) {
  // 9147099755.737 * -3101350 = -28368357827454944.950
  s21_decimal d1 = {{0xb9a1b4d9, 0x851, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x2f52a6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x5e9fc6b6, 0x89b0a724, 0x1, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_172) {
  // 3170.85220299036913 * -278968201025431126.4455904050 =
  // -884566934785748439836.5621015
  s21_decimal d1 = {{0xef7358f1, 0x4668353, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {
      {0x96e4b32, 0xcd962bc2, 0x9039224, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {
      {0xbeb1bb17, 0x33a79762, 0x1c94f758, sign_and_exp_bits(1, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_173) {
  // 8.0 * 8.0 = 64.00
  s21_decimal d1 = {{0x50, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x50, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x1900, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_174) {
  // 93021.26 * -623520229927940895898679280 = S21_SMALL_ERR
  s21_decimal d1 = {{0x8df06e, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {
      {0xd10d37f0, 0x64d1d43f, 0x203c38b, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_175) {
  //-7097597.5018 * -7097597.5018 = 50375890297557.60100324
  s21_decimal d1 = {{0x867f6e6a, 0x10, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x867f6e6a, 0x10, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {
      {0xb4cb43e4, 0x16977445, 0x111, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_176) {
  //-960055.2852112432434661 * -13031239633727330256359375 = S21_HUGE_ERR
  s21_decimal d1 = {{0x54dc0de5, 0x726f7116, 0x208, sign_and_exp_bits(1, 16)}};
  s21_decimal d2 = {{0x9d1f0fcf, 0xea827866, 0xac778, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_177) {
  //-93.3 * -8182844759097604 = 763459416023806453.2
  s21_decimal d1 = {{0x3a5, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x31e4104, 0x1d1241, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x5d42f394, 0x69f386f0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_178) {
  // 3096334 * 957 = 2963191638
  s21_decimal d1 = {{0x2f3f0e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3bd, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xb09eb756, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_179) {
  // 7574272718117 * -7574272718117 = -57369607208411487340025689
  s21_decimal d1 = {{0x85d5b525, 0x6e3, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x85d5b525, 0x6e3, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x61bf5759, 0xa374bc3d, 0x2f747c, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_180) {
  // 2.2 * -87132285828276260676 = -191691028822207773487.2
  s21_decimal d1 = {{0x16, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x6e358f44, 0xb9341050, 0x4, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x789a4fd8, 0xea7966e9, 0x67, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_181) {
  //-96147.83344275 * 713018553.459279770527 = -68555189119593.368221004436392
  s21_decimal d1 = {{0x9dbeee93, 0x8be, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0x133db39f, 0xa71ec4a3, 0x26, sign_and_exp_bits(0, 12)}};
  s21_decimal correct = {
      {0xa89593a8, 0xee4ea132, 0xdd8385f8, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_182) {
  // 247542690714537063 * 247542690714537063 = S21_HUGE_ERR
  s21_decimal d1 = {{0x2c8cc67, 0x36f72c4, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2c8cc67, 0x36f72c4, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_183) {
  //-463669132212260290322 * -769606283729935721977461 = S21_HUGE_ERR
  s21_decimal d1 = {{0x6967bf12, 0x22b3ab1f, 0x19, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8c325675, 0x70b37f87, 0xa2f8, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_184) {
  // 739970572297990 * -71442868526843 = -52865620310418072456509945570
  s21_decimal d1 = {{0xd31b2706, 0x2a0ff, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x16ccdefb, 0x40fa, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x243e76e2, 0x8477debf, 0xaad16a8b, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_185) {
  // 2582819178870062106200 * -87432.693577 = -225822837830944893230343831.88
  s21_decimal d1 = {{0xe026c658, 0x3d106d1, 0x8c, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5b650749, 0x14, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {
      {0xf2441354, 0xdda2843b, 0x48f7a098, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_186) {
  // 101501807551696895221990400 * 6082.3 = S21_HUGE_ERR
  s21_decimal d1 = {{0x17c08400, 0x34fe3b9, 0x53f5d8, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xed97, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_187) {
  //-14519184631173251970446723 * -1560440 = S21_HUGE_ERR
  s21_decimal d1 = {{0xf7ad3583, 0x937432ff, 0xc028e, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x17cf78, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_188) {
  //-48544.30 * -48544.30 = 2356549062.4900
  s21_decimal d1 = {{0x4a129e, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x4a129e, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0xc4b29984, 0x156e, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_189) {
  //-11386009.3104373316118 * -11386009.3104373316118 =
  // 129641208017365.59970721547065
  // bank round error
  s21_decimal d1 = {{0xfb133a16, 0x2c204f6b, 0x6, sign_and_exp_bits(1, 13)}};
  s21_decimal d2 = {{0xfb133a16, 0x2c204f6b, 0x6, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {
      {0x51854339, 0xe15f97f0, 0x29e3ab5c, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);

  // printf("\nd1 exp = %d\n", get_decimal_exp(d1));
  // print_decimal_bits(d1);
  // printf("\nd2 exp = %d\n", get_decimal_exp(d2));
  // print_decimal_bits(d2);
  // printf("\nd1 sign * d2 sign: %d\n", get_decimal_sign(d1) !=
  // get_decimal_sign(d2) ? 1 : 0); printf("\ncorrect exp = %d\n",
  // get_decimal_exp(correct)); print_decimal_bits(correct); printf("\ns21_mul
  // err_code: %d\n", s21_mul(d1, d2, &result)); printf("\nres exp = %d\n",
  // get_decimal_exp(result)); print_decimal_bits(result);
  // ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);

  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_190) {
  // 276057516669634718670 * -23591459310420.5680000 = S21_SMALL_ERR
  s21_decimal d1 = {{0xae0dabce, 0xf71150cb, 0xe, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xcaff8d80, 0xc9f9007f, 0xc, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_191) {
  //-68.290319541092545828358 * -82592402675 = 5640261570342.3367544966353701
  s21_decimal d1 = {{0x21d9606, 0x6905d01, 0xe76, sign_and_exp_bits(1, 21)}};
  s21_decimal d2 = {{0x3ae40cf3, 0x13, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xf221325, 0xf9d022b6, 0xb63f2673, sign_and_exp_bits(0, 16)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_192) {
  // 4254.7 * -280664.00565900000000000 = -1194141144.877347300000000000
  s21_decimal d1 = {{0xa633, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xd3ea7800, 0x7b8d3485, 0x5f1, sign_and_exp_bits(1, 17)}};
  s21_decimal correct = {
      {0x4185e800, 0x2d303e13, 0x3dbc539, sign_and_exp_bits(1, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_193) {
  //-581112674615268009656 * -913706239880778 = S21_HUGE_ERR
  s21_decimal d1 = {{0x1834e6b8, 0x808ef2b2, 0x1f, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xcfdb6e4a, 0x33f02, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_194) {
  // 918373127 * -918373127 = -843409200395758129
  s21_decimal d1 = {{0x36bd4307, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x36bd4307, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xfde2aa31, 0xbb46432, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_195) {
  // 291403 * 247.8162802 = 72214407.4991206
  s21_decimal d1 = {{0x4724b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x93b5c372, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {{0x45110666, 0x290c9, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_196) {
  //-9609665722465271 * -9609665722465271 = S21_HUGE_ERR
  s21_decimal d1 = {{0xa7cc3bf7, 0x2223f0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xa7cc3bf7, 0x2223f0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_HUGE_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_197) {
  // 169688.823 * 4402581147469909 = 747068813076158286127.107
  s21_decimal d1 = {{0xa1d3ef7, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0xcd63c855, 0xfa41f, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x596be003, 0xae77388e, 0x9e32, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_198) {
  // 622473727879463934886 * 8.972398790896825530740778046 =
  // 5585082523390741806597.4760793
  s21_decimal d1 = {{0xcc9d9ba6, 0xbe8eed7f, 0x21, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xc8a6243e, 0x13283a3e, 0x1cfdcb59, sign_and_exp_bits(0, 27)}};
  s21_decimal correct = {
      {0x92d69559, 0xaf7f1230, 0xb476b846, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_199) {
  //-66.7878056 * -316683 = 21150562.6408248
  s21_decimal d1 = {{0x27cf02a8, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0x4d50b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xfdbae538, 0xc05c, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_200) {
  // 79228162514264337593543950335 * 0.9999999999999999999999999999 =
  // 79228162514264337593543950327
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xfffffff, 0x3e250261, 0x204fce5e, sign_and_exp_bits(0, 28)}};
  s21_decimal correct = {
      {0xfffffff7, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_201) {
  // 442320 * 40 = 17692800
  s21_decimal d1 = {{0x6bfd0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x28, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x10df880, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_202) {
  // 38410781346 * 3 = 115232344038
  s21_decimal d1 = {{0xf17602a2, 0x8, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xd46207e6, 0x1a, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_203) {
  // 32768 * -2 = -65536
  s21_decimal d1 = {{0x8000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x10000, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_204) {
  // 32768 * 2 = 65536
  s21_decimal d1 = {{0x8000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x10000, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_205) {
  // 30064771176 * -2 = -60129542352
  s21_decimal d1 = {{0x68, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xd0, 0xe, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_206) {
  //-101 * 10.01 = -1011.01
  s21_decimal d1 = {{0x65, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3e9, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {{0x18aed, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_207) {
  // 2.25 * -1.5 = -3.375
  s21_decimal d1 = {{0xe1, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0xf, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0xd2f, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_208) {
  // 0 * 0.015 = 0.000
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_209) {
  // 0.0000 * 5.7 = 0.00000
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x39, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_210) {
  // 0.00 * 5.00007 = 0.0000000
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0x7a127, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_211) {
  // 0.0 * 5.7 = 0.00
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x39, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_212) {
  // 101 * 0 = 0
  s21_decimal d1 = {{0x65, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_213) {
  //-579 * 0 = -0
  s21_decimal d1 = {{0x243, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_214) {
  // 7 * -3 = -21
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x15, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_215) {
  //-10 * 3 = -30
  s21_decimal d1 = {{0xa, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_216) {
  // 10.0 * 3 = 30.0
  s21_decimal d1 = {{0x64, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x12c, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_217) {
  //-7 * -3.0 = 21.0
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1e, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0xd2, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_218) {
  // 2 * 3 = 6
  s21_decimal d1 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_219) {
  // 7.0 * 7 = 49.0
  s21_decimal d1 = {{0x46, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1ea, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_220) {
  // 7 * 7.0 = 49.0
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x46, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x1ea, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_221) {
  // 7922816251426433759354395033.5 * 0.1 = 792281625142643375935439503.35
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_222) {
  // 7922816251426433759354395033.5 * 0.01 = 79228162514264337593543950.335
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_223) {
  // 7922816251426433759354395033.5 * 0.7 = 5545971375998503631548076523.4
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x33333332, 0x33333333, 0xb3333333, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_224) {
  // 79228162514264337593543950335 * 0.4 = 31691265005705735037417580134
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x66666666, 0x66666666, 0x66666666, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_225) {
  // 0.0000000000000000000000000001 * 8 = 0.0000000000000000000000000008
  s21_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal d2 = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_226) {
  // 20 * 0.00005 = 0.00100
  s21_decimal d1 = {{0x14, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0x64, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_227) {
  // 936582642837 * 0.1041747302401649 = 97568244165.1651857686838213
  s21_decimal d1 = {{0x10acfc95, 0xda, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xb1e7c671, 0x3b376, 0x0, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0x1729bbc5, 0x250d4b90, 0x32710cb, sign_and_exp_bits(0, 16)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_228) {
  // 936582642836 * -0.1041747302401641 = -97568244165.0602617723293876
  s21_decimal d1 = {{0x10acfc94, 0xda, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xb1e7c669, 0x3b376, 0x0, sign_and_exp_bits(1, 16)}};
  s21_decimal correct = {
      {0xdfda10b4, 0x25099148, 0x32710cb, sign_and_exp_bits(1, 16)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_229) {
  //-75384834.34934734873487 * -1349.34984 = 101720514167.71834911982103692
  s21_decimal d1 = {{0xe36ae38f, 0xa9793779, 0x198, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0x80af1c8, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0xf2502c8c, 0x3c235027, 0x20de1fac, sign_and_exp_bits(0, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_230) {
  // 4449249363747.434387 * 43764 = 194716949155042718.512668
  s21_decimal d1 = {{0x234c6f93, 0x3dbee8b9, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0xaaf4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x66f1f61c, 0xa080c1e6, 0x293b, sign_and_exp_bits(0, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_231) {
  //-0.3183718237812378127 * -0.3183718237812378127 =
  // 0.1013606181777915428619956242
  s21_decimal d1 = {{0x85bd4a0f, 0x2c2ed6de, 0x0, sign_and_exp_bits(1, 19)}};
  s21_decimal d2 = {{0x85bd4a0f, 0x2c2ed6de, 0x0, sign_and_exp_bits(1, 19)}};
  s21_decimal correct = {
      {0x61a43012, 0x376725ae, 0x3466f75, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_232) {
  // 948347948.43877834 * 10000000000000000 = 9483479484387783400000000.000
  s21_decimal d1 = {{0x530431ca, 0x150ebbe, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0x6fc10000, 0x2386f2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x903b1000, 0xfc186651, 0x1ea48ce4, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_233) {
  //-184838746726726348023 * 0.00000000193289 = -357272965160.62209083017647
  s21_decimal d1 = {{0x8eebacf7, 0x52724d4, 0xa, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2f309, 0x0, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {
      {0x156589af, 0x9fff2cfa, 0x1d8d8c, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_234) {
  // 45284674874386437639 * 0.00000000048934 = 22159602803.03225939426826
  s21_decimal d1 = {{0xa8dc5607, 0x74737bde, 0x2, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xbf26, 0x0, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {
      {0x74e3fe0a, 0x728f8309, 0x1d53f, sign_and_exp_bits(0, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_235) {
  // 75384834.34934734873487 * 1349.34984 = 101720514167.71834911982103692
  s21_decimal d1 = {{0xe36ae38f, 0xa9793779, 0x198, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {{0x80af1c8, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0xf2502c8c, 0x3c235027, 0x20de1fac, sign_and_exp_bits(0, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_236) {
  // 7.9228162514264337593543950335 * 0.5 = 3.9614081257132168796771975168
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 28)}};
  s21_decimal d2 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x80000000, sign_and_exp_bits(0, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_237) {
  // 0.0047371696578 * -0.14084507042253521126760531 =
  // -0.0006672069940563380281690126
  s21_decimal d1 = {{0x792b9c2, 0xb, 0x0, sign_and_exp_bits(0, 13)}};
  s21_decimal d2 = {
      {0xe2d12053, 0xa81c2d12, 0xba682, sign_and_exp_bits(1, 26)}};
  s21_decimal correct = {
      {0x8262480e, 0xa2dfc0cf, 0x584dd, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_238) {
  // 0.00047371696578 * -0.14084507042253521126760530 =
  // -0.0000667206994056338028169013
  s21_decimal d1 = {{0x792b9c2, 0xb, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {
      {0xe2d12052, 0xa81c2d12, 0xba682, sign_and_exp_bits(1, 26)}};
  s21_decimal correct = {
      {0xc03d0735, 0x5d166014, 0x8d49, sign_and_exp_bits(1, 28)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_239) {
  // 688072.82296528544988060654870 * 55 = 37844005.263090699743433360178
  s21_decimal d1 = {
      {0xb40b1d16, 0x6f9c81d2, 0xde540cc7, sign_and_exp_bits(0, 23)}};
  s21_decimal d2 = {{0x37, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x496c8332, 0x16fc7a9a, 0x7a47d3d4, sign_and_exp_bits(0, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_240) {
  // 8287782888760.950000000 * 8287782888760.950000000 =
  // 68687345211238797321826244.902
  s21_decimal d1 = {{0xbd2e0980, 0x4817a2c5, 0x1c1, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0xbd2e0980, 0x4817a2c5, 0x1c1, sign_and_exp_bits(0, 9)}};
  s21_decimal correct = {
      {0xd0d09926, 0x3ac2882, 0xddf0d71d, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_mul_241) {
  // Segmentation fault test
  s21_decimal d1 = {{0xbd2e0980, 0x4817a2c5, 0x1c1, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0xbd2e0980, 0x4817a2c5, 0x1c1, sign_and_exp_bits(0, 9)}};
  // s21_decimal correct = {
  // {0xd0d09926, 0x3ac2882, 0xddf0d71d, sign_and_exp_bits(0, 3)}};
  // s21_decimal result;

  ck_assert_int_eq(s21_mul(d1, d2, NULL), S21_OK);
  // ASSERT_BITS_EQ
}
END_TEST

Suite *mul_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "S21_MUL" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("S21_MUL");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_mul_0);
  tcase_add_test(tc1_1, s21_mul_1);
  tcase_add_test(tc1_1, s21_mul_2);
  tcase_add_test(tc1_1, s21_mul_3);
  tcase_add_test(tc1_1, s21_mul_4);
  tcase_add_test(tc1_1, s21_mul_5);
  tcase_add_test(tc1_1, s21_mul_6);
  tcase_add_test(tc1_1, s21_mul_7);
  tcase_add_test(tc1_1, s21_mul_8);
  tcase_add_test(tc1_1, s21_mul_9);
  tcase_add_test(tc1_1, s21_mul_10);
  tcase_add_test(tc1_1, s21_mul_11);
  tcase_add_test(tc1_1, s21_mul_12);
  tcase_add_test(tc1_1, s21_mul_13);
  tcase_add_test(tc1_1, s21_mul_14);
  tcase_add_test(tc1_1, s21_mul_15);
  tcase_add_test(tc1_1, s21_mul_16);
  tcase_add_test(tc1_1, s21_mul_17);
  tcase_add_test(tc1_1, s21_mul_18);
  tcase_add_test(tc1_1, s21_mul_19);
  tcase_add_test(tc1_1, s21_mul_20);
  tcase_add_test(tc1_1, s21_mul_21);
  tcase_add_test(tc1_1, s21_mul_22);
  tcase_add_test(tc1_1, s21_mul_23);
  tcase_add_test(tc1_1, s21_mul_24);
  tcase_add_test(tc1_1, s21_mul_25);
  tcase_add_test(tc1_1, s21_mul_26);
  tcase_add_test(tc1_1, s21_mul_27);
  tcase_add_test(tc1_1, s21_mul_28);
  tcase_add_test(tc1_1, s21_mul_29);
  tcase_add_test(tc1_1, s21_mul_30);
  tcase_add_test(tc1_1, s21_mul_31);
  tcase_add_test(tc1_1, s21_mul_32);
  tcase_add_test(tc1_1, s21_mul_33);
  tcase_add_test(tc1_1, s21_mul_34);
  tcase_add_test(tc1_1, s21_mul_35);
  tcase_add_test(tc1_1, s21_mul_36);
  tcase_add_test(tc1_1, s21_mul_37);
  tcase_add_test(tc1_1, s21_mul_38);
  tcase_add_test(tc1_1, s21_mul_39);
  tcase_add_test(tc1_1, s21_mul_40);
  tcase_add_test(tc1_1, s21_mul_41);
  tcase_add_test(tc1_1, s21_mul_42);
  tcase_add_test(tc1_1, s21_mul_43);
  tcase_add_test(tc1_1, s21_mul_44);
  tcase_add_test(tc1_1, s21_mul_45);
  tcase_add_test(tc1_1, s21_mul_46);
  tcase_add_test(tc1_1, s21_mul_47);
  tcase_add_test(tc1_1, s21_mul_48);
  tcase_add_test(tc1_1, s21_mul_49);
  tcase_add_test(tc1_1, s21_mul_50);
  tcase_add_test(tc1_1, s21_mul_51);
  tcase_add_test(tc1_1, s21_mul_52);
  tcase_add_test(tc1_1, s21_mul_53);
  tcase_add_test(tc1_1, s21_mul_54);
  tcase_add_test(tc1_1, s21_mul_55);
  tcase_add_test(tc1_1, s21_mul_56);
  tcase_add_test(tc1_1, s21_mul_57);
  tcase_add_test(tc1_1, s21_mul_58);
  tcase_add_test(tc1_1, s21_mul_59);
  tcase_add_test(tc1_1, s21_mul_60);
  tcase_add_test(tc1_1, s21_mul_61);
  tcase_add_test(tc1_1, s21_mul_62);
  tcase_add_test(tc1_1, s21_mul_63);
  tcase_add_test(tc1_1, s21_mul_64);
  tcase_add_test(tc1_1, s21_mul_65);
  tcase_add_test(tc1_1, s21_mul_66);
  tcase_add_test(tc1_1, s21_mul_67);
  tcase_add_test(tc1_1, s21_mul_68);
  tcase_add_test(tc1_1, s21_mul_69);
  tcase_add_test(tc1_1, s21_mul_70);
  tcase_add_test(tc1_1, s21_mul_71);
  tcase_add_test(tc1_1, s21_mul_72);
  tcase_add_test(tc1_1, s21_mul_73);
  tcase_add_test(tc1_1, s21_mul_74);
  tcase_add_test(tc1_1, s21_mul_75);
  tcase_add_test(tc1_1, s21_mul_76);
  tcase_add_test(tc1_1, s21_mul_77);
  tcase_add_test(tc1_1, s21_mul_78);
  tcase_add_test(tc1_1, s21_mul_79);
  tcase_add_test(tc1_1, s21_mul_80);
  tcase_add_test(tc1_1, s21_mul_81);
  tcase_add_test(tc1_1, s21_mul_82);
  tcase_add_test(tc1_1, s21_mul_83);
  tcase_add_test(tc1_1, s21_mul_84);
  tcase_add_test(tc1_1, s21_mul_85);
  tcase_add_test(tc1_1, s21_mul_86);
  tcase_add_test(tc1_1, s21_mul_87);
  tcase_add_test(tc1_1, s21_mul_88);
  tcase_add_test(tc1_1, s21_mul_89);
  tcase_add_test(tc1_1, s21_mul_90);
  tcase_add_test(tc1_1, s21_mul_91);
  tcase_add_test(tc1_1, s21_mul_92);
  tcase_add_test(tc1_1, s21_mul_93);
  tcase_add_test(tc1_1, s21_mul_94);
  tcase_add_test(tc1_1, s21_mul_95);
  tcase_add_test(tc1_1, s21_mul_96);
  tcase_add_test(tc1_1, s21_mul_97);
  tcase_add_test(tc1_1, s21_mul_98);
  tcase_add_test(tc1_1, s21_mul_99);
  tcase_add_test(tc1_1, s21_mul_100);
  tcase_add_test(tc1_1, s21_mul_101);
  tcase_add_test(tc1_1, s21_mul_102);
  tcase_add_test(tc1_1, s21_mul_103);
  tcase_add_test(tc1_1, s21_mul_104);
  tcase_add_test(tc1_1, s21_mul_105);
  tcase_add_test(tc1_1, s21_mul_106);
  tcase_add_test(tc1_1, s21_mul_107);
  tcase_add_test(tc1_1, s21_mul_108);
  tcase_add_test(tc1_1, s21_mul_109);
  tcase_add_test(tc1_1, s21_mul_110);
  tcase_add_test(tc1_1, s21_mul_111);
  tcase_add_test(tc1_1, s21_mul_112);
  tcase_add_test(tc1_1, s21_mul_113);
  tcase_add_test(tc1_1, s21_mul_114);
  tcase_add_test(tc1_1, s21_mul_115);
  tcase_add_test(tc1_1, s21_mul_116);
  tcase_add_test(tc1_1, s21_mul_117);
  tcase_add_test(tc1_1, s21_mul_118);
  tcase_add_test(tc1_1, s21_mul_119);
  tcase_add_test(tc1_1, s21_mul_120);
  tcase_add_test(tc1_1, s21_mul_121);
  tcase_add_test(tc1_1, s21_mul_122);
  tcase_add_test(tc1_1, s21_mul_123);
  tcase_add_test(tc1_1, s21_mul_124);
  tcase_add_test(tc1_1, s21_mul_125);
  tcase_add_test(tc1_1, s21_mul_126);
  tcase_add_test(tc1_1, s21_mul_127);
  tcase_add_test(tc1_1, s21_mul_128);
  tcase_add_test(tc1_1, s21_mul_129);
  tcase_add_test(tc1_1, s21_mul_130);
  tcase_add_test(tc1_1, s21_mul_131);
  tcase_add_test(tc1_1, s21_mul_132);
  tcase_add_test(tc1_1, s21_mul_133);
  tcase_add_test(tc1_1, s21_mul_134);
  tcase_add_test(tc1_1, s21_mul_135);
  tcase_add_test(tc1_1, s21_mul_136);
  tcase_add_test(tc1_1, s21_mul_137);
  tcase_add_test(tc1_1, s21_mul_138);
  tcase_add_test(tc1_1, s21_mul_139);
  tcase_add_test(tc1_1, s21_mul_140);
  tcase_add_test(tc1_1, s21_mul_141);
  tcase_add_test(tc1_1, s21_mul_142);
  tcase_add_test(tc1_1, s21_mul_143);
  tcase_add_test(tc1_1, s21_mul_144);
  tcase_add_test(tc1_1, s21_mul_145);
  tcase_add_test(tc1_1, s21_mul_146);
  tcase_add_test(tc1_1, s21_mul_147);
  tcase_add_test(tc1_1, s21_mul_148);
  tcase_add_test(tc1_1, s21_mul_149);
  tcase_add_test(tc1_1, s21_mul_150);
  tcase_add_test(tc1_1, s21_mul_151);
  tcase_add_test(tc1_1, s21_mul_152);
  tcase_add_test(tc1_1, s21_mul_153);
  tcase_add_test(tc1_1, s21_mul_154);
  tcase_add_test(tc1_1, s21_mul_155);
  tcase_add_test(tc1_1, s21_mul_156);
  tcase_add_test(tc1_1, s21_mul_157);
  tcase_add_test(tc1_1, s21_mul_158);
  tcase_add_test(tc1_1, s21_mul_159);
  tcase_add_test(tc1_1, s21_mul_160);
  tcase_add_test(tc1_1, s21_mul_161);
  tcase_add_test(tc1_1, s21_mul_162);
  tcase_add_test(tc1_1, s21_mul_163);
  tcase_add_test(tc1_1, s21_mul_164);
  tcase_add_test(tc1_1, s21_mul_165);
  tcase_add_test(tc1_1, s21_mul_166);
  tcase_add_test(tc1_1, s21_mul_167);
  tcase_add_test(tc1_1, s21_mul_168);
  tcase_add_test(tc1_1, s21_mul_169);
  tcase_add_test(tc1_1, s21_mul_170);
  tcase_add_test(tc1_1, s21_mul_171);
  tcase_add_test(tc1_1, s21_mul_172);
  tcase_add_test(tc1_1, s21_mul_173);
  tcase_add_test(tc1_1, s21_mul_174);
  tcase_add_test(tc1_1, s21_mul_175);
  tcase_add_test(tc1_1, s21_mul_176);
  tcase_add_test(tc1_1, s21_mul_177);
  tcase_add_test(tc1_1, s21_mul_178);
  tcase_add_test(tc1_1, s21_mul_179);
  tcase_add_test(tc1_1, s21_mul_180);
  tcase_add_test(tc1_1, s21_mul_181);
  tcase_add_test(tc1_1, s21_mul_182);
  tcase_add_test(tc1_1, s21_mul_183);
  tcase_add_test(tc1_1, s21_mul_184);
  tcase_add_test(tc1_1, s21_mul_185);
  tcase_add_test(tc1_1, s21_mul_186);
  tcase_add_test(tc1_1, s21_mul_187);
  tcase_add_test(tc1_1, s21_mul_188);
  tcase_add_test(tc1_1, s21_mul_189);
  tcase_add_test(tc1_1, s21_mul_190);
  tcase_add_test(tc1_1, s21_mul_191);
  tcase_add_test(tc1_1, s21_mul_192);
  tcase_add_test(tc1_1, s21_mul_193);
  tcase_add_test(tc1_1, s21_mul_194);
  tcase_add_test(tc1_1, s21_mul_195);
  tcase_add_test(tc1_1, s21_mul_196);
  tcase_add_test(tc1_1, s21_mul_197);
  tcase_add_test(tc1_1, s21_mul_198);
  tcase_add_test(tc1_1, s21_mul_199);
  tcase_add_test(tc1_1, s21_mul_200);
  tcase_add_test(tc1_1, s21_mul_201);
  tcase_add_test(tc1_1, s21_mul_202);
  tcase_add_test(tc1_1, s21_mul_203);
  tcase_add_test(tc1_1, s21_mul_204);
  tcase_add_test(tc1_1, s21_mul_205);
  tcase_add_test(tc1_1, s21_mul_206);
  tcase_add_test(tc1_1, s21_mul_207);
  tcase_add_test(tc1_1, s21_mul_208);
  tcase_add_test(tc1_1, s21_mul_209);
  tcase_add_test(tc1_1, s21_mul_210);
  tcase_add_test(tc1_1, s21_mul_211);
  tcase_add_test(tc1_1, s21_mul_212);
  tcase_add_test(tc1_1, s21_mul_213);
  tcase_add_test(tc1_1, s21_mul_214);
  tcase_add_test(tc1_1, s21_mul_215);
  tcase_add_test(tc1_1, s21_mul_216);
  tcase_add_test(tc1_1, s21_mul_217);
  tcase_add_test(tc1_1, s21_mul_218);
  tcase_add_test(tc1_1, s21_mul_219);
  tcase_add_test(tc1_1, s21_mul_220);
  tcase_add_test(tc1_1, s21_mul_221);
  tcase_add_test(tc1_1, s21_mul_222);
  tcase_add_test(tc1_1, s21_mul_223);
  tcase_add_test(tc1_1, s21_mul_224);
  tcase_add_test(tc1_1, s21_mul_225);
  tcase_add_test(tc1_1, s21_mul_226);
  tcase_add_test(tc1_1, s21_mul_227);
  tcase_add_test(tc1_1, s21_mul_228);
  tcase_add_test(tc1_1, s21_mul_229);
  tcase_add_test(tc1_1, s21_mul_230);
  tcase_add_test(tc1_1, s21_mul_231);
  tcase_add_test(tc1_1, s21_mul_232);
  tcase_add_test(tc1_1, s21_mul_233);
  tcase_add_test(tc1_1, s21_mul_234);
  tcase_add_test(tc1_1, s21_mul_235);
  tcase_add_test(tc1_1, s21_mul_236);
  tcase_add_test(tc1_1, s21_mul_237);
  tcase_add_test(tc1_1, s21_mul_238);
  tcase_add_test(tc1_1, s21_mul_239);
  tcase_add_test(tc1_1, s21_mul_240);
  tcase_add_test(tc1_1, s21_mul_241);

  return s1;
}
