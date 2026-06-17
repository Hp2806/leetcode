#include <stdio.h>
int main() {
    int decimal, temp, count = 0;
    int binary[32];
    int i = 0;
    printf("Enter a decimal number: ");
    if (scanf("%d", &decimal) != 1) {
        printf("invalid input\n");
        return 0;
    }
    if (decimal == 0) {
        printf("invalid input\n");
        return 0;
    }
    temp = (decimal < 0) ? -decimal : decimal;
    while (temp > 0) {
        binary[i] = temp % 2;
        if (binary[i] == 1) {
            count++;
        }
        temp = temp / 2;
        i++;
    }
    if (count == 0) {
        printf("invalid input\n");
        return 0;
    }
    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\nCount of 1's: %d\n", count);
    return 0;
}
