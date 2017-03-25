#include "sndFileObj.h"
#include	"sndfile.hh"
#include    <stdio.h>
#include    <stdlib.h>
//Object constructor open wav file and read it. Store original value to destructor.

sndFileObj::sndFileObj(const char * fname)
:soundFile(fname)
{
	// SndFileHandle sndFile(fname);
	this->f = this->soundFile.frames();
	this->c = this->soundFile.channels();
	this->sr = this->soundFile.samplerate();
	this->num_items = this->f * this->c;
	this->buf = (int *) malloc(this->num_items*sizeof(int));
	this->num = this->soundFile.read(this->buf, this->num_items);
}

sndFileObj::~sndFileObj(){
	free(this->buf);
}

void sndFileObj::getWavValues(int ** arry){
	int i;
	int j;
	int index;
	int c = this->c;
	int num = this->num;
	//Pass in an array pointer with the same dimensions as channels,frames 
	for (i = 0; i < num; i += c){
		index = i/c; 
        for (j = 0; j < c; ++j)
        	arry[j][index] = this->buf[i+j];
        }
    return;
}

int sndFileObj::getFrames(){
	return this->f;
}

int sndFileObj::getChannels(){
	return this->c;
}

int sndFileObj::getSampleRate(){
	return this->sr;
}