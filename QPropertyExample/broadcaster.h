#ifndef BROADCASTER_H
#define BROADCASTER_H

#include <QObject>

class Broadcaster : public QObject
{
    Q_OBJECT

private:
    QString inputMessage;

public:
    explicit Broadcaster(QObject *parent = nullptr);

    Q_PROPERTY(QString message READ getMessage WRITE setMessage NOTIFY sendMessage)

    QString getMessage();
    void setMessage(QString message);

signals:
    void sendMessage(QString message);
};

#endif // BROADCASTER_H
