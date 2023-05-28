#include "CommandServer.h"

ClassifyDataServer::ClassifyDataServer(DefaultIO &dio) : CommandServer(dio) {
    this->description = "3. classify data\n";
}
string ClassifyDataServer::getDescription() {
    return this->description;
}
void ClassifyDataServer::execute(ClientInfo& ci) {
    if (ci.getTestFile().getDataTest().empty() || ci.getTrainFile().getDataSet().empty()) {
        defaultIo.write("please upload data");
        return;
    }
    map<int, string> knnList;
    Knn knn(ci.getK(), ci.getMetric(), ci.getTrainFile().getDataSet());
    int index = 1;
    for (auto & it : ci.getTestFile().getDataTest()) {
        knnList.insert({index++, knn.findKnn(it)});
    }
    FileWriter knnFile;
    knnFile.setKnnDataSet(knnList);
    ci.setKnnFile(knnFile);
    defaultIo.write("classifying data complete");
}