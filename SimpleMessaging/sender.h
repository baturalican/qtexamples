#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr, int id = 0, QString name = "");

private:
    int id;
    QString name;

signals:
    void sendMessage(QString message);
    void quitApplication();
};

#endif // SENDER_H
