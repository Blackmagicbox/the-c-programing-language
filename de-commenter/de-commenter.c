#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_BUFFER 1024
#define LINE_BREAK '\n'
#define COMMENT_STARTER_CHAR '/'
#define MULTI_LINE_COMMENT_MARKER '*'

int main(int argc, char *argv[]) {
  int ch;
  char buffer[MAX_LINE_BUFFER];
  char *p = buffer;
  int start_comment = 0;
  int in_single_line_comment = 0;
  int in_multi_line_comment = 0;
  int star_comment = 0;

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
    if (ch != LINE_BREAK) {
      if (ch == COMMENT_STARTER_CHAR) {
        if (!in_multi_line_comment) {
          if (start_comment) {
            in_single_line_comment = 1;
          } else {
            start_comment = 1;
          }
        } else if (star_comment) {
          in_multi_line_comment = 0;
          star_comment = 0;
        }
      } else if (ch == MULTI_LINE_COMMENT_MARKER) {
        if (start_comment) {
          in_multi_line_comment = 1;
          start_comment = 0;
        } else if (in_multi_line_comment) {
          star_comment = 1;
        }
      } else if (!in_single_line_comment && !in_multi_line_comment && !start_comment) {
        *p = (char) ch;
        p++;
      }
    } else {
      *p = '\0';
      printf("%s\n", buffer);
      fprintf(op, "%s\n", buffer);
      p = buffer;
      if (!in_multi_line_comment) {
        start_comment = 0;
      }
      in_single_line_comment = 0;
    }
  }

  fclose(fp);
  fclose(op);

  return 0;

}