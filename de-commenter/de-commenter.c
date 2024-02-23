#include <stdio.h>

#define NEWLINE '\n'
#define SINGLE_COMMENT_START '/'
#define MULTILINE_COMMENT_START '/'
#define MULTILINE_COMMENT_END '*'

int main(void) {
  int current_char;
  int in_single_comment = 0;
  int in_multiline_comment = 0;


  FILE *input = fopen("input.c", "r");
  FILE *output = fopen("output.c", "w");

  if (input == NULL || output == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  while ((current_char = fgetc(input)) != EOF) {
    if (!in_single_comment && !in_multiline_comment && current_char == SINGLE_COMMENT_START) {
      in_single_comment = 1;
      continue;
    } else if (in_single_comment && current_char == NEWLINE) {
      in_single_comment = 0;
    }
    if (!in_single_comment && !in_multiline_comment && current_char == MULTILINE_COMMENT_START) {
      in_multiline_comment = 1;
      current_char = fgetc(input);
      if (current_char != MULTILINE_COMMENT_END) {
        printf("Error: Multiline comment not closed properly!\n");
        continue;
      }
    } else if (in_multiline_comment && current_char == MULTILINE_COMMENT_END) {
      current_char = fgetc(input);
      if (current_char != MULTILINE_COMMENT_START) {
        printf("Error: Multiline comment not closed properly!\n");
        continue;
      }
      in_multiline_comment = 0;
    }
    if (!in_single_comment && !in_multiline_comment) {
      fputc(current_char, output);
    }
  }

  fclose(input);
  fclose(output);

  return 0;
}