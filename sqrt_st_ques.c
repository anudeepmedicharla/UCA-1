//If x is not a perfect square, return floor(sqrt(x)) Example:Input:11 Output:3 

#include <stdio.h>

int bin_search(int num)
{
        long int beg, mid, end, mid2;
        beg = 2;
        end = num/2;
        if(num == 1 || num == 2 || num == 3)
        {
            return 1;
        }
        else
        {  
            while(beg <= end)
            {
                if(end - beg == 1)
                {
                    return beg;
                }
                else
                {     
                    mid = (beg + end)/2;
                    mid2 = mid * mid;
                    if(mid2 > num)
                    {
                        end = mid;
                    }
                    else if(mid2 < num)
                    {
                        beg = mid;
                    }
                    else
                    {
                        return mid;
                    }
                }
            }
        }
    return 0;
}

int floorSqrt(int num) 
{
    int res = bin_search(num);
    return res;  
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int res = floorSqrt(num);
    printf("THE SQUAREROOT IS: %d\n", res);
    return 0;
}