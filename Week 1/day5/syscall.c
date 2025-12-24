#include <stdio.h>
#include <unistd.h> // "Unix Standard" - Contains read(), write(), close()
#include <fcntl.h>  // "File Control" - Contains O_CREAT, O_WRONLY flags
#include <string.h>
int main()
{
   int file_descriptor;
   char buffer[100];

   // file_descriptor = open(PATH, FLAGS, PERMISSIONS);
   // O_CREAT: "If it doesn't exist, create it."
   // O_WRONLY: "I only want to write."
   // O_TRUNC: "If it exists, truncate (wipe) it to zero bytes first."
   // 0644 (Permissions): This is the Linux permission code.
   // 6 (You): Read + Write.
   // 4 (Group): Read only.
   // 4 (Everyone else): Read only.
   file_descriptor = open("demo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
   if (file_descriptor < 0)
   {
      perror("open failed");
      return 1;
   }
   char *msg = "Hello from syscall write!";
   // strlen(msg): We must tell the Kernel exactly how many bytes to grab.
   write(file_descriptor, msg, strlen(msg));
   close(file_descriptor);

   // 3. REOPEN FOR READING
   file_descriptor = open("demo.txt", O_RDONLY);
   if (file_descriptor < 0)
   {
      perror("open read failed");
      return 1;
   }

   // 4. READ USING RAW SYSCALL
   int bytes_read = read(file_descriptor, buffer, sizeof(buffer) - 1);
   buffer[bytes_read] = '\0';

   printf("File content: %s\n", buffer);
   close(file_descriptor);

   // 5. READ USING LOOP
   file_descriptor = open("test.json", O_RDONLY);
   printf("Kernal Identifier: %d\n", file_descriptor);
   char buffer_[100];
   int bytes_read_;

   // "read" returns 0 when it hits End of File (EOF)
   // It returns > 0 as long as it finds data.
   while ((bytes_read_ = read(file_descriptor, buffer_, sizeof(buffer_) - 1)) > 0)
   {
      // 1. Manually add the null terminator at the end of THIS chunk
      buffer_[bytes_read_] = '\0';
      // 2. Print this chunk
      printf("%s", buffer_);
      // Loop repeats! The next read starts exactly where the last one stopped.
   }

   close(file_descriptor);

   // Appeding extra information
   file_descriptor = open("demo.txt", O_WRONLY | O_APPEND);
   if (file_descriptor < 0)
   {
      printf("Unable to open file");
      return 1;
   }
   char *new_msg = "\nThis is the newline hasbeen appended.";
   int byte_written = write(file_descriptor, new_msg, strlen(new_msg));

   if (byte_written < 0)
   {
      perror("Write failed");
   }

   close(file_descriptor);

   return 0;
}