#include "model.h"

void initPoints(points_t &points) {
    points.rows = 0;
    points.columns = 0;
    points.data = NULL;
}

void initEdges(edges_t &edges) {
    edges.rows = 0;
    edges.columns = 0;
    edges.data = NULL;
}

model_t &initModel(void) {
    static model_t model;

    initPoints(model.points);
    initEdges(model.edges);

    return model;
}

void freeModel(model_t &model) {
    freePoints(model.points);
    freeEdges(model.edges);
}

int loadCenter(center_t &center, FILE *const f) {
    int rc = OK;

    if (fscanf(f, "%lf%lf%lf", &center.x, &center.y, &center.z) != 3) {
        rc = ERR_MODEL_CENTER;
    }

    return rc;
}

int loadPoints(points_t &points, FILE *const f) {
    int rc = OK;

    if (fscanf(f, "%d%d", &points.rows, &points.columns) != 2) {
        rc = ERR_MODEL_POINTS;
    }
    if (rc == OK && allocatePoints(points) != OK) {
        rc = ERR_MEMORY_ALLOC;
    }
    if (rc == OK && pointsRead(points, f) != OK) {
        rc = ERR_MODEL_POINTS;
    }

    if (rc != OK) {
        freePoints(points);
    }

    return rc;
}

int loadEdges(edges_t &edges, FILE *const f) {
    int rc = OK;

    if (fscanf(f, "%d%d", &edges.rows, &edges.columns) != 2) {
        rc = ERR_MODEL_EDGES;
    }
    if (rc == OK && allocateEdges(edges) != OK) {
        rc = ERR_MEMORY_ALLOC;
    }
    if (rc == OK && edgesRead(edges, f) != OK) {
        rc = ERR_MODEL_EDGES;
    }

    if (rc != OK) {
        freeEdges(edges);
    }

    return OK;
}

int dataCheck(const points_t &points, const edges_t &edges) {
    int rc = OK;

    if (points.data == NULL || edges.data == NULL) {
        rc = ERR_MEMORY;
    }

    return rc;
}

int readModel(model_t &model, FILE *f) {
    model = initModel();

    int rc = loadCenter(model.center, f);
    if (rc == OK) {
        rc = loadPoints(model.points, f);
        if (rc == OK) {
            rc = loadEdges(model.edges, f);
            if (rc != OK) {
                freePoints(model.points);
            }
        }
    }

    return rc;
}

int downloadModel(model_t &model, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return ERR_FILE_OPEN;
    }

    model_t temp_figure;

    int rc = readModel(temp_figure, f);

    fclose(f);

    if (rc == OK) {
        freeModel(model);
        model = temp_figure;
    }

    return rc;
}

int drawModel(const model_t &model, const canvas_t &canvas) {
    if (dataCheck(model.points, model.edges) != OK) {
        return ERR_MEMORY;
    }

    canvasClear(canvas);

    drawEdges(model.points, model.edges, canvas);

    return OK;
}

int moveModel(model_t &model, const coeffs_t &coeffs) {
    if (dataCheck(model.points, model.edges) != OK) {
        return ERR_MEMORY; 
    }

    movePoints(model.points, model.center, coeffs);

    return OK;
}

int scaleModel(const model_t &model, const coeffs_t &coeffs) {
    if (dataCheck(model.points, model.edges) != OK) {
        return ERR_MEMORY;
    }

    scalePoints(model.points, model.center, coeffs);

    return OK;
}

int rotateModel(const model_t &model, const coeffs_t &coeffs) {
    if (dataCheck(model.points, model.edges) != OK) {
        return ERR_MEMORY;
    }

    rotatePoints(model.points, model.center, coeffs);

    return OK;
}
