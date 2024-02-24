#include <stdio.h>

#define MAX_LINE_BUFFER 1024

int main(void) {
  // Read A line.
  int ch;
  char buffer[MAX_LINE_BUFFER];
  char *p = buffer;
  int single_line_comment_start = 0;
  int in_single_line_comment = 0;

  while ((ch = getchar()) != EOF) {
    if(ch !='\n') {
      if (ch == '/') {
        if (single_line_comment_start) {
          in_single_line_comment = 1;
        } else {
          single_line_comment_start = 1;
        }
      } else if (!in_single_line_comment) {
        *p = (char) ch;
        p++;
      }
    } else {
      *p = '\0';
      printf("%s\n", buffer);
      p = buffer;
      single_line_comment_start = 0;
      in_single_line_comment = 0;
    }
  }

  return 0;

}