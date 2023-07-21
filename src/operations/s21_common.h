#ifndef S21_COMMON_H
#define S21_COMMON_H

#include <math.h>
#include <stdbool.h>

#include "../s21_decimal.h"

typedef struct {
  uint64_t bits[7];
} s21_big_decimal;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                      CONSTANTS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define S21_MAX_EXP 28
#define S21_SIGN_SHIFT 31
#define S21_EXP_SHIFT 16
#define S21_MAX4BITS 0xffffffff

enum comparison_enum { S21_EQUAL = 1, S21_LESS, S21_LESS_OR_EQUAL };
enum error_enum {
  S21_OK,
  S21_ERROR,
  S21_HUGE_ERR = 1,
  S21_SMALL_ERR,
  S21_DIV_ZERO_ERR
};

static const s21_decimal S21_D_ONE = {{1, 0, 0, 0}};
static const s21_big_decimal S21_D_ONE_BIG = {{1, 0, 0, 0, 0, 0, 0}};
static const s21_decimal S21_D_ZERO = {{0, 0, 0, 0}};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                   COMMON FUNCTIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int check_bit(unsigned int numb, int pos);
unsigned int set_bit(unsigned int numb, int pos);
int get_decimal_sign(s21_decimal d);
int get_decimal_sign_big(s21_big_decimal d);
int get_decimal_exp(s21_decimal d);
int get_decimal_exp_big(s21_big_decimal d);
void set_decimal_sign(s21_decimal* d, int sign);
void set_decimal_exp(s21_decimal* d, int exp);
void set_decimal_exp_big(s21_big_decimal* d, int exp);
int decimal_is_zero(s21_decimal d, bool use_all_bits);
int mantissa_is_equal(s21_decimal d1, s21_decimal d2, bool use_all_bits);
int mantissa_is_less(s21_decimal d1, s21_decimal d2, bool use_all_bits);
int increase_exp(s21_decimal* d);
int decrease_exp(s21_decimal* d, int n, bool has_reminder, bool with_round);
int decrease_exp_big(s21_big_decimal* d, int n, int reminder, bool with_round);
void decimal_normalization(s21_decimal* d1, s21_decimal* d2);
int decimal_comparison(s21_decimal value_1, s21_decimal value_2, int mode);
int sum_same_sign(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal* result);
int sum_same_sign_big(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal* result);
int sub_pos(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
s21_decimal s21_decimal_fabs(s21_decimal value);
void set_same_exp(s21_decimal value, s21_decimal* result);
int sub_mantis(s21_decimal value1, s21_decimal value2, s21_decimal* result);
int add_mantis(s21_decimal value1, s21_decimal value2, s21_decimal* result);
int divide_mantissa_by_10(s21_decimal* d);
int divide_mantissa_by_10_big(s21_big_decimal* d);
bool multiply_mantissa_by_10(s21_decimal* d, bool use_all_bits);
bool subtract_bits(s21_decimal* minuend, s21_decimal subtrahend,
                   bool use_all_bits);
bool add_bits(s21_decimal* accumulator, s21_decimal addend);
bool add_bits_big(s21_big_decimal* accumulator, s21_big_decimal addend);
bool left_shift_bits(s21_decimal* d, bool use_all_bits);
bool left_shift_bits_big(s21_big_decimal* d);
void right_shift_bits(s21_decimal* d, bool use_all_bits);
void set_bit96(s21_decimal* d, int bit_position);
void set_bit192(s21_big_decimal* d, int bit_position);
void set_zero_bit192(s21_big_decimal* d, int bit_position);
int get_bit192(s21_big_decimal d, int bit_position);

void div_mantissas(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal* quotient, s21_decimal* remainder);
double conv_round(float src);
void convert_to_decimal(double src, s21_decimal* dst);
int truncate_trailing_zeros(s21_decimal* d, int from_exp, int to_exp);
void bank_rounding(s21_decimal* d, int quotient, bool has_reminder);
void bank_rounding_big(s21_big_decimal* d, int quotient, bool has_reminder);
void from_big_to_decimal_with_rounding(s21_big_decimal* mul_res);
s21_big_decimal bits_mult(s21_big_decimal* value_1_big,
                          s21_big_decimal* value_2_big, int* flag);
int get_div_result(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal* result, int result_sign, int exp1, int exp2);
#endif  // S21_COMMON_H
