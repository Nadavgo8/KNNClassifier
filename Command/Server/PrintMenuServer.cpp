#include "CommandServer.h"

PrintMenuServer::PrintMenuServer(DefaultIO &dio) : CommandServer(dio) {
    this->description = "Welcome to the KNN Classifier Server. Please choose an option:\n";
}
string PrintMenuServer::getDescription() {
    return this->description;
}
void PrintMenuServer::setMenu(string newMenu) {
    this->menu = std::move(newMenu);
}
void PrintMenuServer::execute(ClientInfo &ci) {
    this->defaultIo.write(this->menu);
}