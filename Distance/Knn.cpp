#include "Knn.h"

Knn::Knn(int k, string metric, const map<vector<double>, string> &dataSet) {
    this->k = k;
    this->dataSet = dataSet;
    this->metric = std::move(metric);
}
Distance &Knn::metricType() {
    if (metric == "AUC") {
        static Euclidean euc;
        return euc;
    } else if (metric == "MAN") {
        static Manhattan man;
        return man;
    } else if (metric == "CHB") {
        static Chebyshev chb;
        return chb;
    } else if (metric == "CAN") {
        static Canberra can;
        return can;
    } else {
        static Minkowski min;
        return min;
    }
}
string Knn::findKnn(const vector<double> &v) {
    prepareForFind(v);
    int max = 0;
    string type;
    map<string, int> knn;
    for (auto &it: kDataSet) {
        auto find = knn.find(it.second);
        if (find == knn.end()) { //Checking if the type has not been inserted yet
            knn.insert({it.second, 1});
        } else { //the type is already inserted
            knn[it.second]++;
        }
        if (knn[it.second] > max) {
            max = knn[it.second];
            type = it.second;
        }
    }
    return type;
}
void Knn::prepareForFind(const vector<double> &v) {
    this->kDataSet.clear();
    for (auto &it: this->dataSet) {
        vector<double> temp = it.first;
        string type = it.second;
        temp.insert(temp.begin(), metricType().calculate(v, temp));
        this->kDataSet.insert({temp, type});
        if (this->kDataSet.size() == this->k + 1) {
            //limiting the data structure to size K (deleting the value with the largest distance so far)
            auto tempIt = this->kDataSet.end();
            tempIt--;
            this->kDataSet.erase(tempIt);
        }
    }
}
