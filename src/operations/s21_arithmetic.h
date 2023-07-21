#ifndef S21_ARITHMETIC_H
#define S21_ARITHMETIC_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 ARITHMETIC OPERATIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int s21_add(s21_decimal, s21_decimal, s21_decimal *result);
int s21_sub(s21_decimal, s21_decimal, s21_decimal *result);
int s21_mul(s21_decimal, s21_decimal, s21_decimal *result);
int s21_div(s21_decimal, s21_decimal, s21_decimal *result);
#endif  // S21_ARITHMETIC_H
