#include "Distance.h"

double Chebyshev::calculate(vector<double> v1, vector<double> v2) {
    double dist = 0;
    for (int i = 0; i < v1.size(); i++) {
        double newDist = abs(v1[i] - v2[i]);
        if (newDist > dist)
            dist = newDist;
    }
    return dist;
}
