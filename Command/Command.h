#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../Correctness.h"
#include "../Distance/Knn.h"
#include "../Files/FileReader.h"
#include "../Files/FileWriter.h"
#include "../Communication/DefaultIO.h"
#include "../Communication/ClientInfo.h"

#define COMMANDS 6

using namespace std;

/**
* Class name: Command
* The abstract class is responsible for performing and implementing the 'Command' design pattern.
* It has two extensions: "CommandServer" and "CommandClient",
* each having five extensions for each specific command in the program's menu.
*/
class Command {
protected:
    DefaultIO &defaultIo;
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO (SocketIO or StandardIO for server and client respectively).
    */
    explicit Command(DefaultIO &dio) : defaultIo(dio) {};
    /**
    * destructor.
    */
    virtual ~Command() = default;
    /**
    * Function name: execute
    * The function, which is implemented differently in each extending command,
    * executes the command's operation for the user's choice in the menu.
    * @param ci - the client info.
    */
    virtual void execute(ClientInfo &ci) = 0;
};

#endif
