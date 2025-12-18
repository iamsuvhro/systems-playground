#include <stdio.h>
#include <stdlib.h>

int main()
{
   int number = 0;
   printf("Enter the memory size:\n");
   scanf("%d", &number);

   // Initialize memory
   int *memory = calloc(number, sizeof(int));

   if (memory == NULL)
   {
      printf("Memory allocation failed \n");
      return 1;
   }

   for (int i = 0; i < number; i++)
   {
      printf(" %d", memory[i]);
   }

   free(memory);  // cleaning the memory
   memory = NULL; // avoid dangling pointers

   // size_t current_memory_size = malloc_usable_size(memory);
   // printf("After cleaning current size of memory is %zu\n", current_memory_size);
}