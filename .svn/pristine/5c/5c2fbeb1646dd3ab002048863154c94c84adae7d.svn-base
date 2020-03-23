/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 3
 */

char** split_at(char* s, char d);

typedef struct measurement measurement;

struct measurement {
    double value;
    char* units;
    unsigned int exponent;
};

typedef struct conversion conversions;

struct conversion {
    char *from, *to;
    double mult_by;
};

struct measurement add_measurements(struct measurement m1, \
    struct measurement m2);

struct measurement scale_measurements(struct measurement m, double lambda);

struct measurement multiply_measurements(struct measurement m1, \
    struct measurement m2);

char* measurement_tos(struct measurement m);

struct measurement convert_units(struct conversion* conversions,
                                 unsigned int n_conversions,
                                 struct measurement m, 
                                 char* to);

typedef struct element element;

struct element {
    char* name;
    unsigned int weight;
};

typedef struct molecule molecule;

struct molecule {
    char* name;
    unsigned int nelements;
    struct element** elements;
    unsigned int* atoms;
 /* there are atoms[i] atoms of element elements[i] */ 
};

union chemical {
    struct element* element;
    struct molecule* molecule;
};

enum chemical_tag {
    ELEMENT, MOLECULE
};

typedef struct tagged_chemical tagged_chemical;

struct tagged_chemical {
    enum chemical_tag tag;
    union chemical chemical;
};

typedef struct mixture mixture;

struct mixture {
    char* name;
    unsigned int nchemicals;
    struct tagged_chemical* chemicals;
    double* moles;
/*  there are moles[i] moles of chemical chemicals[i] */ 
};

double mixture_weight(struct mixture* mixture); 
