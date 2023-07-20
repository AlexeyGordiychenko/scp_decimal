#include "s21_common.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error_code = S21_OK;
  if (dst == NULL) {
    error_code = S21_ERROR;
  } else {
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
  }

  return error_code;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error_code = S21_OK;

  if (isnan(src) || isinf(src) || dst == NULL) {
    error_code = S21_ERROR;
  } else if (src > 0 && src < 1e-28) {
    error_code = S21_ERROR;
  } else if (src > powf(2, 96) - 1 || src < -(powf(2, 96) - 1)) {
    error_code = S21_ERROR;
  } else {
    if (src == 0) {
      dst->bits[3] = dst->bits[2] = dst->bits[1] = dst->bits[0] = 0;
    } else {
      double new_src = conv_round(src);
      convert_to_decimal(new_src, dst);
    }
  }
  return error_code;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error_code = S21_OK;

  if (dst == NULL) {
    error_code = S21_ERROR;
  } else {
    int exp = get_decimal_exp(src);

    unsigned long long num = 0;
    for (int i = 0; i < 96; ++i) {
      if (check_bit(src.bits[i / 32], i % 32)) {
        num += (unsigned long long)pow(2, i);
        if (num > 10 && exp) {
          num /= 10;
          exp--;
        }
      }
    }

    while (exp) {
      num /= 10;
      exp--;
    }

    if (num > ((unsigned)__INT_MAX__ + get_decimal_sign(src))) {
      error_code = S21_ERROR;
    } else {
      *dst = num;
      if (get_decimal_sign(src)) {
        *dst = -(*dst);
      }
    }
  }

  return error_code;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error_code = S21_OK;

  if (dst == NULL) {
    error_code = S21_ERROR;
  } else {
    int exp = get_decimal_exp(src);

    double tmp = ((double)(unsigned int)src.bits[0]);
    tmp += ((double)(unsigned int)src.bits[1]) * pow(2, 32);
    tmp += ((double)(unsigned int)src.bits[2]) * pow(2, 64);

    tmp /= pow(10, exp);

    if (get_decimal_sign(src))
      *dst = -tmp;
    else
      *dst = tmp;
    *dst = (float)conv_round(*dst);
  }

  return error_code;
}
