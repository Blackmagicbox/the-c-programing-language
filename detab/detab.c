#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 1024
#define SPACE ' '
#define TAB_CHARACTER '\t'
#define TAB_OFFSET 2

void deSpacer(char *buffer);

int main(int argc, char *argv[]) {
  // # Take the number of spaces and replace by the minimum number of tab characters necessary to keep the same space between words
  // Get each character on a line
  // Save to the buffer
  // iterate over the buffer printing/putting each character
  // Whenever a space appears:
  // Start counting (start a counter)
  // Whenever the number of spaces count matches the offset of the tab character.
  // Put, print a tabCharacter.
  // Set the Space counter to zero.
  // Keep iterating and printing.
  // Edge cases:
  // If the first Character of a line is a space, Ignore it.
  // If the number of spaces between two words is less than the offset of the Tab Character, print the correct amount of spaces instead.
  // If the space between two words is bigger than the offset, print/put as many tab characters you can fit preserving the space and whatever is left put the appropriate number of spaces.


  // Getting the line.

  int buffer[MAX_BUFFER];
  int ch = '\b';
  int idx = 0;

  while ((ch = getchar()) != EOF) {
    if (ch == '\n' || idx >= MAX_BUFFER) {
      //Call the De-spacer method passing the Buffer as parameter
      deSpacer(buffer);
      idx = 0;
    } else {
      // Check if the buffer is in the last position
      if (idx == MAX_BUFFER - 1) {
       buffer[idx] = '\0';
       idx = 0;
       continue;
      } else {
        buffer[0] = ch;
        idx++;
      }
    }
  }



  return 0;
}

void deSpacer(char *buffer){
  int acc = 0;
  // Iterate over the buffer by shifting the pointer
  while(*buffer != '\0') {
    if (*buffer == SPACE) {
      if (acc >= TAB_OFFSET) {
        putchar(TAB_CHARACTER);
        acc = 0;
      }
      acc++;
    } else {
      for (int i = acc; i > 0; i--) {
        putchar(SPACE);
      }
      putchar(*buffer);
    }
    *buffer++;
  }
  putchar('\n');
}
