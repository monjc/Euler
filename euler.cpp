#include "euler.h"
#include "ui_euler.h"

Euler::Euler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Euler)
{
    ui->setupUi(this);
    connect(ui->procesar,SIGNAL(clicked()),this,SLOT(metodo())); //Connections slots-buttons
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

Euler::~Euler()
{
    delete ui;
}
double Euler::oper(double a)
{
   return ((-2*(a*a*a))+(12*(a*a))-(20*(a))+8.5);
}
double Euler::oper2(double b)
{
   return ((-0.5*(b*b*b*b))+(4*(b*b*b))-(10*(b*b))+(8.5*b)+1);
}
void Euler::metodo()
{
    QString temp,temp1,temp2,temp3,temp4; //The variables are declared
    double xi= ui->xi->value();
    double xfinal=ui->xfinal->value();
    double h=ui->h->value();
    double xi0 = 0, error = 0, yi = 0, yi1 = 0, it= 0;
    int i;

    it=(xfinal-xi)/h;

    for(i=0;i<it;i++)
    {
        yi1=oper2(xi0)+(oper(xi0)*h);  // The climax of the method
        xi0=(xi0+h);
        yi=oper2(xi0);//This is the real value of the function
        error=100*std::abs(yi1-yi)/yi1;  //The error is calculated

        temp.append("\n\ny(").append(temp1.setNum(xi0)).append(")=").append(temp2.setNum(yi1)).append("\nYreal=").append(temp3.setNum(yi)).append("\nError=").append(temp4.setNum(error)).append("%");

    }
    ui-> texto-> setText(temp);
}
void Euler::borrar()
{
    ui-> xi-> setValue ( 0.0 ); //The variables are cleared
    ui-> xfinal-> setValue ( 0.0 );
    ui-> h-> setValue ( 0.0 );
    ui-> texto-> clear();

 }
