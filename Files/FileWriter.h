#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../Correctness.h"

#define TEST 0
#define TRAIN 1

using namespace std;

/**
* Class name: FileWriter
* The class creates files and inserts the data into them using special dataSets.
*/
class FileWriter {
private:
    map<int, string> knnDataSet;
    vector<vector<double>> dataTest;
    map<vector<double>, string> dataSet;
    /**
    * Function name: split
    * The function receives a string and splits the elements in the string.
    * Essentially gets rid of the commas in the string.
    * @param s - string.
    * @return values - the split string in a vector.
    */
    static vector<string> split(const string& s);
public:
    /**
    * Copy constructor.
    */
    FileWriter& operator=(const FileWriter& f);
    /**
    * Getter method for the knnDataSet.
    */
    map<int, string> getKnnDataSet() const;
    /**
    * Getter method for the DataTest.
    */
    vector<vector<double>> getDataTest() const;
    /**
    * Getter method for the DataSet.
    */
    map<vector<double>, string> getDataSet() const;
    /**
    * Setter method for the knnDataSet.
    */
    void setKnnDataSet(map<int, string>& knnData);
    /**
    * Function name: addLineToDataSet
    * The function receives a string and adds it to the dataSet.
    * @param s - string.
    */
    void addLineToDataBase(const string& s, int type);
};

#endif
