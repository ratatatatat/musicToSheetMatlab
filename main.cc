#include    <stdio.h>
#include    <stdlib.h>
#include    <cstdio>
#include    <cstring>
#include    <sndfile.hh>
#define     BUFFER_LEN      100000


static void read_file (const char * fname){   
    SndfileHandle file ;
    FILE *out;
    file = SndfileHandle (fname) ;
    int f = file.frames();
    int c = file.channels();
    int sr = file.samplerate();
    int i,j;
    int num, num_items;
    num_items = f*c;
    int *buf;
    buf = (int *) malloc(num_items*sizeof(int));
    printf ("Opened file '%s'\n", fname) ;
    printf ("    frames : %d\n", f);
    printf ("    Sample rate : %d\n", sr) ;
    printf ("    Channels    : %d\n", c) ;

    num = file.read (buf, num_items) ;
    printf("Read %d items\n",num);
    /* Write the data to filedata.out. */
    out = fopen("filedataCPP.out","w");
    for (i = 0; i < num; i += c)
        {
        for (j = 0; j < c; ++j)
            fprintf(out,"%d ",buf[i+j]);
        fprintf(out,"\n");
        }
    fclose(out);
    free(buf);
    puts ("") ;
    return;

    /* RAII takes care of destroying SndfileHandle object. */
    } /* read_file */


int main (void){   

    const char * fname = "./E.wav" ;

    puts ("\nSimple example showing usage of the C++ SndfileHandle object.\n") ;

    // create_file (fname, SF_FORMAT_WAV | SF_FORMAT_PCM_16) ;

    read_file (fname) ;

    puts ("Done.\n") ;
    return 0 ;
} /* main */
