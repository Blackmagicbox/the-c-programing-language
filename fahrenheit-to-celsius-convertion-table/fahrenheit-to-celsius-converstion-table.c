#include <stdio.h>

void convertionTabletFromFahrenheitToCelcius(void) {
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
}

void convertionTabletFromCelciusToFahrenheit(void) {
    const int upper = 300;
    const int lower = 0;
    int celsius = lower;
    printf("Temperature conversion table\n");
    printf("\nCº\tFº\n");
    while (celsius <= upper) {
        const int step = 20;
        const int fahr = (9 * celsius) / 5 + 32;
        printf("%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}

int main() {
    convertionTabletFromFahrenheitToCelcius();
    printf("\n");
    convertionTabletFromCelciusToFahrenheit();
    return 0;
}
