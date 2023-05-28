#include "Distance.h"

#define P 2

double Minkowski::calculate(vector<double> v1, vector<double> v2) {
    double dist = 0;
    for (int i = 0; i < v1.size(); i++) {
        dist += pow(abs(v1[i] - v2[i]), P);
    }
    dist = pow(dist, 1.0 / P);
    return dist;
}

