#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int (*happiness)[3] = malloc(sizeof(int[n][3]));
    if (happiness == NULL) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &happiness[i][0], &happiness[i][1], &happiness[i][2]);
    }
    int (*dp)[3] = malloc(sizeof(int[n][3]));
    if (dp == NULL) {
        free(happiness);
        return 1;
    }
    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = happiness[i][0] + MAX(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = happiness[i][1] + MAX(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = happiness[i][2] + MAX(dp[i - 1][0], dp[i - 1][1]);
    }

    int final_max = MAX(dp[n - 1][0], MAX(dp[n - 1][1], dp[n - 1][2]));
    printf("%d\n", final_max);

    free(happiness);
    free(dp);

    return 0;
}
