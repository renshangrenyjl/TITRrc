#include "mainwindow.h"
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QFileDialog>
#include<QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   QMenuBar *mBar = menuBar();
   setMenuBar(mBar);
   QMenu *menu =mBar->addMenu("对话框");
   QAction *p3 =menu->addAction("关于对话框");
   connect(p3,&QAction::triggered,
           [=]()
   {
     QMessageBox::about(this,"about","关于qt");
   }
         );
   QAction *p4 =menu->addAction("关于对话框");
   connect(p4,&QAction::triggered,
           [=]()
   {
       int ret = QMessageBox::question(this,
                           "question","Are you ok?");
             switch(ret)
       {
        case QMessageBox::Yes:
             qDebug() << "i am ok";
            break;
        case QMessageBox::No:
        qDebug()<<"i am bad";
                  break;
          default:
               break;
   }
   }
         );
   QAction *p5 =menu->addAction("文件对话框");
   connect(p5,&QAction::triggered,
           [=]()
   {
      QString path = QFileDialog::getOpenFileName(
                this,
                "open",
                "../",
              "souce(*.cpp *.h);;Text(*.txt);;all(*.*)"
              );
      qDebug()<<path;
   }
         );
}

MainWindow::~MainWindow()
{
}

