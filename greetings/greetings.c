#include <stdio.h>
#include <time.h>

int main (int argc, char *argv[]) {
  time_t now ;
  time(&now);

  if(argc > 1) {
    printf("Hello, %s!\n", argv[1]);
    printf("Today is %s\n", ctime(&now));
  } else {
    printf("Hello, code master!\n");
    printf("Today is %ld\n", now);
  }
  return 0;
}