#include "CommandClient.h"

void PrintMenuClient::execute(ClientInfo& ci) {
    this->defaultIo.write(this->socketIo.read());
}
