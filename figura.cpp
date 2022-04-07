#include <math.h>
#include "figura.h"

void Figura::move(float Alpha, QPainter *Painter) //приращение координат при повороте
{
     dx = halflen * cos(Alpha);
     dy = halflen * sin(Alpha);
     draw(Painter);
}

void MyLine::draw(QPainter *Painter) //рисование линии
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy); //один конец смещается в одну сторону, другой - в другую
}

void MyRect::draw(QPainter *Painter) //рисование квадрата
{
    //квадрат рисуется как 4 линии, каждая смещена в соответствующую сторону при повороте
     Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
     Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
     Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
     Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
