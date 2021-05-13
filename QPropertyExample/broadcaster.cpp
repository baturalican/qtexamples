#include "broadcaster.h"

Broadcaster::Broadcaster(QObject *parent) : QObject(parent) {

}

QString Broadcaster::getMessage(){
    return inputMessage;
}

void Broadcaster::setMessage(QString message){
    inputMessage = message;
    emit sendMessage(inputMessage);
}
