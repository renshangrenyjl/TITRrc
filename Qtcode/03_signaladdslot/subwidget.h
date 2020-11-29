#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent =0);
     void  sendslot();
signals:
    void mysignal();
   void  mysignal(int,QString );
public slots:
    private:
    QPushButton b;
};

#endif // SUBWIDGET_H
