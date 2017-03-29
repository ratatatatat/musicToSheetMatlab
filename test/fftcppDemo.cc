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
    FILE *out;
    const char * fname = "/home/rajiv/Desktop/gitHub/musicToSheetMatlab/E.wav" ;
    sndFileObj file(fname);

    int channels = file.getChannels();
    int frames = file.getFrames();
    int sampleRate = file.getSampleRate();
    int * buffer;
    buffer = (int *) malloc(frames*sizeof(int));
    file.getChannelValues(buffer, 0);
    int sampleLength = (QUARTERNOTE/TEMPO) * sampleRate;
    double fftInput [sampleLength];
    for(int i = 0; i < sampleLength; i++){
        fftInput[i] = buffer[i];
    }

    unsigned int np=sampleLength/2+1;
    size_t align=sizeof(Complex);
    array1<Complex> F(np,align);
    rcfft1d Forward(sampleLength,fftInput,F);
    crfft1d Backward(sampleLength,F,fftInput);
    Forward.fft(fftInput,F);
    // printf("FFT array first entry, %f \n",F[0]);
      cout << endl << "output:" << endl << F << endl;

    //out = fopen("fft.out","w");
    return 0 ;
} 