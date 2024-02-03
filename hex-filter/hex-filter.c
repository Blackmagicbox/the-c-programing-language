#include <stdio.h>

#define MAX_TERMINAL_LINE_SIZE 80

int main(void){
  int ch = 0;
  int chIndex = 0;

  while ((ch = getchar()) != EOF) {
    if (chIndex + 2 == MAX_TERMINAL_LINE_SIZE) {
      putchar('\n');
      chIndex = 0;
    }
    printf("%02x", ch);
    chIndex += 2;
  }
  putchar('\n');

  return 0;
}