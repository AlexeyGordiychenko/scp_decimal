#ifndef SCP_ROUNDING_H
#define SCP_ROUNDING_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 ARROUNDING OPERATIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int scp_floor(scp_decimal value, scp_decimal *result);
int scp_round(scp_decimal value, scp_decimal *result);
int scp_truncate(scp_decimal value, scp_decimal *result);
int scp_negate(scp_decimal value, scp_decimal *result);
#endif  // SCP_ROUNDING_H
