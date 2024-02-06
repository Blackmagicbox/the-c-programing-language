#include <stdio.h>
#include <string.h>

#define WORD_SIZE 64

void reverse(char word[]) {
  const int l = (int) strlen(word);
  int e = l - 1;
  int c = 0;

  while (c <= e) {
    if (c == e) break;
    const char t = word[c];
    word[c] = word[e];
    word[e] = t;
    c++;
    e--;
  }
}

int main(void) {
  char word[WORD_SIZE];
  char ch;
  int p = 0;

  printf("Type words: ");

  while ((ch = getchar()) != EOF) {
    if (ch == '\n' || ch == ' ') {
      if (p > 0) {
        word[p] = '\0';
        reverse(word);
        printf("%s\n", word);
        p = 0;
        continue;
      }
    } else {
      if (p < WORD_SIZE - 1) {
        word[p] = ch;
      } else {
        word[p] = '\0';
        reverse(word);
        printf("%s\n", word);
        p = 0;
        continue;
      }
    }
    p++;
  }
  return 0;
}
