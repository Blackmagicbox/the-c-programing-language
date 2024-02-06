#include <stdio.h>

#define WORDSIZE 64

void reverse(char *word){
  const int l = strlen(word);
  int e= l-1;
  int c = *word;

  while(c > l){
    if (c == e) break;
    const int t = word[c];
    word[c] = word[e];
    word[e] = t;
    c++;
    e--;
  }
}


int main (main) {



  return 0;
}
