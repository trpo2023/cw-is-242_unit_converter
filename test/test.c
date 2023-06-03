#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "converter.h"
#include "ctest.h"
#include "parser.h"
#include "help.h"

CTEST(INPUT_CHECK, DOUBLE_NUMBER)
{
    char arr[] = "23 mms";
    int expec = 23;
    int real = str_to_double(arr);
    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, STR_IN_NAME)
{
    char arr[] = "23 mes";
    char temp2[] = "mes";
    char* temp = str_in_name(arr);
    int real = strcmp(temp,temp2);
    int expec = 0;
    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, STR_OUT_NAME)
{
    char arr[] = "dm^3";
    char* temp = str_out_name(arr);
    int real = strcmp(temp,arr);
    int expec = 0;
    ASSERT_EQUAL(expec, real);
}

CTEST(ERORR_CHECK, STR_IN_NAME)
{
    char arr[] = "ks 23";
    printf("\n");
    int real = error_check_inname(arr);
    int expec = 0;
    ASSERT_EQUAL(expec, real);
}

CTEST(ERORR_CHECK_2, STR_IN_NAME)
{
    char arr[] = "23 21893219";
    printf("\n");
    int real = error_check_inname(arr);
    int expec = 0;
    ASSERT_EQUAL(expec, real);
}

CTEST(ERORR_CHECK_3, STR_IN_NAME)
{
    char arr[] = "23.23.23 meters";
    printf("\n");
    int real = error_check_inname(arr);
    int expec = 0;
    ASSERT_EQUAL(expec, real);
}

CTEST(ERORR_CHECK, STR_OUT_NAME)
{
    char arr[] = "ms239slkd923485";
    printf("\n");
    int real = error_check_outname(arr);
    int expec = 0;
    ASSERT_EQUAL(expec, real);
}