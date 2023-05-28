#ifndef READFILE_H
#define READFILE_H

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "../Correctness.h"
#include "../Distance/Distance.h"

#define OPEN 0
#define TEST 0
#define TRAIN 1
#define CLOSE 1

/**
* Class name: FileReader
* The class is responsible for reading a file and inserting it into the data structure.
*/
class FileReader {
private:
    string path;
    fstream file;
    int vectorLength;
    vector<vector<double>> dataTest;
    map<vector<double>, string> dataSet;
    /**
    * Function name: openAndCloseFiles
    * The function receives a number and tries to open or close the file field
    * according to the received number.
    * @param num 0 for opening and 1 for closing
    */
    void openAndCloseFiles(int num);
    /**
    * Function name: lastValueInLine
    * The function receives a line from the file and checks where the last value in the line is.
    * @param line single line from file
    * @return The column number of the last word in the line
    */
    static int lastValueInLine(const string &line);
    /**
    * Function name: insertElement
    * The function receives a vector and a string, converts the string to double and checks that it is correct.
    * If it is, it puts it in the vector, otherwise it outputs an error
    * @param v
    * @param numericValue
    */
    static void insertElement(vector<double> &v, string &numericValue);
public:
    FileReader();
    /**
    * Constructor.
    * @param argv pointer to the arguments received from the command line
    */
    explicit FileReader(string path);
    /**
    * Copy constructor
    * @param f fileReader
    * @return the copied file
    */
    FileReader& operator=(FileReader f);
    /**
    * Getter method.
    * @return vectorLength field
    */
    int getVectorLength() const;
    /**
    * Getter method.
    * @return file field
    */
    const fstream& getFile() const;
    /**
    * Getter method.
    * @return dataTest field
    */
    vector<vector<double>> getDataTest();
    /**
    * Getter method.
    * @return dataSet field
    */
    map<vector<double>, string> getDataSet();
    /**
    * Function name: readAndStore
    * The function feeds from file line by line into a map data structure. The map is arranged so that
    * the "key" contains the vector with the numerical values and the "value" contains the type.
    */
    void readAndStore(int type);
};

#endif
