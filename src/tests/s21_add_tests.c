#include "s21_decimal_tests.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 *              ADD FUNCTION TESTS
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

START_TEST(s21_add_0) {
  // 653 + -200825813 = -200825160
  s21_decimal d1 = {{0x28d, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xbf85bd5, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xbf85948, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_1) {
  //-8647181163 + -2525465 = -8649706628
  s21_decimal d1 = {{0x369836b, 0x2, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x268919, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x3900c84, 0x2, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_2) {
  // 96.2 + -96.2 = 0.0
  s21_decimal d1 = {{0x3c2, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x3c2, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_3) {
  // 9593668235491.502 + 9593668235491.502 = 19187336470983.004
  s21_decimal d1 = {{0xf344f8ae, 0x221563, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0xf344f8ae, 0x221563, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0xe689f15c, 0x442ac7, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_4) {
  //-13.778 + -41.207160379402819 = -54.985160379402819
  s21_decimal d1 = {{0x35d2, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0xac9dea43, 0x9265b1, 0x0, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {{0x48550a43, 0xc358b6, 0x0, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_5) {
  //-972821257882890010899801 + -369.052373922709116 =
  //-972821257882890010900170.0524
  s21_decimal d1 = {{0x5ff43559, 0xbefde890, 0xce00, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xc32d7e7c, 0x51f232d, 0x0, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {
      {0x339c34ac, 0x9e4c87a4, 0x1f6efd24, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_6) {
  //-2.890877 + -0.4804 = -3.371277
  s21_decimal d1 = {{0x2c1c7d, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x12c4, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x33710d, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_7) {
  // 6.30062135 + 710864 = 710870.30062135
  s21_decimal d1 = {{0x258dfc37, 0x0, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {{0xad8d0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x3d2ccc37, 0x40a7, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_8) {
  // 1918836449 + -768713910367337860568987 = -768713910367335941732538
  s21_decimal d1 = {{0x725f1ee1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x51d0179b, 0x1088723e, 0xa2c8, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xdf70f8ba, 0x1088723d, 0xa2c8, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_9) {
  // 6527981086056209996 + -6 = 6527981086056209990
  s21_decimal d1 = {{0x6d95e4c, 0x5a980c36, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x6, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x6d95e46, 0x5a980c36, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_10) {
  //-6145793163 + -303521801 = -6449314964
  s21_decimal d1 = {{0x6e515c8b, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x12176009, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x8068bc94, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_11) {
  // 64130.0463 + 14030514 = 14094644.0463
  s21_decimal d1 = {{0x263977ef, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0xd616b2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xd110010f, 0x20, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_12) {
  //-6730.307 + -5 = -6735.307
  s21_decimal d1 = {{0x66b243, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x5, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x66c5cb, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_13) {
  //-65550891282796406842408.987 + 91132 = -65550891282796406751276.987
  s21_decimal d1 = {
      {0x3365401b, 0xefd5f48f, 0x3638f0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x163fc, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2df6afbb, 0xefd5f48f, 0x3638f0, sign_and_exp_bits(1, 3)}};
  s21_decimal result;
  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_14) {
  // 17877612243918955018.3035 + 2 = 17877612243918955020.3035
  s21_decimal d1 = {{0x8219b27b, 0x7917a1f3, 0x25db, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x821a009b, 0x7917a1f3, 0x25db, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_15) {
  //-808308.053357813125066 + -301.5973921379578 = -808609.650749951082866
  s21_decimal d1 = {{0xe7f14fca, 0xd18713ed, 0x2b, sign_and_exp_bits(1, 15)}};
  s21_decimal d2 = {{0x263c54fa, 0xab703, 0x0, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {
      {0xd7828172, 0xd5b69128, 0x2b, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_16) {
  // 91414203640.73772909697648711 + 7410165648791291 =
  // 7410257062994931.7377290969765
  s21_decimal d1 = {
      {0x22434847, 0xeaa6592b, 0x1d899b0e, sign_and_exp_bits(0, 17)}};
  s21_decimal d2 = {{0xa33916fb, 0x1a5381, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2b7ca2a5, 0x30053165, 0xef7035b3, sign_and_exp_bits(0, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_17) {
  // 97738009.7 + 191216.31795811491101330 = 97929226.01795811491101330
  s21_decimal d1 = {{0x3a41a301, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x16a5ba92, 0x95f2d78b, 0x40c, sign_and_exp_bits(0, 17)}};
  s21_decimal correct = {
      {0x6966ba92, 0x65e2d5a6, 0x819bb, sign_and_exp_bits(0, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_18) {
  // 24 + -24 = 0
  s21_decimal d1 = {{0x18, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x18, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;
  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_19) {
  // 65910932 + 65910932 = 131821864
  s21_decimal d1 = {{0x3edb894, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3edb894, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x7db7128, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_20) {
  //-67601557205633 + -2.4698284708 = -67601557205635.4698284708
  s21_decimal d1 = {{0xb6cdb281, 0x3d7b, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xc021eaa4, 0x5, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {
      {0xf2a7cea4, 0xe0a9ed3f, 0x8f26, sign_and_exp_bits(1, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_21) {
  //-7080175794590755626757 + -12973873620000000000 = -7093149668210755626757
  s21_decimal d1 = {{0x1d0c9f05, 0xd12d64cd, 0x17f, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xa0e94800, 0xb40c7551, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xbdf5e705, 0x8539da1e, 0x180, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_22) {
  //-5146.523479478978422 + -3189457764 = -3189462910.523479478978422
  s21_decimal d1 = {{0x4e8d4776, 0x476c1fd6, 0x0, sign_and_exp_bits(1, 15)}};
  s21_decimal d2 = {{0xbe1b4364, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x1f974776, 0x217e3e5e, 0x2a365, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_23) {
  // 274303.463348192276649897 + 22747791 = 23022094.463348192276649897
  s21_decimal d1 = {{0x3e9417a9, 0x5426125, 0x3a16, sign_and_exp_bits(0, 18)}};
  s21_decimal d2 = {{0x15b1a8f, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xe77017a9, 0x3dda930b, 0x130b1e, sign_and_exp_bits(0, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_24) {
  //-75191 + 7.5 = -75183.5
  s21_decimal d1 = {{0x125b7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x4b, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0xb78db, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_25) {
  //-555631835645222649587947289 + 5.8802979 = -555631835645222649587947283.12
  s21_decimal d1 = {
      {0x9045d719, 0x2a59d073, 0x1cb9b9e, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3814323, 0x0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0x5b480378, 0x8b156d24, 0xb388c9c8, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_26) {
  // 370568803271717.844 + -59506.2 = 370568803212211.644
  s21_decimal d1 = {{0xfbda33d4, 0x524865c, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x91476, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0xf84e35bc, 0x524865c, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_27) {
  // 17317 + -8880575561805747210064 = -8880575561805747192747
  s21_decimal d1 = {{0x43a5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xe984750, 0x6abe4628, 0x1e1, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xe9803ab, 0x6abe4628, 0x1e1, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_28) {
  // 66299.6000 + -1.1 = 66298.5000
  s21_decimal d1 = {{0x27848420, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0xb, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x27845928, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_29) {
  //-3561189162.598897857 + -78020451105942.8145042009759 =
  //-78024012295105.4134020579759
  s21_decimal d1 = {{0xe6ad98c1, 0x316be2ac, 0x0, sign_and_exp_bits(1, 9)}};
  s21_decimal d2 = {
      {0x56ffae9f, 0x4b2eafe4, 0x2855ebb, sign_and_exp_bits(1, 13)}};
  s21_decimal correct = {
      {0x341ea1af, 0xd17531d7, 0x2856645, sign_and_exp_bits(1, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_30) {
  // 1000 + -339.1630758724824086720676335 = 660.8369241275175913279323665
  s21_decimal d1 = {{0x3e8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xc47a01ef, 0xd80a3435, 0xaf57dbf, sign_and_exp_bits(1, 25)}};
  s21_decimal correct = {
      {0x4b85fe11, 0x661ace2b, 0x155a509e, sign_and_exp_bits(0, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_31) {
  // 659.0308222976616270264771665 + -9.8 = 649.2308222976616270264771665
  s21_decimal d1 = {
      {0x4e37a451, 0xa2907244, 0x154b600c, sign_and_exp_bits(0, 25)}};
  s21_decimal d2 = {{0x62, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0xac37a451, 0xfd65ff4c, 0x14fa4fbd, sign_and_exp_bits(0, 25)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_32) {
  //-64780354586.79 + 57090599 = -64723263987.79
  s21_decimal d1 = {{0x49009a77, 0x5e4, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x3672227, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xf4b7433b, 0x5e2, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_33) {
  //-22935.351229654626 + 94196639531274 = 94196639508338.648770345374
  s21_decimal d1 = {{0x96d7a662, 0x517b94, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal d2 = {{0xdd3d010a, 0x55ab, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2caaf99e, 0xf4e507d, 0x4deaea, sign_and_exp_bits(0, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_34) {
  // 831 + -87534544791262520 = -87534544791261689
  s21_decimal d1 = {{0x33f, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x67dbd538, 0x136fc34, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x67dbd1f9, 0x136fc34, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_35) {
  //-57128.45974314943704826592611 + 973671963086202 =
  // 973671963029073.5402568505630
  s21_decimal d1 = {
      {0x87073d63, 0xd2451360, 0x12758e30, sign_and_exp_bits(1, 23)}};
  s21_decimal d2 = {{0xab7ccd7a, 0x3758c, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x2531d91e, 0xcd5b407c, 0x1f760694, sign_and_exp_bits(0, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_36) {
  //-18.46676378084615 + -55007218.6625805468 = -55007237.12934432764615
  s21_decimal d1 = {{0xd987e507, 0x68f8a, 0x0, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0x44a74c9c, 0x7a23fbd, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {
      {0xa0a872c7, 0x31e060d4, 0x12a, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_37) {
  // 55.7287321976484684475284 + 8383 = 8438.7287321976484684475284
  s21_decimal d1 = {{0x36e1ab94, 0x9b33ced6, 0x7602, sign_and_exp_bits(0, 22)}};
  s21_decimal d2 = {{0x20bf, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x34a1ab94, 0x321a769, 0x45cdb4, sign_and_exp_bits(0, 22)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_38) {
  // 864.870205886 + -315659267504.90853010861362 = -315659266640.03832422261362
  s21_decimal d1 = {{0x5e4809be, 0xc9, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {
      {0xaebc6d32, 0x51667bc6, 0x1a1c58, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {
      {0x2dee272, 0x5033384a, 0x1a1c58, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_39) {
  // 32652719600000 + 96.6534 = 32652719600096.6534
  s21_decimal d1 = {{0x8dc0b180, 0x1db2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xebf86, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x37245786, 0x4880ec1, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_40) {
  //-34130253777546442612576 + 2214763796624962277240465315 =
  // 2214729666371184730797852739
  s21_decimal d1 = {{0xdb69f60, 0x346b74d8, 0x73a, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xacbfe7a3, 0xfdfda25a, 0x7280279, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x9f094843, 0xc9922d82, 0x727fb3f, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_41) {
  //-0.25812 + -0.25812 = -0.51624
  s21_decimal d1 = {{0x64d4, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {{0x64d4, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0xc9a8, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_42) {
  // 87650.022331960072332685 + -98766 = -11115.977668039927667315
  s21_decimal d1 = {{0x4f87e58d, 0x84694932, 0x128f, sign_and_exp_bits(0, 18)}};
  s21_decimal d2 = {{0x181ce, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xc6f01a73, 0x992dea1b, 0x25a, sign_and_exp_bits(1, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_43) {
  // 0 + 8 = 8
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_44) {
  //-7 + 9318723208830603687 = 9318723208830603680
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xbe8951a7, 0x8152c162, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xbe8951a0, 0x8152c162, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_45) {
  //-821050275838199439618 + -6.4 = -821050275838199439624.4
  s21_decimal d1 = {{0x985da102, 0x825c8bc3, 0x2c, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x40, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0xf3a84a54, 0x179d75a3, 0x1bd, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_46) {
  // 9052737.62288187 + 630873492082864885594100000 =
  // 630873492082864885603152737.62
  s21_decimal d1 = {{0x7906923b, 0x33757, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal d2 = {
      {0xc0009120, 0x88b36f00, 0x209d8a8, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x362e1222, 0x66175c4b, 0xcbd8a1d5, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_47) {
  // 88148 + -88148 = 0
  s21_decimal d1 = {{0x15854, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x15854, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_48) {
  // 75281090 + 75281090 = 150562180
  s21_decimal d1 = {{0x47cb2c2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x47cb2c2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x8f96584, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_49) {
  // 11725239413000 + -7051.434338320097 = 11725239405948.565661679903
  s21_decimal d1 = {{0xfebae908, 0xaa9, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xfee47ee1, 0x190d3d, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {
      {0x81d4011f, 0x8078b960, 0x9b2ea, sign_and_exp_bits(0, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_50) {
  //-37500505727379.23995245377560 + -37500505727379.23995245377560 =
  //-75001011454758.47990490755120
  s21_decimal d1 = {
      {0xac867818, 0xe507acea, 0xc1df818, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {
      {0xac867818, 0xe507acea, 0xc1df818, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {
      {0x590cf030, 0xca0f59d5, 0x183bf031, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_51) {
  //-49182844145253197.785 + 33003.3 = -49182844145220194.485
  s21_decimal d1 = {{0x1137a7d9, 0xaa8c902b, 0x2, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0x50931, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0xf4010b5, 0xaa8c902b, 0x2, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_52) {
  //-427843255.8789 + -569.9913172 = -427843825.8702172
  s21_decimal d1 = {{0x2673eec5, 0x3e4, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x53bdc5d4, 0x1, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {{0x889a775c, 0xf3337, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_53) {
  //-9632757.5118586 + -9846275738564477253472540590 =
  //-9846275738564477253482173348
  s21_decimal d1 = {{0x2e5a2fa, 0x579c, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {
      {0x2b2cd7ae, 0x550785f7, 0x1fd0a5fd, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x2bbfd3a4, 0x550785f7, 0x1fd0a5fd, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_54) {
  // 11980.8880981133 + -304224684584298543 = -304224684584286562.1119018867
  s21_decimal d1 = {{0x2dcab48d, 0x6cf7, 0x0, sign_and_exp_bits(0, 10)}};
  s21_decimal d2 = {{0x208d682f, 0x438d2bd, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xa9042773, 0xf999a0a7, 0x9d47cd3, sign_and_exp_bits(1, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_55) {
  //-7955331219381 + 7955331219381 = -0
  s21_decimal d1 = {{0x3eb0ffb5, 0x73c, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3eb0ffb5, 0x73c, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_56) {
  //-95520317 + 931.151887954197159627979 = -95519385.84811204580284037202
  s21_decimal d1 = {{0x5b1863d, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x9e604ccb, 0xd8516033, 0xc52d, sign_and_exp_bits(0, 21)}};
  s21_decimal correct = {
      {0xd15ff852, 0x414910b5, 0x1edd2dac, sign_and_exp_bits(1, 20)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_57) {
  // 71.34013257510 + 6548996202886 = 6548996202957.34013257510
  s21_decimal d1 = {{0x4537726, 0x67d, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0xce97a186, 0x5f4, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x9278e726, 0x2df74412, 0x8aae, sign_and_exp_bits(0, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_58) {
  // 64080.2039863132392000000 + -7327552556315385.110061452922 =
  // -7327552556251304.9060751396828
  s21_decimal d1 = {{0xbd240a00, 0xf2bc6ccd, 0x87b1, sign_and_exp_bits(0, 19)}};
  s21_decimal d2 = {
      {0xc1d90e7a, 0x7273f20, 0x17ad359c, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {
      {0x2d174fdc, 0x3ea3e138, 0xecc41818, sign_and_exp_bits(1, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_59) {
  // 168055272930536.470509 + 2919405.39432121 = 168055275849941.86483021
  s21_decimal d1 = {{0xd7f237ed, 0x1c3c4455, 0x9, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0xb425fcb9, 0x10984, 0x0, sign_and_exp_bits(0, 8)}};
  s21_decimal correct = {
      {0xec3d54d, 0x78bbb0d, 0x38f, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_60) {
  // 5430.1 + -9269.317011016000 = -3839.217011016000
  s21_decimal d1 = {{0xd41d, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xbc08940, 0x20ee65, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {{0x5e284140, 0xda3bf, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_61) {
  //-574309215149396000958.59100000 + 2001847.7641066 =
  //-574309215149393999110.82689340
  s21_decimal d1 = {
      {0x3302c960, 0xb793e797, 0xb991bead, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0xea3fad6a, 0x1234, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0xc86033c, 0xb7933186, 0xb991bead, sign_and_exp_bits(1, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_62) {
  //-48041.7 + -8493302457 = -8493350498.7
  s21_decimal d1 = {{0x754a1, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0xfa3d82b9, 0x1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xc66e6fdb, 0x13, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_63) {
  // 529691.8727623 + -9602.0201749058 = 520089.8525873942
  s21_decimal d1 = {{0x48f58bc7, 0x4d1, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0x72043a42, 0x5754, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal correct = {{0x8d25c716, 0x127a30, 0x0, sign_and_exp_bits(0, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_64) {
  // 5869208411022 + -40.31736 = 5869208410981.68264
  s21_decimal d1 = {{0x88151b8e, 0x556, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3d84f8, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0x34ee07c8, 0x8252965, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_65) {
  //-994157077 + 4.702189291017355161342 = -994157072.2978107089826448387
  s21_decimal d1 = {{0x3b41a215, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xe7586efe, 0xe7fc36e9, 0xfe, sign_and_exp_bits(0, 21)}};
  s21_decimal correct = {
      {0x6ad8403, 0xc9dee814, 0x201f797c, sign_and_exp_bits(1, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_66) {
  // 1693261574101619 + -39105626768731613.3090000 = -37412365194629994.3090000
  s21_decimal d1 = {{0x2ea2da73, 0x60403, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xc13d92d0, 0x33e764b5, 0x52cf, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {
      {0x4f88f750, 0x48a7d519, 0x4f39, sign_and_exp_bits(1, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_67) {
  // 2091727842841722864334 + -24.668 = 2091727842841722864309.332
  s21_decimal d1 = {{0x8effc2ce, 0x648e1e9d, 0x71, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x605c, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal correct = {
      {0x97109454, 0xcb279776, 0x1baf0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_68) {
  //-3884546591101 + -564661660500000000000 = -564661664384546591101
  s21_decimal d1 = {{0x7105097d, 0x388, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xe0b84800, 0x9c413484, 0x1e, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x51bd517d, 0x9c41380d, 0x1e, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_69) {
  //-2.9 + -85474411480.300000 = -85474411483.200000
  s21_decimal d1 = {{0x1d, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x3dab39e0, 0x12faa86, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {{0x3dd77a00, 0x12faa86, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_70) {
  // 81075 + -995607 = -914532
  s21_decimal d1 = {{0x13cb3, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf3117, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xdf464, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_71) {
  //-1.7 + -95695934543066504.15349 = -95695934543066505.85349
  s21_decimal d1 = {{0x11, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x1336e0f5, 0xc4c990d0, 0x206, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0x13397905, 0xc4c990d0, 0x206, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_72) {
  //-349580591310218 + 91783 = -349580591218435
  s21_decimal d1 = {{0x12f7258a, 0x13df1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x16687, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x12f5bf03, 0x13df1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_73) {
  // 7880090421518558879085629 + -552319774 = 7880090421518558326765855
  s21_decimal d1 = {{0xe660f43d, 0x8ec6b6ba, 0x684ac, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x20ebbb1e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xc575391f, 0x8ec6b6ba, 0x684ac, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_74) {
  //-3651983038755079992060164 + -2988242.1676757 =
  //-3651983038755079995048406.1677
  s21_decimal d1 = {{0xfd072904, 0x65b08857, 0x30556, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8b210ad5, 0x1b2d, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal correct = {
      {0xdcd3bded, 0x3fcded12, 0x76007ee4, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_75) {
  // 1.363 + -95838685 = -95838683.637
  s21_decimal d1 = {{0x553, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x5b661dd, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x506e41f5, 0x16, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_76) {
  //-29927401.3109671 + 915.4081343800000000000000 =
  //-29926485.902832720000000000000
  s21_decimal d1 = {{0x293deda7, 0x11030, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {
      {0xd5ab8000, 0xbe76f881, 0x79273, sign_and_exp_bits(0, 22)}};
  s21_decimal correct = {
      {0xcad50000, 0x891029be, 0x60b29be3, sign_and_exp_bits(1, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_77) {
  //-4912871094535225 + 91780 = -4912871094443445
  s21_decimal d1 = {{0xf06ac439, 0x11743a, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x16684, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xf0695db5, 0x11743a, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_78) {
  // 65.443200 + -2731968501325.384270957318123 = -2731968501259.941070957318123
  s21_decimal d1 = {{0x3e69580, 0x0, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {
      {0x2c9d0feb, 0x3706cc12, 0x8d3d4d5, sign_and_exp_bits(1, 15)}};
  s21_decimal correct = {
      {0xcba60feb, 0x361e4bd3, 0x8d3d4d5, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_79) {
  //-49.572086998908 + 8266383846251344176075213822 =
  // 8266383846251344176075213772
  s21_decimal d1 = {{0xe6a2e77c, 0x2d15, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal d2 = {
      {0x132b8bfe, 0x3c38a5be, 0x1ab5cade, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x132b8bcc, 0x3c38a5be, 0x1ab5cade, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_80) {
  // 35888417529832845040243 + -49346461976644 = 35888417480486383063599
  s21_decimal d1 = {{0xcc9b5a73, 0x83d7de65, 0x799, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5e564844, 0x2ce1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x6e45122f, 0x83d7b184, 0x799, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_81) {
  //-29222012664953859314831.17116 + -29222012664953859314831.17116 =
  //-58444025329907718629662.34232
  s21_decimal d1 = {
      {0xac4ef63c, 0x14264e38, 0x9713030, sign_and_exp_bits(1, 5)}};
  s21_decimal d2 = {
      {0xac4ef63c, 0x14264e38, 0x9713030, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0x589dec78, 0x284c9c71, 0x12e26060, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_82) {
  // 7088639289305705.09046 + 49727163969825826.0 = 56815803259131531.09046
  s21_decimal d1 = {{0xea669af6, 0x6d7693a3, 0x26, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0xf1173954, 0x6e6a9eb, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {
      {0x8595fc36, 0xffc4241d, 0x133, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_83) {
  //-5575.9388 + -40733011303279295.5220 = -40733011303284871.4608
  s21_decimal d1 = {{0x352d21c, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x755d954, 0x14d743ad, 0x16, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {
      {0xaa8ab70, 0x14d743ad, 0x16, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_84) {
  //-4167855803791345426815812 + 543169 = -4167855803791345426272643
  s21_decimal d1 = {{0x1f0edb44, 0xea7565c7, 0x37293, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x849c1, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x1f069183, 0xea7565c7, 0x37293, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_85) {
  // 695271381070462 + -923.02 = 695271381069538.98
  s21_decimal d1 = {{0x7bb0f27e, 0x27858, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1688e, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {{0x511d50aa, 0xf70290, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_86) {
  // 5707421032648 + -9.4065 = 5707421032638.5935
  s21_decimal d1 = {{0xdccda0c8, 0x530, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x16f71, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x2057150f, 0xcac4b1, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_87) {
  //-273218372.91038513339863652 + -273218372.91038513339863652 =
  //-546436745.82077026679727304
  s21_decimal d1 = {
      {0xcf289264, 0xc471d58a, 0x16999f, sign_and_exp_bits(1, 17)}};
  s21_decimal d2 = {
      {0xcf289264, 0xc471d58a, 0x16999f, sign_and_exp_bits(1, 17)}};
  s21_decimal correct = {
      {0x9e5124c8, 0x88e3ab15, 0x2d333f, sign_and_exp_bits(1, 17)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_88) {
  // 99099466 + -96.1 = 99099369.9
  s21_decimal d1 = {{0x5e8234a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3c1, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x3b115d23, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_89) {
  // 9643916628225296740000 + 9643916628225296740000 = 19287833256450593480000
  s21_decimal d1 = {{0xf3b4aea0, 0xcc3a85b5, 0x20a, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xf3b4aea0, 0xcc3a85b5, 0x20a, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xe7695d40, 0x98750b6b, 0x415, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_90) {
  //-1865526566180421342.835252 + -4427341737883.19479911173329 =
  //-1865530993522159226.0300511117
  s21_decimal d1 = {{0xb803b234, 0x65d5d5bc, 0x18b0a, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {
      {0x50f44cd1, 0xa71a3368, 0x16e389b, sign_and_exp_bits(1, 14)}};
  s21_decimal correct = {
      {0xec8c178d, 0x204a341, 0x3c474f8a, sign_and_exp_bits(1, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_91) {
  //-9540802046427249492990207 + -5275216993911356 = -9540802051702466486901563
  s21_decimal d1 = {{0xbb598ff, 0xea5111e5, 0x7e457, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2b09023c, 0x12bdc8, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x36be9b3b, 0xea63cfad, 0x7e457, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_92) {
  //-3157391.3647 + -459048.200520 = -3616439.565220
  s21_decimal d1 = {{0x59f3b02f, 0x7, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0xe167a948, 0x6a, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {{0x4987ba4, 0x34a, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_93) {
  //-3.100481 + 3.100481 = -0.000000
  s21_decimal d1 = {{0x2f4f41, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x2f4f41, 0x0, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_94) {
  //-7381095942219711 + -2.146980215736119901 = -7381095942219713.1469802157361
  s21_decimal d1 = {{0x51b067bf, 0x1a3911, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8abe325d, 0x1dcb9b21, 0x0, sign_and_exp_bits(1, 18)}};
  s21_decimal correct = {
      {0x79d3b531, 0xf07477a7, 0xee7efe9f, sign_and_exp_bits(1, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_95) {
  //-662820163740299158998086 + -91.38792 = -662820163740299158998177.38792
  s21_decimal d1 = {{0x1cd9cc46, 0x8d964e11, 0x8c5b, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8b7268, 0x0, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {
      {0xd5ddc228, 0x78dedca5, 0xd62b32eb, sign_and_exp_bits(1, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_96) {
  // 5814677842689074385873915 + -971251951660000000000 =
  // 5813706590737414385873915
  s21_decimal d1 = {{0x48136bfb, 0x51458a27, 0x4cf4e, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x132ab800, 0xa6d4181f, 0x34, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x34e8b3fb, 0xaa717208, 0x4cf19, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_97) {
  //-9178510 + 1594168968079 = 1594159789569
  s21_decimal d1 = {{0x8c0d8e, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x2be0038f, 0x173, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x2b53f601, 0x173, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_98) {
  //-6052067462567 + -459690624285335870 = -459696676352798437
  s21_decimal d1 = {{0x1b54cda7, 0x581, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xef1ae13e, 0x661262f, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xa6faee5, 0x6612bb1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_99) {
  // 5150273499442526.8989 + -9.43 = 5150273499442517.4689
  s21_decimal d1 = {{0xafcc4afd, 0xcabe789a, 0x2, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x3af, 0x0, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal correct = {
      {0xafcadaa1, 0xcabe789a, 0x2, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_100) {
  //-99331 + 9.389054001415 = -99321.610945998585
  s21_decimal d1 = {{0x18403, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xf3a8107, 0x88a, 0x0, sign_and_exp_bits(0, 12)}};
  s21_decimal correct = {
      {0x9af4aef9, 0x160dc7a, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_101) {
  // 14208301650132 + -552069 = 14208301098063
  s21_decimal d1 = {{0x20c5d0d4, 0xcec, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x86c85, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x20bd644f, 0xcec, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_102) {
  //-1572820682065916945575 + 17933567197712000 = -1572802748498719233575
  s21_decimal d1 = {{0x869364a7, 0x43458d2d, 0x55, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xfe600e80, 0x3fb67b, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x88335627, 0x4305d6b1, 0x55, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_103) {
  //-884935647796623706834005685 + 736994676262046.31639625835 =
  //-884935647795886712157743638.7
  s21_decimal d1 = {
      {0x859aeeb5, 0x97b13f56, 0x2dc0069, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0x94e1906b, 0x2543ee8f, 0x3cf678, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {
      {0xc540a4e3, 0xecd24a73, 0x1c98041f, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_104) {
  // 6846330157971.53072511640836 + -6732650529150735404 =
  // -6732643682820577432.4692748836
  s21_decimal d1 = {
      {0x6b26e504, 0x2774fc33, 0x23650ae, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {{0x32e0142c, 0x5d6f2dfc, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xc5250a24, 0xbe107744, 0xd98b1f8d, sign_and_exp_bits(1, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_105) {
  //-44059011.4470 + -44059011.4470 = -88118022.8940
  s21_decimal d1 = {{0x95379ea6, 0x66, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x95379ea6, 0x66, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x2a6f3d4c, 0xcd, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_106) {
  //-69596821095390092224239 + 71201966252306674109 = -69525619129137785550130
  s21_decimal d1 = {{0xe31866ef, 0xd9ea4e7e, 0xebc, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xf21731bd, 0xdc20330f, 0x3, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xf1013532, 0xfdca1b6e, 0xeb8, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_107) {
  // 9064923047.520730 + -8794409769 = 270513278.520730
  s21_decimal d1 = {{0xde29e9da, 0x20347f, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0xc300b29, 0x2, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xc7df8d9a, 0xf607, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_108) {
  // 6829696062561182365 + -33735126179540995 = 6795960936381641370
  s21_decimal d1 = {{0x34d7e29d, 0x5ec7f462, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x24627003, 0x77d9eb, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x1075729a, 0x5e501a77, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_109) {
  // 4812.158981614356128933686 + 4812.158981614356128933686 =
  // 9624.317963228712257867372
  s21_decimal d1 = {
      {0x52b52736, 0xa93e8b44, 0x3fb03, sign_and_exp_bits(0, 21)}};
  s21_decimal d2 = {
      {0x52b52736, 0xa93e8b44, 0x3fb03, sign_and_exp_bits(0, 21)}};
  s21_decimal correct = {
      {0xa56a4e6c, 0x527d1688, 0x7f607, sign_and_exp_bits(0, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_110) {
  // 30.082222807002643 + -602775945 = -602775914.917777192997357
  s21_decimal d1 = {{0x4c772e13, 0x6adf9f, 0x0, sign_and_exp_bits(0, 15)}};
  s21_decimal d2 = {{0x23eda189, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x384351ed, 0x8c3e2e0c, 0x7fa4, sign_and_exp_bits(1, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_111) {
  //-3678419053714 + -42.3 = -3678419053756.3
  s21_decimal d1 = {{0x72dc6c92, 0x358, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x1a7, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0x7c9c3f5b, 0x2174, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_112) {
  // 6314334871760690547038 + -1163 = 6314334871760690545875
  s21_decimal d1 = {{0x1dad095e, 0x4cffdf16, 0x156, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x48b, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x1dad04d3, 0x4cffdf16, 0x156, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_113) {
  //-67.45792319 + -7681832034938 = -7681832035005.45792319
  s21_decimal d1 = {{0x92149f3f, 0x1, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {{0x90dea27a, 0x6fc, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x1fa3d93f, 0xa4aef993, 0x29, sign_and_exp_bits(1, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_114) {
  // 680406507012.24340 + 680406507012.24340 = 1360813014024.48680
  s21_decimal d1 = {{0x7f553994, 0xf1ba9c, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal d2 = {{0x7f553994, 0xf1ba9c, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {{0xfeaa7328, 0x1e37538, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_115) {
  //-58729.364 + 53518187150.8049 = 53518128421.4409
  s21_decimal d1 = {{0x3802394, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal d2 = {{0xbd576a51, 0x1e6be, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x9a560689, 0x1e6be, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_116) {
  // 2.0 + 3627.68202884483 = 3629.68202884483
  s21_decimal d1 = {{0x14, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x8dde6583, 0x149ef, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {{0x1ecc3583, 0x14a1e, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_117) {
  // 318205165786980270 + 110065549645069756 = 428270715432050026
  s21_decimal d1 = {{0x906d5fae, 0x46a7de9, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xc49a3dbc, 0x1870808, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x55079d6a, 0x5f185f2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_118) {
  // 284831427901586.8704336 + 938918148085245243071089 =
  // 938918148370076670972675.8704
  s21_decimal d1 = {{0xc5b6a650, 0x684d19bf, 0x9a, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0xee089a71, 0xdad3f9fa, 0xc6d2, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x197ac730, 0x1fdc18b1, 0x1e568c84, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_119) {
  //-0.1393855 + 5268595259 = 5268595258.8606145
  s21_decimal d1 = {{0x1544bf, 0x0, 0x0, sign_and_exp_bits(1, 7)}};
  s21_decimal d2 = {{0x3a08623b, 0x1, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x40b26ac1, 0xbb2d98, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_120) {
  // 9 + 5256.1956 = 5265.1956
  s21_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3220824, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x32367b4, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_121) {
  // 480336485616 + 2603 = 480336488219
  s21_decimal d1 = {{0xd6491cf0, 0x6f, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xa2b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xd649271b, 0x6f, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_122) {
  //-207.0414943129132183915065355 + 3170378 = 3170170.9585056870867816084935
  s21_decimal d1 = {
      {0xf56ff00b, 0xf6dfd440, 0x6b09b6a, sign_and_exp_bits(1, 25)}};
  s21_decimal d2 = {{0x30604a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xcbe2f5c7, 0x2e607f5d, 0x666f0a20, sign_and_exp_bits(0, 22)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_123) {
  //-7431069059409783491368168 + -7431069059409783491368168 =
  //-14862138118819566982736336
  s21_decimal d1 = {{0x758394e8, 0xf9779ef, 0x62597, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x758394e8, 0xf9779ef, 0x62597, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xeb0729d0, 0x1f2ef3de, 0xc4b2e, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_124) {
  // 785914618678 + 357301 = 785914975979
  s21_decimal d1 = {{0xfc296336, 0xb6, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x573b5, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xfc2ed6eb, 0xb6, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_125) {
  // 85493316699321700573145 + -21896227733799229298846470 =
  // -21810734417099907598273325
  s21_decimal d1 = {{0x3145dfd9, 0x9a1baf07, 0x121a, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xb17c2b06, 0xe247ffd9, 0x121cb4, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x80364b2d, 0x482c50d2, 0x120a9a, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_126) {
  //-9 + 1.809 = -7.191
  s21_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x711, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {{0x1c17, 0x0, 0x0, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_127) {
  // 4327455195073704834375845 + -5556504 = 4327455195073704828819341
  s21_decimal d1 = {{0xa6c820a5, 0xd0f1ef44, 0x3945f, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x54c918, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xa673578d, 0xd0f1ef44, 0x3945f, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_128) {
  // 294.70284259412083 + -654499001.3630561950774251637 =
  // -654498706.6602136009565951637
  s21_decimal d1 = {{0x40b64873, 0x68b311, 0x0, sign_and_exp_bits(0, 14)}};
  s21_decimal d2 = {
      {0xdb9ad075, 0x956df976, 0x1525e38b, sign_and_exp_bits(1, 19)}};
  s21_decimal correct = {
      {0xb74e5695, 0xd331c618, 0x1525e2eb, sign_and_exp_bits(1, 19)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_129) {
  // 8015.537149903717034254814 + 7365.766765973 = 15381.303915876717034254814
  s21_decimal d1 = {
      {0x207a61de, 0x23bb6582, 0x6a15b, sign_and_exp_bits(0, 21)}};
  s21_decimal d2 = {{0xf9e95d95, 0x6b2, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal correct = {
      {0x6b5cb1de, 0x27f3b911, 0xcb91e, sign_and_exp_bits(0, 21)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_130) {
  //-8.6148 + 8.6148 = -0.0000
  s21_decimal d1 = {{0x15084, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0x15084, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_131) {
  //-4969748127944514 + -23389.758512326558 = -4969748127967903.758512326558
  s21_decimal d1 = {{0xa7ca0f42, 0x11a7f5, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8782679e, 0x5318dc, 0x0, sign_and_exp_bits(1, 12)}};
  s21_decimal correct = {
      {0xa600879e, 0xda38c107, 0x100ee119, sign_and_exp_bits(1, 12)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_132) {
  // 89442.33331747738 + 204653167817045012.1678146116 =
  // 204653167817134454.50113208898
  s21_decimal d1 = {{0x9a86eb9a, 0x1fc6bb, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {
      {0x61444a44, 0x939eb3e2, 0x69cd9f0, sign_and_exp_bits(0, 10)}};
  s21_decimal correct = {
      {0x6731d242, 0xc452cd93, 0x42208365, sign_and_exp_bits(0, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_133) {
  //-50770968388401 + -50770968388401 = -101541936776802
  s21_decimal d1 = {{0x9892331, 0x2e2d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x9892331, 0x2e2d, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x13124662, 0x5c5a, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_134) {
  // 393.68995882699 + 393.68995882699 = 787.37991765398
  s21_decimal d1 = {{0x4f03c6cb, 0x23ce, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal d2 = {{0x4f03c6cb, 0x23ce, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal correct = {{0x9e078d96, 0x479c, 0x0, sign_and_exp_bits(0, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_135) {
  //-2974.024009 + 46143767247.920862 = 46143764273.896853
  s21_decimal d1 = {{0xb1440149, 0x0, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal d2 = {{0x7691ede, 0xa3ef83, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {{0x56251d95, 0xa3ef82, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_136) {
  //-785 + -610771851903378180.181473534 = -610771851903378965.181473534
  s21_decimal d1 = {{0x311, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xb6da38fe, 0x6fb37207, 0x1f937f8, sign_and_exp_bits(1, 9)}};
  s21_decimal correct = {
      {0x7c7fa2fe, 0x6fb372be, 0x1f937f8, sign_and_exp_bits(1, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_137) {
  //-4063043679.810837066141897905 + 154.32 = -4063043525.490837066141897905
  s21_decimal d1 = {
      {0xa03794b1, 0x3a4be22f, 0xd20def7, sign_and_exp_bits(1, 18)}};
  s21_decimal d2 = {{0x3c48, 0x0, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal correct = {
      {0xf5ef94b1, 0xdcad1bce, 0xd20deee, sign_and_exp_bits(1, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_138) {
  //-50585 + 927915754915946020 = 927915754915895435
  s21_decimal d1 = {{0xc599, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x7940de24, 0xce09e76, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x7940188b, 0xce09e76, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_139) {
  //-644846371499117.315717338 + -9547807 = -644846381046924.315717338
  s21_decimal d1 = {{0xd0f178da, 0x311cbff1, 0x888d, sign_and_exp_bits(1, 9)}};
  s21_decimal d2 = {{0x91b01f, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xdd8feeda, 0x313eab9f, 0x888d, sign_and_exp_bits(1, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_140) {
  // 3517226074 + 86845329856368763 = 86845333373594837
  s21_decimal d1 = {{0xd1a49c5a, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xc7d907b, 0x134895e, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xde222cd5, 0x134895e, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_141) {
  // 12766218165671163 + 24085160983.4 = 12766242250832146.4
  s21_decimal d1 = {{0xcae3d4fb, 0x2d5ace, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x13dfe8ea, 0x38, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0xc63ab8, 0x1c58c4c, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_142) {
  // 7916991095469721059 + 4661592131.15585 = 7916991100131313190.15585
  s21_decimal d1 = {{0x8f6745e3, 0x6ddecd74, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x264e78c1, 0x1a7f8, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal correct = {
      {0x1b51f8a1, 0x1841a349, 0xa7a6, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_143) {
  //-456646012700 + -456646012700 = -913292025400
  s21_decimal d1 = {{0x52392f1c, 0x6a, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x52392f1c, 0x6a, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0xa4725e38, 0xd4, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_144) {
  //-692052900.28775113458333 + 692052900.28775113458333 = -0.00000000000000
  s21_decimal d1 = {{0x6f7b829d, 0xa05487d4, 0xea7, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0x6f7b829d, 0xa05487d4, 0xea7, sign_and_exp_bits(0, 14)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_145) {
  // 64328 + 64328 = 128656
  s21_decimal d1 = {{0xfb48, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xfb48, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x1f690, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_146) {
  // 822483604033477.038 + -42998.7109866901081748825032 =
  // 822483603990478.3270133098918
  s21_decimal d1 = {{0xebff99ae, 0xb6a0c7a, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {
      {0x3e7e63c8, 0xeed40887, 0x163ad4f, sign_and_exp_bits(1, 22)}};
  s21_decimal correct = {
      {0xc9bbe9a6, 0x23dd10f4, 0x1a936cc7, sign_and_exp_bits(0, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_147) {
  //-99661985374.4 + 714.4 = -99661984660.0
  s21_decimal d1 = {{0xb2c1fb0, 0xe8, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x1be8, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal correct = {{0xb2c03c8, 0xe8, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_148) {
  //-26167630774951860040043.8000 + -44121850800000 =
  //-26167630819073710840043.8000
  s21_decimal d1 = {
      {0xe9d682f0, 0x1147b968, 0xd8741d, sign_and_exp_bits(1, 4)}};
  s21_decimal d2 = {{0xeb3e6780, 0x2820, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x1f817af0, 0x17673f4e, 0xd8741d, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_149) {
  //-490340717566251076273 + -7664344719775 = -490340725230595796048
  s21_decimal d1 = {{0xa6898ab1, 0x94d82cb0, 0x1a, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x7e8b619f, 0x6f8, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x2514ec50, 0x94d833a9, 0x1a, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_150) {
  //-65800 + 4507 = -61293
  s21_decimal d1 = {{0x10108, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x119b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xef6d, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_151) {
  // 2515445714 + -640989.01676 = 2514804724.98324
  s21_decimal d1 = {{0x95eea7d2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xec979eac, 0xe, 0x0, sign_and_exp_bits(1, 5)}};
  s21_decimal correct = {{0x5c3b3094, 0xe4b8, 0x0, sign_and_exp_bits(0, 5)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_152) {
  // 2.092706 + -3664.124281649659902193996879 = -3662.031575649659902193996879
  s21_decimal d1 = {{0x1feea2, 0x0, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {
      {0x115a944f, 0x5231ce58, 0xbd6e47f, sign_and_exp_bits(1, 24)}};
  s21_decimal correct = {
      {0x2c12944f, 0x8061e5ed, 0xbd52959, sign_and_exp_bits(1, 24)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_153) {
  //-38 + 32693177569906556924 = 32693177569906556886
  s21_decimal d1 = {{0x26, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xb10c7ffc, 0xc5b57fc8, 0x1, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xb10c7fd6, 0xc5b57fc8, 0x1, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_154) {
  // 96492391624423 + 5565677929710000 = 5662170321334423
  s21_decimal d1 = {{0x62b9eee7, 0x57c2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x5fef41b0, 0x13c5f4, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xc2a93097, 0x141db6, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_155) {
  //-27.58386452619000 + -30000000 = -30000027.58386452619000
  s21_decimal d1 = {{0xe4a95ef8, 0x9ccbc, 0x0, sign_and_exp_bits(1, 14)}};
  s21_decimal d2 = {{0x1c9c380, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x80895ef8, 0xa166d60e, 0xa2, sign_and_exp_bits(1, 14)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_156) {
  //-7717097876278614446 + -7717097876278614446 = -15434195752557228892
  s21_decimal d1 = {{0xac8219ae, 0x6b18a3a1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xac8219ae, 0x6b18a3a1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x5904335c, 0xd6314743, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_157) {
  //-7 + 5828714454.7558678907525742 = 5828714447.7558678907525742
  s21_decimal d1 = {{0x7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xdd971a6e, 0x6ff45570, 0x3036c8, sign_and_exp_bits(0, 16)}};
  s21_decimal correct = {
      {0xcf501a6e, 0x6efba4cf, 0x3036c8, sign_and_exp_bits(0, 16)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_158) {
  // 0.8 + -788153061000457573358.0 = -788153061000457573357.2
  s21_decimal d1 = {{0x8, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0xa85474c, 0x42359ba9, 0x1ab, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {
      {0xa854744, 0x42359ba9, 0x1ab, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_159) {
  //-3106395892.45 + -6260.6145 = -3106402153.0645
  s21_decimal d1 = {{0x538ff77d, 0x48, 0x0, sign_and_exp_bits(1, 2)}};
  s21_decimal d2 = {{0x3bb4b41, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0xa7f7f815, 0x1c40, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_160) {
  // 2.200 + 4293300 = 4293302.200
  s21_decimal d1 = {{0x898, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x4182b4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xffe697b8, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_161) {
  //-46.94767277568 + -46.94767277568 = -93.89534555136
  s21_decimal d1 = {{0x15ef9600, 0x445, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {{0x15ef9600, 0x445, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal correct = {{0x2bdf2c00, 0x88a, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_162) {
  //-9369.48696904571683658447643 + -7369356289211809383577489 =
  //-7369356289211809383586858.4870
  s21_decimal d1 = {
      {0x7eb6bb1b, 0xa2732d27, 0x307069a, sign_and_exp_bits(1, 23)}};
  s21_decimal d2 = {{0xcdd7f791, 0x9adca325, 0x61885, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xc9cc3ba6, 0x4aa4f4b8, 0xee1de2f1, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_163) {
  // 4.742525973604714294 + -8567065417.981741 = -8567065413.239215026395285706
  s21_decimal d1 = {{0xfac5c736, 0x41d0d63e, 0x0, sign_and_exp_bits(0, 18)}};
  s21_decimal d2 = {{0x5b019f2d, 0x1e6fb3, 0x0, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {
      {0xfb2e08ca, 0xa499a015, 0x1bae82aa, sign_and_exp_bits(1, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_164) {
  //-3 + 7633641634077048.612 = 7633641634077045.612
  s21_decimal d1 = {{0x3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x15cb7f24, 0x69f0249f, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {
      {0x15cb736c, 0x69f0249f, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_165) {
  //-426843679665393407858795 + 8938137149505824136752025 =
  // 8511293469840430728893230
  s21_decimal d1 = {{0xb0bf986b, 0x3e0374ef, 0x5a63, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x9649eb99, 0x62c20b54, 0x764b9, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xe58a532e, 0x24be9664, 0x70a56, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_166) {
  //-7627622983946145875018544458 + 571063 = -7627622983946145875017973395
  s21_decimal d1 = {
      {0x66ea754a, 0x813690ef, 0x18a56bfe, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x8b6b7, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x66e1be93, 0x813690ef, 0x18a56bfe, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_167) {
  //-69792666455784372559855650 + -31647086030438.386312 =
  //-69792666455816019645886088.386
  s21_decimal d1 = {{0x72c2c022, 0x79d6d0f, 0x39bb2c, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x3c81ca88, 0xb7310912, 0x1, sign_and_exp_bits(1, 6)}};
  s21_decimal correct = {
      {0xb1c3c4c2, 0xbf627333, 0xe18323fd, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_168) {
  //-591777.5 + -591777.5 = -1183555.0
  s21_decimal d1 = {{0x5a4c4f, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0x5a4c4f, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal correct = {{0xb4989e, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_169) {
  // 48786801 + 4 = 48786805
  s21_decimal d1 = {{0x2e86d71, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x2e86d75, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_170) {
  // 90291359.6688212 + 90291359.6688212 = 180582719.3376424
  s21_decimal d1 = {{0xf4318754, 0x33531, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0xf4318754, 0x33531, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {{0xe8630ea8, 0x66a63, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_171) {
  // 709694976172 + -7828312.15836068 = 709687147859.84163932
  s21_decimal d1 = {{0x3d1df0ac, 0xa5, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1889fba4, 0x2c7fb, 0x0, sign_and_exp_bits(1, 8)}};
  s21_decimal correct = {
      {0xe899305c, 0xd8e38616, 0x3, sign_and_exp_bits(0, 8)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_172) {
  // 11063576153 + 79140361951585.830941 = 79151425527738.830941
  s21_decimal d1 = {{0x9370c659, 0x2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x301d081d, 0x4a4b0be4, 0x4, sign_and_exp_bits(0, 6)}};
  s21_decimal correct = {
      {0xbea8905d, 0x4a725a27, 0x4, sign_and_exp_bits(0, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_173) {
  //-36120468116 + 5299924345664967593398 = 5299924345628847125282
  s21_decimal d1 = {{0x68f29a94, 0x8, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xfcfccdb6, 0x4f39b82d, 0x11f, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x940a3322, 0x4f39b825, 0x11f, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_174) {
  //-791.64868896295 + 927993588.997646753014000 = 927992797.348957790064000
  s21_decimal d1 = {{0x1e3a627, 0x4800, 0x0, sign_and_exp_bits(1, 11)}};
  s21_decimal d2 = {{0xa48520f0, 0xa21d789a, 0xc482, sign_and_exp_bits(0, 15)}};
  s21_decimal correct = {
      {0xd7facd80, 0x9720f850, 0xc482, sign_and_exp_bits(0, 15)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_175) {
  //-38599919 + -9680.519852817098578158 = -38609599.519852817098578158
  s21_decimal d1 = {{0x24cfcef, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x77e598ee, 0xc8334c8b, 0x20c, sign_and_exp_bits(1, 18)}};
  s21_decimal correct = {
      {0x2e4198ee, 0x957b30bb, 0x1fefe6, sign_and_exp_bits(1, 18)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_176) {
  // 29 + 27 = 56
  s21_decimal d1 = {{0x1d, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1b, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x38, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_177) {
  //-83654213 + 4000000000 = 3916345787
  s21_decimal d1 = {{0x4fc7645, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0xee6b2800, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xe96eb1bb, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_178) {
  // 29418052896217882905448 + 29418052896217882905448 = 58836105792435765810896
  s21_decimal d1 = {{0xfe474b68, 0xc17eed95, 0x63a, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0xfe474b68, 0xc17eed95, 0x63a, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0xfc8e96d0, 0x82fddb2b, 0xc75, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_179) {
  // 33625152.272950230 + -10766081179233122 = -10766081145607969.727049770
  s21_decimal d1 = {{0xd8bf63d6, 0x7775e5, 0x0, sign_and_exp_bits(0, 9)}};
  s21_decimal d2 = {{0x9c4fab62, 0x263fb1, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xb36ff02a, 0x6da913dd, 0x8e7ce, sign_and_exp_bits(1, 9)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_180) {
  // 31.740603 + 1168415145339 = 1168415145370.740603
  s21_decimal d1 = {{0x1e452bb, 0x0, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal d2 = {{0xaf83d7b, 0x110, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x5a02677b, 0x10370b62, 0x0, sign_and_exp_bits(0, 6)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_181) {
  // 5873910408400000 + 56560212.21606825281570000 =
  // 5873910464960212.2160682528157
  s21_decimal d1 = {{0x5755cc80, 0x14de4a, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0x1ee9c4d0, 0x865996a7, 0x4adb5, sign_and_exp_bits(0, 17)}};
  s21_decimal correct = {
      {0x5b636d9d, 0x8c2f9084, 0xbdcbd93b, sign_and_exp_bits(0, 13)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_182) {
  // 0.4 + -3 = -2.6
  s21_decimal d1 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal d2 = {{0x3, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x1a, 0x0, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_183) {
  //-90.3194599629 + 789927498.700 = 789927408.3805400371
  s21_decimal d1 = {{0x4a97e0cd, 0xd2, 0x0, sign_and_exp_bits(1, 10)}};
  s21_decimal d2 = {{0xeb5913cc, 0xb7, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal correct = {
      {0x54ab8d33, 0x6d9fdbed, 0x0, sign_and_exp_bits(0, 10)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_184) {
  // 223963293603534101927388734 + -441426237956773 =
  // 223963293603092675689431961
  s21_decimal d1 = {
      {0xb38b663e, 0x795e7d03, 0xb94212, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x8e1ba2a5, 0x19179, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x256fc399, 0x795ceb8a, 0xb94212, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_185) {
  //-9667517000 + -75602064621405454 = -75602074288922454
  s21_decimal d1 = {{0x403a9a48, 0x2, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x5e0b850e, 0x10c97ad, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x9e461f56, 0x10c97af, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_186) {
  // 14402633196960539791824071 + 6539421110.6352212 =
  // 14402633196960546331245181.635
  s21_decimal d1 = {{0x8c9394c7, 0x4f619680, 0xbe9e0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x435c6c54, 0xe853b0, 0x0, sign_and_exp_bits(0, 7)}};
  s21_decimal correct = {
      {0xb45c7ac3, 0x1533ec17, 0x2e899436, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_187) {
  // 102797348 + -4674 = 102792674
  s21_decimal d1 = {{0x6209024, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x1242, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x6207de2, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_188) {
  // 3789.830 + 914 = 4703.830
  s21_decimal d1 = {{0x39d406, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal d2 = {{0x392, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x47c656, 0x0, 0x0, sign_and_exp_bits(0, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_189) {
  // 67011776646514880.2457804 + 99412251054554 = 67111188897569434.2457804
  s21_decimal d1 = {{0x168a60cc, 0x282b53f6, 0x8de7, sign_and_exp_bits(0, 7)}};
  s21_decimal d2 = {{0x37e911da, 0x5a6a, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {
      {0x34f909cc, 0xc63f837, 0x8e1d, sign_and_exp_bits(0, 7)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_190) {
  //-92980321907098.9 + 2085716367973140 = 1992736046066041.1
  s21_decimal d1 = {{0xae95700d, 0x34da6, 0x0, sign_and_exp_bits(1, 1)}};
  s21_decimal d2 = {{0xaf371b14, 0x768f2, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x29919ebb, 0x46cbd4, 0x0, sign_and_exp_bits(0, 1)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_191) {
  //-2093 + -1.7927 = -2094.7927
  s21_decimal d1 = {{0x82d, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x4607, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal correct = {{0x13fa3d7, 0x0, 0x0, sign_and_exp_bits(1, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_192) {
  // 899673317.60 + -303025287399000000000 = -303025287398100326682.40
  s21_decimal d1 = {{0xf27889b0, 0x14, 0x0, sign_and_exp_bits(0, 2)}};
  s21_decimal d2 = {{0x820c4600, 0x6d521564, 0x10, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0xda52ce50, 0xb4105b2d, 0x66a, sign_and_exp_bits(1, 2)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_193) {
  // 9 + -673353842428509 = -673353842428500
  s21_decimal d1 = {{0x9, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x68960a5d, 0x26469, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x68960a54, 0x26469, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_194) {
  // 9816757387286293890926 + -7608927510848 = 9816757379677366380078
  s21_decimal d1 = {{0xbf51c76e, 0x2ae04053, 0x214, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x976be140, 0x6eb, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x27e5e62e, 0x2ae03968, 0x214, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_195) {
  // 5349288851481 + 5349288851481 = 10698577702962
  s21_decimal d1 = {{0x7a763819, 0x4dd, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x7a763819, 0x4dd, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xf4ec7032, 0x9ba, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_196) {
  // 4 + -3212267 = -3212263
  s21_decimal d1 = {{0x4, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x3103eb, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x3103e7, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_197) {
  // 10186.8171 + 96247368083439 = 96247368093625.8171
  s21_decimal d1 = {{0x612628b, 0x0, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal d2 = {{0x562f67ef, 0x5789, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xa1de4a7b, 0xd5b64b6, 0x0, sign_and_exp_bits(0, 4)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_198) {
  //-14184011239495 + 97252375 = -14183913987120
  s21_decimal d1 = {{0x78f39047, 0xce6, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x5cbf417, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x73279c30, 0xce6, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_199) {
  //-53886071642 + 8440722183492 = 8386836111850
  s21_decimal d1 = {{0x8bdc335a, 0xc, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x423f5544, 0x7ad, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0xb66321ea, 0x7a0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_201) {
  // 0 + 0 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_202) {
  //-0 + 0 = -0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_203) {
  // 0 + -0 = 0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_204) {
  //-0 + -0 = -0
  s21_decimal d1 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_205) {
  // 79228162514264337593543950335 + 79228162514264337593543950335 = S21_ERROR
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_ERROR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_206) {
  //-79228162514264337593543950335 + -79228162514264337593543950335 = S21_ERROR
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_SMALL_ERR);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_207) {
  //-79228162514264337593543950335 + 79228162514264337593543950335 = -0
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(1, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_208) {
  // 79228162514264337593543950335 + -79228162514264337593543950335 = 0
  s21_decimal d1 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(0, 0)}};
  s21_decimal d2 = {
      {0xffffffff, 0xffffffff, 0xffffffff, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {{0x0, 0x0, 0x0, sign_and_exp_bits(0, 0)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_209) {
  //-33586526831355.03650000 + -30936088168399986925418607 =
  //-30936088168433573452249962.036
  s21_decimal d1 = {{0x3c4d4cd0, 0x12ab5468, 0xb6, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {
      {0xba3eb86f, 0xb33473f5, 0x1996f8, sign_and_exp_bits(1, 0)}};
  s21_decimal correct = {
      {0x2e061634, 0x55c4aa4, 0x63f5bb7c, sign_and_exp_bits(1, 3)}};
  s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, &result), S21_OK);
  ASSERT_BITS_EQ
}
END_TEST

START_TEST(s21_add_210) {
  // Segmentation fault
  s21_decimal d1 = {{0x3c4d4cd0, 0x12ab5468, 0xb6, sign_and_exp_bits(1, 8)}};
  s21_decimal d2 = {
      {0xba3eb86f, 0xb33473f5, 0x1996f8, sign_and_exp_bits(1, 0)}};
  // s21_decimal correct = {
  // {0x2e061634, 0x55c4aa4, 0x63f5bb7c, sign_and_exp_bits(1, 3)}};
  // s21_decimal result;

  ck_assert_int_eq(s21_add(d1, d2, NULL), S21_OK);
  // ASSERT_BITS_EQ
}
END_TEST

Suite *add_tests(void) {
  Suite *s1 = suite_create(PRE_TEST_HEADER "S21_ADD" POST_TEST_HEADER);
  TCase *tc1_1 = tcase_create("S21_ADD");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_add_0);
  tcase_add_test(tc1_1, s21_add_1);
  tcase_add_test(tc1_1, s21_add_2);
  tcase_add_test(tc1_1, s21_add_3);
  tcase_add_test(tc1_1, s21_add_4);
  tcase_add_test(tc1_1, s21_add_5);
  tcase_add_test(tc1_1, s21_add_6);
  tcase_add_test(tc1_1, s21_add_7);
  tcase_add_test(tc1_1, s21_add_8);
  tcase_add_test(tc1_1, s21_add_9);
  tcase_add_test(tc1_1, s21_add_10);
  tcase_add_test(tc1_1, s21_add_11);
  tcase_add_test(tc1_1, s21_add_12);
  tcase_add_test(tc1_1, s21_add_13);
  tcase_add_test(tc1_1, s21_add_14);
  tcase_add_test(tc1_1, s21_add_15);
  tcase_add_test(tc1_1, s21_add_16);
  tcase_add_test(tc1_1, s21_add_17);
  tcase_add_test(tc1_1, s21_add_18);
  tcase_add_test(tc1_1, s21_add_19);
  tcase_add_test(tc1_1, s21_add_20);
  tcase_add_test(tc1_1, s21_add_21);
  tcase_add_test(tc1_1, s21_add_22);
  tcase_add_test(tc1_1, s21_add_23);
  tcase_add_test(tc1_1, s21_add_24);
  tcase_add_test(tc1_1, s21_add_25);
  tcase_add_test(tc1_1, s21_add_26);
  tcase_add_test(tc1_1, s21_add_27);
  tcase_add_test(tc1_1, s21_add_28);
  tcase_add_test(tc1_1, s21_add_29);
  tcase_add_test(tc1_1, s21_add_30);
  tcase_add_test(tc1_1, s21_add_31);
  tcase_add_test(tc1_1, s21_add_32);
  tcase_add_test(tc1_1, s21_add_33);
  tcase_add_test(tc1_1, s21_add_34);
  tcase_add_test(tc1_1, s21_add_35);
  tcase_add_test(tc1_1, s21_add_36);
  tcase_add_test(tc1_1, s21_add_37);
  tcase_add_test(tc1_1, s21_add_38);
  tcase_add_test(tc1_1, s21_add_39);
  tcase_add_test(tc1_1, s21_add_40);
  tcase_add_test(tc1_1, s21_add_41);
  tcase_add_test(tc1_1, s21_add_42);
  tcase_add_test(tc1_1, s21_add_43);
  tcase_add_test(tc1_1, s21_add_44);
  tcase_add_test(tc1_1, s21_add_45);
  tcase_add_test(tc1_1, s21_add_46);
  tcase_add_test(tc1_1, s21_add_47);
  tcase_add_test(tc1_1, s21_add_48);
  tcase_add_test(tc1_1, s21_add_49);
  tcase_add_test(tc1_1, s21_add_50);
  tcase_add_test(tc1_1, s21_add_51);
  tcase_add_test(tc1_1, s21_add_52);
  tcase_add_test(tc1_1, s21_add_53);
  tcase_add_test(tc1_1, s21_add_54);
  tcase_add_test(tc1_1, s21_add_55);
  tcase_add_test(tc1_1, s21_add_56);
  tcase_add_test(tc1_1, s21_add_57);
  tcase_add_test(tc1_1, s21_add_58);
  tcase_add_test(tc1_1, s21_add_59);
  tcase_add_test(tc1_1, s21_add_60);
  tcase_add_test(tc1_1, s21_add_61);
  tcase_add_test(tc1_1, s21_add_62);
  tcase_add_test(tc1_1, s21_add_63);
  tcase_add_test(tc1_1, s21_add_64);
  tcase_add_test(tc1_1, s21_add_65);
  tcase_add_test(tc1_1, s21_add_66);
  tcase_add_test(tc1_1, s21_add_67);
  tcase_add_test(tc1_1, s21_add_68);
  tcase_add_test(tc1_1, s21_add_69);
  tcase_add_test(tc1_1, s21_add_70);
  tcase_add_test(tc1_1, s21_add_71);
  tcase_add_test(tc1_1, s21_add_72);
  tcase_add_test(tc1_1, s21_add_73);
  tcase_add_test(tc1_1, s21_add_74);
  tcase_add_test(tc1_1, s21_add_75);
  tcase_add_test(tc1_1, s21_add_76);
  tcase_add_test(tc1_1, s21_add_77);
  tcase_add_test(tc1_1, s21_add_78);
  tcase_add_test(tc1_1, s21_add_79);
  tcase_add_test(tc1_1, s21_add_80);
  tcase_add_test(tc1_1, s21_add_81);
  tcase_add_test(tc1_1, s21_add_82);
  tcase_add_test(tc1_1, s21_add_83);
  tcase_add_test(tc1_1, s21_add_84);
  tcase_add_test(tc1_1, s21_add_85);
  tcase_add_test(tc1_1, s21_add_86);
  tcase_add_test(tc1_1, s21_add_87);
  tcase_add_test(tc1_1, s21_add_88);
  tcase_add_test(tc1_1, s21_add_89);
  tcase_add_test(tc1_1, s21_add_90);
  tcase_add_test(tc1_1, s21_add_91);
  tcase_add_test(tc1_1, s21_add_92);
  tcase_add_test(tc1_1, s21_add_93);
  tcase_add_test(tc1_1, s21_add_94);
  tcase_add_test(tc1_1, s21_add_95);
  tcase_add_test(tc1_1, s21_add_96);
  tcase_add_test(tc1_1, s21_add_97);
  tcase_add_test(tc1_1, s21_add_98);
  tcase_add_test(tc1_1, s21_add_99);
  tcase_add_test(tc1_1, s21_add_100);
  tcase_add_test(tc1_1, s21_add_101);
  tcase_add_test(tc1_1, s21_add_102);
  tcase_add_test(tc1_1, s21_add_103);
  tcase_add_test(tc1_1, s21_add_104);
  tcase_add_test(tc1_1, s21_add_105);
  tcase_add_test(tc1_1, s21_add_106);
  tcase_add_test(tc1_1, s21_add_107);
  tcase_add_test(tc1_1, s21_add_108);
  tcase_add_test(tc1_1, s21_add_109);
  tcase_add_test(tc1_1, s21_add_110);
  tcase_add_test(tc1_1, s21_add_111);
  tcase_add_test(tc1_1, s21_add_112);
  tcase_add_test(tc1_1, s21_add_113);
  tcase_add_test(tc1_1, s21_add_114);
  tcase_add_test(tc1_1, s21_add_115);
  tcase_add_test(tc1_1, s21_add_116);
  tcase_add_test(tc1_1, s21_add_117);
  tcase_add_test(tc1_1, s21_add_118);
  tcase_add_test(tc1_1, s21_add_119);
  tcase_add_test(tc1_1, s21_add_120);
  tcase_add_test(tc1_1, s21_add_121);
  tcase_add_test(tc1_1, s21_add_122);
  tcase_add_test(tc1_1, s21_add_123);
  tcase_add_test(tc1_1, s21_add_124);
  tcase_add_test(tc1_1, s21_add_125);
  tcase_add_test(tc1_1, s21_add_126);
  tcase_add_test(tc1_1, s21_add_127);
  tcase_add_test(tc1_1, s21_add_128);
  tcase_add_test(tc1_1, s21_add_129);
  tcase_add_test(tc1_1, s21_add_130);
  tcase_add_test(tc1_1, s21_add_131);
  tcase_add_test(tc1_1, s21_add_132);
  tcase_add_test(tc1_1, s21_add_133);
  tcase_add_test(tc1_1, s21_add_134);
  tcase_add_test(tc1_1, s21_add_135);
  tcase_add_test(tc1_1, s21_add_136);
  tcase_add_test(tc1_1, s21_add_137);
  tcase_add_test(tc1_1, s21_add_138);
  tcase_add_test(tc1_1, s21_add_139);
  tcase_add_test(tc1_1, s21_add_140);
  tcase_add_test(tc1_1, s21_add_141);
  tcase_add_test(tc1_1, s21_add_142);
  tcase_add_test(tc1_1, s21_add_143);
  tcase_add_test(tc1_1, s21_add_144);
  tcase_add_test(tc1_1, s21_add_145);
  tcase_add_test(tc1_1, s21_add_146);
  tcase_add_test(tc1_1, s21_add_147);
  tcase_add_test(tc1_1, s21_add_148);
  tcase_add_test(tc1_1, s21_add_149);
  tcase_add_test(tc1_1, s21_add_150);
  tcase_add_test(tc1_1, s21_add_151);
  tcase_add_test(tc1_1, s21_add_152);
  tcase_add_test(tc1_1, s21_add_153);
  tcase_add_test(tc1_1, s21_add_154);
  tcase_add_test(tc1_1, s21_add_155);
  tcase_add_test(tc1_1, s21_add_156);
  tcase_add_test(tc1_1, s21_add_157);
  tcase_add_test(tc1_1, s21_add_158);
  tcase_add_test(tc1_1, s21_add_159);
  tcase_add_test(tc1_1, s21_add_160);
  tcase_add_test(tc1_1, s21_add_161);
  tcase_add_test(tc1_1, s21_add_162);
  tcase_add_test(tc1_1, s21_add_163);
  tcase_add_test(tc1_1, s21_add_164);
  tcase_add_test(tc1_1, s21_add_165);
  tcase_add_test(tc1_1, s21_add_166);
  tcase_add_test(tc1_1, s21_add_167);
  tcase_add_test(tc1_1, s21_add_168);
  tcase_add_test(tc1_1, s21_add_169);
  tcase_add_test(tc1_1, s21_add_170);
  tcase_add_test(tc1_1, s21_add_171);
  tcase_add_test(tc1_1, s21_add_172);
  tcase_add_test(tc1_1, s21_add_173);
  tcase_add_test(tc1_1, s21_add_174);
  tcase_add_test(tc1_1, s21_add_175);
  tcase_add_test(tc1_1, s21_add_176);
  tcase_add_test(tc1_1, s21_add_177);
  tcase_add_test(tc1_1, s21_add_178);
  tcase_add_test(tc1_1, s21_add_179);
  tcase_add_test(tc1_1, s21_add_180);
  tcase_add_test(tc1_1, s21_add_181);
  tcase_add_test(tc1_1, s21_add_182);
  tcase_add_test(tc1_1, s21_add_183);
  tcase_add_test(tc1_1, s21_add_184);
  tcase_add_test(tc1_1, s21_add_185);
  tcase_add_test(tc1_1, s21_add_186);
  tcase_add_test(tc1_1, s21_add_187);
  tcase_add_test(tc1_1, s21_add_188);
  tcase_add_test(tc1_1, s21_add_189);
  tcase_add_test(tc1_1, s21_add_190);
  tcase_add_test(tc1_1, s21_add_191);
  tcase_add_test(tc1_1, s21_add_192);
  tcase_add_test(tc1_1, s21_add_193);
  tcase_add_test(tc1_1, s21_add_194);
  tcase_add_test(tc1_1, s21_add_195);
  tcase_add_test(tc1_1, s21_add_196);
  tcase_add_test(tc1_1, s21_add_197);
  tcase_add_test(tc1_1, s21_add_198);
  tcase_add_test(tc1_1, s21_add_199);
  tcase_add_test(tc1_1, s21_add_201);
  tcase_add_test(tc1_1, s21_add_202);
  tcase_add_test(tc1_1, s21_add_203);
  tcase_add_test(tc1_1, s21_add_204);
  tcase_add_test(tc1_1, s21_add_205);
  tcase_add_test(tc1_1, s21_add_206);
  tcase_add_test(tc1_1, s21_add_207);
  tcase_add_test(tc1_1, s21_add_208);
  tcase_add_test(tc1_1, s21_add_209);
  tcase_add_test(tc1_1, s21_add_210);

  return s1;
}
