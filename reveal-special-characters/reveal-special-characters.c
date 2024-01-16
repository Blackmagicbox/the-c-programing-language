#include <stdio.h>

int main(void) {
  printf("Reveal Special characters\n");

  // Take each character
  // Put it back to screen
  // Replace any special character by its literal simple as a string

  printf("Type your text: ");
  int c;


  while ((c = getchar()) != EOF) {
    if (c == '\b') {
      puts("\\b");
    } else if (c == '\n') {
      puts("\\n");
    } else if (c == '\t') {
      puts("\\t");
    } else {
      putchar(c);
    }
  }

  return 0;
};