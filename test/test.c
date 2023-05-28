#include <ctest.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/converter.h"
#include "ctest.h"
#include "src/parser.h"
#include "src/help.h"

CTEST(INPUT_CHECK, DOUBLE_NUMBER)
{
    char arr[] = "23";
    int expec = 23;
    int real = str_to_double(arr);
    ASSERT_EQUAL(expec, real);
}
CTEST(INPUT_CHECK, STR_IN_NAME)
{
    char arr[] = "23 mm^3";
    char temp2[] = "mm^3";
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