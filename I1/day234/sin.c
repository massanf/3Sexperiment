#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
    double a = atof(argv[1]);
    double f = atof(argv[2]);
    int time = atoi(argv[3]);
    double samp_f = 44100;
    short c[time];
    for (int i = 0; i < time; i++){
        c[i] = sin(2.0*3.1416*f*(double)i/samp_f) * a;
    }
    write(1,c,sizeof(c));
}