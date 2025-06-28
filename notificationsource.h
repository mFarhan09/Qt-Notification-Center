#ifndef NOTIFICATIONSOURCE_H
#define NOTIFICATIONSOURCE_H

#include <QObject>
#include <QString>
#include <QDateTime>

class NotifierSource : public QObject
{
    Q_OBJECT
public:
    explicit  NotifierSource(QObject *parent = nullptr);
    virtual  QString SourceName() const = 0;
  virtual  ~NotifierSource();

signals:
    void newNotification(QString title,QString message, QDateTime timestamp);

public slots:
    virtual void checkForUpdates() = 0;

};





#endif // NOTIFICATIONSOURCE_H
