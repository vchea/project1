///////////////////////////////////////////////////////////////////////////////
// experiment.cc
//
// Example code showing how to run each algorithm while measuring
// elapsed times precisely. You should modify this program to gather
// all of your experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "empirical.hh"
#include "timer.hh"

using namespace std;

void fill_random_vector(vector<int>& result, int n, int seed) {
  assert(n > 0);

  std::mt19937 rng(seed);

  result.clear();
  for (int i = 0; i < n; ++i) {
    result.push_back(rng());
  }

  assert(result.size() == n);
}

int main() {

  const int n = 10000;
  const int SEED = 0xDEADBEEF;
  
  double elapsed;
  Timer timer;
  vector<int> random_numbers;
  fill_random_vector(random_numbers, n, SEED);
  
  timer.reset();
  auto min_max_output = min_max_algorithm(random_numbers);
  elapsed = timer.elapsed();
  cout << "min_max_algorithm, "
       << "n=" << n << ", "
       << "elapsed time=" << elapsed << " seconds" << endl;

  timer.reset();
  auto mode_output = mode_algorithm(random_numbers);
  elapsed = timer.elapsed();
  cout << "mode_algorithm, "
       << "n=" << n << ", "
       << "elapsed time=" << elapsed << " seconds" << endl;

  timer.reset();
  auto sort_output = sort_algorithm(random_numbers);
  elapsed = timer.elapsed();
  cout << "sort_algorithm, "
       << "n=" << n << ", "
       << "elapsed time=" << elapsed << " seconds" << endl;

  return 0;
}
