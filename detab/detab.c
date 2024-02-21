#include <stdio.h>

#define MAX_BUFFER 1024
#define SPACE ' '
#define TAB_CHARACTER '\t'
#define TAB_OFFSET 2

void deSpacer(int *buffer);

int main(int argc, char *argv[]) {
  int buffer[MAX_BUFFER];
  int ch = '\b';
  int idx = 0;

  while ((ch = getchar()) != EOF) {
    if (ch == '\n' || idx >= MAX_BUFFER) {
      //Call the De-spacer method passing the Buffer as parameter
      buffer[idx] = '\0';
      idx = 0;
      deSpacer(buffer);
    } else {
      // Check if the buffer is in the last position
      buffer[idx] = ch;
      idx++;
    }
  }
  return 0;
}

void deSpacer(int *buffer) {
  int *p = buffer;
  int acc = 0;
  // Iterate over the p by shifting the pointer
  while (*p != '\0') {
    if (*p == SPACE) {
      acc++;
      if (acc >= TAB_OFFSET) {
        printf("\\t");
        acc = 0;
      }
    } else {
      for (int i = acc; i > 0; i--) {
        printf("\\s");
      }
      acc = 0;
      putchar(*p);
    }
    *p++;
  }
  putchar('\n');
}
