#include <QDebug>
#include "receiver.h"

Receiver::Receiver(QObject *parent) : QObject(parent) {

}

void Receiver::receiveMessage(QString message) {
    qInfo() << "Message is: " << message;
}
