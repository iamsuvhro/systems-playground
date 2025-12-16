#include <stdio.h>
#include <string.h> // Needed for strlen

int main()
{
   int arr[] = {1, 10, 19, 28};
   int *arrayptr = arr;

   printf("%d\n", arr[0]);
   printf("%d\n", arrayptr[0]);

   printf("=========================\n");
   printf("Size of arr[0]: %zu\n", sizeof(arr[0]));
   printf("Size of arrayptr[0]: %zu\n", sizeof(arrayptr[0]));

   printf("=========================\n");
   printf("Address of arr[0]: %p\n", (void *)&arr[0]);
   printf("Address of arrayptr[0]: %p\n", (void *)&arrayptr[0]);

   printf("=========================\n");
   printf("Value of arr[1]: %d\n", *(&arr[1]));
   printf("Value of arr[1]: %d\n", *(arr + 1));
   printf("Value of arr[1]: %d\n", arr[1]);

   // arr cannot move because it's a fixed-location array
   arrayptr++;
   printf("===================================================\n");
   printf("Value pointed by arrayptr: %d\n", *arrayptr);
   printf("Value of arr[0]: %d\n", *arr);

   // Level 1: Pass by reference
   int total_money = 100;
   int *pay_bill = &total_money;

   printf("Before payment total_money: %d\n", total_money);
   *pay_bill -= 20;
   printf("After payment total_money: %d\n", total_money);

   // Level 2: Pointer arithmetic to find max
   int nums[] = {12, 5, 8, 20, 3};
   int *pnums = nums;
   int max = *pnums;

   for (int i = 0; i < 5; i++)
   {
      if (*pnums > max)
      {
         max = *pnums;
      }
      pnums++;
   }
   printf("Highest value in nums: %d\n", max);

   // Level 3: Swap using pointers
   int x = 10;
   int y = 20;
   int *ptrX = &x;
   int *ptrY = &y;

   printf("Value of x before swap: %d\n", *ptrX);
   printf("Value of y before swap: %d\n", *ptrY);

   int temp = *ptrX;
   *ptrX = *ptrY;
   *ptrY = temp;

   printf("Value of x after swap: %d\n", *ptrX);
   printf("Value of y after swap: %d\n", *ptrY);

   // Level 4: Count evens using pointer walk
   int list[] = {11, 22, 33, 44, 55, 66};
   int count = 0;
   int *plist = list;

   for (int i = 0; i < 6; i++)
   {
      if (*plist % 2 == 0)
      {
         count++;
      }
      plist++;
   }
   printf("Even count: %d\n", count);

   // Level 5: Manual string length
   char name[] = "Gemini";
   char *pname = name;
   int length = 0;

   while (*pname != '\0')
   {
      length++;
      pname++;
   }
   printf("Total length: %d\n", length);

   // Level 6: Reverse string using two-pointer technique
   char str[] = "Gemini";
   char *start = str;
   char *end = str + strlen(str) - 1;

   while (start < end)
   {
      char t = *start;
      *start = *end;
      *end = t;
      start++;
      end--;
   }
   printf("Reversed: %s\n", str);

   return 0;
}
