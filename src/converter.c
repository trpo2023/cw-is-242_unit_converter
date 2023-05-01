#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "converter.h"
#include "constants.h"

#define TRUE 1
#define FALSE 0

char *MEASURE[] = {"metre", "ft", "mile", "yard",
                   "inch", "sec", "min", "hour",
                   "kg", "pound", "ounce",
                   "kelvin", "celsius", "fahr"};

double convert_unit(double unit, int coefficient)
{
    switch (coefficient)
    {
    // Преобразование величин длины
    case METERS_TO_FT:
        return unit * 3.281;

    case FT_TO_METERS:
        return unit / 3.281;

    case METERS_TO_MILE:
        return unit / 1609;

    case MILE_TO_METERS:
        return unit * 1609;

    case METERS_TO_YARD:
        return unit * 1.094;

    case YARD_TO_METERS:
        return unit / 1.094;

    case METERS_TO_INCH:
        return unit * 39.37;

    case INCH_TO_METERS:
        return unit / 39.37;

    // Преобразование величин времени
    case SEC_TO_MIN:
        return unit / 60;

    case MIN_TO_SEC:
        return unit * 60;

    case SEC_TO_HOUR:
        return unit / 3600;

    case HOUR_TO_SEC:
        return unit * 3600;

    // Преобразование величин массы
    case KG_TO_POUND:
        return unit * 2.205;

    case POUND_TO_KG:
        return unit / 2.205;

    case KG_TO_OUNCE:
        return unit * 35.274;

    case OUNCE_TO_KG:
        return unit / 35.274;

    // Преобразование величин температуры
    case KELVIN_TO_CELSIUS:
        return unit - 273.15;

    case CELSIUS_TO_KELVIN:
        return unit + 273.15;

    case CELSIUS_TO_FAHR:
        return (unit * 9. / 5.) + 32;

    case FAHR_TO_CELSIUS:
        return (unit - 32) * 5. / 9.;

    case KELVIN_TO_FAHR:
        return (unit - 273.15) * 9. / 5. + 32;

    case FAHR_TO_KELVIN:
        return (unit - 32) * 5. / 9. + 273.15;

    default:
    {
        printf("Unknown unit of measurement\n");
        return 0;
    }
    }
}

double get_result(double unit, char *from_unit_measure, char *to_unit_measure)
{
    int flag = TRUE;
    int i;

    for (i = 0; i < sizeof(MEASURE); i++)
    {
        if (strcmp(from_unit_measure, MEASURE[i]) != 0)
        {
            flag = FALSE;
            break;
        }
    }

    if (!flag)
    {
        printf("[%s] Unknown unit of measurement\n", from_unit_measure);
        assert(flag);
    }

    for (i = 0, flag = TRUE; i < sizeof(MEASURE); i++)
    {
        if (strcmp(to_unit_measure, MEASURE[i]) != 0)
        {
            flag = FALSE;
            break;
        }
    }

    if (!flag)
    {
        printf("[%s] Unknown unit of measurement\n", to_unit_measure);
        assert(flag);
    }


    if (!strcmp(from_unit_measure, "metre") && !strcmp(to_unit_measure, "ft")) return convert_unit(unit, METERS_TO_FT);
    if (!strcmp(from_unit_measure, "metre") && !strcmp(to_unit_measure, "mile")) return convert_unit(unit, METERS_TO_MILE);
    if (!strcmp(from_unit_measure, "metre") && !strcmp(to_unit_measure, "yard")) return convert_unit(unit, METERS_TO_YARD);
    if (!strcmp(from_unit_measure, "metre") && !strcmp(to_unit_measure, "inch")) return convert_unit(unit, METERS_TO_INCH);
    if (!strcmp(from_unit_measure, "ft") && !strcmp(to_unit_measure, "metre")) return convert_unit(unit, FT_TO_METERS);
    if (!strcmp(from_unit_measure, "mile") && !strcmp(to_unit_measure, "metre")) return convert_unit(unit, MILE_TO_METERS);
    if (!strcmp(from_unit_measure, "yard") && !strcmp(to_unit_measure, "metre")) return convert_unit(unit, YARD_TO_METERS);
    if (!strcmp(from_unit_measure, "inch") && !strcmp(to_unit_measure, "metre")) return convert_unit(unit, INCH_TO_METERS);

    if (!strcmp(from_unit_measure, "sec") && !strcmp(to_unit_measure, "min")) return convert_unit(unit, SEC_TO_MIN);
    if (!strcmp(from_unit_measure, "sec") && !strcmp(to_unit_measure, "hour")) return convert_unit(unit, SEC_TO_HOUR);
    if (!strcmp(from_unit_measure, "hour") && !strcmp(to_unit_measure, "sec")) return convert_unit(unit, HOUR_TO_SEC);
    if (!strcmp(from_unit_measure, "min") && !strcmp(to_unit_measure, "sec")) return convert_unit(unit, MIN_TO_SEC);

    
    

}