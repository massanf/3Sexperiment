#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    int type = 0;
    printf("%d\n",argc);    
    if(argc == 2){
        printf("Server\n");
        type = 1;
    } else {
        printf("Client\n");
        type = 2;
    }
    int ss;
    int s;
    if(type == 2){
        ss = socket(PF_INET, SOCK_STREAM,0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        int addresschecker = inet_aton(argv[1], &addr.sin_addr);//IPアドレス
        if (addresschecker == 0){perror("IPaddress"); exit(1);}
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        addr.sin_port = htons(50000);
        s = connect(ss, (struct sockaddr *)&addr, sizeof(addr));
        if(s == -1){perror("connect"); exit(1);}
    } else {
        ss = socket(PF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(atoi(argv[1]));
        addr.sin_addr.s_addr = INADDR_ANY;
        bind(ss, (struct sockaddr *)&addr, sizeof(addr));
        listen(ss, 10);
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(struct sockaddr_in);
        s = accept(ss, (struct sockaddr *)&client_addr, &len);
        if (s == -1){perror("accept"); exit(1);}
    }

    char data[1000];
    while(1){
        int n = read(s,data,1000*sizeof(unsigned char));
        if(n == -1){ perror("read"); exit(1); }
        if (n == 0) break;
        write(1, data, n);
    }
    close(ss

















    );
    return 0;
}