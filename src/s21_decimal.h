#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 SUB-LIBRARIES
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include "operations/s21_arithmetic.h"
#include "operations/s21_comparison.h"
#include "operations/s21_converting.h"
#include "operations/s21_rounding.h"
#endif
