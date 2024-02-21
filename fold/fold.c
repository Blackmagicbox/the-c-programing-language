#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define FOLD_LENGTH 80

int getLine (char line[], int maxLine) {
  int c = '\b';
  int i;

  for (i = 0; i < maxLine -1 && (c = getchar()) != EOF && c != '\n' ; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}


int main(void) {
  printf("Hello Fold!\n");
  return 0;
}