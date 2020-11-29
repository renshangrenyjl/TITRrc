#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include<QToolBar>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QTextEdit>
#include<QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    QMenu *pFile = mBar->addMenu("文件");
    QAction *pNew =  pFile->addAction("新建");
    connect(pNew,&QAction::triggered,
          [=]()
      {
        qDebug()<<"新建被按下";
       }
           );
   pFile->addSeparator();//添加下划线
   QAction *popen = pFile->addAction("打开");
   QToolBar *toolbar = addToolBar("toolbar");
   toolbar->addAction(pNew);
   QPushButton *b =new QPushButton(this);
   b->setText("@_@");
   toolbar->addWidget(b);
   connect(b,&QPushButton::clicked,
          [=]()
   {
   b->setText("￥—￥");
   }
);
   QStatusBar *sBar =statusBar();
   QLabel *label =new QLabel(this);
   label->setText("apple is badly");
   sBar->addWidget(label);
   sBar->addWidget(new QLabel("2",this));
   sBar->addPermanentWidget(new QLabel("3",this));
 //核心控件
   QTextEdit *textEdit =new QTextEdit(this);
   setCentralWidget(textEdit);
   //浮动窗口
   QDockWidget *dock =new QDockWidget(this);
   addDockWidget(Qt::RightDockWidgetArea,dock);
   //给浮动窗口添加控件
   QTextEdit *textEdit1 =new QTextEdit(this);
   dock->setWidget(textEdit1 );
}

MainWindow::~MainWindow()
{
}

