#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <parser.h>
#include <converter.h>

int main()
{
    char in_name[100];
    char out_name[100];
    printf("You have: ");
    fgets(in_name, 100, stdin);
    printf("You want: ");
    fgets(out_name, 100, stdin);
    error_check_inname(in_name);
}