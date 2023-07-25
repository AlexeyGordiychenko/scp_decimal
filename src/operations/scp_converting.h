#ifndef SCP_CONVERTING_H
#define SCP_CONVERTING_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 CONVERTING OPERATIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int scp_from_int_to_decimal(int src, scp_decimal *dst);
int scp_from_float_to_decimal(float src, scp_decimal *dst);
int scp_from_decimal_to_int(scp_decimal src, int *dst);
int scp_from_decimal_to_float(scp_decimal src, float *dst);
#endif  // SCP_CONVERTING_H
