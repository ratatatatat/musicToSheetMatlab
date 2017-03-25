#include    <stdio.h>
#include    <stdlib.h>
#include    <cstdio>
#include    <cstring>
#include "sndFileObj.cpp"
#include    <sndfile.hh>


int main (void){   

    const char * fname = "/home/rajiv/Desktop/musicToSheet/musicToSheetMatlab/E.wav" ;
    // SndfileHandle file ;

    // file = SndfileHandle (fname) ;
    sndFileObj file(fname);
    // printf ("Opened file '%s'\n", fname) ;
    // printf ("    Sample rate : %d\n", file.samplerate ()) ;
    // printf ("    Channels    : %d\n", file.channels ()) ;

    int channels = file.getChannels();
    int frames = file.getFrames();
    int * buffer;
    buffer = (int *) malloc(frames*sizeof(int));
    file.getChannelValues(buffer, 0);
    puts ("Done.\n") ;
    printf("The number of channels are %d \n",channels);
    printf("values from the channel[0][0], %d",buffer[0]);
    return 0 ;
} 