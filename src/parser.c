#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "converter.h"

double str_to_double(char* arr)
{
    double doub_num;
    char doub_char[30];
    int start = 0;
    int space_start;
    int length = strlen(arr);
    int ending_symbol = length;
    arr[length] = '\0';
    for (; start < ending_symbol; start++) {
        if (arr[start] == ' ') {
            space_start = start;
            break;
        }
    }
    for (int j = 0; j < space_start; j++) {
        if ((arr[j] >= '0' && arr[j] <= '9') || arr[j] == '.') {
            doub_char[j] = arr[j];
        }
    }
    doub_num = atof(doub_char);
    return doub_num;
}

char* str_in_name(char* arr)
{
    int count = 0;
    char* str_in = malloc(sizeof(char) * 100);
    int length = strlen(arr);
    int space_end;
    for (int start = 0; start < length; start++) {
        if (arr[start] == ' ') {
            space_end = start;
        }
    }
    for (int z = (space_end + 1); z < (length - 1); z++) {
        arr[z] = tolower(arr[z]);
        if (arr[z] >= 97 && arr[z] <= 122) {
            str_in[count] = arr[z];
            count++;
        }
    }
    return str_in;
}

char* str_out_name(char* arr)
{
    int count = 0;
    char* str_out = malloc(sizeof(char) * 100);
    for (int i = 0; i < strlen(arr); i++) {
        arr[i] = tolower(arr[i]);
        if (arr[i] >= 97 && arr[i] <= 122) {
            str_out[count] = arr[i];
            count++;
        }
    }
    return str_out;
}

void error_check_inname(char* arr)
{
    int start = 0;
    int ending_symbol;
    int space_start;
    int space_end;
    int length = strlen(arr);
    arr[length] = '\0';
    for (int i = 0; i <= length; i++) {
        if (arr[i] == '\0')
            ending_symbol = i;
    }
    for (; start < ending_symbol; start++) {
        if (arr[start] == ' ') {
            space_start = start;
            break;
        }
    }
    for (; start < ending_symbol; start++) {
        if (arr[start] == ' ') {
            space_end = start;
        }
    }
    for (int z = (space_end + 1); z < (ending_symbol - 1); z++) {
        arr[z] = tolower(arr[z]);
        if (arr[z] >= 97 && arr[z] <= 122) {
            continue;
        } else {
            printf("invalid string input\n");
            break;
        }
    }
    for (int j = 0; j < space_start; j++) {
        if ((arr[j] >= '0' && arr[j] <= '9') || arr[j] == '.') {
            continue;
        } else {
            printf("invalid number input\n");
            break;
        }
    }
}

void parser(char* from_unit_measure, char* to_unit_measure)
{
    Dictionary length[]
            = {{"meters", 1.},
               {"cantimeters", 0.01},
               {"milimeters", 0.001},
               {"kilometers", 1000.0},
               {"feet", 0.3048},
               {"inches", 0.254},
               {"yards", 0.9144},
               {"miles", 1609.34}};
}