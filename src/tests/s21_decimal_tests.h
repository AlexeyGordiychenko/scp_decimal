#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>

#include "../s21_decimal.h"

Suite *comparison_tests(void);
Suite *truncate_tests(void);
Suite *add_tests(void);
Suite *sub_tests(void);

#endif  // S21_DECIMAL_TESTS_H
