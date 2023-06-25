#include "s21_common.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_normalization(&value_1,&value_2);
  set_same_exp(value_1,result);
  add_mantis(value_1,value_2,result);
  return OK;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {

  decimal_normalization(&value_1,&value_2);
  sub_mantis(value_1,value_2,result);
  set_same_exp(value_1,result);
  return OK;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return OK;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  return OK;
}
