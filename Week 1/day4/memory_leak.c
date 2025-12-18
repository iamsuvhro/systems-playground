#include <stdio.h>
#include <stdlib.h>

int main()
{
   // 1. Ask for 12 bytes (One block of heap memory)
   int *num = malloc(4);

   if (num == NULL)
      return 1; // Always check for NULL!

   num[0] = 1;

   // 2. Give the WHOLE block back
   free(num);

   return 0;
}