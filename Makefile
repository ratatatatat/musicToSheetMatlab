CC := gcc
CXX := g++
CFLAGS := -g
CXXFLAGS := -g
INCLUDES := /usr/local/lib
INCLUDES += -lsndfile


setup:
	sudo apt-get update
	sudp apt-get install libsndfile1
	sudo apt-get install libsndfile1-dev

test:
	$(CC) $(CXXFLAGS) main.c -L $(INCLUDES) -o test.o

testcpp:
	$(CXX) $(CXXFLAGS) main.cc -L $(INCLUDES) -o testcpp.o