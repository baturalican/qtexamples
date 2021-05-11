#include "sender.h"

Sender::Sender(QObject *parent) {

}

// This function emits a signal to correspondent slot(s)
void Sender::test() {
    emit mySignal("Hello something from sender to receiver");
}
