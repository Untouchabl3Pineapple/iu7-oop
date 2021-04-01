#ifndef __HANDLERS_H__
#define __HANDLERS_H__

#include <QMessageBox>

#include "ret_codes.h"
#include "model.h"
#include "draw.h"
#include "points.h"

enum commands {
    LOAD,
    DRAW,
    MOVE,
    SCALE,
    ROTATE,
    QUIT
};

struct request_t {
    int command;
    char const *filename;
    canvas_t canvas;
    coeffs_t coeffs;
};

int requestHandler(const request_t &request);
void errorHandler(const int ret_code);

#endif // __HANDLERS_H__