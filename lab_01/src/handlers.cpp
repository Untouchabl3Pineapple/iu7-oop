#include "handlers.h"

int requestHandler(const request_t &request) {
    int ret_code = OK;
    static model_t model = initModel();

    switch (request.command) {
        case LOAD: {
            ret_code = downloadModel(model, request.filename);
            break;
        }
        case DRAW: {
            ret_code = drawModel(model, request.canvas);
            break;
        }
        case MOVE: {
            ret_code = moveModel(model, request.coeffs);
            break;
        }
        case SCALE: {
            ret_code = scaleModel(model, request.coeffs);
            break;
        }
        case ROTATE: {
            ret_code = rotateModel(model, request.coeffs);
            break;
        }
        case QUIT: {
            freeModel(model);
            break;
        }
        default: {
            ret_code = UNKNOWN_COMMAND;
        }
    }

    return ret_code;
}

void errorHandler(const int ret_code) {
    switch (ret_code) {
        case ERR_MEMORY_ALLOC: {
            QMessageBox::critical(NULL, "Ошибка", "Неудалось выделить память под модель.");
            break;
        }
        case ERR_MEMORY: {
            QMessageBox::critical(NULL, "Ошибка", "Модель не загружена.");
            break;
        }
        case ERR_MODEL_CENTER: {
            QMessageBox::critical(NULL, "Ошибка", "Неккоретные данные центра в файле модели");
            break;
        }
        case ERR_MODEL_POINTS: {
            QMessageBox::critical(NULL, "Ошибка", "Неккоретные данные точек в файле модели");
            break;
        }
        case ERR_MODEL_EDGES: {
            QMessageBox::critical(NULL, "Ошибка", "Неккоретные данные ребер в файле модели");
            break;
        }
        case ERR_FILE_OPEN: {
            QMessageBox::critical(NULL, "Ошибка", "Неудалось открыть файл модели.");
            break;
        }
        default:
            QMessageBox::critical(NULL, "Ошибка", "Неизвестная комманда.");
    }
}