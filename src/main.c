#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "converter.h"
#include "parser.h"

int main()
{
    char in_name[100];
    char out_name[100];
    printf("You have: ");
    fgets(in_name, 100, stdin);
    printf("You want: ");
    fgets(out_name, 100, stdin);
    if (error_check_inname(in_name) == 1) {
        if (error_check_outname(out_name) == 1)
        {
            double unit = str_to_double(in_name);
            char* from = str_in_name(in_name);
            char* to = str_out_name(out_name);

            unit = get_result(unit, from, to);
            printf("%lf\n", unit);
        }
    }
}
