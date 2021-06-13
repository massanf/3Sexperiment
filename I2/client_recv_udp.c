#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    int s = socket(PF_INET, SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    int addresschecker = inet_aton(argv[1], &addr.sin_addr);//IPアドレス
    if (addresschecker == 0){perror("IPaddress"); exit(1);}
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(50000);
    int ret = connect(s, (struct sockaddr *)&addr, sizeof(addr));
    if(ret == -1){perror("connect"); exit(1);}
    char data[1000];
    while(1){
        int n = read(s,data,1000*sizeof(unsigned char));
        if(n == -1){ perror("read"); exit(1); }
        if (n == 0) break;
        write(1, data, n);
    }

    close(s);

    return 0;
}