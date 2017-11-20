#ifndef EULER_H
#define EULER_H

#include <QMainWindow>

namespace Ui {
class Euler;
}

class Euler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Euler(QWidget *parent = 0);
    ~Euler();
    double oper(double a);
    double oper2(double b);


private:
    Ui::Euler *ui;

public slots:

    void metodo();//The functions slots for the program are declared
    void borrar();
};

#endif // EULER_H
