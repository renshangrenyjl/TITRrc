#include "mainwidget.h"
#include <QPushButton>
#include<QDebug>//打印
mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{

    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("YOU");

    connect(&b1,&QPushButton::pressed,this,&mainWidget::close);
    connect(b2,&QPushButton::released,this,&mainWidget::myslot);
       connect(b2,&QPushButton::released,&b1,&QPushButton::hide);
       setWindowTitle("老夫");
       b3.setParent(this);
       b3.setText("切换到子窗口");
       b3.move(50,50);
  // w.show();


       connect(&b3,&QPushButton::released,this,&mainWidget::changwin);
       void(subwidget::*funsignal)()=&subwidget::mysignal;
       connect(&w,funsignal,this,&mainWidget::dealsub);
       void(subwidget::* testsignal)(int ,QString)=&subwidget::mysignal;
      connect(&w, testsignal,this,&mainWidget::dealslot);
     QPushButton *b4 =new QPushButton(this);
     b4->setText("Lambda表达式");
      b4->move(150,150);
      int a=10,c =100;
      connect(b4,&QPushButton::released,
              [=] () mutable
      {
           b4->setText("good");
           qDebug()<<"11111";
           qDebug()<<a<<c;
           a=11;
      }

              );
       resize(400,300);
}
void mainWidget::dealslot(int a , QString str)
{
    qDebug()<<a<<str.toUtf8().data();
}
void mainWidget::myslot()
{
  b2->setText("123") ;
}
void mainWidget::changwin()
{
  w.show() ;
  this->hide();
}
void mainWidget::dealsub()
{
  w.hide() ;
  show();
}
mainWidget::~mainWidget()
{
}

