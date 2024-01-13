#include <stdio.h>

int main (void) {

	long nc = 0;
	long nl = 0;
	int c;

	printf("Type any character: ");

	while((c = getchar()) != EOF){
		if(c == '\n') {
			printf("Type any character: ");
			++nl;
		} else {
			++nc;
		}
	}
	printf("The total number of characters typed is :%ld\n",nc);
	printf("The total number of lines typed is :%ld\n",nl);
	
	return 0;
}

