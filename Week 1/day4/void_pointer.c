#include <stdio.h>

void print(void *p, char type)
{
   switch (type)
   {
   case 'i':
      printf("%d\n", *(int *)p);
      break;
   case 'c':
      printf("%c\n", *(char *)p);
      break;
   default:
      break;
   }
}

int main()
{
   // Practise Code
   int n = 10;
   char s[] = "hello";
   void *p = &n;
   printf("Getting the int value from void pointer: %d\n", *(int *)p);
   p = s;
   printf("Getting the char value from void pointer: %c\n", *(char *)p);

   // Mastery Code by Solving Problem
   // The "Universal Printer" (Void Pointers)
   int i = 10;
   char c = 'H';

   print(&i, 'i');
   print(&c, 'c');

   return 0;
}