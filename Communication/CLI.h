#ifndef CLI_H
#define CLI_H

#include "ClientInfo.h"
#include "../Command/Command.h"
#include "../Command/Server/CommandServer.h"

/**
* Class name: CLI
* The class manages the program and commands for a specific client.
*/
class CLI {
private:
    bool first;
    SocketIO sio;
    ClientInfo ci;
    CommandServer *commands[COMMANDS]{};
    /**
    * Function name: initMenu
    * The function creates the menu string using the descriptions of the commands in "commands".
    * */
    void initMenu();
    /**
    * Function name: initCommands
    * The function creates and  fills the commands array.
    */
    void initCommands();
public:
    ~CLI();
    /**
    * Constructor
    * @param sio - SocketIO.
    */
    explicit CLI(SocketIO sio);
    /**
    * Function name: start
    * The function runs the program for the client and executes each command
    * according to the users input received from the client.
    */
    void start();
};

#endif
