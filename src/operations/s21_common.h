#ifndef S21_COMMON_H
#define S21_COMMON_H

#include <stdbool.h>

#include "../s21_decimal.h"

#define MAX_EXP 28
#define EQUAL 1
#define LESS 2
#define LESS_OR_EQUAL 3
#define OK 0
#define ERROR 1
#define HUGE_ERR 1
#define SMALL_ERR 2
#define DIV_ZERO_ERR 3
#define TRUE 1
#define FALSE 0

int check_bit(unsigned int numb, int pos);
void print_binary(unsigned int num);
unsigned int set_bit(unsigned int numb, int pos);
void print_full_binary(unsigned int num);
void print_decimal_bits(s21_decimal obj);
int get_decimal_sign(s21_decimal d);
int get_decimal_exp(s21_decimal d);
void set_decimal_exp(s21_decimal* d, int exp);
int decimal_is_zero(s21_decimal d);
int mantissa_is_equal(s21_decimal d1, s21_decimal d2);
int mantissa_is_less(s21_decimal d1, s21_decimal d2);
int increase_exp(s21_decimal* d);
int divide_by_10(s21_decimal* d, int with_round);
int decrease_exp(s21_decimal* d, bool with_round);
void decimal_normalization(s21_decimal* d1, s21_decimal* d2);
int decimal_comparison(s21_decimal value_1, s21_decimal value_2, int mode);
int sum_same_sign(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal* result);
int sub_pos(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
s21_decimal s21_decimal_fabs(s21_decimal value);
void set_same_exp(s21_decimal value, s21_decimal* result);
void sub_mantis(s21_decimal value1, s21_decimal value2, s21_decimal* result);
void add_mantis(s21_decimal value1, s21_decimal value2, s21_decimal* result);
void divide_mantissa_by_10(s21_decimal* d, bool with_round);
bool multiply_mantissa_by_10(s21_decimal* d);
#endif
