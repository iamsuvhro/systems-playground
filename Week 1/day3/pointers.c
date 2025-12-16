#include <stdio.h>

void printX(int *p)
{
   printf("Value of x is %d\n", *p);
}

int main()
{
   int x = 10;
   int *p = NULL; // Good practise to assign NULL if declaring a pointer
   p = &x;
   printf("Address of x is %p\n", &x);
   printf("Value of pX is %p\n", p);

   printf("Value of x %d\n", x);
   printf("Value at stored address: %d\n", *p); // dereferencing

   // To check size of integer
   printf("Size of x: %d bytes \n", sizeof(x));
   printf("Size of pX: %d bytes \n", sizeof(*p));

   printX(p);

   return 0;
}