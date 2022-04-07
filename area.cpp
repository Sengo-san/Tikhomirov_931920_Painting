#include "area.h"

Area::Area(QWidget *parent) : QWidget(parent) //создание холста с линией и квадратом
{
    setFixedSize(QSize(300,200)); //размер холста
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}

void Area::showEvent(QShowEvent *) //включение таймера
{
     myTimer = startTimer(50); // создать таймер (50 мс)
}

void Area::paintEvent(QPaintEvent *) //рисование пошагово перемещающихся фигур
{
     QPainter painter(this); //перо
     painter.setPen(Qt::red); //цвет пера - красный
     myline->move(alpha,&painter); //перерисовка линии
     myrect->move(alpha*(-0.5),&painter); //перерисовка квадрата
}

void Area::timerEvent(QTimerEvent *event) //инициация перерисовки Холста
{
     if (event->timerId() == myTimer){ // если наш таймер
         alpha = alpha + 0.2;
         update(); // обновить внешний вид
     }
     else
     QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *) //выключение таймера
{
    killTimer(myTimer); // уничтожить таймер
}

Area::~Area() //деструктор. Класс-родитель (в смысле иерархии виджетов) холст отвечает за освобождение памяти от потомков (линии и квадрата)
{
 delete myline;
 delete myrect;
}
