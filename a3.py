#include <stdio.h>
int findStart(int p[], int d[], int n) {
    int start = 0;
    int deficit = 0;
    int balance = 0;
    for (int i = 0; i < n; i++) {
        balance += p[i] - d[i];
        if (balance < 0) {
            deficit += balance; 
            start = i + 1;      
            balance = 0;        
        }
    }
    return (balance + deficit >= 0) ? start : -1;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int p[n], d[n];
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    printf("%d\n", findStart(p, d, n));

    return 0;
}
