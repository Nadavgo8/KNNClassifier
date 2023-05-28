#include "Distance.h"

double Euclidean::calculate(vector<double> v1, vector<double> v2) {
    double dist = 0;
    for (int i = 0; i < v1.size(); i++) {
        dist += pow(v1[i] - v2[i], 2);
    }
    dist = sqrt(dist);
    return dist;
}