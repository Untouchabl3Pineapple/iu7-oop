#ifndef __POINTS_H__
#define __POINTS_H__

#include <stdio.h>
#include <math.h>

#include "ret_codes.h"
#include "model_struc.h"

struct coeffs_t {
    double x;
    double y;
    double z;
};

int pointRead(double *const point, const int point_len, FILE *const f);
int pointsRead(points_t &points, FILE *const f);

int edgeRead(int *const edge, const int edge_len, FILE *const f);
int edgesRead(edges_t &edges, FILE *const f);

void movePoint(double *const point, const coeffs_t &coeffs);
void moveCenter(center_t &center, const coeffs_t &coeffs);
void movePoints(const points_t &points, center_t &center, const coeffs_t &coeffs);

void scalePoint(double *const point, const center_t &center, const coeffs_t &coeffs);
void scalePoints(const points_t &points, const center_t &center, const coeffs_t &coeffs);

double getRadians(const double angle);
void rotatePoint(double &first_point, double &second_point, const double sinus, const double cosine);
void rotatePoints(const points_t &points, const center_t &center, const coeffs_t &coeffs);

#endif // __POINTS_H__