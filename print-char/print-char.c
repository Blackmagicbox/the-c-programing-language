#include <stdio.h>


int main(void) {

	printf("Type a character: ");
	int c;
	while ((c = getchar()) != EOF) {
		// Printe the value of (c = getchar()) != EOF
		printf("getchar() != EOF: %d\n", c != EOF);
		putchar(c);
		printf("\n");
		printf("Type a character:");
		c = getchar();
	}

	printf("EOF: %d\n", EOF);


	return 0;
}
