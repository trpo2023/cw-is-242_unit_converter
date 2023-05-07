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
    for (int z = (space_end + 1); z < (ending_symbol - 1); z++) {
        arr[z] = tolower(arr[z]);
        if (arr[z] >= 97 && arr[z] <= 122) {
            continue;
        } else {
            printf("invalid string input\n");
            return 0;
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
    return 1;
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

    Dictionary mass[]
            = {{"kilogram", 1.},
               {"pound", 0.453592909},
               {"gram", 0.001},
               {"miligram", 0.000001},
               {"ton", 1000.},
               {"ounce", 0.028349493}};

    Dictionary time[]
            = {{"seconds", 1.},
               {"minutes", 60.},
               {"hour", 3600.},
               {"day", 86400.},
               {"miliseconds", 0.001},
               {"microseconds", 0.000001},
               {"nanoseconds", 0.000000001}};

    Dictionary temperature[]
            = {{"kelvin", 1.}, {"celsius", -273.15}, {"fahr", -273.15}};

    Dictionary pressure[]
            = {{"pascal", 1.},
               {"bar", 0.00001},
               {"atmospheres", 0.000009869},
               {"torr", 0.007500638}};

    Dictionary energy[]
            = {{"joule", 1.},
               {"kilojoule", 1000.},
               {"gram/calorie", 0.239005736},
               {"kilocalorie", 0.000239005},
               {"watt/hour", 0.000277778},
               {"kilowatt/hour", 2.77778e-7},
               {"electron/volt", 1.6022e-19}};

    Dictionary volume[]
            = {{"m^3", 1.},
               {"dm^3", 1e+3},
               {"cm^3", 1e+6},
               {"liter", 1e+3},
               {"mm^3", 1e+9},
               {"km^3", 1e-9},
               {"inches^3", 61023.7},
               {"feet^3"}, 35.3147};

    Dictionary area[]
            = {{"m^2", 1.},
               {"km^2", 1e+6},
               {"miles^2", 2.59e+6},
               {"yards^2", 0.836127},
               {"feet^2", 0.092903},
               {"inces^2", 0.00064516},
               {"hectare", 1e-4},
               {"arc", 0.000247105}};

    Dictionary velocity[]
            = {{"meter/second", 1.},
               {"kilometer/hour", 0.277778},
               {"mile/hour", 0.44704},
               {"feet/second", 0.3048},
               {"knot", 0.514444}};

    Dictionary angle[]
            = {{"degree", 1.},
               {"radian", M_PI / 180.},
               {"minutes-of-angle", 60.},
               {"seconds-of-angle", 60. * 60.}};
}