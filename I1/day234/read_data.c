#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int fd = open(argv[1],O_RDONLY);
    unsigned char data[1000];
    int i = 0;
    while(1){
        int n = read(fd,data,1000*sizeof(unsigned char));
        if(n == -1){ perror("read"); exit(1); }
        if (n == 0) break;
        for(int j=0; j<n; j++){
            printf("%d %d\n",i,data[j]);
            i++;
        }
    }
    close(fd);
}