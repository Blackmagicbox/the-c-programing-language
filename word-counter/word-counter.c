#include <stdio.h>

#define Debug

int main(void) {
  // Program to copy its input to its output, replacing each string of one or
  // more blanks by a single blank.
  int c;
  int lastc = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (lastc != ' ') {
        putchar(c);
      }
    }
    else {
      putchar(c);
    }
    lastc = c;
  }
  return 0;
}
