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




     QCPCurve *fermatSpiral1 = new QCPCurve(ui->widget_2->xAxis, ui->widget_2->yAxis);
     QCPCurve *deltoidRadial = new QCPCurve(ui->widget_2->xAxis, ui->widget_2->yAxis);
     // generate the curve data points:
     const int pointCount = 500;

     QVector<QCPCurveData> dataSpiral(pointCount), dataSpiral1(pointCount);
     for (int i=0; i<pointCount; ++i)
     {
        double phi = i/(double)(pointCount-1)*2*M_PI;

       dataSpiral[i] = QCPCurveData(i, qCos(phi), qSin(phi));
       dataSpiral1[i]=QCPCurveData(i, 2*qCos(phi), qSin(phi));

     }
     // pass the data to the curves; we know t (i in loop above) is ascending, so set alreadySorted=true (saves an extra internal sort):
     fermatSpiral1->data()->set(dataSpiral1, true);
     deltoidRadial->data()->set(dataSpiral, true);
     // color the curves:
     fermatSpiral1->setPen(QPen(Qt::blue));
 //    fermatSpiral1->setBrush(QBrush(QColor(0, 0, 255, 20)));
 //    fermatSpiral2->setPen(QPen(QColor(255, 120, 0)));
 //    fermatSpiral2->setBrush(QBrush(QColor(255, 120, 0, 30)));

     deltoidRadial->setPen(QPen(QColor(Qt::red)));
    // deltoidRadial->setBrush(QBrush(radialGrad));
     // set some basic customPlot config:
//     ui->widget_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget_2->axisRect()->setupFullAxesBox();
    ui->widget_2->xAxis->setRange(-4, 4);
     ui->widget_2->yAxis->setRange(-4,4);
//     ui->widget_2->rescaleAxes();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



     scene = new QGraphicsScene(0,0,420,420,this);
     ui->graphicsView->setScene(scene);



     QBrush greenBrush(Qt::green);
     QBrush blueBrush(Qt::blue);
     QPen outlinePen(Qt::black);
     outlinePen.setWidth(2);

     rectangle = scene->addRect(100, 0, 20, 20, outlinePen, blueBrush);
     rectangle->setFlag(QGraphicsItem::ItemIsMovable);


     rectangle1 = scene->addRect(0, 0, 20, 20, outlinePen, blueBrush);
     rectangle1->setFlag(QGraphicsItem::ItemIsMovable);

     rectangle2 = scene->addRect(50, 0, 20, 20, outlinePen, blueBrush);
     rectangle2->setFlag(QGraphicsItem::ItemIsMovable);

     rectangle3 = scene->addRect(70, 0, 20, 20, outlinePen, blueBrush);
     rectangle3->setFlag(QGraphicsItem::ItemIsMovable);



      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////












}

void MainWindow::aButtonClicked()
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

