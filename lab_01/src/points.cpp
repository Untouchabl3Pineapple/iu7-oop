#include "points.h"

int pointRead(double *const point, const int point_len, FILE *const f) {
    int rc = 0;

    for (int i = 0; i < point_len && rc == 0; i++) {
        if (fscanf(f, "%lf", &point[i]) != 1) {
            rc = ERR_MODEL_POINTS;
        }
    }

    return rc;
}

int pointsRead(points_t &points, FILE *const f) {
    int rc = 0;

    for (int i = 0; i < points.rows && rc == 0; i++) {
        if (pointRead(points.data[i], points.columns, f) == ERR_MODEL_POINTS) {
            rc = ERR_MODEL_POINTS;
        }
    }

    return rc;
}

int edgeRead(int *const edge, const int edge_len, FILE *const f) {
    int rc = 0;

    for (int i = 0; i < edge_len && rc == 0; i++) {
        if (fscanf(f, "%d", &edge[i]) != 1) {
            rc = ERR_MODEL_EDGES;
        }
    }

    return rc;
}

int edgesRead(edges_t &edges, FILE *const f) {
    int rc = 0;

    for (int i = 0; i < edges.rows && rc == 0; i++) {
        if (edgeRead(edges.data[i], edges.columns, f) == ERR_MODEL_EDGES) {
            rc = ERR_MODEL_EDGES;
        }
    }

    return rc;
}

void movePoint(double *const point, const coeffs_t &coeffs) {
    point[0] += coeffs.x;
    point[1] += coeffs.y;
    point[2] += coeffs.z;
}

void moveCenter(center_t &center, const coeffs_t &coeffs) {
    center.x += coeffs.x;
    center.y += coeffs.y;
    center.z += coeffs.z;
}

void movePoints(const points_t &points, center_t &center, const coeffs_t &coeffs) {
    for (int i = 0; i < points.rows; i++) {
        movePoint(points.data[i], coeffs);
    }

    moveCenter(center, coeffs);
}

void scalePoint(double *const point, const center_t &center, const coeffs_t &coeffs) {
    point[0] = center.x + coeffs.x * (point[0] - center.x);
    point[1] = center.y + coeffs.y * (point[1] - center.y);
    point[2] = center.z + coeffs.z * (point[2] - center.z);
}

void scalePoints(const points_t &points, const center_t &center, const coeffs_t &coeffs) {
    for (int i = 0; i < points.rows; i++) {
        scalePoint(points.data[i], center, coeffs);
    }
}

double getRadians(const double angle) {
    return angle * M_PI / 180;
}

void rotatePoint(double &first_point, double &second_point, const double sinus, const double cosine) {
    int first_pcopy = first_point, second_pcopy = second_point;

    first_point = first_pcopy * cosine + second_pcopy * sinus;
    second_point = second_pcopy * cosine - first_pcopy * sinus;
}

void rotatePoints(const points_t &points, const center_t &center, const coeffs_t &coeffs) {
    double sinx = sin(getRadians(coeffs.x));
    double siny = sin(getRadians(coeffs.y));
    double sinz = sin(getRadians(coeffs.z));

    double cosx = cos(getRadians(coeffs.x));
    double cosy = cos(getRadians(coeffs.y));
    double cosz = cos(getRadians(coeffs.z));

    for (int i = 0; i < points.rows; i++) {
        points.data[i][0] -= center.x;
        points.data[i][1] -= center.y;
        points.data[i][2] -= center.z;

        rotatePoint(points.data[i][1], points.data[i][2], sinx, cosx);
        rotatePoint(points.data[i][0], points.data[i][2], siny, cosy);
        rotatePoint(points.data[i][0], points.data[i][1], sinz, cosz);

        points.data[i][0] += center.x;
        points.data[i][1] += center.y;
        points.data[i][2] += center.z;
    }
}