#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>
#include <QWidget>

class Figura //класс фигура
{
protected:
     int x, y, //координаты
     halflen,
     dx, dy, //приращение координат при повороте
     r;
     virtual void draw(QPainter *Painter) = 0; // рисование: чисто виртуальный метод, реализован в наследниках
public:
     Figura(int X,int Y,int Halflen) : x(X),y(Y), halflen(Halflen){}
     void move(float Alpha,QPainter *Painter);
};


class MyLine : public Figura //класс линия (наследник фигуры)
{
protected:
     void draw(QPainter *Painter); //рисовнание линии
public:
    MyLine(int x,int y,int halflen) : Figura(x,y,halflen){}
};


class MyRect : public Figura //класс квадрат (наследник фигуры)
{
protected:
     void draw(QPainter *Painter); //рисовнание квадрата
public:
     MyRect(int x,int y,int halflen) : Figura(x,y,halflen){}
};

#endif // FIGURA_H
