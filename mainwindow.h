#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "photowindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void aButtonClicked();



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();



    void on_spinBox_5_valueChanged(int arg1);

   // void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_4_clicked();

//    void on_spinBox_5_valueChanged(const QString &arg1);

  //  void on_spinBox_5_valueChanged(const QString &arg1);

private:

    Ui::MainWindow *ui;
    PhotoWindow *window;







};

#endif
