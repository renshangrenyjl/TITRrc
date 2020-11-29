#include "mywidget.h"
#include<QPushButton>
#include "mybutton.h"
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{

    mybutton *b3 = new mybutton(this);
    b3->setText("1234");
    //move(100,100);
}

myWidget::~myWidget()
{
}

