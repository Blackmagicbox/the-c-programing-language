#include <stdio.h>
#include <string.h>

#define WORD_SIZE 64

void reverse(char *word){
  const int l = (int) strlen(word);
  int e= l-1;
  int c = 0;

  while(c > l){
    if (c == e) break;
    const char t = word[c];
    word[c] = word[e];
    word[e] = t;
    c++;
    e--;
  }
}


int main (void) {
  char word[WORD_SIZE];




  return 0;
}
