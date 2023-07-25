#ifndef SCP_DECIMAL
#define SCP_DECIMAL

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
} scp_decimal;

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 SUB-LIBRARIES
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include "operations/scp_arithmetic.h"
#include "operations/scp_comparison.h"
#include "operations/scp_converting.h"
#include "operations/scp_rounding.h"
#endif
