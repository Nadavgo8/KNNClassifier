#include "CLI.h"

CLI::CLI(SocketIO sio) : sio(std::move(sio)) {
    initCommands();
    this->first = true;
    this->ci = ClientInfo();
}
CLI::~CLI() {
    for (auto &command: commands) {
        delete command;
    }
}
void CLI::initMenu() {
    string s;
    for (auto &command: this->commands) {
        s += command->getDescription();
    }
    s += "8. exit";
    (dynamic_cast<PrintMenuServer *>(this->commands[0]))->setMenu(s);
}
void CLI::initCommands() {
    this->commands[0] = new PrintMenuServer(this->sio);
    this->commands[1] = new UploadDataServer(this->sio);
    this->commands[2] = new AlgorithmServer(this->sio);
    this->commands[3] = new ClassifyDataServer(this->sio);
    this->commands[4] = new DisplayResultsServer(this->sio);
    this->commands[5] = new DownloadResultsServer(this->sio);
}
void CLI::start() {
    while (true) {
        if (this->first) {
            initMenu();
            this->first = false;
            this->commands[MENU]->execute(this->ci);
        }
        string choice = this->sio.read();
        if (choice.empty()) {
            break;
        }
        int option = convertToPositive(choice, K);
        commands[option]->execute(this->ci);
    }
}

