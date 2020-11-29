#include <QApplication>
#include<QWidget>
#include<QPushButton>
int main(int argc ,char **argv)
{
    QApplication app(argc,argv);
    QWidget w;
    w.setWindowTitle(QString("万物皆可算法"));

    QPushButton b;
    b.setText("-_-");
    b.setParent(&w);
    b.move(600,600);
    QPushButton b2(&w);
    b2.setText("^-^");
    b2.move(800,600);

     w.show();
    app.exec();
    return 0;
}
