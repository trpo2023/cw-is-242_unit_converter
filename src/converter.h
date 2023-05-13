typedef struct Dict {
    char* key;
    double value;

} Dictionary;

typedef struct list {
    char* key;
    double value;

    struct list *next;
} Listnode;

double convert(char* from_unit_measure, double inp_value, char* to_unit_measure);
void list_delete(Listnode* list);
Listnode* list_pushfront(Listnode* list, char* key, double value);
Listnode* list_createnode(char* key, double value);