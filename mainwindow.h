#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dummywhatsappnotifier.h"
#include <QVBoxLayout>

#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

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
    void handleIncomingNotification();

private:
    Ui::MainWindow *ui;
    DummyWhatsappNotifier *wa;
    QVBoxLayout *whatsappLayout;
    QProcess * notifProcess;

};
#endif // MAINWINDOW_H
