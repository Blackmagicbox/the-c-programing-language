#include <stdio.h>

int main(void){
  /* This is the test for the de-commenter */
  char *name = "John Doe";

  // This line should be removed.
  printf("Hello, %s!\n", name);

  // Also this line should be removed.
  return 0;

  /* Here is one last bit of multi line comment,
   * so we can check if it's working:
   * One more line
   * Another one
   * Now yes we can finish
   * Here I go */
}
