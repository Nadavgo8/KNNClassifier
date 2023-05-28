#include <cstdio>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "DefaultIO.h"
#include "../Correctness.h"
#include "../Command/Client/CommandClient.h"

#define EXPECTED_ARGUMENTS 3

/**
* Function name: initCommands
* The function initializes the command array with the commands in the menu.
* @param commands - the commands array.
* @param dio - DefaultIO.
* @param sio - SocketIO.
*/
void initCommands(CommandClient *commands[COMMANDS], DefaultIO &dio, SocketIO &sio) {
    commands[0] = new PrintMenuClient(dio, sio);
    commands[1] = new UploadDataClient(dio, sio);
    commands[2] = new AlgorithmClient(dio, sio);
    commands[3] = new ClassifyDataClient(dio, sio);
    commands[4] = new DisplayResultsClient(dio, sio);
    commands[5] = new DownloadResultsClient(dio, sio);
}
/**
* Function name: start
* The function runs the program for the client, receiving inputs and checking their validity.
* If they are valid, calls the chosen command.
* @param sock - the sock, int.
*/
void start(int sock) {
    ClientInfo ci;
    StandardIO standardIo;
    SocketIO socketIo(sock);
    CommandClient *commands[COMMANDS]{};
    initCommands(commands, standardIo, socketIo);
    commands[MENU]->execute(ci);
    vector<thread> threads;
    DownloadResultsClient downClient(standardIo,socketIo);
    while (true) {
        string choice = standardIo.read();
        int option = convertToPositive(choice, K);
        if (option == 8) {
            break;
        }
        if (choice.empty() || option < 1 || option > 5) {
            standardIo.write(invalid);
        } else {
            socketIo.write(choice);
            commands[option]->execute(ci);
        }
        socketIo.write("0");
        commands[MENU]->execute(ci);
    }
    for (auto& command : commands) {
        delete command;
    }
    close(sock);
}
/**
 * Function name: initialize
 * The function initializes the client, creat a connection with the server and starts communicating with it.
 * @param argc num arguments received from CMD
 * @param argv array of arguments received from CMD
 */
void initialize(int argc, char*argv[]) {
    if (argc != EXPECTED_ARGUMENTS) {
        cout << "num of arguments is invalid" << endl;
        exit(EXIT_FAILURE);
    }
    const char *ip_address = argv[IP];
    const int port = convertToPositive(argv[PORT], PORT);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin{};
    if (inet_pton(AF_INET, argv[IP], &(sin.sin_addr)) != 1) {
        cerr << "Invalid IPv4 address" << endl;
        exit(EXIT_FAILURE);
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    start(sock);
}

int main(int argc, char *argv[]) {
    initialize(argc, argv);
    return 0;
}