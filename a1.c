#include <stdio.h>
int main() {
    int n, m, i, j, x, found = 0;
    scanf("%d %d", &n, &m);
    int mat[n][m]; 
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    scanf("%d", &x);
    i = 0;
    j = m - 1;
    while (i < n && j >= 0) {
        if (mat[i][j] == x) {
            found = 1;
            break;
        }
        if (mat[i][j] > x) 
            j--; 
        else 
            i++; 
    }
    if (found) {
        printf("Element is present in the matrix\n");
    } else {
        printf("Element is not present in the matrix\n");
    }
    return 0;
}
