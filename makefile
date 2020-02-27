all:test

test:test.cpp
	g++ -std=c++11 test.cpp
clean:
	rm -f test
