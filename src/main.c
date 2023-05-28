#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "converter.h"
#include "help.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    // system("clear");
    if (argc == 2) {
        const char* help = argv[1];
        if ((strcmp(help, "-h") == 0) || (strcmp(help, "-help") == 0)) {
            pr_help();
        }
    }
    printf("Enter the number and unit of measurement as shown in the "
           "example\nYou have: <number> space <string>\nYou want: "
           "<string>\n\n");
    while (1) {
        char* in_name = malloc(100 * sizeof(char));
        char* out_name = malloc(100 * sizeof(char));
        printf("You have: ");
        fgets(in_name, 100, stdin);
        printf("You want: ");
        fgets(out_name, 100, stdin);
        if (error_check_inname(in_name) == 1) {
            if (error_check_outname(out_name) == 1) {
                double unit = str_to_double(in_name);
                char* from = str_in_name(in_name);
                char* to = str_out_name(out_name);

                unit = convert(from, unit, to);
                printf("%lf\n", unit);
                free(from);
                free(to);
            }
        }
        printf("would you like to continue?[y/n]\n");
        char temp[2];
        fgets(temp, 2, stdin);
        fflush(stdin);
        if (*temp != 'y') {
            free(in_name);
            free(out_name);
            break;
        }
        *temp = getchar();
        free(in_name);
        free(out_name);
        system("clear");
    }
}
