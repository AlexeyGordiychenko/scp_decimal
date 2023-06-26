#include <math.h>

#include "s21_common.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error_code = OK;
  if (dst != NULL) {
    int is_int_min = 0;
    int sign = 0;

    if (src < 0) {
      if (src == (-__INT_MAX__ - 1)) {
        ++src;
        is_int_min = 1;
      }
      sign = 1;
      src = -src;
    }

    dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
    dst->bits[0] = src;

    if (is_int_min) {
      ++dst->bits[0];
    }
    if (sign == 1) {
      dst->bits[3] = set_bit(dst->bits[3], 31);
    }
  } else {
    error_code = ERROR;
  }

  return error_code;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error_code = OK;
  
  if (!isnan(src) && !isinf(src) && dst != NULL && src < pow(2, 64) && src != 0) {
    dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;

    int sign = 0;
    if (src < 0) {
      sign = 1;
      src = -src;
    }

    int reminder = 0;
    while (src < 1) {
      src *= 10;
      ++reminder;
    }

    unsigned long long num = src;
    unsigned long long next = src;
    for (int i = 0; next < pow(2, 64) && i < 40; ++i) {
      num = next;
      next = src * pow(10, i);
    }

    int exp = floor(log10(num) + 1) - floor(log10(src) + 1) + reminder;

    if (exp > 0) {
      dst->bits[3] = (exp << 16);
    }
    if (sign == 1) {
      dst->bits[3] = set_bit(dst->bits[3], 31);
    }

    for (int i = 0; i < 64; ++i) {
      if ((num & 1) == 1)
        dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
      num = num >> 1;
    }
  } else if (src == 0) {
    dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;
  } else {
    error_code = ERROR;
  }

  return error_code;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error_code = OK;

  if (dst != NULL) {
    int exp = get_decimal_exp(src);

    unsigned long long num = 0;
    for (int i = 0; i < 96; ++i) {
      if (check_bit(src.bits[i / 32], i % 32)) {
        num += pow(2, i);
      }
    }

    while (exp--) {
      num /= 10;
    }

    if (num > (unsigned)__INT_MAX__ + get_decimal_sign(src)) {
      error_code = ERROR;
    } else {
      *dst = num;
      if (get_decimal_sign(src)) {
        *dst = -(*dst);
      }
    }
  } else {
    error_code = ERROR;
  }

  return error_code;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error_code = OK;

  if (dst != NULL) {
    int exp = get_decimal_exp(src);

    *dst = 0.f;
    for (int i = 95; i >= 0; --i) {
      if (check_bit(src.bits[i / 32], i % 32)) {
        *dst += pow(2, i);
      }
    }

    *dst /= pow(10, exp);
    *dst = get_decimal_sign(src) == 0 ? *dst : -(*dst);
  } else {
    error_code = ERROR;
  }

  return error_code;
}
