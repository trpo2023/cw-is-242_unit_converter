double convert_unit(double unit, int coefficient);

double get_result(double unit, char* from_unit_measure, char* to_unit_measure);

typedef struct {
    char* key;
    double value;
} Dictionary;
