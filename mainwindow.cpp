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

     wa = new DummyWhatsappNotifier(this);
     connect(wa,&DummyWhatsappNotifier::newNotification,this,&MainWindow::handleNotification);

}

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

