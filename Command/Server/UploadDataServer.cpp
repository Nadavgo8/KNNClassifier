#include "CommandServer.h"

UploadDataServer::UploadDataServer(DefaultIO &dio) : CommandServer(dio) {
    this->description = "1. upload an unclassified csv data file\n";
}
string UploadDataServer::getDescription() {
    return this->description;
}
void UploadDataServer::execute(ClientInfo& ci) {
    this->defaultIo.write("Please upload your local train CSV file.");
    FileWriter train;
    string s = this->defaultIo.read();
    if (s == invalid) {
        return;
    }
    while(s != "end") {
        train.addLineToDataBase(s, TRAIN);
        s = this->defaultIo.read();
    }
    ci.setTrainFile(train);
    this->defaultIo.write("Upload complete.\nPlease upload your local test CSV file.");
    FileWriter test;
    s = this->defaultIo.read();
    if (s == invalid) {
        return;
    }
    while(s != "end") {
        test.addLineToDataBase(s, TEST);
        s = this->defaultIo.read();
    }
    if (this->defaultIo.read() == "success") {
        ci.setTestFile(test);
        this->defaultIo.write("Upload complete.");
    } else {
        FileWriter empty;
        ci.setTestFile(empty);
        ci.setTrainFile(empty);
    }
}
