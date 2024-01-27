#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char *argv[]) {
  printf("Type your secret message: ");

  char filename[64] = "./encrypted.txt";

  if(argc > 1)
    strcpy(filename, argv[1]);

  int fp = open(filename,O_RDWR | O_CREAT, 0644 );
  if(fp == -1) {
    perror("open");
    return 1;
  } 
  
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

  write(fp, message, strlen(message));
  
  close(fp);

  printf("Encrypted message: %s\n", message);
  return 0; 
}

