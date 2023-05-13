#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "converter.h"

double str_to_double(char* arr)
{
    double doub_num;
    char doub_char[30];
    int space_start;
    int length = strlen(arr);
    int ending_symbol = length;
    int start_num_index = 0;
    arr[length] = '\0';
    for (int i = 0; i < length; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            start_num_index = i;
            break;
        }
    }
    int start = start_num_index;
    for (; start < ending_symbol; start++) {
        if (arr[start] == ' ') {
            space_start = start;
            break;
        }
    }
    int count = 0;
    for (int j = start_num_index; j < space_start; j++) {
        if ((arr[j] >= '0' && arr[j] <= '9') || arr[j] == '.') {
            doub_char[count] = arr[j];
            count++;
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
    for (int i = space_end; i > 0; i--) {
        arr[i] = tolower(arr[i]);
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            if (arr[i - 1] == ' ') {
                space_end = i - 1;
                break;
            }
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

int error_check_inname(char* arr)
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
    int count = 0;
    for (int j = 0; j < space_end; j++) {
        if (arr[j] == '.') {
            count++;
        }
        if (count <= 1) {
            continue;
        } else {
            printf("use a single character '.' to store a floating point "
                   "number\n");
            return 0;
        }
    }

    for (int j = 0; j < space_start; j++) {
        if ((arr[j] >= '0' && arr[j] <= '9') || arr[j] == '.') {
            continue;
        } else {
            printf("invalid number input\n");
            return 0;
        }
    }
    for (int z = (space_end + 1); z < (ending_symbol - 1); z++) {
        arr[z] = tolower(arr[z]);
        if (arr[z] >= 97 && arr[z] <= 122) {
            continue;
        } else {
            printf("invalid string input\n");
            return 0;
        }
    }
    return 1;
}
int error_check_outname(char* arr)
{
    for (int i = 0; i < (strlen(arr) - 1); i++) {
        arr[i] = tolower(arr[i]);
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            continue;
        } else {
            printf("invalid string output\n");
            return 0;
        }
    }
    return 1;
}
