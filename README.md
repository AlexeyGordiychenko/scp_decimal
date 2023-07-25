# scp_decimal (Group project, 4 members)

## My part of the project
My part was to make
   + Makefile
   + tests (generated with C#) for all the functions, except converting
   + scp_div, scp_truncate functions
   + comparison functions

So for my code you can check files
+ [Makefile](src/Makefile)
+ [tests](src/tests)
+ [scp_div](src/operations/scp_arithmetic.c?plain=1#L102)
+ [scp_truncate](src/operations/scp_rounding.c?plain=1#L106)
+ [comparison functions](src/operations/scp_comparison.c)

## Score:
The final score is 97% (max is 100%)

Functional tests failed for the function `scp_from_float_to_decimal`.

## Task
Development of Decimal type (96-bit).

### Example:

```c
typedef struct 
{
    int bits[4];
} scp_decimal;
```

### Arithmetic Functions
```c
int scp_add(scp_decimal value_1, scp_decimal value_2, scp_decimal *result)
int scp_sub(scp_decimal value_1, scp_decimal value_2, scp_decimal *result)
int scp_mul(scp_decimal value_1, scp_decimal value_2, scp_decimal *result)
int scp_div(scp_decimal value_1, scp_decimal value_2, scp_decimal *result)
```

The functions return the error code:
- 0 - OK
- 1 - the number is too large or equal to infinity
- 2 - the number is too small or equal to negative infinity
- 3 - division by 0

### Comparison Functions

```c
int scp_is_less(scp_decimal, scp_decimal)             
int scp_is_less_or_equal(scp_decimal, scp_decimal)    
int scp_is_greater(scp_decimal, scp_decimal)          
int scp_is_greater_or_equal(scp_decimal, scp_decimal) 
int scp_is_equal(scp_decimal, scp_decimal)            
int scp_is_not_equal(scp_decimal, scp_decimal)        
```

Return value:
- 0 - FALSE
- 1 - TRUE

### Convertors and parsers

```c
int scp_from_int_to_decimal(int src, scp_decimal *dst)     
int scp_from_float_to_decimal(float src, scp_decimal *dst) 
int scp_from_decimal_to_int(scp_decimal src, int *dst)     
int scp_from_decimal_to_float(scp_decimal src, float *dst) 
```

Return value - code error:
- 0 - OK
- 1 - convertation error

### Another functions

```c
int scp_floor(scp_decimal value, scp_decimal *result)    
int scp_round(scp_decimal value, scp_decimal *result)    
int scp_truncate(scp_decimal value, scp_decimal *result) 
int scp_negate(scp_decimal value, scp_decimal *result)   
```

Return value - code error:
- 0 - OK
- 1 - calculation error