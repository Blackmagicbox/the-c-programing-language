#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
  printf("World counter\n");
  
  int nw = 0;
  int c;
  int state = OUT;
  
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      nw++;
      putchar('\n');
    }
    putchar(c);
  }   
  
  printf("The number of words typed is %d\n", nw);
  
  return 0;
}
