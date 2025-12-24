#include <stdio.h>

// BUFFER_SIZE: 4KB is the standard "Page Size" for most disks.
// It is the most efficient chunk size for moving data.
#define buffer_size 4096

int main(int argc, char *argv[])
{
   if (argc != 3)
   {
      printf("Usage: %s <source_file> <destination_file>", argv[0]);
      return 1;
   }
   // OPEN FILES
   FILE *source_file = fopen(argv[1], "r");
   if (source_file == NULL)
   {
      printf("Error: Could not open source file '%s'\n", argv[1]);
      return 1;
   }
   // DEST FILE
   FILE *destination_file = fopen(argv[2], "w");
   if (destination_file == NULL)
   {
      printf("Error: Could not open destination file '%s'\n", argv[2]);
      return 1;
   }
   printf("------------------- Copying file -------------------\n");
   char buffer[buffer_size];
   while (fgets(buffer, buffer_size, source_file) != NULL)
   {
      // fprintf(destination_file, "%s", buffer);
      fputs(buffer, destination_file);
   }
   printf("------------------- File Copied Successfully -------------------\n");

   fclose(source_file);
   fclose(destination_file);
   return 0;
}