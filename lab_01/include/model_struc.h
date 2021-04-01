#ifndef __MODEL_STRUC__
#define __MODEL_STRUC__

struct center_t {
    double x;
    double y;
    double z;
};

struct points_t {
    double **data;
    int rows;
    int columns;
};

struct edges_t {
    int **data;
    int rows;
    int columns;
};

struct model_t {
    center_t center;
    points_t points;
    edges_t edges;
};

#endif // __MODEL_STRUC__