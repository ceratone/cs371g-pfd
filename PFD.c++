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
#include <set>

#include "PFD.h"

using namespace std;
//#ifdef
//#endif
const int MAX = 100;
int num_jobs;
int num_rules;
set<int> out_degree[MAX];
short in_degree[MAX];
set<int> queue;
list<int> output;

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
    int dependents;
    int_stream >> dependents;
    for(int i = 0; i < dependents; i++){
      int dep_job;
      int_stream >> dep_job;
      //In-degree implementation init
      if(dep_job != job_num){
        std::pair<std::set<int>::iterator,bool> ret = out_degree[dep_job-1].insert(job_num-1);
        if(ret.second == true) 
          in_degree[job_num-1] ++;
      }
    }
  }
  else {
    istringstream int_stream(current);
    int_stream >> num_jobs;
    int_stream >> num_rules;
    assert(num_jobs <= MAX);
    assert(num_rules <= MAX);
  }
  return true;
}

// ------------
// pfd_eval
// ------------
void topological_sort(/*int (&matrix)[rows][cols], int &i, int &j */) {
 
  //Attempt at using in-degree method
  while(!queue.empty()){
    int i = *queue.begin();
    queue.erase(queue.begin());
    output.push_back(i+1);
    std::set<int>::iterator id_it;
    for(id_it = out_degree[i].begin(); id_it != out_degree[i].end(); id_it++){
      int dependent = *id_it;
      in_degree[dependent]-=1;
      if(in_degree[dependent] == 0){
        queue.insert(dependent);
      }
    }
  }
}


// -------------
// pfd_print
// -------------

void pfd_print(ostream &w) {
  
  for(std::list<int>::iterator iter = output.begin(); iter != output.end(); iter++){
    //if(
    w << *iter << " ";
  }
  w << endl;
}

// PFD_solve
// -------------

void pfd_solve(istream &r, ostream &w) {
  int i;
  bool rules = false;
  assert(pfd_read(r, i, rules));
  rules = true;
  while (pfd_read(r, i, rules)) {
  }
  //Put all possible roots into a queue arbitrarily
  for(int i = 0; i < num_jobs; i++){
    if(in_degree[i] == 0)
      queue.insert(i);
  }   
  topological_sort(/*x, y*/);
  pfd_print(w);
}
