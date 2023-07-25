#ifndef SCP_COMPARISON_H
#define SCP_COMPARISON_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                 COMPARATION OPERATIONS
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int scp_is_less(scp_decimal, scp_decimal);
int scp_is_less_or_equal(scp_decimal, scp_decimal);
int scp_is_greater(scp_decimal, scp_decimal);
int scp_is_greater_or_equal(scp_decimal, scp_decimal);
int scp_is_equal(scp_decimal, scp_decimal);
int scp_is_not_equal(scp_decimal, scp_decimal);
#endif  // SCP_CONVERTING_H
