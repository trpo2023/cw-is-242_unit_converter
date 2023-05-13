#include <assert.h>
#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "constants.h"
#include "converter.h"

#define TRUE 1
#define FALSE 0

Listnode *list_createnode(char *key, double value)
{
    Listnode *p;

    p = malloc(sizeof(*p));

    if (p != NULL) 
    {
        p->key = key;
        p->value = value;
        p->next = NULL;
    }
    return p;
}

Listnode *list_pushfront(Listnode *list, char *key, double value)
{
    Listnode *newnode;
    newnode = list_createnode(key, value);

    if (newnode != NULL) 
    {
        newnode->next = list;
        return newnode;
    }

    return list;
}

void list_delete(Listnode *list)
{
    Listnode *prev;

    for (prev = list; prev != NULL; prev = list)
    {
        list = list->next;
        free(prev);
    }
}

int convert(char* from_unit_measure, double inp_value, char* to_unit_measure)
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
               {"feet^3", 35.3147}};

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

    Dictionary frequency[]
            = {{"hertz", 1.},
               {"kilohertz", 1000.},
               {"megahertz", 1e+6},
               {"gigahertz", 1e+9}};

}