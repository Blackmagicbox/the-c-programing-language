#include <stdio.h>
#include <ctype.h>

int main (int charc, char *charv[]) {
  printf("Type your secret message: ");
  
  char message[100];
  char ch;
  int idx = 0;
  int offset = 25;

  while((ch = getchar()) != '\n') {
    if(idx >  99)
      break;
    if(isalpha(ch)) {
      if(ch + offset > 'z')
        message[idx++] = ch + offset - 26;
      else
      message[idx++] = ch + offset;
    } else {
      message[idx++] = ch;
    }
  }

  message[idx] = '\0';

  printf("Encrypted message: %s\n", message);
  return 0; 
}

