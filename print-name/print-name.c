#include <stdio.h>

int main() {
    printf("Type your name: ");
    char name[50];
    scanf("%s", name);
    printf("Your name is %s\n", name);
    return 0;
}
