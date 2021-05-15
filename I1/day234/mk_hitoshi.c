#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (){
    int fd = open("hitoshi", O_WRONLY | O_CREAT | O_TRUNC , 0644);
    unsigned char data[6];
    data[0] = 228;
    data[1] = 186;
    data[2] = 186;
    data[3] = 229;
    data[4] = 191;
    data[5] = 151;
    write(fd,data,6);
    close(fd);
    return 0;
}