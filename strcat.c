#include <stdio.h>
#include <stdlib.h>
void strcat1(char *s, char *t)
{
   while(*s)
   {
      s++;
   }
   while(*s++ = *t++);
}
int main()
{
    char str[] = "Hello";
    char str1[]  = "hello";
    strcat1(str, str1);
    puts(str);
    return 0;
}
