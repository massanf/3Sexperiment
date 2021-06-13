#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
  int ss = socket(PF_INET, SOCK_STREAM, 0);
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_addr.s_addr = INADDR_ANY;
  bind(ss, (struct sockaddr *)&addr, sizeof(addr));
  listen(ss, 10);
  struct sockaddr_in client_addr;
  socklen_t len = sizeof(struct sockaddr_in);
  int s = accept(ss, (struct sockaddr *)&client_addr, &len);
  if (s == -1){perror("accept"); exit(1);} else {printf("connected\n");}
  unsigned char data[1000];
  FILE *fpin;
  fpin = popen("rec -t raw -b 16 -c 1 -e s -r 44100 -", "r");
  int desc = fileno(fpin);
  printf("%d\n",desc);
  while(1){
      int n = read(desc,data,1000);
      if(n == -1){ perror("read"); exit(1); }
      if (n == 0) break;
      write(s,data,n);
  }
  close(s);
  close(ss);
  pclose(fpin);
  return 0;
}