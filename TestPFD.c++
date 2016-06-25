// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <list>

#include "gtest/gtest.h"

#include "PFD.h"

using namespace std;

// -----
// print
// -----

TEST(PFDFixture, print_1) {
  ostringstream w;
  list<int> output;
  output.push_back(1);
  output.push_back(2);
  output.push_back(4);
  pfd_print(w, output);
  ASSERT_EQ("1 2 4 \n", w.str());
}

TEST(PFDFixture, print_2) {
  ostringstream w;
  list<int> output;
  output.push_back(1);
  output.push_front(6);
  output.push_back(0);
  pfd_print(w, output);
  ASSERT_EQ("6 1 0 \n", w.str());
}

TEST(PFDFixture, print_3) {
  ostringstream w;
  list<int> output;
  pfd_print(w, output);
  ASSERT_EQ("\n", w.str());
}

// -----
// solve
// -----

TEST(PFDFixture, solve_1) {
  istringstream r("5 4\n3 2 1 5\n2 2 5 3\n4 1 3\n5 1 1\n");
  ostringstream w;
  pfd_solve(r, w);
  ASSERT_EQ("1 5 3 2 4 \n", w.str());
}

TEST(PFDFixture, solve_2) {
  istringstream r("3 2\n3 1 2\n1 1 2\n");
  ostringstream w;
  pfd_solve(r, w);
  ASSERT_EQ("2 1 3 \n", w.str());
}

TEST(PFDFixture, solve_3) {
  istringstream r("5 3\n5 1 4\n4 1 3\n3 1 2\n");
  ostringstream w;
  pfd_solve(r, w);
  ASSERT_EQ("1 2 3 4 5 \n", w.str());
}
