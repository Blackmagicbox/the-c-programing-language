#include <stdio.h>

int main() {
    const int upper = 300;
    const int lower = 0;
    int fahr = lower;
    printf("Temperature conversion table\n");
    printf("\nFº\tCº\n");
    while (fahr <= upper) {
        const int step = 20;
        const int celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
