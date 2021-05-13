#include <QCoreApplication>
// We add QVariant library here so that in setProperty function below, second parameter can be converted to QVariant type automatically.
#include <QVariant>
#include "broadcaster.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create one message publisher object and one subscriber object
    Broadcaster station;
    Receiver radio;

    // Connect signal & slot of the publisher and subscriber objects respectively
    QObject::connect(&station, &Broadcaster::sendMessage, &radio, &Receiver::receiveMessage);

    // Use Q_PROPERTY field of the publisher object (Broadcaster class) to set message variable to "Hey something"
    // First, in the Broadcaster class, setMessage function will be called
    // Then, sendMessage signal will be sent to radio object (Receiver class)
    // After that, radio object will run its slot function which is receiveMessage
    // Finally, the message "This has to be something" will appear on the command line

    station.setProperty("message", "This has to be something");

    return a.exec();
}
