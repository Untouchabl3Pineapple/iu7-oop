#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>

#include "ret_codes.h"
#include "model_struc.h"

int allocatePoints(points_t &edges);
int allocateEdges(edges_t &edges);

void freePoints(points_t &points);
void freeEdges(edges_t &edges);

#endif // __MEMORY_H__
