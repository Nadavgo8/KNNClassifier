#include "FileWriter.h"

FileWriter& FileWriter::operator=(const FileWriter& f) {
    if (this != &f) {
        this->dataSet = f.getDataSet();
        this->dataTest = f.getDataTest();
        this->knnDataSet = f.getKnnDataSet();
    }
    return *this;
}
map<int, string> FileWriter::getKnnDataSet() const {
    return this->knnDataSet;
}
vector<vector<double>> FileWriter::getDataTest() const {
    return this->dataTest;
}
map<vector<double>, string> FileWriter::getDataSet() const{
    return this->dataSet;
}
void FileWriter::setKnnDataSet(map<int, string>& knnData) {
    this->knnDataSet = knnData;
}
vector<string> FileWriter::split(const string &s) {
    string value;
    vector<string> values;
    istringstream tokenStream(s);
    while (getline(tokenStream, value, ',')) {
        values.push_back(value);
    }
    return values;
}
void FileWriter::addLineToDataBase(const string& s, int type) {
    string value;
    vector<double> key;
    vector<string> splitString = split(s);
    int length = (int) splitString.size() - 1;
    for (int i = 0; i < length; i++) {
        key.push_back(stod(splitString[i]));
    }
    value = splitString[length];
    if (type) {
        this->dataSet.insert({key, value});
    } else {
        key.push_back(stod(value));
        this->dataTest.push_back(key);
    }
}