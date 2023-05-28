#ifndef CORRECTNESS_H
#define CORRECTNESS_H

#include <string>
#include <vector>

#define K 0
#define IP 1
#define MENU 0
#define PORT 2
#define ASCII_GAP 48
#define MAX_BUFFER 4096

using namespace std;

static string invalid = "invalid input";

/**
* Class name: Correctness
* The class holds several functions which check the various inputs' and arguments' validity.
* The class' main goal is to make sure the program runs normally through all of its inputs.
 */

/**
 * Function name: convertToPositive
 * The function gets a string representing a number and converts it.
 * If the number is negative or invalid (unnatural number) it throws an exception.
 * @param num a string to convert, representing a number
 * @param type - 0,1,2 indicating if checking 'K', port and ID respectively.
 * @return the converted string
 */
int convertToPositive(const string &num, int type);
/**
 * Function name: convertCheck
 * The function checks the path we received is valid and that the file exists there.
 * @param file The path we receive from the user.
 * @return invalid input if the path is invalid, 1 otherwise
 */
string fileCheck(const string &path);
/**
* Function name: metricCheck
* The function checks if the input received from the user is indeed a known metric.
* @param metric The string received from the user.
* @return "invalid input" if the metric is invalid, 1 otherwise.
*/
string metricCheck(const string& metric);
/**
 * Function name: convertCheck
 * The function checks the characters in the string before converting,
 * if the string cannot be converted to a real number, an error is thrown to the user.
 * @param numericValue A number received for checking before conversion, represented by a string.
 * @return "invalid input" if the numericValue is invalid, 1 otherwise.
 */
string convertCheck(string numericValue);

#endif
