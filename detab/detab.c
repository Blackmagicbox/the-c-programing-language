#include <stdio.h>

int main(void) {
  int ch;

  printf("Type a word: ");

  while((ch = getchar()) != EOF) {
    if(ch == '\t') {
      putchar(' ');
      putchar(' ');
    } else {
      putchar(ch);
    }
  }

  putchar('\n');

  return 0;
} 
