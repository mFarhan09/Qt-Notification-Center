#ifndef DUMMYWHATSAPPNOTIFIER_H
#define DUMMYWHATSAPPNOTIFIER_H

#include "notificationsource.h"
#include <QObject>
#include <QTimer>

class DummyWhatsappNotifier : public NotifierSource
{
    Q_OBJECT
public:
    explicit DummyWhatsappNotifier(QObject * parent = nullptr);

     QString SourceName() const override;

signals:

public slots:
     void checkForUpdates() override;

private:
     QTimer * timer;
};

#endif // DUMMYWHATSAPPNOTIFIER_H
