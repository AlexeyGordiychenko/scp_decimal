#include "s21_decimal_tests.h"

unsigned int sign_and_exp_bits(int sign, int exp) {
  return (sign << S21_SIGN_SHIFT) | (exp << S21_EXP_SHIFT);
}

int main(void) {
  int failed = 0;
  Suite *decimal_tests[] = {
      comparison_tests(), converting_tests(), truncate_tests(), add_tests(),
      sub_tests(),        div_tests(),        floor_tests(),    NULL};

  for (int i = 0; decimal_tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(decimal_tests[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
