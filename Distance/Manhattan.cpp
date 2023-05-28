#include "Distance.h"

double Manhattan::calculate(vector<double> v1, vector<double> v2) {
    double dist = 0;
    for (int i = 0; i < v1.size(); i++) {
        dist += abs(v1[i] - v2[i]);
    }
    return dist;
}

