/*#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
    int space;
    space = atoi(argv[1]);
    unsigned char data[10000];
    int i = 0;
    int count = 0;
    while(1){
        count++;
        int n = read(0,data,10000);
        if(n == -1){ perror("read"); exit(1); }
        if (n == 0) break;
        if(count%space == 0) {write(1,data,sizeof(data));}
        i++;
    }
}*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){
    short data[10000];
    int comp_fac = atoi(argv[1]);
    int new = 10000/comp_fac;
    short comp[new];
    while(1){
        int n = read(0,data,10000);
        if(n == -1){ perror("read"); exit(1); }
        if (n == 0) break;
        for(int j=0; j<n; j++){
            if(j%comp_fac == 0){
                comp[j/comp_fac] = data[j]*0.5;
            }
        }
        write(1,comp,new);
    }
}