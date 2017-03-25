CC := gcc
CXX := g++
CFLAGS := -g
CXXFLAGS := -g -Wall
INCLUDES := /usr/local/lib
INCLUDES += -lsndfile
INCLUDES += -I ./src/


setup:
	sudo apt-get update
	sudp apt-get install libsndfile1
	sudo apt-get install libsndfile1-dev

# test:
# 	$(CC) $(CXXFLAGS) main.c -L $(INCLUDES) -o test.o

testcpp:
	pwd
	$(CXX) $(CXXFLAGS) ./test/main.cc -L $(INCLUDES) -o ./test/bin/testcpp.o
	$(./bin/testcpp.o)