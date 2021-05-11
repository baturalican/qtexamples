#include <QCoreApplication>
#include "sender.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create sender and creater objects
    Sender sender{};
    Receiver receiver{};

    // Connect them so that signal & slot functions know each other
    QObject::connect(&sender, &Sender::mySignal, &receiver, &Receiver::receivedMessage);

    sender.test();

    return a.exec();
}
