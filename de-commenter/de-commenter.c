#include <stdio.h>

#define MAX_LINE_BUFFER 1024

int main(void) {
  // Read A line.
  int ch;
  char buffer[MAX_LINE_BUFFER];
  char *p = buffer;
  int comment_start = 0;
  int in_single_line_comment = 0;
  int in_multi_line_comment = 0;

  while ((ch = getchar()) != EOF) {
    if(ch !='\n') {
      if (ch == '/') {
        if (!in_multi_line_comment) {
          if (comment_start) {
            in_single_line_comment = 1;
          } else {
            comment_start = 1;
          }
        } else {
          in_multi_line_comment = 0;
        }
      } else if ( ch == '*' && comment_start) {
        in_multi_line_comment = 1;
      } else if (!in_single_line_comment && !in_multi_line_comment && !comment_start) {
        *p = (char) ch;
        p++;
      }
    } else {
      *p = '\0';
      printf("%s\n", buffer);
      p = buffer;
      if (!in_multi_line_comment) {
        comment_start = 0;
      }
      in_single_line_comment = 0;
    }
  }

  return 0;

}