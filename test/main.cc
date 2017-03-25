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
    puts ("Done.\n") ;
    printf("The number of channels are %d \n",channels);
    return 0 ;
} 