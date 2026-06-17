#include <stdio.h>
void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    for (int i = 1; i <= n; i++) {
        int element = 2 * i - 1;
        if (i == n) {
            printf("%d\n", element);
        } else {
            printf("%d ", element);
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }

    return 0;
}
