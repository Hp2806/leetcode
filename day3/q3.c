#include <stdio.h>
#include <string.h>

// Helper function to find the maximum of two integers
int max_val(int a, int b) {
    return (a > b) ? a : b;
}

void solve() {
    int n, x, s;
    if (scanf("%d %d %d", &n, &x, &s) != 3) return;
   
    char u[3005];
    scanf("%s", u);

    // dp[j] = maximum people seated using exactly j tables
    // Initialize with -1 to represent unreachable states
    int dp[3005];
    for (int i = 0; i <= x; i++) dp[i] = -1;
    dp[0] = 0;

    // current_limit tracks the maximum number of tables we could have possibly opened
    int current_limit = 0;

    for (int i = 0; i < n; i++) {
        if (u[i] == 'I') {
            // Introvert: Must start a new table (j -> j+1)
            for (int j = current_limit; j >= 0; j--) {
                if (dp[j] != -1 && j + 1 <= x) {
                    dp[j + 1] = max_val(dp[j + 1], dp[j] + 1);
                }
            }
            if (current_limit < x) current_limit++;
        }
        else if (u[i] == 'E') {
            // Extrovert: Must join a non-empty table (j stays same)
            for (int j = 1; j <= current_limit; j++) {
                if (dp[j] != -1 && (long long)dp[j] < (long long)j * s) {
                    dp[j]++;
                }
            }
        }
        else if (u[i] == 'A') {
            static int next_dp[3005];
            for (int j = 0; j <= x; j++) next_dp[j] = dp[j];

            for (int j = 0; j <= current_limit; j++) {
                if (dp[j] == -1) continue
                if (j + 1 <= x) {
                    next_dp[j + 1] = max_val(next_dp[j + 1], dp[j] + 1);
                }
                if (j > 0 && (long long)dp[j] < (long long)j * s) {
                    next_dp[j] = max_val(next_dp[j], dp[j] + 1);
                }
            }
            for (int j = 0; j <= x; j++) dp[j] = next_dp[j];
            if (current_limit < x) current_limit++;
        }
    }
    int result = 0;
    for (int j = 0; j <= x; j++) {
        if (dp[j] > result) result = dp[j];
    }
    printf("%d\n", result);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
