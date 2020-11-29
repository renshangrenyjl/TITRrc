#include "subwidget.h"

subwidget::subwidget(QWidget *parent) : QWidget(parent)
{
  this->setWindowTitle("小弟");
    b.setParent(this);
    b.setText("切换到子窗口");
   connect(&b,&QPushButton::clicked,this,&subwidget::sendslot);

   resize(400,300);
}
void  subwidget::sendslot()
{
    emit mysignal();
    emit mysignal(250,"你配吗");
}
