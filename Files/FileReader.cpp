#include "FileReader.h"

FileReader::FileReader() {
    this->vectorLength = 0;
}
FileReader::FileReader(string path) {
    this->vectorLength = 0;
    this->path = std::move(path);
}
FileReader &FileReader::operator=(FileReader f) {
    if (this != &f) {
        this->dataSet = f.getDataSet();
        this->dataTest = f.getDataTest();
        this->file << f.getFile().rdbuf();
        this->vectorLength = f.getVectorLength();
    }
    return *this;
}
int FileReader::getVectorLength() const {
    return this->vectorLength;
}
const fstream &FileReader::getFile() const {
    return this->file;
}
vector<vector<double>> FileReader::getDataTest() {
    return this->dataTest;
}
map<vector<double>, string> FileReader::getDataSet() {
    return dataSet;
}
void FileReader::insertElement(vector<double> &v, string &numericValue) {
    if (convertCheck(numericValue) != invalid) {
        try {
            v.push_back(stod(numericValue));
        } catch (exception &(c)) {
            cout << "The conversion from string to double has failed" << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        cout << "The vectors in the file are invalid";
        exit(EXIT_FAILURE);
    }
}
void FileReader::readAndStore(int type) {
    int numOfLine = 1;
    openAndCloseFiles(OPEN);
    string line, numericValue;
    while (getline(this->file, line)) {
        vector<double> temp;
        stringstream stream(line);
        int lastValue = lastValueInLine(line);
        int blankLine = 0, locationInLine = 1;
        while (getline(stream, numericValue, ',') && locationInLine < lastValue) {
            if (numericValue.empty()) { //blank column
                numericValue = '0';
                blankLine++;
            }
            insertElement(temp, numericValue);
            locationInLine++; //to stop at the last value in a line
        }
        if (blankLine == lastValue) { //checking if the line is blank
            continue;
        }
        if (numOfLine++ != 1 && locationInLine != this->vectorLength) {
            cout << "The vectors in the file aren't the same size" << endl;
            exit(EXIT_FAILURE);
        } else {
            this->vectorLength = locationInLine;
        }
        if (type) {
            this->dataSet.insert({temp, numericValue});
        } else {
            double d = stod(numericValue);
            temp.push_back(d);
            this->dataTest.push_back(temp);
        }
    }
    openAndCloseFiles(CLOSE);
}
void FileReader::openAndCloseFiles(int num) {
    if (num == OPEN) {
        try {
            file.open(path, ios::in);
        } catch (ifstream::failure &e) {
            cout << "An error occurred opening the file" << endl;
        }
    } else {
        try {
            file.close();
        } catch (ifstream::failure &e) {
            cout << "An error occurred closing the file" << endl;
        }
    }
}
int FileReader::lastValueInLine(const string &line) {
    int length = 0, spaces = 0;
    string word;
    stringstream stream(line);
    while (getline(stream, word, ',')) {
        length++;
        spaces++;
        if (!word.empty() && word != "\r" && word != "\n") {
            spaces = 0;
        }
    }
    return length - spaces;
}