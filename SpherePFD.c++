// ----------------------------
// Darya Y. Mylius
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <list>

using namespace std;
//#ifdef
//#endif

int num_jobs;
int num_rules;
int adj_matrix[100][100];
bool visited[100];
int pushed[100];
vector<int> queue;
list<int> output_firm;
list<int> output_lax;

// ------------
// PFD_read
// ------------

bool pfd_read(istream &r, int &i, bool &rules) {
  string current;
  if (!(getline(r, current)))
    return false;
  if (rules){
    istringstream int_stream(current);
    int job_num;
    int_stream >> job_num;
    int next;
    while(int_stream >> next){
      int dependent = next;
//      if (job_num != dependent)
        adj_matrix[dependent-1][job_num-1] = 1;
    }
  }
  else {
    istringstream int_stream(current);
    int_stream >> num_jobs;
    int_stream >> num_rules;
    assert(num_jobs <= 100);
    assert(num_rules <= 100);
  }
  return true;
}

// ------------
// pfd_eval
// ------------
template<int rows, int cols>
void topological_sort(int (&matrix)[rows][cols], int &i, int &j) {
  bool singular = true;
  for(j; j < num_jobs; j++){
    
    if(adj_matrix[i][j] == 1 && visited[j] != true){
      singular = false;
      visited[j] = true;
      int temp = 0;
      topological_sort(matrix, j, temp);
    }
  }
  if(!pushed[i]){
    if(!singular)
      output_firm.push_front(i+1);
    //else
      //output_lax.push_back(i+1);
    pushed[i] = 1;
  }
}

// -------------
// pfd_print
// -------------

void pfd_print(ostream &w) {
  
  //iterator lax = output_lax.begin();
  for(std::list<int>::iterator iter = output_firm.begin(); iter != output_firm.end(); iter++){
    //if(
    w << *iter << " ";
  }
  w << endl;
  for(std::list<int>::iterator iter = output_lax.begin(); iter != output_lax.end(); iter++){
    w << *iter << " ";
  }

  w << endl;/*
  for(int i = 0;i< num_jobs; i++){
    for(int j = 0;j < num_jobs;j++){
      w << adj_matrix[i][j] << " ";
    }
    w << endl;
  }*/
}

// -------------
// PFD_solve
// -------------

void pfd_solve(istream &r, ostream &w) {
  int i;
  bool rules = false;
  assert(pfd_read(r, i, rules));
  rules = true;
  while (pfd_read(r, i, rules)) {
  }
  for(int x = 0; x < num_jobs; x++){
    int y = 0;
    topological_sort(adj_matrix, x, y);
  }
  pfd_print(w);
}
// --------
// includes
// --------

#include <iostream> // cin, cout


// ----
// main
// ----

int main() {
  using namespace std;
  pfd_solve(cin, cout);
  return 0;
}

