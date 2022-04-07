#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtGui>

#include "area.h"

//<QtGui> в моей версии Qt не подключает библиотеки виджетов, поэтому каждый подключаю отдельно.
//Также не распознается библиотека <QTextCodec>,
//поэтому всё что связано с перекодировкой в русский алфавит закомментировано, интерфейс написан на английском

//#include <QTextCodec>
#include <QPushButton>
#include <QVBoxLayout>


class Window : public QWidget //класс окна
{
protected:
     //QTextCodec *codec;
     Area *area; // область отображения рисунка
     QPushButton *btn; //кнопка "завершить"
public:
    Window();
};

#endif // WINDOW_H
