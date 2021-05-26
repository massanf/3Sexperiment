#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int notes = 2;
    double a = 10000;
    int notes_list[15] = {7,16,24,14,24,24,12,24,11,9,7,24,7,24,24};
    int second_notes_list[15] = {24,11,11,11,11,12,12,12,24,12,12,12,12,24,11};
    int third_notes_list[15] = {24,4,4,4,9,9,9,9,24,14,14,2,2,24,7};
    int tempo = 23000;
    double time_list[15] = {0.5, 0.5,0.5, 0.5,0.25,0.25, 0.5,0.5, 0.75,0.5,0.23,0.02,0.5,0.5,1};
    double freq_list[25];
    for(int j = 0; j < 25; j++){
        freq_list[j] = 440*pow(pow(2,1.0/12),j);
    }
    freq_list[24] = 0;
    int time_sum = 0;
    for(int j = 0; j < sizeof(time_list)/sizeof(double); j++){
        time_sum += time_list[j]*tempo;
    }
    short c[time_sum];
    int currenttime = 0;
    for(int j = 0; j < sizeof(notes_list)/sizeof(int); j++){
        double samp_f = 44100;
        for (int i = 0; i < time_list[j]*tempo; i++){
            currenttime++;
            c[currenttime] = sin(2.0*3.1416*freq_list[notes_list[j]]*(double)i/samp_f) * a +  sin(2.0*3.1416*freq_list[second_notes_list[j]]*(double)i/2/samp_f) * a/1.8 +  sin(2.0*3.1416*freq_list[third_notes_list[j]]*(double)i/4/samp_f) * a;
        }
    }
    write(1,c,sizeof(c));
}