#include "CLI.h"
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define EXPECTED_ARGUMENTS 2

using namespace std;

/**
 * Function name: threadForClient
 * The function opens a new thread for each connecting new client
 * @param arg
 */
void *threadForClient(void *arg) {
    int client_sock = *(int *) arg;
    CLI cli((SocketIO(client_sock)));
    cli.start();
    pthread_exit(nullptr);
}
/**
 * Function name: initialize
 * The function initializes the server, create a connection, waits for client and starts communicating with it.
 * @param argc num arguments received from CMD
 * @param argv array of arguments received from CMD
 */
void initialize(int argc, char*argv[]) {
    if (argc != EXPECTED_ARGUMENTS) {
        cout << "num of arguments is invalid" << endl;
        exit(EXIT_FAILURE);
    }
    const int port = convertToPositive(argv[PORT - IP], PORT);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
    }
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("Error listening to a socket");
    }
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("Error accepting client");
        }
        pthread_t thread;
        if (pthread_create(&thread, nullptr, threadForClient, (void *) &client_sock)) {
            cout << "Error creating thread" << endl;
            continue;
        }
    }
}

int main(int argc, char *argv[]) {
    initialize(argc, argv);
}

