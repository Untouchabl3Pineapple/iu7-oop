#include "memory.h"

int allocatePoints(points_t &points) {
    points.data = (double **) malloc(points.rows * sizeof(double *));
    if (!points.data) {
        return ERR_MEMORY_ALLOC;
    }

    int rc = 0;
    for (int i = 0; i < points.rows && rc == 0; i++) {
        points.data[i] = (double *) malloc(points.columns * sizeof(double));
        if (!points.data[i]) {
            rc = ERR_MEMORY_ALLOC;
        }
    }

    return rc;
}

int allocateEdges(edges_t &edges) {
    edges.data = (int **) malloc(edges.rows * sizeof(int *));
    if (!edges.data) {
        return ERR_MEMORY_ALLOC;
    }

    int rc = 0;
    for (int i = 0; i < edges.rows && rc == 0; i++) {
        edges.data[i] = (int *) malloc(edges.columns * sizeof(int));
        if (!edges.data[i]) {
            rc = ERR_MEMORY_ALLOC;
        }
    }

    return rc;
}

void freePoints(points_t &points) {
    for (int i = 0; i < points.rows; i++) {
        free(points.data[i]);
    }

    free(points.data);
}

void freeEdges(edges_t &edges) {
    for (int i = 0; i < edges.rows; i++) {
        free(edges.data[i]);
    }

    free(edges.data);
}
