#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "parser.h"
#include "converter.h"
#include "constants.h"

int main()
{
    char in_name[100];
    char out_name[100];
    printf("You have: ");
    fgets(in_name, 100, stdin);
    printf("You want: ");
    fgets(out_name, 100, stdin);
    error_check_inname(in_name);


    double unit = str_to_double(in_name);
    printf("%lf\n", unit);
    char *from = str_in_name(in_name);
    char *to = str_out_name(out_name);

    unit = get_result(unit, from, to);

    printf("%g\n", unit);
}