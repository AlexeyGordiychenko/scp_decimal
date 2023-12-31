#include "scp_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *           SUBSTRACTION FUNCTION TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(scp_sub_0) {
  //-16771877577118760013302133 - -16771877577118760013302133 = -0
  scp_decimal d1 = {{0x59428975, 0x4e2765b0, 0xddf95, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x59428975, 0x4e2765b0, 0xddf95, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_1) {
  // 3277581140362 - -53258058645.33085574 = 3330839199007.33085574
  scp_decimal d1 = {{0x1f0f418a, 0x2fb, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x6a2fcd86, 0x49e91037, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {
      {0x3ddc1786, 0xe77cc65, 0x12, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_2) {
  //-18372 - 731410805776 = -731410824148
  scp_decimal d1 = {{0x47c4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x4b7b3410, 0xaa, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x4b7b7bd4, 0xaa, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_3) {
  //-2.65 - 2.65 = -5.30
  scp_decimal d1 = {{0x109, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal d2 = {{0x109, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x212, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_4) {
  //-4563780 - -21821060760.41 = 21816496980.41
  scp_decimal d1 = {{0x45a344, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xfa85389, 0x1fc, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0xf4748cf9, 0x1fb, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_5) {
  // 45377918509.19538649606 - 435349641.2 = 44942568867.99538649606
  scp_decimal d1 = {{0xe16eea06, 0xfe832e28, 0xf5, sign_and_exp_bits(0, 11)}};
  scp_decimal d2 = {{0x37d155c, 0x1, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0x5f74fa06, 0xa257eaf3, 0xf3, sign_and_exp_bits(0, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_6) {
  // 160.44 - 77780639204961012599521 = -77780639204961012599360.56
  scp_decimal d1 = {{0x3eac, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {{0x7aa2cae1, 0x7f34d96c, 0x1078, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xe7970138, 0xb0a4ee5f, 0x66f11, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_7) {
  // 7409470.58 - 8423929018713733859832 = -8423929018713726450361.42
  scp_decimal d1 = {{0x2c29f472, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {{0xa10809f8, 0xa97fdaa1, 0x1c8, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xbaf9f06e, 0x35f16722, 0xb262, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_8) {
  //-35352452784636836533670983 - 471192.103222149342700000 =
  //-35352452784636836534142175.103
  scp_decimal d1 = {
      {0x5ad69447, 0x4e3b20ce, 0x1d3e2c, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x9be621e0, 0x600675c9, 0x63c7, sign_and_exp_bits(0, 18)}};
  scp_decimal correct = {
      {0xf249077f, 0x96f82612, 0x723add11, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_9) {
  //-367674072677.1 - 4951012 = -367679023689.1
  scp_decimal d1 = {{0xed32ff3, 0x358, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {{0x4b8be4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x11c6a6db, 0x358, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_10) {
  // 15898350115008170601724173 - -777.0534 = 15898350115008170601724950.053
  scp_decimal d1 = {{0x99f3b90d, 0x4963f2f4, 0xd269b, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x7691a6, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {
      {0x6016b625, 0xae6d0b79, 0x335ece96, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_11) {
  //-1.0 - -1.0 = -0.0
  scp_decimal d1 = {{0xa, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {{0xa, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_12) {
  // 1 - -2012512867 = 2012512868
  scp_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x77f48263, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x77f48264, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_13) {
  //-1347890269835 - -1347890269835 = -0
  scp_decimal d1 = {{0xd4854e8b, 0x139, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xd4854e8b, 0x139, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_14) {
  // 1202.46812168 - 1202.46812168 = 0.00000000
  scp_decimal d1 = {{0xff44be08, 0x1b, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal d2 = {{0xff44be08, 0x1b, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_15) {
  //-5332893259598917375.03 - 6.6 = -5332893259598917381.63
  scp_decimal d1 = {{0xfad95b9f, 0xe8e04878, 0x1c, sign_and_exp_bits(1, 2)}};
  scp_decimal d2 = {{0x42, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0xfad95e33, 0xe8e04878, 0x1c, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_16) {
  // 0.6408214 - 4076108238976864 = -4076108238976863.3591786
  scp_decimal d1 = {{0x61c816, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal d2 = {{0xe7a67760, 0xe7b32, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x3dcc27ea, 0xa9a6f806, 0x8a1, sign_and_exp_bits(1, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_17) {
  // 899.9029607748703152273 - 899.9029607748703152273 = 0.0000000000000000000
  scp_decimal d1 = {{0x5c48e891, 0xd69f9558, 0x1e7, sign_and_exp_bits(0, 19)}};
  scp_decimal d2 = {{0x5c48e891, 0xd69f9558, 0x1e7, sign_and_exp_bits(0, 19)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 19)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_18) {
  // 745425233.6110309091647287016 - -745425233.6110309091647287016 =
  // 1490850467.2220618183294574032
  scp_decimal d1 = {
      {0x85e1eee8, 0xda71af31, 0x18160354, sign_and_exp_bits(0, 19)}};
  scp_decimal d2 = {
      {0x85e1eee8, 0xda71af31, 0x18160354, sign_and_exp_bits(1, 19)}};
  scp_decimal correct = {
      {0xbc3ddd0, 0xb4e35e63, 0x302c06a9, sign_and_exp_bits(0, 19)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_19) {
  //-90452939689.2316062781 - 87190518497.034 = -177643458186.2656062781
  scp_decimal d1 = {{0x48d1d43d, 0x8ddf612, 0x31, sign_and_exp_bits(1, 10)}};
  scp_decimal d2 = {{0x9fe1ff0a, 0x4f4c, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {
      {0x1331353d, 0x4cfb7040, 0x60, sign_and_exp_bits(1, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_20) {
  //-7342133758659441 - 74958.75031710622 = -7342133758734399.75031710622
  scp_decimal d1 = {{0xba940b71, 0x1a15a1, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x688bbb9e, 0x1aa175, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {
      {0xa100239e, 0xdc07dd27, 0x25f53ba, sign_and_exp_bits(1, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_21) {
  //-31283044 - 75140.30 = -31358184.30
  scp_decimal d1 = {{0x1dd5764, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x72a7ae, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0xbae8cabe, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_22) {
  // 29893.8 - 4514418814 = -4514388920.2
  scp_decimal d1 = {{0x48fba, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0xd14907e, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x82c91532, 0xa, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_23) {
  //-52235447915.00486715789 - 683325909291034.58221678800 =
  //-683378144738949.58708394589
  scp_decimal d1 = {{0xe065a98d, 0x2b3f0857, 0x11b, sign_and_exp_bits(1, 11)}};
  scp_decimal d2 = {
      {0x76dbe0d0, 0x2d45b473, 0x3885fd, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {
      {0x57418a5d, 0x5884bccb, 0x388718, sign_and_exp_bits(1, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_24) {
  // 9497024309594809342547464 - -5339163467.60 = 9497024309594814681710931.60
  scp_decimal d1 = {{0x4a2ad608, 0xb82c992e, 0x7db12, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x4fe4e988, 0x7c, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {
      {0x48a084a8, 0xf16bd691, 0x311934f, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_25) {
  //-787878659215.59 - -787878659215.59 = -0.00
  scp_decimal d1 = {{0x3ac2c817, 0x47a8, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal d2 = {{0x3ac2c817, 0x47a8, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_26) {
  //-9988706202067211004165363 - 40868572.3023500 =
  //-9988706202067211045033935.302
  scp_decimal d1 = {{0x48f03cf3, 0xd9259a84, 0x84330, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x8f58788c, 0x173b2, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {
      {0x6e6301c6, 0x3ae394c6, 0x204676d0, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_27) {
  //-9853.8917 - -73808672.9019454858800000 = 73798819.0102454858800000
  scp_decimal d1 = {{0x5df95a5, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal d2 = {{0xee0d2b80, 0xc302541a, 0x9c4b, sign_and_exp_bits(1, 16)}};
  scp_decimal correct = {
      {0xdd59db80, 0x6b81c52c, 0x9c46, sign_and_exp_bits(0, 16)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_28) {
  //-240593334.5311911051473320906 - -1041114.349419 =
  //-239552220.1817721051473320906
  scp_decimal d1 = {
      {0x5879fbca, 0xfdfbe01d, 0x7c62433, sign_and_exp_bits(1, 19)}};
  scp_decimal d2 = {{0x67403f6b, 0xf2, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal correct = {
      {0x59311bca, 0xc5bc1c9e, 0x7bd878e, sign_and_exp_bits(1, 19)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_29) {
  //-3585276.804857360760 - -38075544676 = 38071959399.195142639240
  scp_decimal d1 = {{0x26f87178, 0x31c17642, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal d2 = {{0xdd7ab464, 0x8, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x98c1ce88, 0xe292efae, 0x80f, sign_and_exp_bits(0, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_30) {
  //-42458331521362399701 - 65268077074621 = -42458396789439474322
  scp_decimal d1 = {{0x969391d5, 0x4d3a4b90, 0x2, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x688c98bd, 0x3b5c, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xff202a92, 0x4d3a86ec, 0x2, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_31) {
  // 0.5 - 374.63764769128 = -374.13764769128
  scp_decimal d1 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0xb6641968, 0x2212, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {{0x1228a568, 0x2207, 0x0, sign_and_exp_bits(1, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_32) {
  // 72393679459269 - 732307.298871429489 = 72393678726961.701128570511
  scp_decimal d1 = {{0x778c53c5, 0x41d7, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xbfa84971, 0xa29ad9b, 0x0, sign_and_exp_bits(0, 12)}};
  scp_decimal correct = {
      {0x278d068f, 0x2ffff736, 0x3be1f5, sign_and_exp_bits(0, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_33) {
  //-480511888776.1517161257179 - -939261954420904632930614 =
  // 939261954420424121041837.8483
  scp_decimal d1 = {{0x2ce098db, 0x450d020, 0x3f986, sign_and_exp_bits(1, 13)}};
  scp_decimal d2 = {{0xc8ae5136, 0x7e1972b2, 0xc6e5, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x2cdbb6f3, 0xc1ff5584, 0x1e59648d, sign_and_exp_bits(0, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_34) {
  // 743074149530803080100000 - 743074149530803080100000 = 0
  scp_decimal d1 = {{0xa5d978a0, 0x215f66b0, 0x9d5a, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xa5d978a0, 0x215f66b0, 0x9d5a, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_35) {
  //-940773132909251215858 - -940773132909251215858 = -0
  scp_decimal d1 = {{0x874541f2, 0xffd993f3, 0x32, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x874541f2, 0xffd993f3, 0x32, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_36) {
  //-2516487156 - 2035480647028749779487264176 = -2035480647028749782003751332
  scp_decimal d1 = {{0x95fe8bf4, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0xf6718db0, 0xfa60bbc9, 0x693b5ca, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x8c7019a4, 0xfa60bbca, 0x693b5ca, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_37) {
  // 789336361088866015581001 - 510900 = 789336361088866015070101
  scp_decimal d1 = {{0xed951349, 0x287370b, 0xa726, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x7cbb4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xed8d4795, 0x287370b, 0xa726, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_38) {
  //-5320936240171619970984 - 84 = -5320936240171619971068
  scp_decimal d1 = {{0x5bfbefa8, 0x72d2f6e8, 0x120, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x54, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x5bfbeffc, 0x72d2f6e8, 0x120, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_39) {
  // 353117020.870 - 63672361569360018336831.4901 =
  // -63672361569359665219810.6201
  scp_decimal d1 = {{0x376a22c6, 0x52, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal d2 = {
      {0xfcec7015, 0x5ed1f777, 0x20eaf78, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {
      {0xd2c71459, 0x5ed1f441, 0x20eaf78, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_40) {
  // 7825388299694969184500962134 - -341774526948478169918604.2425 =
  // 7825730074221917662670880738.2
  scp_decimal d1 = {
      {0xa951d356, 0xc0ebb5fa, 0x1949026d, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0xca4c2639, 0x4f1249c8, 0xb0b17b6, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {
      {0x7263fed6, 0xe0d6a9b0, 0xfcdcec05, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_41) {
  // 13765046 - -8460778935767645 = 8460778949532691
  scp_decimal d1 = {{0xd209b6, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x9afd525d, 0x1e0f08, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x9bcf5c13, 0x1e0f08, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_42) {
  //-514.8577652267584077342626275 - -514.8577652267584077342626275 =
  //-0.0000000000000000000000000
  scp_decimal d1 = {
      {0xaaded1e3, 0xca399d67, 0x10a2cdb9, sign_and_exp_bits(1, 25)}};
  scp_decimal d2 = {
      {0xaaded1e3, 0xca399d67, 0x10a2cdb9, sign_and_exp_bits(1, 25)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 25)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_43) {
  //-0 - 3274.97564719445639 = -3274.97564719445639
  scp_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xc9e87687, 0x48b814c, 0x0, sign_and_exp_bits(0, 14)}};
  scp_decimal correct = {
      {0xc9e87687, 0x48b814c, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_44) {
  // 71873412.7 - 631547183561901817354 = -631547183561829943941.3
  scp_decimal d1 = {{0x2ad7032f, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0x81933e0a, 0x3c7a515e, 0x22, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xe4e96935, 0x5cc72db0, 0x156, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_45) {
  // 621497689.45 - 621497689.45 = 0.00
  scp_decimal d1 = {{0x786a36f1, 0xe, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {{0x786a36f1, 0xe, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_46) {
  //-52172086460865 - -208038.7419584 = -52172086252826.2580416
  scp_decimal d1 = {{0x42ae41c1, 0x2f73, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x60c0cdc0, 0x1e4, 0x0, sign_and_exp_bits(1, 7)}};
  scp_decimal correct = {
      {0x1b7f28c0, 0x4854d846, 0x1c, sign_and_exp_bits(1, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_47) {
  //-2197654499214544734058.996 - -76093.6470000000 =
  //-2197654499214544657965.3490000
  scp_decimal d1 = {{0xfa2cf9f4, 0x16d0a310, 0x1d15f, sign_and_exp_bits(1, 3)}};
  scp_decimal d2 = {{0x53fdb180, 0x2b411, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {
      {0x518ab550, 0x35e1c67b, 0x4702926b, sign_and_exp_bits(1, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_48) {
  // 849297514402810.8945402365484 - 103132.47403287643 =
  // 849297514299678.4205073601184
  scp_decimal d1 = {
      {0x9158062c, 0x19dd5131, 0x1b713971, sign_and_exp_bits(0, 13)}};
  scp_decimal d2 = {{0x7f4245b, 0x24a3d8, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {
      {0x75f9d2a0, 0xb8d50ce, 0x1b713971, sign_and_exp_bits(0, 13)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_49) {
  //-148006.2 - -50035 = -97971.2
  scp_decimal d1 = {{0x16957e, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {{0xc373, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0xef300, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_50) {
  // 8338383797154889160315213 - 555328777028054333208494016 =
  // -546990393230899444048178803
  scp_decimal d1 = {{0x5539d14d, 0xb0ff3d9a, 0x6e5b8, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0xcbd17fc0, 0x532b1f3c, 0x1cb5b71, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x7697ae73, 0xa22be1a2, 0x1c475b8, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_51) {
  //-23024675.362 - 1.680108 = -23024677.042108
  scp_decimal d1 = {{0x5c60aa22, 0x5, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal d2 = {{0x19a2ec, 0x0, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {{0xd9b237bc, 0x14f0, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_52) {
  //-32.4046629764 - 289000000 = -289000032.4046629764
  scp_decimal d1 = {{0x72af2b84, 0x4b, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal d2 = {{0x1139ca40, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x9b902b84, 0x281b57fb, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_53) {
  // 9.643 - -9.643 = 19.286
  scp_decimal d1 = {{0x25ab, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal d2 = {{0x25ab, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0x4b56, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_54) {
  // 71.78562778689539917 - 92942552496 = -92942552424.21437221310460083
  scp_decimal d1 = {{0x45a18f4d, 0x639f60d0, 0x0, sign_and_exp_bits(0, 17)}};
  scp_decimal d2 = {{0xa3cecdb0, 0x15, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x8b3e70b3, 0x45fde7e3, 0x1e08071a, sign_and_exp_bits(1, 17)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_55) {
  //-5935439098284455483 - 687779026 = -5935439098972234509
  scp_decimal d1 = {{0x9f35b63b, 0x525eea69, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x28feacd2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xc834630d, 0x525eea69, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_56) {
  //-0.71125 - 288733042330203894184939123 = -288733042330203894184939123.71
  scp_decimal d1 = {{0x115d5, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal d2 = {
      {0x3ee00e73, 0x9690330e, 0xeed599, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x8f85a533, 0xd053f190, 0x5d4b6ffe, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_57) {
  // 551116041237897682932 - -482.950395890000000 =
  // 551116041237897683414.95039589
  scp_decimal d1 = {{0x646c1ff4, 0xe0457f91, 0x1d, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x87286080, 0x6b3c8d3, 0x0, sign_and_exp_bits(1, 15)}};
  scp_decimal correct = {
      {0x9f354665, 0x23a0168, 0xb213401e, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_58) {
  //-760317971747196856 - 521421833347722689 = -1281739805094919545
  scp_decimal d1 = {{0xbe564fb8, 0xa8d312a, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x12d2edc1, 0x73c7665, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xd1293d79, 0x11c9a78f, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_59) {
  //-25590910503732458345 - 63902903461721325128874871 =
  //-63902929052631828861333216
  scp_decimal d1 = {{0x45c93369, 0x63252d84, 0x1, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0xca037b77, 0x568b8675, 0x34dbf7, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xfccaee0, 0xb9b0b3fa, 0x34dbf8, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_60) {
  // 8138991 - -8138991 = 16277982
  scp_decimal d1 = {{0x7c30ef, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x7c30ef, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0xf861de, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_61) {
  //-90824 - -6 = -90818
  scp_decimal d1 = {{0x162c8, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x162c2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_62) {
  // 74236 - -74236 = 148472
  scp_decimal d1 = {{0x121fc, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x121fc, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x243f8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_63) {
  // 5.90 - 75041536.12344928223581569 = -75041530.22344928223581569
  scp_decimal d1 = {{0x24e, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {
      {0x838b5581, 0xfb8265e4, 0x63510, sign_and_exp_bits(0, 17)}};
  scp_decimal correct = {
      {0xc2105581, 0xf3524c04, 0x63510, sign_and_exp_bits(1, 17)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_64) {
  // 800.73018979 - -5399 = 6199.73018979
  scp_decimal d1 = {{0xa4b94e63, 0x12, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal d2 = {{0x1517, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x59458563, 0x90, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_65) {
  //-16635921359129797343795216 - -5779241 = -16635921359129797338015975
  scp_decimal d1 = {{0x5c935810, 0x1a9c07a4, 0xdc2cb, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x582f29, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x5c3b28e7, 0x1a9c07a4, 0xdc2cb, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_66) {
  // 8288240465171 - -8288240465171 = 16576480930342
  scp_decimal d1 = {{0xc1a0f513, 0x789, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xc1a0f513, 0x789, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x8341ea26, 0xf13, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_67) {
  //-49574.4 - -56721.684510109187 = 7147.284510109187
  scp_decimal d1 = {{0x79080, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {{0x50496e03, 0xc98412, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {{0xda556e03, 0x19646a, 0x0, sign_and_exp_bits(0, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_68) {
  // 823551680430076.0 - 823551680430076.0 = 0.0
  scp_decimal d1 = {{0xada97fd8, 0x1d4228, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0xada97fd8, 0x1d4228, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_69) {
  // 4120702101969129218.9506971 - -74330875517765354 =
  // 4195032977486894572.9506971
  scp_decimal d1 = {
      {0xc3b3bd9b, 0x15e746ea, 0x2215ed, sign_and_exp_bits(0, 7)}};
  scp_decimal d2 = {{0x971486ea, 0x1081389, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x6ff44e9b, 0xef155e6c, 0x22b353, sign_and_exp_bits(0, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_70) {
  //-3591 - 901272420061874018325 = -901272420061874021916
  scp_decimal d1 = {{0xe07, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x7ca4d815, 0xdbaadae6, 0x30, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x7ca4e61c, 0xdbaadae6, 0x30, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_71) {
  // 8023674401914906260731 - 858616434494000309 = 8022815785480412260422
  scp_decimal d1 = {{0xecd0b4fb, 0xf6d9cd4a, 0x1b2, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x1853ccb5, 0xbea6b19, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xd47ce846, 0xeaef6231, 0x1b2, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_72) {
  //-45.0890000000 - 98.92974372174544409290540 = -144.01874372174544409290540
  scp_decimal d1 = {{0xfb236680, 0x68, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal d2 = {
      {0xf6ed672c, 0x37200c1b, 0x82eeb, sign_and_exp_bits(0, 23)}};
  scp_decimal correct = {
      {0xbbfd672c, 0x2c926410, 0xbe9b7, sign_and_exp_bits(1, 23)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_73) {
  //-71.3628790475 - 33421251477307317281040 = -33421251477307317281111.362879
  scp_decimal d1 = {{0x27972ecb, 0xa6, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal d2 = {{0x4dcbe110, 0xc509493b, 0x713, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x372f4d3f, 0xf1ad27d4, 0x6bfd6948, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_74) {
  //-334617181 - 12971051275.908 = -13305668456.908
  scp_decimal d1 = {{0x13f1da5d, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xee75684, 0xbcc, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {{0xf7a451cc, 0xc19, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_75) {
  //-32868881026211 - -2102284541.633031693874 = -32866778741669.366968306126
  scp_decimal d1 = {{0xe1fa4ca3, 0x1de4, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xffc1e632, 0xf70f0c3b, 0x71, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {
      {0x61749ce, 0xa54da366, 0x1b2fcf, sign_and_exp_bits(1, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_76) {
  //-92440670526.08723924 - 0.0000 = -92440670526.08723924
  scp_decimal d1 = {{0xd6a29bd4, 0x80498601, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {
      {0xd6a29bd4, 0x80498601, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_77) {
  // 842779 - 874094328450476902.9917 = -874094328449634123.9917
  scp_decimal d1 = {{0xcdc1b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x36f3671d, 0xd8f4c5c1, 0x1d9, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {
      {0x409d886d, 0xd8f4c5bf, 0x1d9, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_78) {
  //-850072.5583498323503 - -1 = -850071.5583498323503
  scp_decimal d1 = {{0x217e262f, 0x75f8a4e1, 0x0, sign_and_exp_bits(1, 13)}};
  scp_decimal d2 = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xd30b862f, 0x75f89bc8, 0x0, sign_and_exp_bits(1, 13)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_79) {
  // 5 - -9432339707912228340239 = 9432339707912228340244
  scp_decimal d1 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x2822820f, 0x54024dab, 0x1ff, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x28228214, 0x54024dab, 0x1ff, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_80) {
  //-4459829.1557 - -4459829.1557 = -0.0000
  scp_decimal d1 = {{0x6243ec65, 0xa, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal d2 = {{0x6243ec65, 0xa, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_81) {
  // 2553409659 - 5645133666963052453945369679 = -5645133666963052451391960020
  scp_decimal d1 = {{0x9831f07b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0x9c3644f, 0x48dcde30, 0x123d8b8d, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x719173d4, 0x48dcde2f, 0x123d8b8d, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_82) {
  //-890724625241294513 - -3715618325369.78229129221532 =
  //-890720909622969143.2177087078
  scp_decimal d1 = {{0xd03346b1, 0xc5c7d53, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0xebfd959c, 0x4d6e4db7, 0x1335947, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {
      {0x2ffdb266, 0xa54f78de, 0x1cc7dee4, sign_and_exp_bits(1, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_83) {
  // 26863287463871961293 - 7.55285490886005778839 =
  // 26863287463871961285.447145091
  scp_decimal d1 = {{0xdf4ad8cd, 0x74cd919e, 0x1, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x6ae86997, 0xf1b11849, 0x28, sign_and_exp_bits(0, 20)}};
  scp_decimal correct = {
      {0xf7345683, 0x6befef2c, 0x56ccca63, sign_and_exp_bits(0, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_84) {
  // 979791441209098071.700388588 - 23983640404224 =
  // 979767457568693847.700388588
  scp_decimal d1 = {
      {0x8d8fbaec, 0x75033833, 0x32a76e8, sign_and_exp_bits(0, 9)}};
  scp_decimal d2 = {{0x205de100, 0x15d0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x2005baec, 0x4d23e355, 0x32a71d4, sign_and_exp_bits(0, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_85) {
  //-67822224131.79326 - 5 = -67822224136.79326
  scp_decimal d1 = {{0x35b9a9be, 0x181865, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal d2 = {{0x5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x35c14ade, 0x181865, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_86) {
  // 97273000000 - 906720619133005558831685 = -906720619132908285831685
  scp_decimal d1 = {{0xa5ec3040, 0x16, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xdc8dda45, 0x6c5a71bc, 0xc001, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x36a1aa05, 0x6c5a71a6, 0xc001, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_87) {
  // 71397.0895 - 296095572982185.3 = -296095572910788.2105
  scp_decimal d1 = {{0x2a8e54cf, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal d2 = {{0x3a78c09d, 0xa84f9, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {
      {0x3d221079, 0x29176d8c, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_88) {
  //-483537099816768149140486.229 - -116348697229335335 =
  //-483536983468070919805151.229
  scp_decimal d1 = {
      {0x5dab3855, 0xb4768e2e, 0x18ff8f6, sign_and_exp_bits(1, 3)}};
  scp_decimal d2 = {{0x106f1b27, 0x19d5a86, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x2ba927fd, 0x65ccf27e, 0x18ff8f0, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_89) {
  //-2113355893894 - 952483.9542566753222130030000 =
  //-2113356846377.9542566753222130
  scp_decimal d1 = {{0xdd3cc86, 0x1ec, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0x387655b0, 0x3b38cf70, 0x1ec6c33a, sign_and_exp_bits(0, 22)}};
  scp_decimal correct = {
      {0xf07b3df2, 0xa40783a, 0x44494732, sign_and_exp_bits(1, 16)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_90) {
  // 356782554091226187603 - -3.8539 = 356782554091226187606.8539
  scp_decimal d1 = {{0x8820c753, 0x575a42a1, 0x13, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x968b, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {
      {0x806ab0bb, 0x35cac5d5, 0x2f384, sign_and_exp_bits(0, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_91) {
  // 45 - 170445.12648409252230 = -170400.12648409252230
  scp_decimal d1 = {{0x2d, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xb2160186, 0xec8a45f2, 0x0, sign_and_exp_bits(0, 14)}};
  scp_decimal correct = {
      {0xcc98c186, 0xec7a4938, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_92) {
  // 316199760 - 8120 = 316191640
  scp_decimal d1 = {{0x12d8d350, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x1fb8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x12d8b398, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_93) {
  //-8312178319967343230105 - -8312178319967343230105 = -0
  scp_decimal d1 = {{0xbcba3c99, 0x9aa59e33, 0x1c2, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xbcba3c99, 0x9aa59e33, 0x1c2, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_94) {
  //-2150590 - -3926122697310.559600310800530 = 3926120546720.559600310800530
  scp_decimal d1 = {{0x20d0be, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0x8fa0d092, 0xe4b85801, 0xcaf9cd1, sign_and_exp_bits(1, 15)}};
  scp_decimal correct = {
      {0xfc4dd092, 0x4f49d551, 0xcaf9c5d, sign_and_exp_bits(0, 15)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_95) {
  //-802955209402619.60420 - 2753.94313175299196158101 =
  //-802955209405373.5473317529920
  scp_decimal d1 = {{0xb40eae4, 0x5a52fedf, 0x4, sign_and_exp_bits(1, 5)}};
  scp_decimal d2 = {{0x42cb8095, 0x27d77b54, 0x3a51, sign_and_exp_bits(0, 20)}};
  scp_decimal correct = {
      {0xd3a5c940, 0x3911e992, 0x19f1e3cb, sign_and_exp_bits(1, 13)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_96) {
  // 33.91096768665823200000 - 256347049.39 = -256347015.47903231334176800000
  scp_decimal d1 = {{0x563c300, 0xd4ebe04d, 0xb7, sign_and_exp_bits(0, 20)}};
  scp_decimal d2 = {{0xf7f28e2b, 0x5, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {
      {0x90683d00, 0x76742f41, 0x52d48733, sign_and_exp_bits(1, 20)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_97) {
  // 275397483993496625 - -8904816469023083259300191.95 =
  // 8904816744420567252796816.95
  scp_decimal d1 = {{0x7577fc31, 0x3d2688d, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0xb7e7a97b, 0xce76a0e5, 0x2e096d2, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {
      {0x9ac62c9f, 0x4ca77827, 0x2e096d4, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_98) {
  // 57 - -8.2 = 65.2
  scp_decimal d1 = {{0x39, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x52, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {{0x28c, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_99) {
  //-276090.5391866 - 25505097935021282122.782 = -25505097935021558213.3211866
  scp_decimal d1 = {{0xd2c8fefa, 0x282, 0x0, sign_and_exp_bits(1, 7)}};
  scp_decimal d2 = {{0xfc7b5c1e, 0xa2565019, 0x566, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {
      {0x658752da, 0x4b98f999, 0xd2f925, sign_and_exp_bits(1, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_100) {
  //-4.7063820891262 - -3104 = 3099.2936179108738
  scp_decimal d1 = {{0xe653747e, 0x2acd, 0x0, sign_and_exp_bits(1, 13)}};
  scp_decimal d2 = {{0xc20, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x47808b82, 0x6e1be9, 0x0, sign_and_exp_bits(0, 13)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_101) {
  //-24.89224 - 8617.423520802937535470538 = -8642.315760802937535470538
  scp_decimal d1 = {{0x25fb88, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal d2 = {
      {0x57a41bca, 0x77125faf, 0x720cf, sign_and_exp_bits(0, 21)}};
  scp_decimal correct = {
      {0xf12c1bca, 0xe04beaf1, 0x72614, sign_and_exp_bits(1, 21)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_102) {
  // 5762988.4627 - 5972643090482422.105948250367 =
  // -5972643084719433.643248250367
  scp_decimal d1 = {{0x6b0240d3, 0xd, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal d2 = {
      {0x49df60ff, 0xb58632f0, 0x134c745e, sign_and_exp_bits(0, 12)}};
  scp_decimal correct = {
      {0x25f6edff, 0x658bf377, 0x134c745e, sign_and_exp_bits(1, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_103) {
  //-7026133984880292440724 - 7026133984880292440724 = -14052267969760584881448
  scp_decimal d1 = {{0x1a2aa94, 0xe3325132, 0x17c, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x1a2aa94, 0xe3325132, 0x17c, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x3455528, 0xc664a264, 0x2f9, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_104) {
  // 5.6 - -68820714590219333 = 68820714590219338.6
  scp_decimal d1 = {{0x38, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0x4656ac45, 0xf48013, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0xbf62baea, 0x98d00c0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_105) {
  // 340708624697669789670 - 98.1791373498 = 340708624697669789571.82086265
  scp_decimal d1 = {{0xc87d27e6, 0x78483102, 0x12, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x975378ba, 0xe4, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal correct = {
      {0x63fdac79, 0x68a7c3c2, 0x6e16c1c3, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_106) {
  // 60941608.58652418 - -560 = 60942168.58652418
  scp_decimal d1 = {{0x652f1f02, 0x15a69b, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal d2 = {{0x230, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x6f0b4f02, 0x15a6a8, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_107) {
  //-95.634346 - 89257542391847974844932 = -89257542391847974845027.63435
  scp_decimal d1 = {{0x5b343aa, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal d2 = {{0x849fba04, 0xa93bcaa8, 0x12e6, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x39c847ab, 0xdc1b635e, 0x1cd735fa, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_108) {
  // 91427283.904 - -3.52 = 91427287.424
  scp_decimal d1 = {{0x497da3c0, 0x15, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal d2 = {{0x160, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal correct = {{0x497db180, 0x15, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_109) {
  // 70172372063805.049053804768 - 100.529200000 = 70172372063704.519853804768
  scp_decimal d1 = {
      {0x7a8a78e0, 0xe978f555, 0x3a0b93, sign_and_exp_bits(0, 12)}};
  scp_decimal d2 = {{0x6801db80, 0x17, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal correct = {
      {0x33490ce0, 0xe97899e7, 0x3a0b93, sign_and_exp_bits(0, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_110) {
  // 7179591164.07302934937766267 - -589263 = 7180180427.07302934937766267
  scp_decimal d1 = {
      {0x40a0897b, 0xb02fbf0d, 0x251e1c1, sign_and_exp_bits(0, 17)}};
  scp_decimal d2 = {{0x8fdcf, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x4536897b, 0x16dfcc22, 0x251ee3c, sign_and_exp_bits(0, 17)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_111) {
  // 43.490 - -1595199999298671980 = 1595199999298672023.490
  scp_decimal d1 = {{0xa9e2, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal d2 = {{0x97e6956c, 0x162349f2, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x5cb857c2, 0x79d8dba1, 0x56, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_112) {
  // 22.600035312 - 33539937579 = -33539937556.399964688
  scp_decimal d1 = {{0x43112bf0, 0x5, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal d2 = {{0xcf22d52b, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x5e00c210, 0xd175cb81, 0x1, sign_and_exp_bits(1, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_113) {
  //-53363211.3809108 - -76766573314926 = 76766519951714.6190892
  scp_decimal d1 = {{0xe89596d4, 0x1e555, 0x0, sign_and_exp_bits(1, 7)}};
  scp_decimal d2 = {{0x9c55436e, 0x45d1, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x40de942c, 0x9d7ea7b2, 0x29, sign_and_exp_bits(0, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_114) {
  // 9.3 - 851634105212 = -851634105202.7
  scp_decimal d1 = {{0x5d, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0x49592b7c, 0xc6, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0xdd7bb27b, 0x7be, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_115) {
  // 4563.9951640753 - 4563.9951640753 = 0.0000000000
  scp_decimal d1 = {{0x611ae8b1, 0x2982, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal d2 = {{0x611ae8b1, 0x2982, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_116) {
  // 89747575083 - 6.3463800000000000 = 89747575076.6536200000000000
  scp_decimal d1 = {{0xe55f512b, 0x14, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x6718b000, 0xe177fd, 0x0, sign_and_exp_bits(0, 16)}};
  scp_decimal correct = {
      {0x6f525000, 0xefcc05b6, 0x2e65fe1, sign_and_exp_bits(0, 16)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_117) {
  //-234.1 - 938598 = -938832.1
  scp_decimal d1 = {{0x925, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {{0xe5266, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x8f4121, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_118) {
  //-7244330141556784709046542894 - 3242673584.325018812058 =
  //-7244330141556784712289216478.3
  scp_decimal d1 = {
      {0x276aa22e, 0xe2478eea, 0x17685e93, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xcb6c7e9a, 0xc922cc85, 0xaf, sign_and_exp_bits(0, 12)}};
  scp_decimal correct = {
      {0x16f30eaf, 0xd6cb952d, 0xea13b1c6, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_119) {
  //-278102961.5953 - -66209800.460 = -211893161.1353
  scp_decimal d1 = {{0x82484951, 0x287, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal d2 = {{0x6a69610c, 0xf, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal correct = {{0x5a2a7ed9, 0x1ed, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_120) {
  // 9098659969686434850807.969196 - -82988870.33732 =
  // 9098659969686517839678.306516
  scp_decimal d1 = {
      {0x9d3f75ac, 0x4ac38c58, 0x1d663c31, sign_and_exp_bits(0, 6)}};
  scp_decimal d2 = {{0x3c36b384, 0x78c, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal correct = {
      {0xf76278d4, 0x4ac3d7d2, 0x1d663c31, sign_and_exp_bits(0, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_121) {
  // 6.7231677 - 6.7231677 = 0.0000000
  scp_decimal d1 = {{0x401dfbd, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal d2 = {{0x401dfbd, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_122) {
  //-3826064636613715252000 - -764.805539 = -3826064636613715251235.194461
  scp_decimal d1 = {{0x14835320, 0x69502ba4, 0xcf, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x2d9601a3, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal correct = {
      {0xad8d065d, 0x8de86a00, 0xc5cd8b3, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_123) {
  //-213437535127963 - 912514342546445 = -1125951877674408
  scp_decimal d1 = {{0xcc76899b, 0xc21e, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x4d3d6c0d, 0x33ded, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x19b3f5a8, 0x4000c, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_124) {
  //-644504884330587100.86 - 92151116321325602744701063 =
  //-92151116965830487075288163.86
  scp_decimal d1 = {{0xace30246, 0x7e6e21c1, 0x3, sign_and_exp_bits(1, 2)}};
  scp_decimal d2 = {{0xee861087, 0x68f8272, 0x4c39c2, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xd9417702, 0xe7d16a6, 0x1dc68fce, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_125) {
  //-1 - 9163270347162332524719178 = -9163270347162332524719179
  scp_decimal d1 = {{0x1, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x49e02c4a, 0xe180e91f, 0x79465, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x49e02c4b, 0xe180e91f, 0x79465, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_126) {
  // 574211594314083539.60047 - 4320.817373 = 574211594314079218.783097
  scp_decimal d1 = {{0x460e606f, 0xceaa9086, 0xc28, sign_and_exp_bits(0, 5)}};
  scp_decimal d2 = {{0x18a70dd, 0x1, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {
      {0xbb055379, 0x12a9a53d, 0x7998, sign_and_exp_bits(0, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_127) {
  // 574287385380473.5 - 574287385380473.5 = 0.0
  scp_decimal d1 = {{0x40bc0bf, 0x14671d, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0x40bc0bf, 0x14671d, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_128) {
  // 9540722643088559602 - 8400812.686083187318733323 =
  // 9540722643080158789.313916813
  scp_decimal d1 = {{0xe9d1cdf2, 0x846774b1, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0xedb03a0b, 0xf7dee375, 0x6f2f0, sign_and_exp_bits(0, 18)}};
  scp_decimal correct = {
      {0x961a6f8d, 0xd5e08cad, 0x1ed3e69a, sign_and_exp_bits(0, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_129) {
  //-5976628557.88313012629499 - 775.078777954 = -5976629332.96190808029499
  scp_decimal d1 = {{0xc7c46ffb, 0x5e4b11f2, 0x7e8f, sign_and_exp_bits(1, 14)}};
  scp_decimal d2 = {{0x764b9462, 0xb4, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal correct = {
      {0xdb0e793b, 0x5f5e6ef3, 0x7e8f, sign_and_exp_bits(1, 14)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_130) {
  //-5786197933908712577 - -322258297028720 = -5785875675611683857
  scp_decimal d1 = {{0x42ba5c81, 0x504cb45d, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x9b520070, 0x12517, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xa7685c11, 0x504b8f45, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_131) {
  //-35624616807274270023 - 626194371625362290859896104 =
  //-626194407249979098134166127
  scp_decimal d1 = {{0x28fe4d47, 0xee64103d, 0x1, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0xafcced28, 0xe7dd4f12, 0x205f9d0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xd8cb3a6f, 0xd6415f4f, 0x205f9d2, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_132) {
  // 88295053152796 - -9138278 = 88295062291074
  scp_decimal d1 = {{0xcb47521c, 0x504d, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x8b7066, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0xcbd2c282, 0x504d, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_133) {
  // 6.7700767095 - 52376.4649102328 = -52369.6948335233
  scp_decimal d1 = {{0xc347b977, 0xf, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal d2 = {{0x75db0bf8, 0x1dc5c, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal correct = {{0xb2935281, 0x1dc4c, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_134) {
  // 10303.65 - 383067581335256980283 = -383067581335256969979.35
  scp_decimal d1 = {{0xfb8dd, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {{0x380c5b3b, 0xc4216fa5, 0x14, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xe4c3ea2f, 0x9d0f9c89, 0x81c, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_135) {
  // 34024438.5990463954124 - -4741530632.227765522661213594 =
  // 4775555070.826811918073613594
  scp_decimal d1 = {{0xc67f9ccc, 0x71d6e25d, 0x12, sign_and_exp_bits(0, 13)}};
  scp_decimal d2 = {
      {0x96d859a, 0x9e4f2b7c, 0xf521a2a, sign_and_exp_bits(1, 18)}};
  scp_decimal correct = {
      {0x820e4d1a, 0x2177827e, 0xf6e3f1f, sign_and_exp_bits(0, 18)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_136) {
  // 2.8377208108947004798 - -7.2 = 10.0377208108947004798
  scp_decimal d1 = {{0x1b1edd7e, 0x89d0186d, 0x1, sign_and_exp_bits(0, 19)}};
  scp_decimal d2 = {{0x48, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal correct = {
      {0x2f3edd7e, 0x71037af4, 0x5, sign_and_exp_bits(0, 19)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_137) {
  //-51013 - 185955141477759997.733840 = -185955141477811010.733840
  scp_decimal d1 = {{0xc745, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x3ff46bd0, 0xa5fec575, 0x2760, sign_and_exp_bits(0, 6)}};
  scp_decimal correct = {
      {0x20910710, 0xa5fec581, 0x2760, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_138) {
  // 30995254974 - 30995254974 = 0
  scp_decimal d1 = {{0x37760ebe, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x37760ebe, 0x7, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_139) {
  //-48676796852210506471090 - 48676796852210506471090 =
  //-97353593704421012942180
  scp_decimal d1 = {{0xd3c916b2, 0xc642045c, 0xa4e, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xd3c916b2, 0xc642045c, 0xa4e, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xa7922d64, 0x8c8408b9, 0x149d, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_140) {
  //-420618940011.4 - 420618940011.4 = -841237880022.8
  scp_decimal d1 = {{0x546cd032, 0x3d3, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {{0x546cd032, 0x3d3, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0xa8d9a064, 0x7a6, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_141) {
  // 46220165512.620441628666820 - 46220165512.620441628666820 =
  // 0.000000000000000
  scp_decimal d1 = {
      {0x82d56bc4, 0x316d1c1c, 0x263b80, sign_and_exp_bits(0, 15)}};
  scp_decimal d2 = {
      {0x82d56bc4, 0x316d1c1c, 0x263b80, sign_and_exp_bits(0, 15)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 15)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_142) {
  //-6.5947400000000000 - 825794 = -825800.5947400000000000
  scp_decimal d1 = {{0x96dc5000, 0xea4acf, 0x0, sign_and_exp_bits(1, 16)}};
  scp_decimal d2 = {{0xc99c2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xa01e5000, 0xaadab05e, 0x1bf, sign_and_exp_bits(1, 16)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_143) {
  // 1.94137 - 2781.95554582218000000 = -2780.01417582218000000
  scp_decimal d1 = {{0x2f659, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal d2 = {{0x5e5c680, 0x14bd26f3, 0xf, sign_and_exp_bits(0, 17)}};
  scp_decimal correct = {
      {0x5b233680, 0x120b7060, 0xf, sign_and_exp_bits(1, 17)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_144) {
  // 7103557445056.6208 - 285241.18780407 = 7103557159815.43299593
  scp_decimal d1 = {{0x858ab440, 0xfc5e7a, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal d2 = {{0x49f7a9f7, 0x19f1, 0x0, sign_and_exp_bits(0, 8)}};
  scp_decimal correct = {
      {0x30295a09, 0x822a780f, 0x26, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_145) {
  // 962107952.33 - 962107952.33 = 0.00
  scp_decimal d1 = {{0x669c3ae1, 0x16, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {{0x669c3ae1, 0x16, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_146) {
  // 7.9 - 638478710742504 = -638478710742496.1
  scp_decimal d1 = {{0x4f, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal d2 = {{0x68c01de8, 0x244b1, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x17812ac1, 0x16aeee, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_147) {
  // 56896837953934 - 56896837953934 = 0
  scp_decimal d1 = {{0x53d0a98e, 0x33bf, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x53d0a98e, 0x33bf, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_148) {
  // 121 - 70990293038397.744854424 = -70990293038276.744854424
  scp_decimal d1 = {{0x79, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xf799b598, 0x643923ba, 0xf08, sign_and_exp_bits(0, 9)}};
  scp_decimal correct = {
      {0xcb703b98, 0x6439239e, 0xf08, sign_and_exp_bits(1, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_149) {
  //-59.4608 - -59.4608 = -0.0000
  scp_decimal d1 = {{0x912b0, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal d2 = {{0x912b0, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_150) {
  // 18070851480000000 - -18070851480000000 = 36141702960000000
  scp_decimal d1 = {{0xfb411600, 0x403357, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xfb411600, 0x403357, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0xf6822c00, 0x8066af, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_151) {
  // 2.9147777333352208 - -668449.2160360689 = 668452.1308138022352208
  scp_decimal d1 = {{0xc1f25710, 0x678dbf, 0x0, sign_and_exp_bits(0, 16)}};
  scp_decimal d2 = {{0x9cb8e0f1, 0x17bf82, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {
      {0xc847b550, 0x5e5e49a3, 0x16a, sign_and_exp_bits(0, 16)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_152) {
  //-10009067843.8861666392 - 10009067843.8861666392 = -20018135687.7723332784
  scp_decimal d1 = {{0xac32f858, 0x6d0985bc, 0x5, sign_and_exp_bits(1, 10)}};
  scp_decimal d2 = {{0xac32f858, 0x6d0985bc, 0x5, sign_and_exp_bits(0, 10)}};
  scp_decimal correct = {
      {0x5865f0b0, 0xda130b79, 0xa, sign_and_exp_bits(1, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_153) {
  // 97109294122688757623926 - 95377 = 97109294122688757528549
  scp_decimal d1 = {{0x8ffbec76, 0x4e2d917e, 0x1490, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x17491, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x8ffa77e5, 0x4e2d917e, 0x1490, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_154) {
  //-740.25056709545542130000000 - -766730475.3348870000 =
  // 766729735.08431990454457870000
  scp_decimal d1 = {
      {0x2c1ee080, 0x5d79fc39, 0x3d3b6a, sign_and_exp_bits(1, 23)}};
  scp_decimal d2 = {{0xd005ff70, 0x6a67bd0c, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal correct = {
      {0x60e226b0, 0x7032c472, 0xf7be65ae, sign_and_exp_bits(0, 20)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_155) {
  // 183 - -183 = 366
  scp_decimal d1 = {{0xb7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xb7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x16e, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_156) {
  //-818.615 - -414848.450048 = 414029.835048
  scp_decimal d1 = {{0xc7db7, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  scp_decimal d2 = {{0x96e4fe00, 0x60, 0x0, sign_and_exp_bits(1, 6)}};
  scp_decimal correct = {{0x6619eb28, 0x60, 0x0, sign_and_exp_bits(0, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_157) {
  // 99810388845398477461913 - -4.0445223 = 99810388845398477461917.04452
  scp_decimal d1 = {{0x23135999, 0xbb65bcc9, 0x1522, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x2692527, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  scp_decimal correct = {
      {0x669d4184, 0x1d306925, 0x20401f32, sign_and_exp_bits(0, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_158) {
  //-1015010130733.170524085 - -201.8483757151212739364629127 =
  //-1015010130531.3221483698787261
  scp_decimal d1 = {{0xcd6d7fb5, 0x6186025, 0x37, sign_and_exp_bits(1, 9)}};
  scp_decimal d2 = {
      {0x93ebaa87, 0xbb43bdef, 0x685a68f, sign_and_exp_bits(1, 25)}};
  scp_decimal correct = {
      {0x512713bd, 0x4ef51a00, 0x20cbf78e, sign_and_exp_bits(1, 16)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_159) {
  // 142741819695837935105440901 - 142741819695837935105440901 = 0
  scp_decimal d1 = {
      {0x873f7c85, 0x8d0a4737, 0x7612c1, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0x873f7c85, 0x8d0a4737, 0x7612c1, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_160) {
  //-4065210259755 - -4065210259755 = -0
  scp_decimal d1 = {{0x8169d92b, 0x3b2, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x8169d92b, 0x3b2, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_161) {
  // 49721171662 - 239045599925099475.242 = -239045550203927813.242
  scp_decimal d1 = {{0x939cdece, 0xb, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x2fb2b12a, 0xf56c929d, 0xc, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {
      {0x92ec5c7a, 0xf56c6564, 0xc, sign_and_exp_bits(1, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_162) {
  // 36988591922.7443 - -48584163991382522845 = 48584164028371114767.7443
  scp_decimal d1 = {{0xc6d2ae33, 0x15068, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal d2 = {{0x7fadfbdd, 0xa23d9fbd, 0x2, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x43111703, 0x87312ab4, 0x66e1, sign_and_exp_bits(0, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_163) {
  //-722 - 6174.8360 = -6896.8360
  scp_decimal d1 = {{0x2d2, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x3ae3488, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x41c5fa8, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_164) {
  // 7.4036 - 7.4036 = 0.0000
  scp_decimal d1 = {{0x12134, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal d2 = {{0x12134, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_165) {
  //-3942974174073958500000000 - -651227484 = -3942974174073957848772516
  scp_decimal d1 = {{0xbf41e100, 0xeeb63c0, 0x342f5, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x26d0f15c, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x9870efa4, 0xeeb63c0, 0x342f5, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_166) {
  //-55133234.3316630006 - -6622 = -55126612.3316630006
  scp_decimal d1 = {{0x5c9249f6, 0x7a6b9d8, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal d2 = {{0x19de, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x50fe91f6, 0x7a67d9e, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_167) {
  // 3.5310848 - -3.07068381224731 = 6.60176861224731
  scp_decimal d1 = {{0x21acd00, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  scp_decimal d2 = {{0xedc8df1b, 0x11746, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {{0x674d5f1b, 0x2586d, 0x0, sign_and_exp_bits(0, 14)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_168) {
  //-62951183811 - -62951183811 = -0
  scp_decimal d1 = {{0xa82ed5c3, 0xe, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xa82ed5c3, 0xe, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_169) {
  // 6145296082304894723304 - -294072885385003383509049379 =
  // 294079030681085688403772683
  scp_decimal d1 = {{0xa6eb64e8, 0x231d73ae, 0x14d, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xc7156023, 0xf67a228, 0xf3405b, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x6e00c50b, 0x328515d7, 0xf341a8, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_170) {
  //-93558213766400000000000 - 90130343315757 = -93558213856530343315757
  scp_decimal d1 = {{0x3d020000, 0xcd09cfe1, 0x13cf, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x1b18c92d, 0x51f9, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x581ac92d, 0xcd0a21da, 0x13cf, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_171) {
  //-24 - 555062640981.6 = -555062641005.6
  scp_decimal d1 = {{0x18, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x5b1d8d58, 0x50c, 0x0, sign_and_exp_bits(0, 1)}};
  scp_decimal correct = {{0x5b1d8e48, 0x50c, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_172) {
  // 996779748419964561236434 - -996779748419964561236434 =
  // 1993559496839929122472868
  scp_decimal d1 = {{0x9647a1d2, 0x89d6f682, 0xd313, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x9647a1d2, 0x89d6f682, 0xd313, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x2c8f43a4, 0x13aded05, 0x1a627, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_173) {
  //-7322179.812048190828114560 - -7322179.812048190828114560 =
  //-0.000000000000000000
  scp_decimal d1 = {
      {0x69faf280, 0x29b8e686, 0x60e88, sign_and_exp_bits(1, 18)}};
  scp_decimal d2 = {
      {0x69faf280, 0x29b8e686, 0x60e88, sign_and_exp_bits(1, 18)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 18)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_174) {
  //-3.5 - -329187336187637391570096421 = 329187336187637391570096417.5
  scp_decimal d1 = {{0x23, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {
      {0xe23dd125, 0x40a1b7ef, 0x1104c21, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xd66a2b4f, 0x86512f5e, 0xaa2f94c, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_175) {
  // 4961114.134439166059195 - 44356000459283081958967 =
  // -44356000459283076997852.865561
  scp_decimal d1 = {{0xc805a2bb, 0xf14a0c29, 0x10c, sign_and_exp_bits(0, 15)}};
  scp_decimal d2 = {{0x37839637, 0x8b29918e, 0x964, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x8166a419, 0x9404a10, 0x8f526c73, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_176) {
  // 504477193939338287450074 - -9 = 504477193939338287450083
  scp_decimal d1 = {{0x26ed07da, 0xc3738d1a, 0x6ad3, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x26ed07e3, 0xc3738d1a, 0x6ad3, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_177) {
  //-504783984797 - -504783984797 = -0
  scp_decimal d1 = {{0x8778589d, 0x75, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x8778589d, 0x75, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_178) {
  // 1245791.3240179283 - 61920031.956 = -60674240.6319820717
  scp_decimal d1 = {{0xf552d253, 0x2c4267, 0x0, sign_and_exp_bits(0, 10)}};
  scp_decimal d2 = {{0x6ab8b4d4, 0xe, 0x0, sign_and_exp_bits(0, 3)}};
  scp_decimal correct = {
      {0xfedbcfad, 0x86b9500, 0x0, sign_and_exp_bits(1, 10)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_179) {
  //-516809427701354 - -184033527640336137851.78790370 =
  // 184033010830908436497.78790370
  scp_decimal d1 = {{0x125ace6a, 0x1d609, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0xaa9359e2, 0x639d3a25, 0x3b76e588, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {
      {0x3db62fe2, 0xc274ea14, 0x3b76da96, sign_and_exp_bits(0, 8)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_180) {
  //-125.00 - -1622.226148297 = 1497.226148297
  scp_decimal d1 = {{0x30d4, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal d2 = {{0xb4369bc9, 0x179, 0x0, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0x99a1f9c9, 0x15c, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_181) {
  //-249.9764 - -8 = -241.9764
  scp_decimal d1 = {{0x2624b4, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal d2 = {{0x8, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x24ec34, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_182) {
  // 73887043320283.15 - 4481421532046635014.86647 = -4481347645003314731.71647
  scp_decimal d1 = {{0xc90f999b, 0x1a3ffc, 0x0, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {{0xdb687a37, 0xd5b5bcc0, 0x5ee5, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {
      {0x767874bf, 0x6f2bc94f, 0x5ee5, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_183) {
  //-325129255003 - 5.15300000000 = -325129255008.15300000000
  scp_decimal d1 = {{0xb336b85b, 0x4b, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0xfa460100, 0x77, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal correct = {
      {0x234a7900, 0x877b2a21, 0x6e2, sign_and_exp_bits(1, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_184) {
  // 133068260443625432509831 - 4067797840055324961331641 =
  // -3934729579611699528821810
  scp_decimal d1 = {{0x119b6d87, 0xa515179e, 0x1c2d, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xee32d9b9, 0xc344f5ad, 0x35d63, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0xdc976c32, 0x1e2fde0f, 0x34136, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_185) {
  // 99670904527484732 - 99670904527484732 = 0
  scp_decimal d1 = {{0xdacd773c, 0x1621a28, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xdacd773c, 0x1621a28, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_186) {
  //-153.77 - 86.81763 = -240.58763
  scp_decimal d1 = {{0x3c11, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  scp_decimal d2 = {{0x847923, 0x0, 0x0, sign_and_exp_bits(0, 5)}};
  scp_decimal correct = {{0x16f1b8b, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_187) {
  //-502067009.388849339 - 58867861700873211163752 =
  //-58867861700873713230761.388849
  scp_decimal d1 = {{0xf410a8bb, 0x6f7b348, 0x0, sign_and_exp_bits(1, 9)}};
  scp_decimal d2 = {{0x4a513468, 0x3bb181a5, 0xc77, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x2ba76b31, 0x487e29de, 0xbe365a99, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_188) {
  // 1.59356592413 - -26833.273500000 = 26834.86706592413
  scp_decimal d1 = {{0x1a64a11d, 0x25, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal d2 = {{0x9bbc3160, 0x1867, 0x0, sign_and_exp_bits(1, 9)}};
  scp_decimal correct = {{0xefe7ea9d, 0x9889d, 0x0, sign_and_exp_bits(0, 11)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_189) {
  //-191201827250104378184078737 - 942905920796972335.0158956715 =
  //-191201828193010298981051072.02
  scp_decimal d1 = {{0x51a9591, 0xd30b18a0, 0x9e288f, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0x665c58ab, 0xe385da79, 0x1e7788f3, sign_and_exp_bits(0, 10)}};
  scp_decimal correct = {
      {0x69ffb302, 0x8ce1186e, 0x3dc7d833, sign_and_exp_bits(1, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_190) {
  //-47471964.1 - -9043790293550597700572 = 9043790293550550228607.9
  scp_decimal d1 = {{0x1c4ba599, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  scp_decimal d2 = {{0x1147bdc, 0x43cd7bee, 0x1ea, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xee8130ff, 0xa606d74b, 0x1326, sign_and_exp_bits(0, 1)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_191) {
  //-7 - -7 = -0
  scp_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_192) {
  // 83285448633704133.7064 - -83285448633704133.7064 = 166570897267408267.4128
  scp_decimal d1 = {{0xddc60ae8, 0x262d86ab, 0x2d, sign_and_exp_bits(0, 4)}};
  scp_decimal d2 = {{0xddc60ae8, 0x262d86ab, 0x2d, sign_and_exp_bits(1, 4)}};
  scp_decimal correct = {
      {0xbb8c15d0, 0x4c5b0d57, 0x5a, sign_and_exp_bits(0, 4)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_193) {
  // 5553989 - 8686767329490636717 = -8686767329485082728
  scp_decimal d1 = {{0x54bf45, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x98c20fad, 0x788d98dc, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {
      {0x986d5068, 0x788d98dc, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_194) {
  //-47764084543191397719405 - -7.00000000 = -47764084543191397719398.000000
  scp_decimal d1 = {{0x19405d6d, 0x4bd48311, 0xa1d, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x29b92700, 0x0, 0x0, sign_and_exp_bits(1, 8)}};
  scp_decimal correct = {
      {0x6125a580, 0x6ceba78e, 0x9a558653, sign_and_exp_bits(1, 6)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_195) {
  // 7139627801048592086.40 - -23757205 = 7139627801072349291.40
  scp_decimal d1 = {{0xb8764bc0, 0xb43955c4, 0x26, sign_and_exp_bits(0, 2)}};
  scp_decimal d2 = {{0x16a8195, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x4610e9f4, 0xb43955c5, 0x26, sign_and_exp_bits(0, 2)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_196) {
  // 22363135040 - -5402.24947648651078 = 22363140442.24947648651078
  scp_decimal d1 = {{0x34f25c40, 0x5, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x4766df46, 0x77f43ba, 0x0, sign_and_exp_bits(1, 14)}};
  scp_decimal correct = {
      {0xd4f6df46, 0xd3c702fa, 0x1d98e, sign_and_exp_bits(0, 14)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_197) {
  // 1034799581800573 - -95.905041650837 = 1034799581800668.905041650837
  scp_decimal d1 = {{0xd7ca87d, 0x3ad25, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0xa1f09495, 0x5739, 0x0, sign_and_exp_bits(1, 12)}};
  scp_decimal correct = {
      {0x89096495, 0xbbd84639, 0x357f755, sign_and_exp_bits(0, 12)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_198) {
  //-971015090005351573 - -971015090005351573 = -0
  scp_decimal d1 = {{0x67501c95, 0xd79bd14, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x67501c95, 0xd79bd14, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_199) {
  // 3.820664427 - -6148333097174547 = 6148333097174550.820664427
  scp_decimal d1 = {{0xe3bab66b, 0x0, 0x0, sign_and_exp_bits(0, 9)}};
  scp_decimal d2 = {{0x5a37c613, 0x15d7e0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0x6e73b46b, 0xce182764, 0x515f5, sign_and_exp_bits(0, 9)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_201) {
  // 0 - 0 = 0
  scp_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_202) {
  //-0 - 0 = -0
  scp_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_203) {
  // 0 - -0 = 0
  scp_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_204) {
  //-0 - -0 = -0
  scp_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_205) {
  // 79228162514264337593543950335 - 79228162514264337593543950335 = 0
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_206) {
  //-79228162514264337593543950335 - -79228162514264337593543950335 = -0
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_207) {
  //-79228162514264337593543950335 - 79228162514264337593543950335 = SCP_ERROR
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_208) {
  // 79228162514264337593543950335 - -79228162514264337593543950335 = SCP_ERROR
  scp_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  scp_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_ERROR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_209) {
  //-33586526831355.03650000 - -30936088168399986925418607 =
  // 30936088168366400398587251.964
  scp_decimal d1 = {{0x3c4d4cd0, 0x12ab5468, 0xb6, sign_and_exp_bits(1, 8)}};
  scp_decimal d2 = {
      {0xba3eb86f, 0xb33473f5, 0x1996f8, sign_and_exp_bits(1, 0)}};
  scp_decimal correct = {
      {0xdbfaccfc, 0x46da51a, 0x63f5bb7c, sign_and_exp_bits(0, 3)}};
  scp_decimal result;

  ck_assert_int_eq(scp_sub(d1, d2, &result), SCP_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(scp_sub_210) {
  // Segmentation fault test
  scp_decimal d1 = {{0x3c4d4cd0, 0x12ab5468, 0xb6, sign_and_exp_bits(1, 8)}};
  scp_decimal d2 = {
      {0xba3eb86f, 0xb33473f5, 0x1996f8, sign_and_exp_bits(1, 0)}};

  ck_assert_int_eq(scp_sub(d1, d2, NULL), SCP_OK);
  // ASSERT_BITS_EQ
}
END_TEST

Suite *sub_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "SCP_SUB" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("SCP_SUB");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, scp_sub_0);
  tcase_add_test(tc1_1, scp_sub_1);
  tcase_add_test(tc1_1, scp_sub_2);
  tcase_add_test(tc1_1, scp_sub_3);
  tcase_add_test(tc1_1, scp_sub_4);
  tcase_add_test(tc1_1, scp_sub_5);
  tcase_add_test(tc1_1, scp_sub_6);
  tcase_add_test(tc1_1, scp_sub_7);
  tcase_add_test(tc1_1, scp_sub_8);
  tcase_add_test(tc1_1, scp_sub_9);
  tcase_add_test(tc1_1, scp_sub_10);
  tcase_add_test(tc1_1, scp_sub_11);
  tcase_add_test(tc1_1, scp_sub_12);
  tcase_add_test(tc1_1, scp_sub_13);
  tcase_add_test(tc1_1, scp_sub_14);
  tcase_add_test(tc1_1, scp_sub_15);
  tcase_add_test(tc1_1, scp_sub_16);
  tcase_add_test(tc1_1, scp_sub_17);
  tcase_add_test(tc1_1, scp_sub_18);
  tcase_add_test(tc1_1, scp_sub_19);
  tcase_add_test(tc1_1, scp_sub_20);
  tcase_add_test(tc1_1, scp_sub_21);
  tcase_add_test(tc1_1, scp_sub_22);
  tcase_add_test(tc1_1, scp_sub_23);
  tcase_add_test(tc1_1, scp_sub_24);
  tcase_add_test(tc1_1, scp_sub_25);
  tcase_add_test(tc1_1, scp_sub_26);
  tcase_add_test(tc1_1, scp_sub_27);
  tcase_add_test(tc1_1, scp_sub_28);
  tcase_add_test(tc1_1, scp_sub_29);
  tcase_add_test(tc1_1, scp_sub_30);
  tcase_add_test(tc1_1, scp_sub_31);
  tcase_add_test(tc1_1, scp_sub_32);
  tcase_add_test(tc1_1, scp_sub_33);
  tcase_add_test(tc1_1, scp_sub_34);
  tcase_add_test(tc1_1, scp_sub_35);
  tcase_add_test(tc1_1, scp_sub_36);
  tcase_add_test(tc1_1, scp_sub_37);
  tcase_add_test(tc1_1, scp_sub_38);
  tcase_add_test(tc1_1, scp_sub_39);
  tcase_add_test(tc1_1, scp_sub_40);
  tcase_add_test(tc1_1, scp_sub_41);
  tcase_add_test(tc1_1, scp_sub_42);
  tcase_add_test(tc1_1, scp_sub_43);
  tcase_add_test(tc1_1, scp_sub_44);
  tcase_add_test(tc1_1, scp_sub_45);
  tcase_add_test(tc1_1, scp_sub_46);
  tcase_add_test(tc1_1, scp_sub_47);
  tcase_add_test(tc1_1, scp_sub_48);
  tcase_add_test(tc1_1, scp_sub_49);
  tcase_add_test(tc1_1, scp_sub_50);
  tcase_add_test(tc1_1, scp_sub_51);
  tcase_add_test(tc1_1, scp_sub_52);
  tcase_add_test(tc1_1, scp_sub_53);
  tcase_add_test(tc1_1, scp_sub_54);
  tcase_add_test(tc1_1, scp_sub_55);
  tcase_add_test(tc1_1, scp_sub_56);
  tcase_add_test(tc1_1, scp_sub_57);
  tcase_add_test(tc1_1, scp_sub_58);
  tcase_add_test(tc1_1, scp_sub_59);
  tcase_add_test(tc1_1, scp_sub_60);
  tcase_add_test(tc1_1, scp_sub_61);
  tcase_add_test(tc1_1, scp_sub_62);
  tcase_add_test(tc1_1, scp_sub_63);
  tcase_add_test(tc1_1, scp_sub_64);
  tcase_add_test(tc1_1, scp_sub_65);
  tcase_add_test(tc1_1, scp_sub_66);
  tcase_add_test(tc1_1, scp_sub_67);
  tcase_add_test(tc1_1, scp_sub_68);
  tcase_add_test(tc1_1, scp_sub_69);
  tcase_add_test(tc1_1, scp_sub_70);
  tcase_add_test(tc1_1, scp_sub_71);
  tcase_add_test(tc1_1, scp_sub_72);
  tcase_add_test(tc1_1, scp_sub_73);
  tcase_add_test(tc1_1, scp_sub_74);
  tcase_add_test(tc1_1, scp_sub_75);
  tcase_add_test(tc1_1, scp_sub_76);
  tcase_add_test(tc1_1, scp_sub_77);
  tcase_add_test(tc1_1, scp_sub_78);
  tcase_add_test(tc1_1, scp_sub_79);
  tcase_add_test(tc1_1, scp_sub_80);
  tcase_add_test(tc1_1, scp_sub_81);
  tcase_add_test(tc1_1, scp_sub_82);
  tcase_add_test(tc1_1, scp_sub_83);
  tcase_add_test(tc1_1, scp_sub_84);
  tcase_add_test(tc1_1, scp_sub_85);
  tcase_add_test(tc1_1, scp_sub_86);
  tcase_add_test(tc1_1, scp_sub_87);
  tcase_add_test(tc1_1, scp_sub_88);
  tcase_add_test(tc1_1, scp_sub_89);
  tcase_add_test(tc1_1, scp_sub_90);
  tcase_add_test(tc1_1, scp_sub_91);
  tcase_add_test(tc1_1, scp_sub_92);
  tcase_add_test(tc1_1, scp_sub_93);
  tcase_add_test(tc1_1, scp_sub_94);
  tcase_add_test(tc1_1, scp_sub_95);
  tcase_add_test(tc1_1, scp_sub_96);
  tcase_add_test(tc1_1, scp_sub_97);
  tcase_add_test(tc1_1, scp_sub_98);
  tcase_add_test(tc1_1, scp_sub_99);
  tcase_add_test(tc1_1, scp_sub_100);
  tcase_add_test(tc1_1, scp_sub_101);
  tcase_add_test(tc1_1, scp_sub_102);
  tcase_add_test(tc1_1, scp_sub_103);
  tcase_add_test(tc1_1, scp_sub_104);
  tcase_add_test(tc1_1, scp_sub_105);
  tcase_add_test(tc1_1, scp_sub_106);
  tcase_add_test(tc1_1, scp_sub_107);
  tcase_add_test(tc1_1, scp_sub_108);
  tcase_add_test(tc1_1, scp_sub_109);
  tcase_add_test(tc1_1, scp_sub_110);
  tcase_add_test(tc1_1, scp_sub_111);
  tcase_add_test(tc1_1, scp_sub_112);
  tcase_add_test(tc1_1, scp_sub_113);
  tcase_add_test(tc1_1, scp_sub_114);
  tcase_add_test(tc1_1, scp_sub_115);
  tcase_add_test(tc1_1, scp_sub_116);
  tcase_add_test(tc1_1, scp_sub_117);
  tcase_add_test(tc1_1, scp_sub_118);
  tcase_add_test(tc1_1, scp_sub_119);
  tcase_add_test(tc1_1, scp_sub_120);
  tcase_add_test(tc1_1, scp_sub_121);
  tcase_add_test(tc1_1, scp_sub_122);
  tcase_add_test(tc1_1, scp_sub_123);
  tcase_add_test(tc1_1, scp_sub_124);
  tcase_add_test(tc1_1, scp_sub_125);
  tcase_add_test(tc1_1, scp_sub_126);
  tcase_add_test(tc1_1, scp_sub_127);
  tcase_add_test(tc1_1, scp_sub_128);
  tcase_add_test(tc1_1, scp_sub_129);
  tcase_add_test(tc1_1, scp_sub_130);
  tcase_add_test(tc1_1, scp_sub_131);
  tcase_add_test(tc1_1, scp_sub_132);
  tcase_add_test(tc1_1, scp_sub_133);
  tcase_add_test(tc1_1, scp_sub_134);
  tcase_add_test(tc1_1, scp_sub_135);
  tcase_add_test(tc1_1, scp_sub_136);
  tcase_add_test(tc1_1, scp_sub_137);
  tcase_add_test(tc1_1, scp_sub_138);
  tcase_add_test(tc1_1, scp_sub_139);
  tcase_add_test(tc1_1, scp_sub_140);
  tcase_add_test(tc1_1, scp_sub_141);
  tcase_add_test(tc1_1, scp_sub_142);
  tcase_add_test(tc1_1, scp_sub_143);
  tcase_add_test(tc1_1, scp_sub_144);
  tcase_add_test(tc1_1, scp_sub_145);
  tcase_add_test(tc1_1, scp_sub_146);
  tcase_add_test(tc1_1, scp_sub_147);
  tcase_add_test(tc1_1, scp_sub_148);
  tcase_add_test(tc1_1, scp_sub_149);
  tcase_add_test(tc1_1, scp_sub_150);
  tcase_add_test(tc1_1, scp_sub_151);
  tcase_add_test(tc1_1, scp_sub_152);
  tcase_add_test(tc1_1, scp_sub_153);
  tcase_add_test(tc1_1, scp_sub_154);
  tcase_add_test(tc1_1, scp_sub_155);
  tcase_add_test(tc1_1, scp_sub_156);
  tcase_add_test(tc1_1, scp_sub_157);
  tcase_add_test(tc1_1, scp_sub_158);
  tcase_add_test(tc1_1, scp_sub_159);
  tcase_add_test(tc1_1, scp_sub_160);
  tcase_add_test(tc1_1, scp_sub_161);
  tcase_add_test(tc1_1, scp_sub_162);
  tcase_add_test(tc1_1, scp_sub_163);
  tcase_add_test(tc1_1, scp_sub_164);
  tcase_add_test(tc1_1, scp_sub_165);
  tcase_add_test(tc1_1, scp_sub_166);
  tcase_add_test(tc1_1, scp_sub_167);
  tcase_add_test(tc1_1, scp_sub_168);
  tcase_add_test(tc1_1, scp_sub_169);
  tcase_add_test(tc1_1, scp_sub_170);
  tcase_add_test(tc1_1, scp_sub_171);
  tcase_add_test(tc1_1, scp_sub_172);
  tcase_add_test(tc1_1, scp_sub_173);
  tcase_add_test(tc1_1, scp_sub_174);
  tcase_add_test(tc1_1, scp_sub_175);
  tcase_add_test(tc1_1, scp_sub_176);
  tcase_add_test(tc1_1, scp_sub_177);
  tcase_add_test(tc1_1, scp_sub_178);
  tcase_add_test(tc1_1, scp_sub_179);
  tcase_add_test(tc1_1, scp_sub_180);
  tcase_add_test(tc1_1, scp_sub_181);
  tcase_add_test(tc1_1, scp_sub_182);
  tcase_add_test(tc1_1, scp_sub_183);
  tcase_add_test(tc1_1, scp_sub_184);
  tcase_add_test(tc1_1, scp_sub_185);
  tcase_add_test(tc1_1, scp_sub_186);
  tcase_add_test(tc1_1, scp_sub_187);
  tcase_add_test(tc1_1, scp_sub_188);
  tcase_add_test(tc1_1, scp_sub_189);
  tcase_add_test(tc1_1, scp_sub_190);
  tcase_add_test(tc1_1, scp_sub_191);
  tcase_add_test(tc1_1, scp_sub_192);
  tcase_add_test(tc1_1, scp_sub_193);
  tcase_add_test(tc1_1, scp_sub_194);
  tcase_add_test(tc1_1, scp_sub_195);
  tcase_add_test(tc1_1, scp_sub_196);
  tcase_add_test(tc1_1, scp_sub_197);
  tcase_add_test(tc1_1, scp_sub_198);
  tcase_add_test(tc1_1, scp_sub_199);
  tcase_add_test(tc1_1, scp_sub_201);
  tcase_add_test(tc1_1, scp_sub_202);
  tcase_add_test(tc1_1, scp_sub_203);
  tcase_add_test(tc1_1, scp_sub_204);
  tcase_add_test(tc1_1, scp_sub_205);
  tcase_add_test(tc1_1, scp_sub_206);
  tcase_add_test(tc1_1, scp_sub_207);
  tcase_add_test(tc1_1, scp_sub_208);
  tcase_add_test(tc1_1, scp_sub_209);
  tcase_add_test(tc1_1, scp_sub_210);

  return s1;
}
