#include "CommandServer.h"

AlgorithmServer::AlgorithmServer(DefaultIO &dio) : CommandServer(dio) {
    this->description = "2. algorithm settings\n";
}
string AlgorithmServer::getDescription() {
    return this->description;
}
void AlgorithmServer::execute(ClientInfo &ci) {
    this->defaultIo.write("The current KNN parameters are: K = " + to_string(ci.getK())
                          + ", distance metric = " + ci.getMetric());
    string message = this->defaultIo.read();
    if (message == invalid) {
        return;
    }
    if (!message.empty()) {
        string k, metric;
        stringstream ss(message);
        ss >> k >> metric;
        ci.setK(stoi(k));
        ci.setMetric(metric);
    }
}