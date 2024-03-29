#ifndef SENDER_H
#define SENDER_H

#include <QObject>

class Sender : public QObject
{
    Q_OBJECT

public:
    explicit Sender(QObject *parent = nullptr);

    void test();

signals:
    // Signal prototype
    void mySignal(QString message);
};

#endif // SENDER_H
