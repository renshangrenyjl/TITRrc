#include "mybutton.h"
#include <QDebug>
mybutton::mybutton(QWidget *parent) : QPushButton(parent)//通过构造函数列表给基类传参

{

}
mybutton::~mybutton()
{
    qDebug()<<"按钮被析构";

}
