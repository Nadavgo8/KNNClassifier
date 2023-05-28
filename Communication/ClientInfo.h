#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include "../Files/FileWriter.h"

using namespace std;

/**
* Class name: ClientInfo
* The class holds the client's information whether it's the files or the 'k' and metric.
* This class is critical for the commands running and operation and they all receive it as an argument.
*/
class ClientInfo {
private:
    int k;
    string metric;
    FileWriter knnFile;
    FileWriter testFile;
    FileWriter trainFile;
public:
    /**
    * Constructor
    * */
    ClientInfo() : knnFile(), testFile(), trainFile() {
        this->k = 5;
        this->metric = "AUC";
    }
    /**
    * Function name: getK
    * Getter method for the 'k'.
    * @return k - int.
    * */
    int getK() const;
    /**
    * Function name: getMetric
    * Getter method for the metric.
    * @return metric - string.
    * */
    string getMetric();
    /**
    * Function name: getKnnFile
    * Getter method for the knn file.
    * @return knnFile - FileWriter.
    * */
    FileWriter &getKnnFile();
    /**
    * Function name: getTestFile
    * Getter method for the test file.
    * @return testFile - FileWriter.
    * */
    FileWriter &getTestFile();
    /**
    * Function name: getTrainFile
    * Getter method for the train file.
    * @return trainFile - FileWriter.
    * */
    FileWriter &getTrainFile();
    /**
    * Function name: setK
    * Setter method for the 'k'.
    * @param newK - the new 'k', int.
    * */
    void setK(int newK);
    /**
    * Function name: setMetric
    * Setter method for the metric.
    * @param newMetric - the new metric, string.
    * */
    void setMetric(const string &newMetric);
    /**
    * Function name: setKnnFile
    * Setter method for the Knn file.
    * @param newKnnFile - FileWriter.
    * */
    void setKnnFile(FileWriter &newKnnFile);
    /**
    * Function name: setTestFile
    * Setter method for the test file.
    * @param newTestFile - FileWriter.
    * */
    void setTestFile(FileWriter &newTestFile);
    /**
    * Function name: setTrainFile
    * Setter method for the train file.
    * @param newTrainFile - FileWriter.
    * */
    void setTrainFile(FileWriter &newTrainFile);
};

#endif
