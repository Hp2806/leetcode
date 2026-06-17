#include <stdio.h>
#include <string.h>
int is_binary(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') return 0;
    }
    return 1;
}
void solve() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return;
    char s[200005];
    scanf("%s", s);
    if (!is_binary(s)) {
        printf("%s ", s);
        scanf("%s", s);
    }
    int count[k];
    for (int i = 0; i < k; i++) count[i] = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            count[i % k]++;
        }
    }
    int possible = 1;
    for (int i = 0; i < k; i++) {
        if (count[i] % 2 != 0) {
            possible = 0;
            break;
        }
    }
    if (possible) printf("YES\n");
    else printf("NO\n");
}
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
