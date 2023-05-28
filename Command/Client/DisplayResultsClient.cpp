#include "CommandClient.h"

void DisplayResultsClient::execute(ClientInfo &ci) {
    string message = this->socketIo.read();
    if (message == "please upload data" || message == "please classify the data") {
        this->defaultIo.write(message);
        return;
    }
    while (message != "Done.") {
        this->defaultIo.write(message);
        message = this->socketIo.read();
    }
    this->defaultIo.write(message);
}