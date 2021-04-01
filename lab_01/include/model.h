#ifndef __MODEL_H__
#define __MODEL_H__

#include <stdio.h>

#include "ret_codes.h"
#include "model_struc.h"
#include "memory.h"
#include "draw.h"
#include "points.h"

void initPoints(points_t &points);
void initEdges(edges_t &edges);
model_t &initModel(void);

int loadCenter(center_t &center);
int loadPoints(points_t &points, FILE *const f);
int loadEdges(edges_t &edges, FILE *const f);
int dataCheck(const points_t &points, const edges_t &edges);
int readModel(model_t &model, FILE *f);
int downloadModel(model_t &figure, const char *filename);
void freeModel(model_t &model);

int drawModel(const model_t &model, const canvas_t &canvas);

int moveModel(model_t &model, const coeffs_t &coeffs);
int scaleModel(const model_t &model, const coeffs_t &coeffs);
int rotateModel(const model_t &model, const coeffs_t &coeffs);

#endif // __MODEL_H__