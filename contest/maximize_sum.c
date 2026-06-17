#include <limits.h>
long long maxRatings(int** units, int unitsSize, int* unitsColSize) {
    int m = unitsSize;
    long long initialSum = 0;
    long long totalSecondMins = 0;
    int minOfSecondMins = INT_MAX;
    int globalMin = INT_MAX;
    int canPerformOperation = (m > 1); 
    for (int i = 0; i < m; i++) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        int n = unitsColSize[i];

        for (int j = 0; j < n; j++) {
            int val = units[i][j];
            
            if (val < firstMin) {
                secondMin = firstMin;
                firstMin = val;
            } else if (val < secondMin) {
                secondMin = val;
            }
            if (val < globalMin) {
                globalMin = val;
            }
        }
        initialSum += (long long)firstMin;
        if (n < 2) {
            secondMin = 0;
        }
        totalSecondMins += (long long)secondMin;
        if (secondMin < minOfSecondMins) {
            minOfSecondMins = secondMin;
        }
    }
    long long greedySum = 0;
    if (canPerformOperation) {
        greedySum = totalSecondMins - minOfSecondMins + globalMin;
    }
    return (initialSum > greedySum) ? initialSum : greedySum;
}
