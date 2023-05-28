#include "CommandServer.h"

DownloadResultsServer::DownloadResultsServer(DefaultIO &dio) : CommandServer(dio) {
    this->description = "5. download results\n";
}
string DownloadResultsServer::getDescription() {
    return this->description;
}
void DownloadResultsServer::execute(ClientInfo& ci) {
    if (ci.getTestFile().getDataTest().empty() || ci.getTrainFile().getDataSet().empty()) {
        defaultIo.write("please upload data");
        return;
    }
    if (ci.getKnnFile().getKnnDataSet().empty()) {
        defaultIo.write("please classify the data");
        return;
    }
    for (auto & it : ci.getKnnFile().getKnnDataSet()) {
        this->defaultIo.write(to_string(it.first) + ", "  + it.second);
    }
    this->defaultIo.write("Done.");
}
