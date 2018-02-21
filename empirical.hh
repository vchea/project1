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

  // TODO: replace this comment with working code

  return min_max(0, 0); // this is wrong, replace it with something correct
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

  // TODO: replace this comment with working code

  return mode(0, 1); // this is wrong, replace it with something correct
}

// Return a pointer to a vector that contains the same integers as in
// values, but sorted into non-decreasing order. Note that values may
// be empty, in which case this function returns a pointer to an empty
// vector.
std::unique_ptr<std::vector<int>> sort_algorithm(const std::vector<int>& values) {

  // TODO: replace this comment with working code

  // this is wrong, replace it with something correct
  // return a pointer to a copy of the input
  return std::unique_ptr<std::vector<int>>(new std::vector<int>(values));
}
