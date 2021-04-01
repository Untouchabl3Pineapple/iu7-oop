#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow(void) {
    request_t request;

    request.command = QUIT;

    requestHandler(request);

    delete ui;
}

int MainWindow::on_draw(void) {
    static canvas_t canvas = initCanvas(ui);
    request_t request;

    request.command = DRAW;
    request.canvas = canvas;

    int ret_code = requestHandler(request);

    return ret_code;
}

void MainWindow::on_loadButton_clicked(void) {
    request_t request;

    request.command = LOAD;
    request.filename = "../lab01/data/cubeModel.txt";

    int ret_code = requestHandler(request);
    if (ret_code != OK) {
        errorHandler(ret_code);
        return;
    }

    ret_code = on_draw();
    if (ret_code != OK) {
        errorHandler(ret_code);
    }
}

void MainWindow::on_moveButton_clicked(void) {
    coeffs_t coeffs;
    request_t request;

    coeffs.x = ui->dx_spbox->value();
    coeffs.y = ui->dy_spbox->value();
    coeffs.z = ui->dz_spbox->value();

    request.command = MOVE;
    request.coeffs = coeffs;

    int ret_code = requestHandler(request);
    if (ret_code != OK) {
        errorHandler(ret_code);
        return;
    }

    ret_code = on_draw();
    if (ret_code != OK) {
        errorHandler(ret_code);
    }
}

void MainWindow::on_scaleButton_clicked(void)
{
    coeffs_t coeffs;
    request_t request;

    coeffs.x = ui->kx_spbox->value();
    coeffs.y = ui->ky_spbox->value();
    coeffs.z = ui->kz_spbox->value();

    request.command = SCALE;
    request.coeffs = coeffs;

    int ret_code = requestHandler(request);
    if (ret_code != OK) {
        errorHandler(ret_code);
        return;
    }

    ret_code = on_draw();
    if (ret_code != OK) {
        errorHandler(ret_code);
    }
}

void MainWindow::on_rotateButton_clicked(void)
{
    coeffs_t coeffs;
    request_t request;

    coeffs.x = ui->ox_spbox->value();
    coeffs.y = ui->oy_spbox->value();
    coeffs.z = ui->oz_spbox->value();

    request.command = ROTATE;
    request.coeffs = coeffs;

    int ret_code = requestHandler(request);
    if (ret_code != OK) {
        errorHandler(ret_code);
        return;
    }

    ret_code = on_draw();
    if (ret_code != OK) {
        errorHandler(ret_code);
    }
}
