#include    <stdio.h>
#include    <stdlib.h>
#include    <cstdio>
#include    <cstring>
#include "sndFileObj.cpp"
#include    <sndfile.hh>
#include "Array.h"
#include "fftw++.h"

#define TEMPO   120
#define QUARTERNOTE 60

using namespace std;
using namespace utils;
using namespace Array;
using namespace fftwpp;

int main (void){   

    const char * fname = "/home/rajiv/Desktop/gitHub/musicToSheetMatlab/E.wav" ;
    sndFileObj file(fname);

    int channels = file.getChannels();
    int frames = file.getFrames();
    int sampleRate = file.getSampleRate();
    int * buffer;
    buffer = (int *) malloc(frames*sizeof(int));
    file.getChannelValues(buffer, 0);
    int sampleLength = (QUARTERNOTE/TEMPO) * sampleRate;
    int fftInput [sampleLength];
    for(int i = 0; i < sampleLength; i++){
        fftInput[i] = buffer[i];
    }

    return 0 ;
} 