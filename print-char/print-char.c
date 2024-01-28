#include <stdio.h>


int main(void) {

	printf("Type a character: ");
	int c;
	while ((c = getchar()) != EOF) {
		printf("getchar() != EOF: %d\n", c != EOF);
		putchar(c);
		printf("\n");
		printf("Type a character:");
	}

	printf("EOF: %d\n", EOF);


	return 0;
}
