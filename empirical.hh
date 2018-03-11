///////////////////////////////////////////////////////////////////////////////
// empirical.hh
//
// Definitions for three algorithms:
// 1) min_max
// 2) mode
// 3) sort
//
// As provided, this header has function definitions for each of the three
// algorithms, but the function bodies are empty. Your job is to fill in the
// TODO sections with your own working code.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cassert>
#include <vector>
#include <memory>

using namespace std;

// Container class to store a minimum and maximum int.
class min_max {
public:

  min_max(int min_value,
	  int max_value)
    : _min_value(min_value),
      _max_value(max_value) {
    
    assert(min_value <= max_value);
  }

  int min_value() const { return _min_value; }
  int max_value() const { return _max_value; }

private:

  int _min_value, _max_value;
};

// Return a min_max object containing the minimum (least) element, and
// maximum (greatest) element, of the passed-in vector of integers.
min_max min_max_algorithm(const std::vector<int>& values) {

  assert(!values.empty());

  int minValue = values[0];
  int maxValue = values[0];
  int size = values.size(); //	Caching the size, so that loop doesn't query the same information again and again. 
  for (int i = 1; i < values.size(); i++)
  {
	  if (values[i] > maxValue)
		  maxValue = values[i];

	  if (values[i] < minValue)
		  minValue = values[i];
  }

  return min_max(minValue, maxValue); // this is wrong, replace it with something correct
}

// Container class that stores a mode, i.e. an integer value, and the
// count of how many times that value appears.
class mode {
public:

  mode(int value,
       int count)
    : _value(value),
      _count(count) {

    assert(count > 0);
  }

  int value() const { return _value; }
  int count() const { return _count; }

private:

  int _value, _count;
};

// Return a mode object containing the most-frequent element of
// values, and the number of times that value appears in values.
mode mode_algorithm(const std::vector<int>& values) {

  assert(!values.empty());

  bool have_best = false;
  int best_value = values[0];
  int best_count = 0;
  int size = values.size();	//	Caching the size, so that loop doesn't query the same information again and again. 
  int v_count = 0;

  for (int i = 0; i < size; i++)
  {
	  v_count = 0;

	  for (int j = 0; j < size; j++)
		  if (values[i] == values[j])
			  v_count++;

	  if (have_best == false || v_count > best_count)
	  {
		  have_best = true;
		  best_value = values[i];
		  best_count = v_count;
	  }
  }

  return mode(best_value, best_count);
}

// Return a pointer to a vector that contains the same integers as in
// values, but sorted into non-decreasing order. Note that values may
// be empty, in which case this function returns a pointer to an empty
// vector.
std::unique_ptr<std::vector<int>> sort_algorithm(const std::vector<int>& values) {
	/*
	// This method is a traditional method. 
	vector<int> copy_values;
	int size = values.size();
	for (int i = 0; i < size; i++)
		copy_values.push_back(values[i]);
	*/

	vector<int> *copy_values = new vector<int>(values);

	sort(copy_values->begin(), copy_values->end());

	// return a pointer to a copy of the input
	return std::unique_ptr<std::vector<int>>(copy_values);
}
