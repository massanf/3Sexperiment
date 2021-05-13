#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
    int space;
    space = atoi(argv[1]);
    unsigned char data[1000];
    int i = 0;
    int count = 0;
    while(1){
        count++;
        int n = read(0,data,1000);
        if(n == -1){ perror("read"); exit(1); }
        if (n == 0) break;
        if(count%space == 0) {write(1,data,sizeof(data));}
        i++;
    }
}