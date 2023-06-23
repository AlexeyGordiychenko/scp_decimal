#include "s21_common.h"

int s21_floor(s21_decimal value, s21_decimal *result) { return OK; }

int s21_round(s21_decimal value, s21_decimal *result) { return OK; }

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int exp = get_decimal_exp(value);
  while (exp--) {
    decrease_exp(&value, 0);
  }
  set_decimal_exp(&value, 0);
  *result = value;

  return OK;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
    *result = value;
    unsigned int mask = 1 << 31;
    if (get_bit(value.bits[3], 31) == 0) {
        result->bits[3] |= mask;
    } else {
        result->bits[3] &= ~mask;
    }
    return 0;
}
