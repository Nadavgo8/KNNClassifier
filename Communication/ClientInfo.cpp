#include "ClientInfo.h"

int ClientInfo::getK() const {
    return this->k;
}
string ClientInfo::getMetric() {
    return this->metric;
}
FileWriter& ClientInfo::getKnnFile() {
    return this->knnFile;
}
FileWriter& ClientInfo::getTestFile() {
    return this->testFile;
}
FileWriter& ClientInfo::getTrainFile() {
    return this->trainFile;
}
void ClientInfo::setK(int newK) {
    this->k = newK;
}
void ClientInfo::setMetric(const string& newMetric) {
    this->metric = newMetric;
}
void ClientInfo::setKnnFile(FileWriter& newKnnFile) {
    this->knnFile = newKnnFile;
}
void ClientInfo::setTestFile(FileWriter& newTestFile) {
    this->testFile = newTestFile;
}
void ClientInfo::setTrainFile(FileWriter& newTrainFile) {
    this->trainFile = newTrainFile;
}

