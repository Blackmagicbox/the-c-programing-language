#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_BUFFER 1024

int main(int argc, char *argv[]) {
  int ch;
  char buffer[MAX_LINE_BUFFER];
  char *p = buffer;
  int comment_start = 0;
  int in_single_line_comment = 0;
  int in_multi_line_comment = 0;

  if (argc < 2) {
    printf("Usage: %s <FILENAME>\n", argv[0]);
    exit(-1);
  }

  FILE *fp = fopen(argv[1], "r");

  FILE *op = fopen("no-comments.c", "w+");

  if (fp == NULL) {
    printf("It was not possible to open the selected file\n");
    exit(-1);
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (ch != '\n') {
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
      } else if (ch == '*' && comment_start) {
        in_multi_line_comment = 1;
      } else if (!in_single_line_comment && !in_multi_line_comment && !comment_start) {
        *p = (char) ch;
        p++;
      }
    } else {
      *p = '\0';
      printf("%s\n", buffer);
      fprintf(op, "%s\n", buffer);
      p = buffer;
      if (!in_multi_line_comment) {
        comment_start = 0;
      }
      in_single_line_comment = 0;
    }
  }

  fclose(fp);
  fclose(op);

  return 0;

}