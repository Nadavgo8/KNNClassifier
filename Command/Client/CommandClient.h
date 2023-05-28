#ifndef COMMANDCLIENT_H
#define COMMANDCLIENT_H

#include "../Command.h"

/**
* Class name: CommandClient
* The abstract class is responsible for performing and implementing the
* 'Command' design pattern for all commands on the client's side.
* It has five extensions: one for each specific command in the program's menu.
*/
class CommandClient : public Command {
protected:
    SocketIO socketIo;
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO - StandardIO.
    * @param sio - the SocketIO.
    */
    explicit CommandClient(DefaultIO &dio, SocketIO sio) : socketIo(std::move(sio)), Command(dio) {}
    /**
    * destructor.
    */
    ~CommandClient() override = default;
    void execute(ClientInfo &ci) override = 0;
};
class PrintMenuClient : virtual public CommandClient {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO - StandardIO.
    * @param sio - the SocketIO.
    */
    explicit PrintMenuClient(DefaultIO &dio, const SocketIO &sio) : CommandClient(dio, sio) {};
    /**
    * Function name: execute
    * The function reads the menu from the client info's 'socketIO' and prints it to the user.
    * @param ci - the client info.
    */
    void execute(ClientInfo &ci) override;
};
class UploadDataClient : virtual public CommandClient {
private:
    int testLength;
    int trainLength;
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO - StandardIO.
    * @param sio - the SocketIO.
    */
    explicit UploadDataClient(DefaultIO &dio, const SocketIO &sio) : CommandClient(dio, sio) {
        this->testLength = 0;
        this->trainLength = 0;
    }
    /**
    * Function name: execute
    * The function receives two files from the user and after validation sends them to the client info in the server.
    * @param ci - the client info.
    */
    void execute(ClientInfo &ci) override;
};
class AlgorithmClient : virtual public CommandClient {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO - StandardIO.
    * @param sio - the SocketIO.
    */
    explicit AlgorithmClient(DefaultIO &dio, const SocketIO &sio) : CommandClient(dio, sio) {}
    /**
    * Function name: execute
    * The function receives a 'K' and 'metric' from the user and if they pass the validation, sends them to the server.
    * @param ci - the client info.
    */
    void execute(ClientInfo &ci) override;
};
class ClassifyDataClient : virtual public CommandClient {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO - StandardIO.
    * @param sio - the SocketIO.
    */
    explicit ClassifyDataClient(DefaultIO &dio, const SocketIO &sio) : CommandClient(dio, sio) {}
    /**
    * Function name: execute
    * The function prints what was received from the server, being a request for uploading or a message confirming the classification.
    * @param ci - the client info.
    */
    void execute(ClientInfo &ci) override;
};
class DisplayResultsClient : virtual public CommandClient {
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO - StandardIO.
    * @param sio - the SocketIO.
    */
    explicit DisplayResultsClient(DefaultIO &dio, const SocketIO &sio) : CommandClient(dio, sio) {}
    /**
    * Function name: execute
    * The function prints the classified results for the test file.
    * @param ci - the client info.
    */
    void execute(ClientInfo &ci) override;
};
class DownloadResultsClient : virtual public CommandClient {
private:
/**
* Function name: downloadToPath
* The function receives data in a string vector and a path.
* It creates a file containing the data, in the path.
* @param data - vector<string>.
* @param path - the path.
*/
static void downloadToPath(const vector<string> &data, const string &path);
public:
    /**
    * Constructor.
    * @param dio - the relevant DefaultIO - StandardIO.
    * @param sio - the SocketIO.
    */
    explicit DownloadResultsClient(DefaultIO &dio, const SocketIO &sio) : CommandClient(dio, sio) {}
    /**
    * Function name: execute
    * The function downloads the classified results for the train file in the given path from the user after it passes validation.
    * @param ci - the client info.
    */
    void execute(ClientInfo &ci) override;
};

#endif
