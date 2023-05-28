#include <thread>
#include <vector>
#include "CommandClient.h"

void DownloadResultsClient::downloadToPath(const vector<string>& data, const string& path){
    ofstream file(path);
    try {
        if (file.is_open()) {
            for (auto & i : data) {
                file << i << endl;
            }
            file.close();
        }
    } catch (ifstream::failure &e) {
        cout << "An error occurred opening the file" << endl;
    }
}
void DownloadResultsClient::execute(ClientInfo &ci) {
    string message = this->socketIo.read();
    if (message == "please upload data" || message == "please classify the data") {
        this->defaultIo.write(message);
        return;
    }
    string path = this->defaultIo.read();
    vector<string> knnResults;
    while(message != "Done."){
        knnResults.push_back(message);
        message = this->socketIo.read();
    }
    thread t(downloadToPath, knnResults, path);
    t.detach();
}


