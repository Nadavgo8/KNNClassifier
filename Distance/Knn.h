#ifndef KNN_H
#define KNN_H

#include <map>
#include <vector>
#include <string>
#include "Distance.h"

/**
* Class name: Knn
* The class is responsible for performing and implementing the 'knn' algorithm
* for each given vector on the given dataBase.
*/
class Knn {
private:
    int k;
    string metric;
    map <vector<double>, string> dataSet;
    map <vector<double>, string> kDataSet;
    /**
    * Function name: metricType
    * The function returns the object corresponding to the metric keyword.
    * @return metric distance object
    */
    Distance &metricType();
    /**
    * Function name: prepareForFind
    * The function receives a vector from the user and calculates the distance between it
    * and all the vectors in the received file according to the selected distance metric.
    * Later, it updates the kDataset field so it contains the K nearest neighbors.
    * @param v vector from user
    */
    void prepareForFind(const vector<double> &v);
public:
    /**
     * Constructor.
     * @param k - the 'K'.
     * @param keyword - the distance metric.
     * @param dataSet a map with all the vectors and corresponding types from the file
     */
    Knn(int k, string metric, const map<vector<double>, string> &dataSet);
    /**
    * Function name: findKnn
    * The function runs through the kDataSet data structure, checks which type appears the most and prints it.
    * @param v vector from user
    * @return the most common type of the knn
    */
    string findKnn(const vector<double> &v);
};

#endif
