#include <stdio.h>
#include <stdlib.h>

int main()
{
   int number = 0;
   printf("Enter the memory size:\n");
   scanf("%d", &number);

   // Initialize memory
   char *memory = malloc(number * sizeof(char));

   if (memory == NULL)
   {
      printf("Memory allocation failed \n");
      return 1;
   }
   // CHECKING THE SIZE
   // Note: The OS might give you slightly MORE than you asked for (alignment padding)
   size_t actual_size = malloc_usable_size(memory);

   printf("You asked for: %d bytes\n", number);
   printf("System gave you: %zu bytes\n", actual_size);

   free(memory);  // cleaning the memory
   memory = NULL; // avoid dangling pointers

   size_t current_memory_size = malloc_usable_size(memory);
   printf("After cleaning current size of memory is %zu\n", current_memory_size);
}