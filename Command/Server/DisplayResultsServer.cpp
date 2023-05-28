#include "CommandServer.h"

DisplayResultsServer::DisplayResultsServer(DefaultIO &dio) : CommandServer(dio) {
    this->description = "4. display results\n";
}
string DisplayResultsServer::getDescription() {
    return this->description;
}
void DisplayResultsServer::execute(ClientInfo& ci) {
    if (ci.getTestFile().getDataTest().empty() || ci.getTrainFile().getDataSet().empty()) {
        this->defaultIo.write("please upload data");
        return;
    }
    if (ci.getKnnFile().getKnnDataSet().empty()) {
        this->defaultIo.write("please classify the data");
        return;
    }
    for (auto & it : ci.getKnnFile().getKnnDataSet()) {
        this->defaultIo.write(to_string(it.first) + " " + it.second);
    }
    this->defaultIo.write("Done.");
}