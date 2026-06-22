#include <stdio.h>

int findMaxProfit(int arr[], int size) {
    int max_so_far = arr[0];
    int current_max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > current_max + arr[i]) {
            current_max = arr[i];
        } else {
            current_max = current_max + arr[i];
        }
        if (current_max > max_so_far) {
            max_so_far = current_max;
        }
    }
    return max_so_far;
}

int main() {
    int profits[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(profits) / sizeof(profits[0]);
    printf("Input Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", profits[i]);
    }
    int max_profit = findMaxProfit(profits, size);
    printf("\nOutput (Maximum Continuous Profit): %d\n", max_profit);

    return 0;
}
