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
  if (isnan(src) || isinf(src) || dst == NULL || (0 < src && src < 1e-28) ||
      (powf(2, 96) - 1 < src || src < -(powf(2, 96) - 1))) {
    error_code = ERROR;
  }

  if (error_code == OK && src == 0) {
    dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;
  } else if (error_code == OK && src < powf(2, 32) && src > -powf(2, 32) - 1) {
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

    unsigned long num = src;
    unsigned long next = src;
    for (int i = 0; next < powf(2, 32) && i < 35; ++i) {
      num = next;
      next = src * powf(10, i);
    }

    int exp = floor(log10(num) + 1) - floor(log10(src) + 1) + reminder;

    if (exp > 0) {
      dst->bits[3] = (exp << 16);
    }
    if (sign == 1) {
      dst->bits[3] = set_bit(dst->bits[3], 31);
    }

    for (int i = 0; i < 32; ++i) {
      if ((num & 1) == 1)
        dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
      num = num >> 1;
    }
  } else if (error_code == OK && src < powf(2, 64) && src > -powf(2, 64) - 1) {
    dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;

    int sign = 0;
    if (src < 0) {
      sign = 1;
      src = -src;
    }

    unsigned long long num = src;
    unsigned long long next = src;
    for (int i = 0; next < powf(2, 64) && i < 35; ++i) {
      num = next;
      next = src * powf(10, i);
    }

    int exp = floorf(log10(num) + 1) - floorf(log10(src) + 1);

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

  } else if (error_code == OK &&
             (src >= powf(2, 64) || src <= -powf(2, 64) - 1)) {
    dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;

    int sign = 0;
    if (src < 0) {
      sign = 1;
      src = -src;
    }

    float scaledValue = src;

    for (int i = 0; i < 96; ++i) {
      if (fmodf(floorf(scaledValue), 2) == 1)
        dst->bits[i / 32] = set_bit(dst->bits[i / 32], i % 32);
      scaledValue /= 2;
    }

    if (sign == 1) {
      dst->bits[3] = set_bit(dst->bits[3], 31);
    }
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

    if (num > ((unsigned)__INT_MAX__ + get_decimal_sign(src))) {
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

    *dst =  ((float)(unsigned int) src.bits[0]);
    *dst += ((float)(unsigned int) src.bits[1]) * powf(2.f, 32.f);
    *dst += ((float)(unsigned int) src.bits[2]) * powf(2.f, 64.f);

    if (*dst != 0)
      *dst = roundf(*dst * powf(10, exp) / pow(10, exp));
    *dst /= powf(10, exp);
    *dst = get_decimal_sign(src) == 0 ? *dst : -(*dst);
  } else {
    error_code = ERROR;
  }

  return error_code;
}
