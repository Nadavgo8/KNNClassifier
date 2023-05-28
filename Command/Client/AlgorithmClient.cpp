#include "CommandClient.h"

void AlgorithmClient::execute(ClientInfo &ci) {
    this->defaultIo.write(this->socketIo.read());
    string message = this->defaultIo.read();
    if (message.empty()) {
        this->socketIo.write(invalid);
        return;
    }
    bool flag = false;
    string k, metric, invalidInput;
    stringstream ss(message);
    ss >> k >> metric;
    if (!ss.eof()) {
        this->socketIo.write(invalid);
        this->defaultIo.write(invalid);
        return;
    }
    if (convertToPositive(k, K) < 1) {
        flag = true;
        invalidInput += "invalid value for K";
    }
    if (metricCheck(metric) == invalid) {
        if (flag) {
            invalidInput += "\ninvalid value for metric";
        } else {
            flag = true;
            invalidInput += "invalid value for metric";
        }
    }
    if (flag) {
        this->defaultIo.write(invalidInput);
        this->socketIo.write(invalid);
    } else {
        this->socketIo.write(message);
    }
}