#include	<sndfile.hh>
// #include "sndFileObj.cpp"
#ifndef	_sndFileObj_h_
#define	_sndFileObj_h_


class sndFileObj{
	SndfileHandle soundFile ; // Initialize the c++ libsndfile wrapper
	public:
		sndFileObj(const char * fname);
		~sndFileObj();
		void getWavValues(int ** arry);
		int getFrames();
		int getChannels();
		int getSampleRate();
		void getChannelValues(int *buffer, int channel);//channel starting from 0

	private:
		// SndfileHandle soundFile ; // Initialize the c++ libsndfile wrapper
    	FILE *out; // Initialize an object for writing values, intermittent storage
    	int f; //frames
    	int c; //channel
    	int sr; //sampleRate
    	int *buf; // Buffer Value for containing wav file values;
    	int num;
    	int num_items;
};
#endif