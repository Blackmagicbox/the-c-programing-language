#include <stdio.h>
#include <stdbool.h>

void conversionTabletFromFahrenheitToCelsius(const bool r) {
    const int upper = 300;
    const int lower = 0;
    int fahr = lower;
    printf("Temperature conversion table\n");
    printf("\nFº\tCº\n");

    // If r == true, the table will be printed in reverse order
    if (r) {
        fahr = upper;
        while (fahr >= lower) {
            const int step = 20;
            const int celsius = 5 * (fahr - 32) / 9;
            printf("%d\t%d\n", fahr, celsius);
            fahr = fahr - step;
        }
        return;
    }
    while (fahr <= upper) {
        const int step = 20;
        const int celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void conversionTabletFromCelsiusToFahrenheit(const bool r) {
    const int upper = 300;
    const int lower = 0;
    int celsius = lower;
    printf("Temperature conversion table\n");
    printf("\nCº\tFº\n");

    // if r == true, the table will be printed in reverse order
    if (r) {
        celsius = upper;
        while (celsius >= lower) {
            const int step = 20;
            const int fahr = (9 * celsius) / 5 + 32;
            printf("%d\t%d\n", celsius, fahr);
            celsius = celsius - step;
        }
        return;
    }
    while (celsius <= upper) {
        const int step = 20;
        const int fahr = (9 * celsius) / 5 + 32;
        printf("%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}

int main() {
  conversionTabletFromFahrenheitToCelsius(0);
    printf("\n");
  conversionTabletFromCelsiusToFahrenheit(0);
    printf("\n");
  conversionTabletFromFahrenheitToCelsius(1);
    return 0;
}
