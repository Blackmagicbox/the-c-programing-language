#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define FOLD_LENGTH 80

int getLine(char line[], int maxLine) {
  int c = '\b';
  int i;

  for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}

void foldLine(char line[], int maxLine, int foldLength) {
  int i = 0;
  int j = 0;
  int spaceHolder = 0;
  char tempLine[MAX_LINE_LENGTH];

  while (line[i] != '\0') {
    if (line[i] == ' ' || line[i] == '\t') {
      spaceHolder = i;
    }

    if (i >= foldLength) {
      if (spaceHolder > 0) {
        line[spaceHolder] = '\n';
        foldLength = spaceHolder + FOLD_LENGTH;
        spaceHolder = 0;
      } else {
        for (j = 0; j <= i; j++) {
          tempLine[j] = line[j];
          if (j == foldLength) {
            tempLine[j] = '\n';
            foldLength += FOLD_LENGTH;
          }
        }
        strcpy(line, tempLine);
      }
    }
    i++;
  }
}


int main(void) {
  char line[MAX_LINE_LENGTH];
  while (getLine(line, MAX_LINE_LENGTH)) {
    foldLine(line, MAX_LINE_LENGTH, FOLD_LENGTH);
    printf("%s", line);
  }
  return 0;
}