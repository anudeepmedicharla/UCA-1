#include <stdio.h>

long long int power(int x, int n, int d)
{
    long long int i, result = 1;
    if(n==0)
    {
        result = 1;
    }
    else if(n == 1)
    {
        result = x % d;
    }
    else
    {
      if(n%2 != 0)
        {
            result = x * power(x, n-1, d)%d; 
        }
     else
        {
            long long int y = power(x, n/2, d);
            result = (y * y)%d;
        }
    }
    return result;
}
    
int findPow(int x, int n, int d) 
{
    long long result = power(x, n, d);
    if(result < 0)
    {
        result = result + d;
    }
    return result;
}

int main()
{
    int num, powers, mod;
    printf("Enter number, power and mod: ");
    scanf("%d, %d, %d", &num, &powers, &mod);
    int res = findPow(num, powers, mod);
    printf("The result is: %d", res);
    return 0;
}
