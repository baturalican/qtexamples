#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT

public:
    explicit Receiver(QObject* parent = nullptr);

public slots:
    // Slot prototype
    void receivedMessage(QString message);
};

#endif // RECEIVER_H
