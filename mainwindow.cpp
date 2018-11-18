#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "photowindow.h"

bool check=false;
bool check1=false;
bool check2=false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->label_26->hide();
    ui->label_28->hide();
    ui->label_29->hide();
    ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton->setStyleSheet("* {background-color:red}");
    ui->pushButton_2->setStyleSheet("* {background-color:green}");
    ui->pushButton_3->setStyleSheet("* {background-color:#0077D6}");
    setStyleSheet("*{background-color: #F5F5CF;}");

      connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(aButtonClicked()));
      connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(aButtonClicked()));
      // create empty curve objects:
     QVector<double> x(1000), y(1000);
     for (int i = 0; i < 1000; ++i) {
         x[i]=qSin(i);
         y[i]=2*qCos(i);
     }
     QVector<double> x1(1000), y1(1000);
     for (int i = 0; i < 1000; ++i) {
         x1[i]=2*qSin(i);
         y1[i]=qCos(i);
     }

     ui->widget_2->addGraph();
     ui->widget_2->graph(0)->setData(x,y);
//     ui->widget_2->xAxis->setLabel("x");
//     ui->widget_2->yAxis->setLabel("y");
     ui->widget_2->addGraph();
     ui->widget_2->graph(1)->setData(x1,y1);
     ui->widget_2->graph(1)->setPen(QPen(Qt::red));
     ui->widget_2->xAxis->setRange(-5,5);
//     ui->widget_2->graph(0)->rescaleAxes();
//     ui->widget_2->graph(1)->rescaleAxes(true);

     ui->widget_2->yAxis->setRange(-5,5);
     ui->widget_2->replot();












//      //Рисуем график y=x*x

//          //Сгенерируем данные
//          //Для этого создадим два массива точек:
//          //один для созранения x координат точек,
//          //а второй для y соответственно

//          double a = 0; //Начало интервала, где рисуем график по оси Ox
//          double b =  100; //Конец интервала, где рисуем график по оси Ox
//          double h = 1; //Шаг, с которым будем пробегать по оси Ox

//          int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
//          QVector<double> x(N), y(N); //Массивы координат точек

//          //Вычисляем наши данные
//          int i=0;
//          for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
//          {
//              x[i] = X;
//              y[i] = X*X;//Формула нашей функции
//              i++;
//          }

//          ui->widget->clearGraphs();//Если нужно, но очищаем все графики
//          //Добавляем один график в widget
//          ui->widget->addGraph();
//          //Говорим, что отрисовать нужно график по нашим двум массивам x и y
//          ui->widget->graph(0)->setData(x, y);

//          //Подписываем оси Ox и Oy
//          ui->widget->xAxis->setLabel("x");
//          ui->widget->yAxis->setLabel("y");

//          //Установим область, которая будет показываться на графике
//          ui->widget->xAxis->setRange(a, b);//Для оси Ox

//          //Для показа границ по оси Oy сложнее, так как надо по правильному
//          //вычислить минимальное и максимальное значение в векторах
//          double minY = y[0], maxY = y[0];
//          for (int i=1; i<N; i++)
//          {
//              if (y[i]<minY) minY = y[i];
//              if (y[i]>maxY) maxY = y[i];
//          }
//          ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

//          //И перерисуем график на нашем widget
//          ui->widget->replot();



}

void MainWindow::aButtonClicked() //change "class" to your class its name
{
  check=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    check1=true;
    ui->stackedWidget->setCurrentIndex(2);

    ui->groupBox_4->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    check1=false;
    ui->stackedWidget->setCurrentIndex(0);
    ui->groupBox_4->show();
    ui->label_3->hide();
    ui->label_9->hide();
    ui->spinBox_7->hide();
    ui->spinBox_8->hide();
    ui->label->setText("РП_1(левый)");
    ui->label_4->setText("РП_3(правый)");
    ui->label_26->show();
    ui->label_28->show();
    ui->label_29->show();


}

void MainWindow::on_pushButton_clicked()
{
    check1=false;
    ui->stackedWidget->setCurrentIndex(1);
    ui->groupBox_4->show();
    ui->label_3->show();
    ui->label_9->show();
    ui->spinBox_7->show();
    ui->spinBox_8->show();
    ui->label->setText("СКО угла места");
    ui->label_4->setText("Угл места");
    ui->label_26->hide();
    ui->label_28->hide();
    ui->label_29->hide();


}

void MainWindow::on_spinBox_5_valueChanged(int arg1)
{
   if (((ui->spinBox_5->value())<2) && (check1==true)) {ui->stackedWidget_2->setCurrentIndex(1);}
    else ui->stackedWidget_2->setCurrentIndex(0);
//    if (ui->spinBox_5->value() == 1){
//        ui->label_57->hide();}
}


void MainWindow::on_pushButton_4_clicked()
{
    window = new PhotoWindow;
    window->show();

}

