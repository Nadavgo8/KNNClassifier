#include "CommandClient.h"

void UploadDataClient::execute(ClientInfo &ci) {
    this->defaultIo.write(this->socketIo.read());
    for (int i = 0; i < 2; i++) {
        string path = this->defaultIo.read();
        if (fileCheck(path) == invalid) {
            this->socketIo.write(invalid);
            this->defaultIo.write(invalid);
            return;
        }
        FileReader file(path);
        if (!i) {
            file.readAndStore(TRAIN);
            this->trainLength = file.getVectorLength();
            for (const auto &value: file.getDataSet()) {
                string s;
                for (const auto &num: value.first) {
                    s += to_string(num) + ",";
                }
                s += value.second;
                this->socketIo.write(s);
            }
        } else {
            file.readAndStore(TEST);
            this->testLength = file.getVectorLength() + 1;
            for (const auto &value: file.getDataTest()) {
                string s;
                for (double num: value) {
                    s += to_string(num) + ",";
                }
                s.pop_back();
                this->socketIo.write(s);
            }
        }
        this->socketIo.write("end");
        if (!i) {
            this->defaultIo.write(this->socketIo.read());
        }
    }
    if (this->trainLength != this->testLength) {
        this->socketIo.write("fail");
        this->defaultIo.write("The vectors in the train file are not the same length as the test file");
    } else {
        this->socketIo.write("success");
        this->defaultIo.write(this->socketIo.read());
    }
}