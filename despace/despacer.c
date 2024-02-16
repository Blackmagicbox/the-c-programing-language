#include <stdio.h>
#define TAB_CHARACTER '\t'
#define SPACE ' '
#define OFFSET 4
#define MAX_BUFFER 1024
#define NEW_LINE '\n'

void calculate_tabs(int spaces);

int get_line(char line[], int limit) {
  char ch;
  int i;
  for (i = 0; i < limit - 1 && (ch = getchar()) != EOF && ch != NEW_LINE; ++i) {
    line[i] = ch;
  }
  return i;
}

void calculate_tabs(const int spaces) {
  // Check the number of spaces
  // If the number of spaces is not 0 and less or equal to OFFSET - put one Tab Character
  // Else cont == spaces / OFFSET

  if (spaces != 0 && spaces <= OFFSET) {
    putchar(TAB_CHARACTER);
  } else {
    int count = spaces / OFFSET;
    for (int i = 0; i < count; i++) {
      putchar(TAB_CHARACTER);
    }
  }
}

int main(void) {
  // Read characters into line[] until limit is reached, EOF is encountered, or a newline ch is read
  int ch;
  int i;
  char line[MAX_BUFFER];

  while ((i = get_line(line, MAX_BUFFER)) > 0) {
    for (ch = 0; ch < i; ch++) {
      if (ch != SPACE) {

      }
      if (line[ch] == SPACE) {
        calculate_tabs(0);
      } else {
        putchar(line[ch]);
      }
    }
  }

  return 0;
}