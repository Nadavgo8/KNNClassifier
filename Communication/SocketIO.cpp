#include <cstdio>
#include <cstring>
#include <sys/socket.h>
#include "DefaultIO.h"
#include "../Correctness.h"

SocketIO::SocketIO(int clientSocket) : socket(clientSocket) {}
string SocketIO::SocketIO::read() {
    char buffer[MAX_BUFFER];
    int bytes_received = (int) recv(this->socket, buffer, MAX_BUFFER, 0);
    if (bytes_received == 0) {
        return "";
    } else if (bytes_received < 0) {
        perror("Error occurred while reading message");
    }
    return buffer;
}
void SocketIO::write(const string &message) {
    char buffer[MAX_BUFFER];
    strncpy(buffer, message.c_str(), MAX_BUFFER);
    int sent_bytes = (int) send(this->socket, buffer, MAX_BUFFER, 0);
    if (sent_bytes < 0) {
        perror("Error occurred while sending message");
    }
}
