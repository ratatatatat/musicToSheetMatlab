CC := gcc
CXX := g++
CFLAGS := -g
CXXFLAGS := -g -Wall

LDFLAGS := /usr/local/lib
LDFLAGS += -lsndfile -lfftw3 -lfftw3_omp

INCLUDES := -I ./src/ 
INCLUDES += -I ./fftwpp/




setupSound:
	sudo apt-get update
	sudo apt-get install libsndfile1
	sudo apt-get install libsndfile1-dev

setupFFT:
	# wget -P /tmp/  http://www.fftw.org/fftw-3.3.6-pl2.tar.gz
	# tar xvzf fftw-3.3.6-pl2.tar.gz
	# cd fftw-3.3.6-pl2/
	# sudo ./configure
	# sudo make
	# sudo make install
	sudo apt-get update
	sudo apt-get install libfftw3-dev libfftw3-doc
	# Install the C++ Wrapper
	git clone https://github.com/dealias/fftwpp.git
	cd fftwpp
	cd tests
	make
	cd ../wrappers
	make

testcpp:
	pwd
	$(CXX) $(CXXFLAGS) ./test/main.cc -L $(LDFLAGS) $(INCLUDES) -o ./test/bin/testcpp.o

testfft:
	$(CXX) $(CXXFLAGS) ./test/fftcppDemo.cc -L $(LDFLAGS) $(INCLUDES) -o ./test/bin/fftTestcpp.o
