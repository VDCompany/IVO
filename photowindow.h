#ifndef PHOTOWINDOW_H
#define PHOTOWINDOW_H

#include <QDialog>

namespace Ui {
class PhotoWindow;
}

class PhotoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PhotoWindow(QWidget *parent = nullptr);
    ~PhotoWindow();

private:
    Ui::PhotoWindow *ui;
};

#endif // PHOTOWINDOW_H
