#include <fstream>
#include <iostream>
#include <dirent.h>
#include "Correctness.h"

int convertToPositive(const string &num, int type) {
    int converted = 0;
    for (char n: num) {
        if (n < '0' || n > '9') {
            if (!type) {
                return -1;
            } else if (type == PORT) {
                cout << "The chosen port isn't a natural number" << endl;
                exit(EXIT_FAILURE);
            }
        }
        converted *= 10;
        converted += n - ASCII_GAP;
    }
    if (type == PORT && (converted < 1024 || converted > 65535)) {
        cout << "The port value is out of range" << endl;
        exit(EXIT_FAILURE);
    }
    return converted;
}
string metricCheck(const string &metric) {
    string metrics[5] = {"AUC", "MAN", "CHB", "CAN", "MIN"};
    bool flag = false;
    for (const string &m: metrics) {
        if (metric == m) //checking if the distance metric is valid
            flag = true;
    }
    if (!flag) {
        return invalid;
    }
    return "1";
}
string fileCheck(const string &path) {
    ifstream file(path);
        if (!file) {
            return invalid;
        }
    return "1";
}
string convertCheck(string numericValue) {
    int e = 0, dots = 0, i = 0;
    if (numericValue[0] == '-') { //Negative sign
        i = 1;
    }
    size_t length = numericValue.size();
    for (; i < length; i++) {
        if (numericValue[i] == '.') { //count dots in num
            dots++;
            if (dots > 1) { //Multiple dots
                return invalid;
            }
            continue;
        }
        if (numericValue[i] < '0' || numericValue[i] > '9') { //Any character that is not a number
            if ((i < length - 2) && (numericValue[i] == 'E' || numericValue[i] == 'e')
                && (numericValue[i + 1] == '-' || numericValue[i + 1] == '+')) {
                //The number is very small and converted to the format of "xxxxE±xx" (where x is a number)
                e++;
                i++;
                if (e > 1) {
                    return invalid;
                }
                continue;
            } else {
                return invalid;
            }
        }
    }
    return "1";
}
