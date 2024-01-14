#include <stdio.h>

#define Debug
int main(void) {
  // Count blanks tabs and new lines
  int c;
  int nc = 0;
  int nl = 0;
  int nt = 0;
  int nb = 0;

  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    } else if (c == '\t') {
      ++nt;
    } else if (c == ' ') {
      ++nb;
    }
  }

  printf("%d %d %d\n", nl, nt, nb);

// print only number of characters if debug is defined
#ifdef Debug
  printf("%d\n", nc);
#endif

  return 0;
}