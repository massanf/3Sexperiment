/* 
 * p06.c
 */

/* 
 * usage:
 * 
 *   ./a.out
 *
 * Intented behavior:
 * It should print the content of this file.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

int main()
{
  int fd = open("p06.c", O_RDONLY);
  char buf[100];
  int count = 0;
  while (1) {
    int n = read(fd, buf, 100);
    count++;
    if (count == 1000) break;
    write(1, buf, n);
  }
  return 0;
}