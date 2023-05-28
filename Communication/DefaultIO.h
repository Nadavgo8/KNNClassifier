#ifndef DEFAULTIO_H
#define DEFAULTIO_H

#include <string>

using namespace std;

/**
* Class name: DefaultIO
* The abstract class has two main functions - read and write.
* It has two extensions: one for each socketIO (for socket communication) and StandardIO (for cin/cout communication).
*/
class DefaultIO {
public:
    virtual string read() = 0;
    virtual void write(const string& s) = 0;
};
class SocketIO : public DefaultIO {
private:
    int socket;
public:
    /**
    * Constructor
    * @param clientSocket - the socket.
    */
    explicit SocketIO(int clientSocket);
    /**
    * Function name: read
    * The function reads a message from the buffer.
    * */
    string read() override;
    /**
    * Function name: write
    * The function receives a string and sends it to the other side (client/server).
    * @param s - string.
    * */
    void write(const string& s) override;
};
class StandardIO : public DefaultIO {
public:
    /**
    * Function name: read
    * The function reads an input from the user.
    * */
    string read() override;
    /**
    * Function name: write
    * The function receives a string and prints it to the screen.
    * @param s - string.
    * */
    void write(const string& s) override;
};

#endif
