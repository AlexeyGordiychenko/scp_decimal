#ifndef S21_CONVERTING_H
#define S21_CONVERTING_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 CONVERTING OPERATIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
#endif  // S21_CONVERTING_H
