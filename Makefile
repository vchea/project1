
all: experiment test

test: empirical_test
	./empirical_test

empirical_test: rubrictest.hh empirical.hh empirical_test.cc
	g++ -std=c++11 empirical_test.cc -o empirical_test

experiment: timer.hh empirical.hh experiment.cc
	g++ -std=c++11 experiment.cc -o experiment

clean:
	rm -f empirical_test experiment
