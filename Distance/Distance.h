#ifndef DISTANCE_H
#define DISTANCE_H

#include <cmath>
#include <vector>

using namespace std;

/**
* Class name: Distance
* The class is responsible for calculating the distance between two vectors.
*/
class Distance {
public:
    /**
    * Function name: calculate
    * The function calculates the distance between the two vectors.
    * @param v1 - the first vector.
    * @param v2 - the second vector.
    * @return the distance.
    */
    virtual double calculate(vector<double> v1, vector<double> v2) = 0;
};
class Chebyshev : virtual public Distance {
public:
    double calculate(vector<double> v1, vector<double> v2) override;
};
class Euclidean : public Distance {
public:
    double calculate(vector<double> v1, vector<double> v2) override;
};
class Manhattan : public Distance {
public:
    double calculate(vector<double> v1, vector<double> v2) override;
};
class Canberra : public Distance {
public:
    double calculate(vector<double> v1, vector<double> v2) override;
};
class Minkowski : public Distance {
public:
    double calculate(vector<double> v1, vector<double> v2) override;
};

#endif
