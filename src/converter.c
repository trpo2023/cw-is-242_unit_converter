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

double
temp_convert(char* from_unit_measure, double inp_value, char* to_unit_measure)
{
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
    return NAN;
}

double convert(char* from_unit_measure, double inp_value, char* to_unit_measure)
{
    Dictionary dict_length[] = {{"meters", 1.},         {"metr", 1.},
                                {"meter", 1.},          {"metre", 1.},
                                {"metres", 1.},         {"decimeters", 0.1},
                                {"decimeter", 0.1},     {"decimetre", 0.1},
                                {"decimetres", 0.1},    {"centimeters", 0.01},
                                {"centimeter", 0.01},   {"centimetre", 0.01},
                                {"centimetres", 0.01},  {"cm", 0.01},
                                {"milimeters", 0.001},  {"milimeter", 0.001},
                                {"milimetre", 0.001},   {"milimetres", 0.001},
                                {"mm", 0.001},          {"kilometers", 1000.0},
                                {"kilometer", 1000.0},  {"kilometre", 1000.0},
                                {"kilometres", 1000.0}, {"km", 1000.0},
                                {"foot", 0.3048},       {"feet", 0.3048},
                                {"ft", 0.3048},         {"inches", 0.254},
                                {"inch", 0.254},        {"in", 0.254},
                                {"yards", 0.9144},      {"yard", 0.9144},
                                {"miles", 1609.34},     {"mile", 1609.34}};

    Dictionary dict_mass[]
            = {{"kilograms", 1.},
               {"kilogram", 1.},
               {"kg", 1.},
               {"pounds", 0.453592909},
               {"pound", 0.453592909},
               {"lb", 0.453592909},
               {"grams", 0.001},
               {"gram", 0.001},
               {"miligrams", 0.000001},
               {"miligram", 0.000001},
               {"mg", 0.000001},
               {"tons", 1000.},
               {"ton", 1000.},
               {"ounces", 0.028349493},
               {"ounce", 0.028349493}};

    Dictionary dict_time[]
            = {{"seconds", 1.},
               {"second", 1.},
               {"sec", 1.},
               {"minutes", 60.},
               {"minute", 60.},
               {"min", 60.},
               {"hours", 3600.},
               {"hour", 3600.},
               {"days", 86400.},
               {"day", 86400.},
               {"miliseconds", 0.001},
               {"milisecond", 0.001},
               {"milisec", 0.001},
               {"msec", 0.001},
               {"ms", 0.001},
               {"microseconds", 0.000001},
               {"microsecond", 0.000001},
               {"microsec", 0.000001},
               {"mcsec", 0.000001},
               {"mcs", 0.000001},
               {"nanoseconds", 0.000000001},
               {"nanosecond", 0.000000001},
               {"nanosec", 0.000000001},
               {"nsec", 0.000000001},
               {"ns", 0.000000001}};

    Dictionary dict_temperature[]
            = {{"celsius", 1}, {"kelvin", -273.15}, {"fahrenheit", -273.15}};

    Dictionary dict_pressure[]
            = {{"pascals", 1.},
               {"pascal", 1.},
               {"bars", 0.00001},
               {"bar", 0.00001},
               {"atmospheres", 0.000009869},
               {"atmosphere", 0.000009869},
               {"torrs", 0.007500638},
               {"torr", 0.007500638}};

    Dictionary dict_energy[]
            = {{"joules", 1.},
               {"joule", 1.},
               {"j", 1.},
               {"kilojoules", 1000.},
               {"kilojoule", 1000.},
               {"kiloj", 1000.},
               {"kjoules", 1000.},
               {"kjoule", 1000.},
               {"kj", 1000.},
               {"megajoules", 1e+6},
               {"megajoule", 1e+6},
               {"megaj", 1e+6},
               {"mgjoules", 1e+6},
               {"mgjoule", 1e+6},
               {"mgj", 1e+6},
               {"gigajoules", 1e+9},
               {"gigajoule", 1e+9},
               {"gigaj", 1e+9},
               {"gjoules", 1e+9},
               {"gjoule", 1e+9},
               {"gj", 1e+9},
               {"gram/calories", 0.239005736},
               {"gram/calorie", 0.239005736},
               {"gram/cal", 0.239005736},
               {"kilocalories", 0.000239005},
               {"kilocalorie", 0.000239005},
               {"kilocal", 0.000239005},
               {"kcal", 0.000239005},
               {"watts/hours", 0.000277778},
               {"watts/hour", 0.000277778},
               {"watt/hours", 0.000277778},
               {"watt/hour", 0.000277778},
               {"w/hour", 0.000277778},
               {"watt/h", 0.000277778},
               {"w/h", 0.000277778},
               {"kilowatts/hours", 2.77778e-7},
               {"kilowatts/hour", 2.77778e-7},
               {"kilowatt/hours", 2.77778e-7},
               {"kilowatt/hour", 2.77778e-7},
               {"kilow/hours", 2.77778e-7},
               {"kilow/hour", 2.77778e-7},
               {"kw/hours", 2.77778e-7},
               {"kw/hour", 2.77778e-7},
               {"kw/h", 2.77778e-7},
               {"electron/volts", 1.6022e-19},
               {"electron/volt", 1.6022e-19},
               {"e/v", 1.6022e-19}};

    Dictionary dict_volume[] = {{"meters^3", 1.},
                                {"meter^3", 1.},
                                {"m^3", 1.},
                                {"decimeters^3", 1e-3},
                                {"decimeter^3", 1e-3},
                                {"decim^3", 1e-3},
                                {"dmeters^3", 1e-3},
                                {"dmeter^3", 1e-3},
                                {"dm^3", 1e-3},
                                {"centimeters^3", 1e-6},
                                {"centimeter^3", 1e-6},
                                {"centim^3", 1e-6},
                                {"cmeters^3", 1e-6},
                                {"cmeter^3", 1e-6},
                                {"cm^3", 1e-6},
                                {"milimeters^3", 1e-9},
                                {"milimeter^3", 1e-9},
                                {"milim^3", 1e-9},
                                {"mmeters^3", 1e-9},
                                {"mmeter^3", 1e-9},
                                {"mm^3", 1e-9},
                                {"liter", 1e-3},
                                {"kilometers^3", 1e+9},
                                {"kilometer^3", 1e+9},
                                {"kilom^3", 1e+9},
                                {"kmeters^3", 1e+9},
                                {"kmeter^3", 1e+9},
                                {"km^3", 1e+9},
                                {"inches^3", 1.6387e-5},
                                {"inch^3", 1.6387e-5},
                                {"in^3", 1.6387e-5},
                                {"feet^3", 1.6387e-5},
                                {"foot^3", 1.6387e-5},
                                {"ft^3", 1.6387e-5}};

    Dictionary dict_area[] = {{"meters^2", 1.},
                              {"meter^2", 1.},
                              {"m^2", 1.},
                              {"decimeters^2", 1e-2},
                              {"decimeter^2", 1e-2},
                              {"decim^2", 1e-2},
                              {"dmeters^2", 1e-2},
                              {"dmeter^2", 1e-2},
                              {"dm^2", 1e-2},
                              {"centimeters^2", 1e-4},
                              {"centimeter^2", 1e-4},
                              {"centim^2", 1e-4},
                              {"cmeters^2", 1e-4},
                              {"cmeter^2", 1e-4},
                              {"cm^2", 1e-4},
                              {"milimeters^2", 1e-6},
                              {"milimeter^2", 1e-6},
                              {"milim^2", 1e-6},
                              {"mmeters^2", 1e-6},
                              {"mmeter^2", 1e-6},
                              {"mm^2", 1e-6},
                              {"kilometers^2", 1e+6},
                              {"kilometer^2", 1e+6},
                              {"kilom^2", 1e+6},
                              {"kmeters^2", 1e+6},
                              {"kmeter^2", 1e+6},
                              {"km^2", 1e+6},
                              {"miles^2", 2.59e+6},
                              {"mile^2", 2.59e+6},
                              {"yards^2", 0.836127},
                              {"yard^2", 0.836127},
                              {"feet^2", 0.092903},
                              {"foot^2", 0.092903},
                              {"ft^2", 0.092903},
                              {"inces^2", 0.00064516},
                              {"ince^2", 0.00064516},
                              {"hectares", 1e+4},
                              {"hectare", 1e+4},
                              {"arcs", 4046.86},
                              {"arc", 4046.86}};

    Dictionary dict_velocity[]
            = {{"meters/seconds", 1.},
               {"meters/second", 1.},
               {"meter/seconds", 1.},
               {"m/sec", 1.},
               {"meters/sec", 1.},
               {"meter/sec", 1.},
               {"m/s", 1.},
               {"kilometers/hours", 0.277778},
               {"kilometers/hour", 0.277778},
               {"kilometer/hours", 0.277778},
               {"kilometr/hour", 0.277778},
               {"kilometr/hours", 0.277778},
               {"kilom/hours", 0.277778},
               {"kilom/hour", 0.277778},
               {"kilometers/h", 0.277778},
               {"kilometer/h", 0.277778},
               {"kilometr/h", 0.277778},
               {"kmeter/hour", 0.277778},
               {"km/hours", 0.277778},
               {"km/hour", 0.277778},
               {"km/h", 0.277778},
               {"miles/hours", 0.44704},
               {"mile/hours", 0.44704},
               {"miles/hour", 0.44704},
               {"miles/h", 0.44704},
               {"mile/h", 0.44704},
               {"feet/seconds", 0.3048},
               {"feets/second", 0.3048},
               {"feet/second", 0.3048},
               {"foot/seconds", 0.3048},
               {"foots/second", 0.3048},
               {"foot/second", 0.3048},
               {"knots", 0.514444},
               {"knot", 0.514444}};

    Dictionary dict_angle[]
            = {{"degrees", 1.},
               {"degree", 1.},
               {"radians", M_PI / 180.},
               {"radian", M_PI / 180.},
               {"minutes-of-angle", 60.},
               {"seconds-of-angle", 60. * 60.}};

    Dictionary dict_frequency[]
            = {{"hertzs", 1.},
               {"hertz", 1.},
               {"hz", 1.},
               {"kilohertzs", 1000.},
               {"kilohertz", 1000.},
               {"kilohz", 1000.},
               {"khertz", 1000.},
               {"khz", 1000.},
               {"megahertzs", 1e+6},
               {"megahertz", 1e+6},
               {"megahz", 1e+6},
               {"mghertz", 1e+6},
               {"mghz", 1e+6},
               {"gigahertzs", 1e+9},
               {"gigahertz", 1e+9},
               {"gigahz", 1e+9},
               {"ghertz", 1e+9},
               {"ghz", 1e+9}};

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
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++) {
        cur = tab[i];

        for (Listnode* lst = cur; lst != NULL; lst = lst->next) {
            char* s1 = lst->key;
            char* s2 = lst->key;

            if (strcmp(s1, from_unit_measure) == 0) {
                from_coefficient = lst->value;
                cnt1++;
            }
            if (strcmp(s2, to_unit_measure) == 0) {
                to_coefficient = lst->value;
                cnt2++;
            }
        }
        if (from_coefficient && to_coefficient) {
            flag = TRUE;
            break;
        } else {
            from_coefficient = 0;
            to_coefficient = 0;
        }
    }

    if (flag) {
        if (cur == temperature) {
            return temp_convert(from_unit_measure, inp_value, to_unit_measure);
        }

        inp_value = inp_value * from_coefficient / to_coefficient;
        return inp_value;
    } else {
        if (cnt1 && cnt2) {
            printf("Cannot be converted from '%s' to '%s'\n",
                   from_unit_measure,
                   to_unit_measure);
        } else {
            if (!cnt1)
                printf("Unknown unit of measure '%s'\n", from_unit_measure);
            if (!cnt2)
                printf("Unknown unit of measure '%s'\n", to_unit_measure);
        }
        return NAN;
    }
}