#include "photowindow.h"
#include "ui_photowindow.h"

PhotoWindow::PhotoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhotoWindow)
{
//    pix->void setScaledContents(bool);
    ui->setupUi(this);
    QPixmap p("V:/VTP/VTP/K.jpg");

//    QImage img;

//    p.convertFromImage(img, Qt::AutoColor);

   QSize imageSize(500,500);
    QSize labelSize = ui->pix->size();

//    if ((imageSize.height()>labelSize.height()) || (imageSize.width()>labelSize.width()))
//       imageSize.scaled(labelSize,Qt::KeepAspectRatio);
    p=p.scaled(imageSize,Qt::KeepAspectRatio);
    ui->pix->setPixmap(p);
//    ui->pix->repaint();
}

PhotoWindow::~PhotoWindow()
{
    delete ui;
}
