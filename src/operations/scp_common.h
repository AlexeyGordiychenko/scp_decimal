#ifndef SCP_COMMON_H
#define SCP_COMMON_H

#include <math.h>
#include <stdbool.h>

#include "../scp_decimal.h"

typedef struct {
  uint64_t bits[7];
} scp_big_decimal;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                      CONSTANTS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define SCP_MAX_EXP 28
#define SCP_SIGN_SHIFT 31
#define SCP_EXP_SHIFT 16
#define SCP_MAX4BITS 0xffffffff

enum comparison_enum { SCP_EQUAL = 1, SCP_LESS, SCP_LESS_OR_EQUAL };
enum error_enum {
  SCP_OK,
  SCP_ERROR,
  SCP_HUGE_ERR = 1,
  SCP_SMALL_ERR,
  SCP_DIV_ZERO_ERR
};

static const scp_decimal SCP_D_ONE = {{1, 0, 0, 0}};
static const scp_big_decimal SCP_D_ONE_BIG = {{1, 0, 0, 0, 0, 0, 0}};
static const scp_decimal SCP_D_ZERO = {{0, 0, 0, 0}};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                   COMMON FUNCTIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int check_bit(unsigned int numb, int pos);
unsigned int set_bit(unsigned int numb, int pos);
int get_decimal_sign(scp_decimal d);
int get_decimal_sign_big(scp_big_decimal d);
int get_decimal_exp(scp_decimal d);
int get_decimal_exp_big(scp_big_decimal d);
void set_decimal_sign(scp_decimal* d, int sign);
void set_decimal_exp(scp_decimal* d, int exp);
void set_decimal_exp_big(scp_big_decimal* d, int exp);
int decimal_is_zero(scp_decimal d, bool use_all_bits);
int mantissa_is_equal(scp_decimal d1, scp_decimal d2, bool use_all_bits);
int mantissa_is_less(scp_decimal d1, scp_decimal d2, bool use_all_bits);
int increase_exp(scp_decimal* d);
int decrease_exp(scp_decimal* d, int n, bool has_reminder, bool with_round);
int decrease_exp_big(scp_big_decimal* d, int n, int reminder, bool with_round);
void decimal_normalization(scp_decimal* d1, scp_decimal* d2);
int decimal_comparison(scp_decimal value_1, scp_decimal value_2, int mode);
int sum_same_sign(scp_decimal value_1, scp_decimal value_2,
                  scp_decimal* result);
int sum_same_sign_big(scp_big_decimal value_1, scp_big_decimal value_2,
                      scp_big_decimal* result);
int sub_pos(scp_decimal value_1, scp_decimal value_2, scp_decimal* result);
scp_decimal scp_decimal_fabs(scp_decimal value);
void set_same_exp(scp_decimal value, scp_decimal* result);
int sub_mantis(scp_decimal value1, scp_decimal value2, scp_decimal* result);
int add_mantis(scp_decimal value1, scp_decimal value2, scp_decimal* result);
int divide_mantissa_by_10(scp_decimal* d);
int divide_mantissa_by_10_big(scp_big_decimal* d);
bool multiply_mantissa_by_10(scp_decimal* d, bool use_all_bits);
bool subtract_bits(scp_decimal* minuend, scp_decimal subtrahend,
                   bool use_all_bits);
bool add_bits(scp_decimal* accumulator, scp_decimal addend);
bool add_bits_big(scp_big_decimal* accumulator, scp_big_decimal addend);
bool left_shift_bits(scp_decimal* d, bool use_all_bits);
bool left_shift_bits_big(scp_big_decimal* d);
void right_shift_bits(scp_decimal* d, bool use_all_bits);
void set_bit96(scp_decimal* d, int bit_position);
void set_bit192(scp_big_decimal* d, int bit_position);
void set_zero_bit192(scp_big_decimal* d, int bit_position);
int get_bit192(scp_big_decimal d, int bit_position);

void div_mantissas(scp_decimal value_1, scp_decimal value_2,
                   scp_decimal* quotient, scp_decimal* remainder);
double conv_round(float src);
void convert_to_decimal(double src, scp_decimal* dst);
int truncate_trailing_zeros(scp_decimal* d, int from_exp, int to_exp);
void bank_rounding(scp_decimal* d, int quotient, bool has_reminder);
void bank_rounding_big(scp_big_decimal* d, int quotient, bool has_reminder);
void from_big_to_decimal_with_rounding(scp_big_decimal* mul_res);
scp_big_decimal bits_mult(scp_big_decimal* value_1_big,
                          scp_big_decimal* value_2_big, int* flag);
int get_div_result(scp_decimal value_1, scp_decimal value_2,
                   scp_decimal* result, int result_sign, int exp1, int exp2);
#endif  // SCP_COMMON_H
