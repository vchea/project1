///////////////////////////////////////////////////////////////////////////////
// project1_test.cc
//
// Unit tests for empirical.hh
//
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <random>
#include <vector>

#include "rubrictest.hh"

#include "empirical.hh"

using namespace std;

int main() {

  vector<int> one({1}),
    nine({7, 8, 3, 2, 1, 5, 7, -1, 6}),
    all_positive({1, 2, 3, 4, 5}),
    all_negative({-1, -2, -3, -4, -5});

  const int LARGE_N = 10000;
  vector<int> large(LARGE_N);
  default_random_engine rng;
  for (int i = 0; i < LARGE_N; ++i) {
    large[i] = rng();
  }
  
  Rubric rubric;

  rubric.criterion("min_max_algorithm(...)", 1,
		   [&]() {
		     min_max mm = min_max_algorithm(one);
		     TEST_EQUAL("one minimum is 1", 1, mm.min_value());
		     TEST_EQUAL("one maximum is 1", 1, mm.max_value());
		     
		     mm = min_max_algorithm(nine);
		     TEST_EQUAL("nine minimum is -1", -1, mm.min_value());
		     TEST_EQUAL("nine maximum is 8", 8, mm.max_value());

		     mm = min_max_algorithm(all_positive);
		     TEST_EQUAL("all_positive minimum is 1", 1, mm.min_value());
		     TEST_EQUAL("all_positive maximum is 5", 5, mm.max_value());

		     mm = min_max_algorithm(all_negative);
		     TEST_EQUAL("all_negative minimum is -5", -5, mm.min_value());
		     TEST_EQUAL("all_negative maximum is -1", -1, mm.max_value());

		     mm = min_max_algorithm(large);
		     TEST_LE("large min and max works", mm.min_value(), mm.max_value());
		   });

  rubric.criterion("mode_algorithm(...)", 1,
		   [&]() {
		     mode m = mode_algorithm(one);
		     TEST_EQUAL("one mode value is 1", 1, m.value());
		     TEST_EQUAL("one mode count is 1", 1, m.count());

		     m = mode_algorithm(nine);
		     TEST_EQUAL("nine mode value is 7", 7, m.value());
		     TEST_EQUAL("nine mode count is 2", 2, m.count());

		     m = mode_algorithm(all_positive);
		     TEST_TRUE("all_positive mode value is 1-5", (m.value() >= 1) && (m.value() <= 5));
		     TEST_EQUAL("all_positive mode count is 1", 1, m.count());

		     m = mode_algorithm(all_negative);
		     TEST_TRUE("all_negative mode value is (-5) - (-1)", (m.value() >= -5) && (m.value() <= -1));
		     TEST_EQUAL("all_negative mode count is 1", 1, m.count());

		     vector<int> tricky({1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5});
		     m = mode_algorithm(tricky);
		     TEST_EQUAL("tricky mode value is 5", 5, m.value());
		     TEST_EQUAL("tricky mode count is 5", 5, m.count());

		     m = mode_algorithm(large);
		     TEST_GT("large mode works", m.count(), 0);
		   });

  rubric.criterion("sort_algorithm(...)", 1,
		   [&]() {
		     unique_ptr<vector<int>> v = sort_algorithm(one);
		     TEST_TRUE("sorted one is non-null", v);
		     TEST_EQUAL("sorted one has length 1", 1, v->size());
		     TEST_EQUAL("sorted one, element at index 0", 1, (*v)[0]);
		     
		     v = sort_algorithm(nine);
		     TEST_TRUE("sorted nine is non-null", v);
		     TEST_EQUAL("sorted nine has length 9", 9, v->size());
		     TEST_EQUAL("sorted nine, element at index 0", -1, (*v)[0]);
		     TEST_EQUAL("sorted nine, element at index 1", 1, (*v)[1]);
		     TEST_EQUAL("sorted nine, element at index 2", 2, (*v)[2]);
		     TEST_EQUAL("sorted nine, element at index 3", 3, (*v)[3]);
		     TEST_EQUAL("sorted nine, element at index 4", 5, (*v)[4]);
		     TEST_EQUAL("sorted nine, element at index 5", 6, (*v)[5]);
		     TEST_EQUAL("sorted nine, element at index 6", 7, (*v)[6]);
		     TEST_EQUAL("sorted nine, element at index 7", 7, (*v)[7]);
		     TEST_EQUAL("sorted nine, element at index 8", 8, (*v)[8]);
		     
		     v = sort_algorithm(all_positive);
		     TEST_TRUE("sorted all_positive is non-null", v);
		     TEST_EQUAL("sorted all_positive has length 5", 5, v->size());
		     TEST_EQUAL("sorted all_positive, element at index 0", 1, (*v)[0]);
		     TEST_EQUAL("sorted all_positive, element at index 1", 2, (*v)[1]);
		     TEST_EQUAL("sorted all_positive, element at index 2", 3, (*v)[2]);
		     TEST_EQUAL("sorted all_positive, element at index 3", 4, (*v)[3]);
		     TEST_EQUAL("sorted all_positive, element at index 4", 5, (*v)[4]);
		     
		     v = sort_algorithm(all_negative);
		     TEST_TRUE("sorted all_negative is non-null", v);
		     TEST_EQUAL("sorted all_negative has length 5", 5, v->size());
		     TEST_EQUAL("sorted all_negative, element at index 0", -5, (*v)[0]);
		     TEST_EQUAL("sorted all_negative, element at index 1", -4, (*v)[1]);
		     TEST_EQUAL("sorted all_negative, element at index 2", -3, (*v)[2]);
		     TEST_EQUAL("sorted all_negative, element at index 3", -2, (*v)[3]);
		     TEST_EQUAL("sorted all_negative, element at index 4", -1, (*v)[4]);

		     v = sort_algorithm(large);
		     TEST_TRUE("large sort works", is_sorted(v->begin(), v->end()));

		     vector<int> empty;
		     v = sort_algorithm(empty);
		     TEST_TRUE("sorted empty is non-null", v);
		     TEST_EQUAL("sorted empty has length 0", 0, v->size());
		   });

  return rubric.run();
}
