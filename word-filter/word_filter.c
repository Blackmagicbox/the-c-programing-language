#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 64

int main() {
  char word[MAX_WORD_LENGTH];
  int ch, offset = 0;

  while ((ch = getchar()) != EOF) {
    if (isspace(ch)) {
      word[offset] = '\0';
      if (offset > 0) {
        printf("%s\n", word);
      }
      offset = 0;
    } else {
      word[offset] = ch;
      offset++;
      if (offset == MAX_WORD_LENGTH - 1) {
        word[offset] = '\0';
        printf("%s\n", word);
        offset = 0;
      }
    }
  }

  return 0;
}