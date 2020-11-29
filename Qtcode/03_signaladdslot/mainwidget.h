#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPushButton>
#include "subwidget.h" //子窗口头文件
class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
     void myslot();
     void changwin();
     void  dealsub();
     void  dealslot(int ,QString) ;
private:
   QPushButton b1;
   QPushButton *b2;
   QPushButton b3;
   subwidget w;
};
#endif // MAINWIDGET_H
