#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

#include "converter.h"

#define TRUE 1
#define FALSE 0

Listnode* list_createnode(char* key, double value)
{
    Listnode* p;

    p = malloc(sizeof(*p));

    if (p != NULL) {
        p->key = key;
        p->value = value;
        p->next = NULL;
    }
    return p;
}

Listnode* list_pushfront(Listnode* list, char* key, double value)
{
    Listnode* newnode;
    newnode = list_createnode(key, value);

    if (newnode != NULL) {
        newnode->next = list;
        return newnode;
    }

    return list;
}

void list_delete(Listnode* list)
{
    Listnode* prev;

    for (prev = list; prev != NULL; prev = list) {
        list = list->next;
        free(prev);
    }
}

double convert(char* from_unit_measure, double inp_value, char* to_unit_measure)
{
    Dictionary dict_length[]
            = {{"meters", 1.},
               {"cantimeters", 0.01},
               {"milimeters", 0.001},
               {"kilometers", 1000.0},
               {"feet", 0.3048},
               {"inches", 0.254},
               {"yards", 0.9144},
               {"miles", 1609.34}};

    Dictionary dict_mass[]
            = {{"kilogram", 1.},
               {"pound", 0.453592909},
               {"gram", 0.001},
               {"miligram", 0.000001},
               {"ton", 1000.},
               {"ounce", 0.028349493}};

    Dictionary dict_time[]
            = {{"seconds", 1.},
               {"minutes", 60.},
               {"hour", 3600.},
               {"day", 86400.},
               {"miliseconds", 0.001},
               {"microseconds", 0.000001},
               {"nanoseconds", 0.000000001}};

    Dictionary dict_temperature[]
            = {{"celsius", 1}, {"kelvin", -273.15}, {"fahrenheit", -273.15}};

    Dictionary dict_pressure[]
            = {{"pascal", 1.},
               {"bar", 0.00001},
               {"atmospheres", 0.000009869},
               {"torr", 0.007500638}};

    Dictionary dict_energy[]
            = {{"joule", 1.},
               {"kilojoule", 1000.},
               {"gram/calorie", 0.239005736},
               {"kilocalorie", 0.000239005},
               {"watt/hour", 0.000277778},
               {"kilowatt/hour", 2.77778e-7},
               {"electron/volt", 1.6022e-19}};

    Dictionary dict_volume[]
            = {{"m^3", 1.},
               {"dm^3", 1e+3},
               {"cm^3", 1e+6},
               {"liter", 1e+3},
               {"mm^3", 1e+9},
               {"km^3", 1e-9},
               {"inches^3", 61023.7},
               {"feet^3", 35.3147}};

    Dictionary dict_area[]
            = {{"m^2", 1.},
               {"km^2", 1e+6},
               {"miles^2", 2.59e+6},
               {"yards^2", 0.836127},
               {"feet^2", 0.092903},
               {"inces^2", 0.00064516},
               {"hectare", 1e-4},
               {"arc", 0.000247105}};

    Dictionary dict_velocity[]
            = {{"meter/second", 1.},
               {"kilometer/hour", 0.277778},
               {"mile/hour", 0.44704},
               {"feet/second", 0.3048},
               {"knot", 0.514444}};

    Dictionary dict_angle[]
            = {{"degree", 1.},
               {"radian", M_PI / 180.},
               {"minutes-of-angle", 60.},
               {"seconds-of-angle", 60. * 60.}};

    Dictionary dict_frequency[]
            = {{"hertz", 1.},
               {"kilohertz", 1000.},
               {"megahertz", 1e+6},
               {"gigahertz", 1e+9}};

    Listnode* length
            = list_createnode(dict_length[0].key, dict_length[0].value);
    for (int i = 1; i < sizeof(dict_length) / sizeof(dict_length[0]); i++) {
        length = list_pushfront(
                length, dict_length[i].key, dict_length[i].value);
    }

    Listnode* mass = list_createnode(dict_mass[0].key, dict_mass[0].value);
    for (int i = 1; i < sizeof(dict_mass) / sizeof(dict_mass[0]); i++) {
        mass = list_pushfront(mass, dict_mass[i].key, dict_mass[i].value);
    }

    Listnode* time = list_createnode(dict_time[0].key, dict_time[0].value);
    for (int i = 1; i < sizeof(dict_time) / sizeof(dict_time[0]); i++) {
        time = list_pushfront(time, dict_time[i].key, dict_time[i].value);
    }

    Listnode* temperature = list_createnode(
            dict_temperature[0].key, dict_temperature[0].value);
    for (int i = 1; i < sizeof(dict_temperature) / sizeof(dict_temperature[0]);
         i++) {
        temperature = list_pushfront(
                temperature,
                dict_temperature[i].key,
                dict_temperature[i].value);
    }

    Listnode* pressure
            = list_createnode(dict_pressure[0].key, dict_pressure[0].value);
    for (int i = 1; i < sizeof(dict_pressure) / sizeof(dict_pressure[0]); i++) {
        pressure = list_pushfront(
                pressure, dict_pressure[i].key, dict_pressure[i].value);
    }

    Listnode* energy
            = list_createnode(dict_energy[0].key, dict_energy[0].value);
    for (int i = 1; i < sizeof(dict_energy) / sizeof(dict_energy[0]); i++) {
        energy = list_pushfront(
                energy, dict_energy[i].key, dict_energy[i].value);
    }

    Listnode* volume
            = list_createnode(dict_volume[0].key, dict_volume[0].value);
    for (int i = 1; i < sizeof(dict_volume) / sizeof(dict_volume[0]); i++) {
        volume = list_pushfront(
                volume, dict_volume[i].key, dict_volume[i].value);
    }

    Listnode* area = list_createnode(dict_area[0].key, dict_area[0].value);
    for (int i = 1; i < sizeof(dict_area) / sizeof(dict_area[0]); i++) {
        area = list_pushfront(area, dict_area[i].key, dict_area[i].value);
    }

    Listnode* velocity
            = list_createnode(dict_velocity[0].key, dict_velocity[0].value);
    for (int i = 1; i < sizeof(dict_velocity) / sizeof(dict_velocity[0]); i++) {
        velocity = list_pushfront(
                velocity, dict_velocity[i].key, dict_velocity[i].value);
    }

    Listnode* angle = list_createnode(dict_angle[0].key, dict_angle[0].value);
    for (int i = 1; i < sizeof(dict_angle) / sizeof(dict_angle[0]); i++) {
        angle = list_pushfront(angle, dict_angle[i].key, dict_angle[i].value);
    }

    Listnode* frequency
            = list_createnode(dict_frequency[0].key, dict_frequency[0].value);
    for (int i = 1; i < sizeof(dict_frequency) / sizeof(dict_frequency[0]);
         i++) {
        frequency = list_pushfront(
                frequency, dict_frequency[i].key, dict_frequency[i].value);
    }

    Listnode* tab[]
            = {length,
               mass,
               time,
               temperature,
               pressure,
               energy,
               volume,
               area,
               velocity,
               angle,
               frequency};

    Listnode* cur;
    int flag = FALSE;

    double from_coefficient = 0;
    double to_coefficient = 0;

    for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++) {
        cur = tab[i];

        for (Listnode* lst = cur; lst != NULL; lst = lst->next) {
            char* s1 = lst->key;
            char* s2 = lst->key;

            if (strcmp(s1, from_unit_measure) == 0)
                from_coefficient = lst->value;

            if (strcmp(s2, to_unit_measure) == 0)
                to_coefficient = lst->value;
        }
        if (from_coefficient && to_coefficient) {
            flag = TRUE;
            break;
        }
    }

    if (flag) {
        if (cur == temperature) {
            if (!strcmp(from_unit_measure, to_unit_measure))
                return inp_value;
            if (!strcmp("celsius", from_unit_measure)
                && !strcmp("kelvin", to_unit_measure))
                return inp_value + 273.15;
            if (!strcmp("kelvin", from_unit_measure)
                && !strcmp("celsius", to_unit_measure))
                return inp_value - 273.15;
            if (!strcmp("celsius", from_unit_measure)
                && !strcmp("fahrenheit", to_unit_measure))
                return (inp_value * 9.0 / 5.0) + 32;
            if (!strcmp("fahrenheit", from_unit_measure)
                && !strcmp("celsius", to_unit_measure))
                return (inp_value - 32) * 5.0 / 9.0;
            if (!strcmp("fahrenheit", from_unit_measure)
                && !strcmp("kelvin", to_unit_measure))
                return (inp_value - 32) * 5.0 / 9.0 + 273.15;
            if (!strcmp("kelvin", from_unit_measure)
                && !strcmp("fahrenheit", to_unit_measure))
                return (inp_value - 273.15) * 9.0 / 5.0 + 32;
        }

        inp_value = inp_value * from_coefficient / to_coefficient;
        return inp_value;
    } else {
        if (from_coefficient && to_coefficient) {
            printf("Cannot be converted from '%s' to '%s'\n",
                   from_unit_measure,
                   to_unit_measure);
        } else {
            if (!from_coefficient)
                printf("Unknown unit of measure '%s'\n", from_unit_measure);
            if (!to_coefficient)
                printf("Unknown unit of measure '%s'\n", to_unit_measure);
        }
        return NAN;
    }
}