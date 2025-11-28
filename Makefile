CXX = g++
CXXFLAGS = -O3 -march=native -std=c++17 -fopenmp -Wall -Wextra

.PHONY: all seq omp run plot clean

all: seq omp

seq:
	$(CXX) $(CXXFLAGS) src/seq/main_seq.cpp -o bin/seq

omp:
	$(CXX) $(CXXFLAGS) src/omp/main_omp.cpp -o bin/omp

run:
	./run.sh

plot:
	python3 plot.py results.csv

clean:
	rm -rf bin/* results.csv outputs/
