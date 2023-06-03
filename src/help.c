#include <stdio.h>

void pr_help()
{
    printf("To use unit converter you should input amount and unit "
           "type.\nUnits can be converted only if they are from the same "
           "group.\nCurrently supported units 56:\nlength (meters, "
           "cantimeters, milimeters, kilometers, feet, inches, yards, "
           "miles)\nmass (kilogram, pound, gram, miligram, ton, ounce)\ntime "
           "(seconds, minutes, hour, day, miliseconds, microseconds, "
           "nanoseconds)\ntemperature (kelvin, celsius, fahr)\npressure "
           "(pascal, bar, atmospheres,torr)\nenergy (joule, kilojoule, "
           "gram/calorie,kilocalori, watt/hour, kilowatt/hour, "
           "electron/volt)\nvolume (m^3, dm^3, cm^3, liter, mm^3, km^3, "
           "inches^3, feet^3)\narea (m^2, km^2, miles^2, yards^2, feet^2, "
           "inces^2, hectare, arc)\nspeed (meter/second, kilometer/hour, "
           "mile/hour, feet/second)\nangle (knot, degree, radian, "
           "minutes-of-angle, seconds-of-angle)\nfrequency (hertz, kilohertz, "
           "megahertz, gigahertz)\n\nAlso program support abbreviation.\nFor "
           "example you can use \"mm\" instead of \"milimeters\"\n\n");
}
