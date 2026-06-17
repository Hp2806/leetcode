#include <stdio.h>

int main()
{
    int n, digit, sum = 0;
    
    printf("Enter the car no:");
    scanf("%d", &n);
    
    if (n < 1000 || n > 9999)
    {
        printf("%d is not a valid car number\n", n);
    }
    else
    {
        int temp = n; 
        
        while (temp > 0) 
        {
            digit = temp % 10;   
            sum += digit;     
            temp = temp / 10;       
        }
        if (sum % 3 == 0 || sum % 5 == 0 || sum % 7 == 0)
        {
            printf("Lucky Number\n");
        }
        else
        {
            printf("Sorry its not my lucky number\n");
        }
    }
    
    return 0;
}
