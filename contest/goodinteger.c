#include <stdio.h>
#include <stdbool.h> 

bool checkGoodInteger(int n) {
    int sum1 = 0; 
    int sum2 = 0; 
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;   
        sum1 += digit;           
        sum2 += (digit * digit); 
        temp /= 10;              
    }
    int sub = sum2 - sum1;
    if (sub < 50) {
        return false;
    } else {
        return true;
    }
}
