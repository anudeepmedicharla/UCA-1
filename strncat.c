#include <stdio.h>
#include <stdlib.h>
void strncat1(char *s, char *t, int n)
{
  int i;
   while(*s)
   {
      s++;
   }
   for(i = 0; i < n;i++)
   {
      *s++ = *t++;
   }
}
int main()
{
    char str[] = "Hello";
    char str1[]  = "hello";
    int n = 3;
    strncat1(str, str1, n);
    puts(str);
    return 0;
}