#ifndef SCP_ARITHMETIC_H
#define SCP_ARITHMETIC_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 ARITHMETIC OPERATIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int scp_add(scp_decimal, scp_decimal, scp_decimal *result);
int scp_sub(scp_decimal, scp_decimal, scp_decimal *result);
int scp_mul(scp_decimal, scp_decimal, scp_decimal *result);
int scp_div(scp_decimal, scp_decimal, scp_decimal *result);
#endif  // SCP_ARITHMETIC_H
