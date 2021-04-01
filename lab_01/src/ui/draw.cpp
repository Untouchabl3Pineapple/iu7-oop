#include "draw.h"
    
canvas_t &initCanvas(Ui::MainWindow *ui) {
    static canvas_t canvas;

    canvas.scene = ui->graphicsView->scene();

    return canvas;
}

void canvasClear(const canvas_t &canvas) {
    canvas.scene->clear();
}

void drawEdge(double *const first_point, double *const second_point, const canvas_t &canvas) {
    canvas.scene->addLine(
        first_point[0],
        first_point[1],
        second_point[0],
        second_point[1]
   );
}

void drawEdges(const points_t &points, const edges_t &edges, const canvas_t &canvas) {
    for (int i = 0; i < edges.rows; i++) {
        drawEdge(points.data[edges.data[i][0]], points.data[edges.data[i][1]], canvas);
    }
}