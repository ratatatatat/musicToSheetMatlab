#include    <stdio.h>
#include    <stdlib.h>
#include    <cstdio>
#include    <cstring>
#include "sndFileObj.cpp"
#include    <sndfile.hh>
#include "Array.h"
#include "fftw++.h"
#include <fftw3.h>

// #define TEMPO   120
// #define QUARTERNOTE 60

using namespace std;
using namespace utils;
using namespace Array;
using namespace fftwpp;

int main (void){   
    FILE *fileout;
    const char * fname = "/home/rajiv/Desktop/gitHub/musicToSheetMatlab/E.wav" ;
    sndFileObj file(fname);
    int TEMPO = 120;
    int QUARTERNOTE = 60;
    int channels = file.getChannels();
    int frames = file.getFrames();
    int sampleRate = file.getSampleRate();
    int * buffer;
    buffer = (int *) malloc(frames*sizeof(int));
    file.getChannelValues(buffer, 0);
    // int sampleLength = (QUARTERNOTE/TEMPO) * sampleRate;
    int sampleLength = sampleRate/2;
    printf("Size of sampleLength: %d \n",sampleLength);
    int N = sampleLength/2 +1;

    fftw_complex *in, *out;
    fftw_plan p;

    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * sampleLength);
    for(int i = 0; i < sampleLength; i++){
        in[i][0] = buffer[i];   //Set the Real Component
        in[i][1] = 0;   //Set the imaginary component
    }
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(p); /* repeat as needed */

    fftw_destroy_plan(p);
    /* Write the data to filedata.out. */
    fileout = fopen("filedata.out","w");
    printf("Size of N: %d \n",N);
    for (int k = 0; k < N; k++){
        printf("Writing fft value: %f \n",out[k][0]);
        fprintf(fileout,"%f \n",out[k][0]);
    }
    fclose(fileout);

    fftw_free(in); fftw_free(out);
    //out = fopen("fft.out","w");
    return 0 ;
} 