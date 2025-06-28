#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dummywhatsappnotifier.h"
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void handleNotification(QString title, QString message, QDateTime dt );

private:
    Ui::MainWindow *ui;
    DummyWhatsappNotifier *wa;
    QVBoxLayout *whatsappLayout;

};
#endif // MAINWINDOW_H
