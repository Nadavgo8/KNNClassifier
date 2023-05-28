#include "Distance.h"

double Canberra::calculate(vector<double> v1, vector<double> v2) {
    double dist = 0, numerator;
    for (int i = 0; i < v1.size(); i++) {
        numerator = abs(v1[i] - v2[i]);
        if (v1[i] != 0 || v2[i] != 0) { //Making sure that at least one of the indexes isn't 0,
            // so we won't divide by 0 according to the formula.
            double denominator = abs(v1[i]) + abs(v2[i]);
            dist += numerator / denominator;
        }
    }
    return dist;
}

