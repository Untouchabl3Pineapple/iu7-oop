#ifndef __DRAW_H__
#define __DRAW_H__

#include "ui_mainwindow.h"
#include "model_struc.h"

struct canvas_t {
    QGraphicsScene *scene;
};

canvas_t &initCanvas(Ui::MainWindow *ui);

void canvasClear(const canvas_t &canvas);

void drawEdge(double *const first_point, double *const second_point, const canvas_t &canvas);
void drawEdges(const points_t &points, const edges_t &edges, const canvas_t &canvas);

#endif // __DRAW_H__