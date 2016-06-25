// --------------------------
// Darya Y Mylius
// --------------------------

#ifndef PFD_h
#define PFD_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <sstream>
#include <string>  // string
#include <utility> // pair
#include <list>

using namespace std;

// ------------
// pfd_read
// ------------

/**
 * read two ints from r into i an j
 * @param r an istream
 * @param i an int
 * @param j an int
 * @return true if the read is successful, otherwise false
 */
bool pfd_read(istream &r, int &i, int &j);

// ------------
// pfd_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j)
 */
int pfd_eval(int i, int j);

// -------------
// pfd_print
// -------------

/**
 * print three ints to w
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void pfd_print(ostream &w, list<int> &output);

// -------------
// pfd_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void pfd_solve(istream &r, ostream &w);

#endif // PFD_h
