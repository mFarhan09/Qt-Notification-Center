#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Notification Center");

    // Create layout in code and assign it to the container
    whatsappLayout = new QVBoxLayout;
    ui->whatsappContainer->setLayout(whatsappLayout);

    notifProcess = new QProcess(this);
    connect (notifProcess,&QProcess::readyReadStandardOutput,this,&MainWindow::handleIncomingNotification);
     //start the python script
    QString pythonPath = "C:/Users/farhan/AppData/Local/Programs/Python/Python312/python.exe";
    QString scriptPath = "C:/Users/farhan/Desktop/Summer2025/3_Phase1_Qt/6_NotificationCenter/NotificationCenter/notifier.py";

    notifProcess->start(pythonPath, QStringList() << scriptPath);


      if(!notifProcess->waitForStarted())
      {
          qDebug()  << "Process Failed to start : " << notifProcess->errorString();
      }
      else
      {
          qDebug() << "Process started Sucessfully!" ;
      }
   //  wa = new DummyWhatsappNotifier(this);
   //  connect(wa,&DummyWhatsappNotifier::newNotification,this,&MainWindow::handleNotification);

}
//handle incoming notification
void MainWindow::handleIncomingNotification()
{
    while (notifProcess->canReadLine()) {
          QByteArray line = notifProcess->readLine().trimmed();

          QJsonParseError err;
          QJsonDocument doc = QJsonDocument::fromJson(line, &err);
          if (err.error != QJsonParseError::NoError) {
              qDebug() << "JSON parse error:" << err.errorString();
              continue;
          }

          QJsonObject obj = doc.object();
          QString source = obj["source"].toString();
          QString title = obj["title"].toString();
          QString msg = obj["message"].toString();
          QDateTime ts = QDateTime::fromString(obj["timestamp"].toString(), Qt::ISODate);

          // Route to your signal-based card display
          handleNotification(source,msg,ts);
      }
}



//handle notification
void MainWindow::handleNotification(QString title, QString message, QDateTime dt)
{
    // Create the card container
       QWidget *card = new QWidget;
       QVBoxLayout *cardLayout = new QVBoxLayout(card);

       QLabel *titleLabel = new QLabel("<b>" + title + "</b>");
       QLabel *messageLabel = new QLabel(message);
       QLabel *timeLabel = new QLabel(dt.toString("hh:mm:ss dd-MM-yyyy"));

       // Optional: customize font or spacing
       titleLabel->setStyleSheet("font-size: 16px;");
       messageLabel->setStyleSheet("color: #333;");
       timeLabel->setStyleSheet("font-size: 11px; color: gray;");

       // Assemble card
       cardLayout->addWidget(titleLabel);
       cardLayout->addWidget(messageLabel);
       cardLayout->addWidget(timeLabel);
       cardLayout->setSpacing(4);
       cardLayout->setContentsMargins(10, 10, 10, 10);

       // Style the card widget
       card->setStyleSheet("background-color: #e3f2fd; border: 1px solid #90caf9; border-radius: 8px;");

       // Add the card to the vertical layout
       whatsappLayout->addWidget(card);
}




MainWindow::~MainWindow()
{
    delete ui;
}

