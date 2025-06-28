#include "dummywhatsappnotifier.h"




DummyWhatsappNotifier::DummyWhatsappNotifier(QObject * parent): NotifierSource(parent)
{
  timer = new QTimer(this);  //creates a new timer tied to this class
  connect(timer,&QTimer::timeout,this,&DummyWhatsappNotifier::checkForUpdates);
  timer->start(5000);

}


QString DummyWhatsappNotifier::SourceName() const
{
    return "WhatsApp";
}

void DummyWhatsappNotifier::checkForUpdates()
{
    emit newNotification("WhatApp","Dummy Message recieved!",QDateTime::currentDateTime());
}
