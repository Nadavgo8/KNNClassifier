#include "CommandClient.h"

void ClassifyDataClient::execute(ClientInfo& ci) {
    this->defaultIo.write(this->socketIo.read());
}