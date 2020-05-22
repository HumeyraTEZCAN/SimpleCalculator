#include "mainwindow.h"
#include "ui_mainwindow.h"
double calcvalue=0.0;
bool divtrigger=false;
bool multrigger=false;
bool addtrigger=false;
bool subtrigger=false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   ui->lineEdit->setText(QString::number(calcvalue));
   QPushButton *numButtons[10];
   for(int i=0;i<10;i++){

       QString butName ="bt" +QString::number(i);
       numButtons[i] =MainWindow::findChild<QPushButton*>(butName);
       connect(numButtons[i],SIGNAL(released()),this,SLOT(NumPressed()));

   }
   connect(ui->plus,SIGNAL(released()),this,SLOT(MathButtonPressed()));
   connect(ui->mul,SIGNAL(released()),this,SLOT(MathButtonPressed()));
   connect(ui->minus,SIGNAL(released()),this,SLOT(MathButtonPressed()));
   connect(ui->div,SIGNAL(released()),this,SLOT(MathButtonPressed()));
   connect(ui->equal,SIGNAL(released()),this,SLOT(EqualButtonPressed()));
   connect(ui->setsign,SIGNAL(released()),this,SLOT(ChangeNumberSign()));





}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::NumPressed(){
    QPushButton *button =(QPushButton*)sender();
    QString butVal=button->text();
    QString displayVal =ui->lineEdit->text();
    if(displayVal.toDouble() == 0 || displayVal.toDouble()==0.0){

        ui->lineEdit->setText(butVal);

    }else{

        QString newValue = displayVal+butVal;
        double dblNewVal = newValue.toDouble();
        ui->lineEdit->setText(QString::number(dblNewVal,'g',16));




    }



}
void MainWindow::MathButtonPressed(){

    divtrigger=false;
    addtrigger =false;
    multrigger=false;
    subtrigger =false;
    QString displayvalue=ui->lineEdit->text();

    calcvalue = displayvalue.toDouble();
    QPushButton *button=(QPushButton*)sender();
    QString buttonvalue=button->text();
    if(QString::compare(buttonvalue,"/",Qt::CaseInsensitive)==0){
        divtrigger=true;

    }
    else if(QString::compare(buttonvalue,"*",Qt::CaseInsensitive)==0){
        multrigger=true;

    }
    else if(QString::compare(buttonvalue,"+",Qt::CaseInsensitive)==0){
        addtrigger=true;

    }
    else if(QString::compare(buttonvalue,"-",Qt::CaseInsensitive)==0){
        subtrigger=true;

    }

    ui->lineEdit->setText("");

}
void MainWindow::EqualButtonPressed(){

    double solution=0.0;
    QString displayval=ui->lineEdit->text();
    double dbldisplayvalue=displayval.toDouble();
  if(addtrigger||subtrigger||divtrigger||multrigger){

      if(addtrigger){
          solution=calcvalue+dbldisplayvalue;

      }
      else  if(subtrigger){
          solution=calcvalue-dbldisplayvalue;

      }
      else  if(multrigger){
          solution=calcvalue*dbldisplayvalue;

      }
      else  if(divtrigger){
          solution=calcvalue/dbldisplayvalue;

      }

      ui->lineEdit->setText(QString::number(solution));
  }


}
void MainWindow::ChangeNumberSign(){
    QString displayVal=ui->lineEdit->text();


    QRegExp reg("[-]?[0-9.]*");

    if(reg.exactMatch(displayVal)){

        double dbldisplayvalue = displayVal.toDouble();
        double dbldisplayvaluesign= -1*dbldisplayvalue;
        ui->lineEdit->setText(QString::number(dbldisplayvaluesign));



    }




}

void MainWindow::on_delete_2_clicked()
{
    ui->lineEdit->setText("");
}


