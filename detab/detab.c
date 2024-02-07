#include <stdio.h>

#define TAB_SPACES 2

void add_spaces (void) {
  for(int i = 0; i < TAB_SPACES; i++) {
    putchar(' ');
  }
}

int main(void) {
  int ch;

  printf("Type a word:\n");

  while((ch = getchar()) != EOF) {
    if(ch == '\t') {
      add_spaces();
    } else {
      putchar(ch);
    }
  }

  putchar('\n');

  return 0;
} 
