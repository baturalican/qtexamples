#include <QDebug>
#include "receiver.h"

Receiver::Receiver(QObject *parent) {

}

// When a signal is get from the corresponding signal function, this function is called
void Receiver::receivedMessage(QString message) {
    qInfo() << "Received message is: " << message;
}
