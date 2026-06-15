#include <stdio.h>
int findIndex(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        if (a[low] <= a[mid]) {
            if (key >= a[low] && key < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } 
        else {
            if (key > a[mid] && key <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1; 
}
int main() {
    int n, key;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &key);
    printf("%d\n", findIndex(a, n, key));
    return 0;
}
