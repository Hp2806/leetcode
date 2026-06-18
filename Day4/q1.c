#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    int n, i, j;
    if (scanf("%d", &n) != 1) return 0;
    double m[n];
    for(i = 0; i < n; i++)
    {
        scanf("%lf", &m[i]);
    }
    double *dp = (double *)calloc(n + 1, sizeof(double));
    if (dp == NULL) return 1;
    dp[0] = 1.0;
    for (i = 0; i < n; i++) 
    {
        double p_head = m[i];
        double p_tail = 1.0 - p_head;
        for (j = i + 1; j >= 0; j--) 
        {
            dp[j] = (j > 0 ? dp[j - 1] * p_head : 0.0) + dp[j] * p_tail;
        }
    }
    double total_probability = 0.0;
    for (j = 0; j <= n; j++) 
    {
        if (j > n - j) 
        {
            total_probability += dp[j];
        }
    }
    printf("%.10f\n", total_probability);
    free(dp);
    return 0;
}
