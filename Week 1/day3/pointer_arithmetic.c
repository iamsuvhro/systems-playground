#include <stdio.h>

int main()
{
   int n = 10;
   int *ptrn = &n;
   printf("%d \n", ptrn);
   ptrn++;
   printf("%d \n", ptrn);

   char s = "Hello";
   char *ptrs = &s;
   printf("%d \n", ptrs);
   ptrs++;
   printf("%d \n", ptrs);
}