#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "receiver.h"
#include "sender.h"

const int NUMBER_OF_CLIENTS = 3;

void displayMenu();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create our server
    Sender server{nullptr, 23, "Hello Server"};

    // Create our clients (3 of them)
    Receiver* clients[NUMBER_OF_CLIENTS];

    clients[0] = new Receiver{&server};
    clients[1] = new Receiver{&server};
    clients[2] = new Receiver{&server};

    // First connect our quit signal of server object to our Application quit slot so that, when quit signal is emitted, the application shuts itself down.
    server.connect(&server, &Sender::quitApplication, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    do {
        displayMenu();

        // Get menu choice
        QTextStream inputStream(stdin);
        QString line = inputStream.readLine().trimmed().toUpper();

        if (line == "ON") {
            for (auto client : clients) {
                // If the server is ON, send message signal will be connected to receive message slot of the receiver object
                client->connect(&server, &Sender::sendMessage, client, &Receiver::receiveMessage);
            }

            qInfo() << "";
            qInfo() << "All clients are connected!";
            qInfo() << "";
        }

        else if (line == "OFF") {
            for (auto client : clients) {
                // If the server is OFF, send message signal will be disconnected from receive message slot of the receiver object
                client->disconnect(&server, &Sender::sendMessage, client, &Receiver::receiveMessage);
            }

            qInfo() << "";
            qInfo() << "All clients are disconnected!";
            qInfo() << "";
        }

        else if (line == "SEND") {
            qInfo() << "";
            qInfo() << "Please enter your message: ";

            // Read message input
            QTextStream messageStream(stdin);
            QString message = inputStream.readLine();

            // Send it to the all receiver objects with a proper signal
            emit server.sendMessage(message);
        }

        else if (line == "QUIT") {
            qInfo() << "";
            qInfo() << "Quitting the application...";
            qInfo() << "";

            // Signal quitting to the main application so that it can shut down the program.
            emit server.quitApplication();
            break;
        }

        else {
            qInfo() << "Entered invalid input, try again.";
            qInfo() << "";
        }

    } while(true);

    // Free the memory
    delete clients[0];
    delete clients[1];
    delete clients[2];

    return a.exec();
}

void displayMenu() {
    qInfo() << "******************************";
    qInfo() << "Please enter your choice: ";
    qInfo() << "ON to open the server ";
    qInfo() << "OFF to close the server ";
    qInfo() << "SEND to send message to clients";
    qInfo() << "QUIT application ";
    qInfo() << "******************************";
    qInfo() << "";
    qInfo() << "Enter your choice: ";
}
