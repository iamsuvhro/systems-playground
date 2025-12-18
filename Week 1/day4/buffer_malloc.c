#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Needed for strcpy

int main()
{
   // 1. CREATION (Heap-Based Buffer)
   // We rent 20 bytes of space in the Heap.
   char *my_buffer = malloc(20 * sizeof(char));

   if (my_buffer == NULL)
      return 1;

   // 2. MANIPULATION (Writing Initial Data)
   // We copy the string "Binance" into our rented space.
   strcpy(my_buffer, "Binance");
   printf("Original Buffer: %s\n", my_buffer);

   // 3. MANIPULATION (Modifying Data)
   // Let's hack the buffer directly!
   // We want to change it to "Finance".
   // 'B' is at index 0. 'F' is the letter F.
   my_buffer[0] = 'F';

   // Let's add an exclamation mark at the end.
   // "Finance" is 7 letters (0-6). Index 7 is the null terminator.
   // We overwrite the null terminator with '!' and add a new null at 8.
   my_buffer[7] = '!';
   my_buffer[8] = '\0'; // We must manually stop the string!

   printf("Manipulated Buffer: %s\n", my_buffer);

   // 4. CLEANUP
   free(my_buffer);

   return 0;
}