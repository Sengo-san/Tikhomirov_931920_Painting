#include "window.h"

Window::Window()
{
     //codec = QTextCodec::codecForName("Windows-1251"); //таблица перекодировки для кириллицы
     //this->setWindowTitle(codec->toUnicode("Обработка событий"));
      this->setWindowTitle("Ivent processing"); //изменение имени окна
     area = new Area(this); //создание холста
    // btn = new QPushButton(codec->toUnicode("Завершить"), this );
     btn = new QPushButton("Finish", this); //создание кнопки "Завершить"

     //компановка
     QVBoxLayout *layout = new QVBoxLayout(this);
     layout->addWidget(area);
     layout->addWidget(btn);

     connect(btn, SIGNAL(clicked(bool)),this,SLOT(close())); //подключение сигнал кнопки "Завершить" и слот закрытия окна
};
