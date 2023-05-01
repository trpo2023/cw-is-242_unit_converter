#include <stdio.h>

#include "converter.h"
#include "constants.h"

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