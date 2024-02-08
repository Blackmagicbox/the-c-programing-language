#include <stdio.h>
#define TAB '\t'
#define SPACE ' '
#define OFFSET 4
#define MAX_BUFFER 1024
#define NEW_LINE '\n'

int get_line(char line[], int limit) {
  char ch;
  int i;
  for (i = 0; i < limit - 1 && (ch = getchar()) != EOF && ch != NEW_LINE; ++i) {
    line[i] = ch;
  }
  return i;
}
void calculate_tabs() {
  for (int j = 0; j < OFFSET; j++) {
    putchar(' ');
  }
}
int main(void) {
  // Read characters into line[] until limit is reached, EOF is encountered, or a newline ch is read
  int ch;
  int i;
  char line[MAX_BUFFER];

  while ((i = get_line(line, MAX_BUFFER)) > 0) {
    for (ch = 0; ch < i; ch++) {
      if (line[ch] == SPACE) {
        calculate_tabs();
      } else {
        putchar(line[ch]);
      }
    }
  }

  return 0;
}