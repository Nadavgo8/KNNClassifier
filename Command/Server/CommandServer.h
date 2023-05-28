#ifndef COMMANDSERVER_H
#define COMMANDSERVER_H

#include "../Command.h"

/**
* Class name: CommandServer
* The abstract class is responsible for performing and implementing the
* 'Command' design pattern for all commands on the server's side.
* It has five extensions: one for each specific command in the program's menu.
*/
class CommandServer : public Command {
protected:
    string description;
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO.
    */
    explicit CommandServer(DefaultIO &dio) : Command(dio), description("Default Command") {}
    /**
    * destructor.
    */
    ~CommandServer() override = default;
    virtual string getDescription() = 0;
    void execute(ClientInfo& ci) override = 0;
};
class PrintMenuServer : virtual public CommandServer {
private:
    string menu;
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO.
    */
    explicit PrintMenuServer(DefaultIO &dio);
    /**
    * Function name: setMenu
    * The function sets 's' which will represent the menu strings.
    * @param newMenu - the menu string.
    */
    void setMenu(string newMenu);
    /**
     * Getter method
     * @return description field
     */
    string getDescription() override;
    /**
    * Function name: execute
    * The function sends the menu (it's in 's') to the client.
    * @param ci - the client info.
    */
    void execute(ClientInfo& ci) override;
};
class UploadDataServer : virtual public CommandServer {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO.
    */
    explicit UploadDataServer(DefaultIO &dio);
    string getDescription() override;
    /**
    * Function name: execute
    * The function receives two file contents from the user and saves them into the 'train' and 'test' files in ci.
    * @param ci - the client info.
    */
    void execute(ClientInfo& ci) override;
};
class AlgorithmServer : virtual public CommandServer {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO.
    */
    explicit AlgorithmServer(DefaultIO &dio);
    string getDescription() override;
    /**
    * Function name: execute
    * The function sends the current 'K' and 'metric' to the client and receives back the user input.
    * If the input is invalid or empty, no change will occur.
    * Otherwise, it'll change the 'K' and 'metric'.
    * @param ci - the client info.
    */
    void execute(ClientInfo& ci) override;
};
class ClassifyDataServer : virtual public CommandServer {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO.
    */
    explicit ClassifyDataServer(DefaultIO &dio);
    string getDescription() override;
    /**
    * Function name: execute
    * The function creates a classified file called "knn.csv" using the K and metric in the ClientInfo.
    * If one of the test or train files doesn't exist, it sends the client a message requesting to upload them.
    * @param ci - the client info.
    */
    void execute(ClientInfo& ci) override;
};
class DisplayResultsServer : virtual public CommandServer {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO.
    */
    explicit DisplayResultsServer(DefaultIO &dio);
    string getDescription() override;
    /**
    * Function name: execute
    * The function sends the client the results of the classification made on the test file.
    * If the files weren't uploaded or classified, a relevant message will be sent to the client.
    * @param ci - the client info.
    * */
    void execute(ClientInfo& ci) override;
};
class DownloadResultsServer : virtual public CommandServer {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO.
    */
    explicit DownloadResultsServer(DefaultIO &dio);
    string getDescription() override;
    /**
    * Function name: execute
     * The function sends the client the results of the classification made on the test file.
     * If the files weren't uploaded or classified, a relevant message will be sent to the client.
    * @param ci - the client info.
     * */
    void execute(ClientInfo& ci) override;
};

#endif
