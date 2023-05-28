#include <iostream>
#include "DefaultIO.h"

string StandardIO::read() {
    string message;
    getline(cin, message);
    return message;
}
void StandardIO::write(const string &message) {
    cout << message << endl;
}
