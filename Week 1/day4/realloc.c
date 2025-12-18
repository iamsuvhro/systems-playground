#include <stdio.h>
#include <stdlib.h>

int main()
{
   int number = 0;
   printf("Enter the initialize memory size: ");
   scanf("%d", &number);

   // Initialize memory allocation
   int *memory = malloc(number * sizeof(int));

   if (memory == NULL)
   {
      printf("Memory allocation failed \n");
      return 1;
   }
   else
   {
      printf("Success: Memory allocation successfull! \n");
      for (int i = 0; i < number; i++)
      {
         printf("Enter the memory #%d: ", i + 1);
         scanf("%d", &memory[i]);
      }
   }

   // Reallocation of existing memory size
   int newSize = 0;
   printf("Enter extended memory size: ");
   scanf("%d", &newSize);
   int *temp = realloc(memory, sizeof(int) * newSize);

   if (temp == NULL)
   {
      printf("Memory reallocation failed \n");
      return 1;
   }
   else
   {
      printf("Success: Memory reallocation successfull! \n");
      memory = temp;
      for (int i = number; i < newSize; i++)
      {
         printf("Enter the memory #%d: ", i + 1);
         scanf("%d", &memory[i]);
      }

      for (int i = 0; i < newSize; i++)
      {
         printf("%d -> ", memory[i]);
      }
   }

   free(memory);  // cleaning the memory
   memory = NULL; // avoid dangling pointers
}