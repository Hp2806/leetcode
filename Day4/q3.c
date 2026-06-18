#include <stdio.h>
#include <stdlib.h>
int a[100005];
int b[100005];
int c[100005];
int id[100005];


int asc(const void *x, const void *y) {
    return (*(int *)x - *(int *)y);
}


int desc(const void *x, const void *y) {
    return (c[*(int *)y] - c[*(int *)x]);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;


    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }


    for (int i = 0; i < m; i++) {
        scanf("%d %d", &b[i], &c[i]);
        id[i] = i; 
    }


    qsort(a, n, sizeof(int), asc);
    qsort(id, m, sizeof(int), desc);


    int p = 0;
    for (int i = 0; i < m; i++) {
        int cur = id[i];
        int count = b[cur];
        int val = c[cur];

        while (count > 0 && p < n && val > a[p]) {
            a[p] = val;
            p++;
            count--;
        }
        if (p >= n) break;
    }


    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("%lld\n", sum);

    return 0;
}
