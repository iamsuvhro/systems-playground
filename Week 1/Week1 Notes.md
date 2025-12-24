# Weekly Learning Notes: C Programming & Systems

This document summarizes the key concepts and commands learned during the first week of a C programming and systems course.

---

## Day 1: Compilation and Debugging Fundamentals

The first day covered the essential workflow of turning C source code into an executable program and performing basic debugging.

### The GCC Compiler

The GNU Compiler Collection (GCC) is used to compile C code. A robust command includes flags for warnings, debugging, and output control.

```bash
gcc -Wall -Wextra -O0 -g hello.c -o hello
```

**Flag Breakdown:**

| Flag      | Purpose                               | "Crisp of Butter" 🧈                                                               |
| :-------- | :------------------------------------ | :--------------------------------------------------------------------------------- |
| `-Wall`   | Enables most common compiler warnings | This is your first line of defense against bugs. Always use it.                    |
| `-Wextra` | Enables even more warnings            | Catches subtle issues that `-Wall` might miss.                                     |
| `-O0`     | Disables all optimizations            | Essential for debugging, as it ensures the compiled code directly matches your source. |
| `-g`      | Includes debug symbols in the binary  | This is what allows GDB to link machine code back to your source lines and variable names. |
| `-o hello`  | Specifies the output filename       | Without this, your executable would be named `a.out` by default.                     |

### Inspecting the Binary

Once compiled, you can use several utilities to inspect the executable file.

```bash
# Identify the file type
file hello

# List the shared libraries it depends on
ldd hello

# Read the ELF header information
readelf -h hello
```

> **🧈 What is ELF?** ELF stands for "Executable and Linkable Format". It's the standard file format for executables, object code, and shared libraries on Linux and many other Unix-like systems.

### Basic Debugging with GDB

The GNU Debugger (GDB) is used to step through your code and inspect its state.

```bash
# Start a debugging session
gdb ./hello

# (inside gdb) Run the program
(gdb) run 
# You can also just use 'r'

# (inside gdb) Exit GDB
(gdb) quit
# Or just 'q'
```

---

## Day 2: Multi-File Projects & Deeper Debugging

This day focused on structuring projects with multiple source files and expanding GDB skills.

### Compilation and Linking Workflow

For larger projects, you compile files separately into **object files** (`.o`) and then link them together.

1.  **Compile Only** (`-c`): Create object files from each source file. An object file is partially compiled code waiting to be linked.

    ```bash
    gcc -Wall -Wextra -O0 -g -c main.c       # Produces main.o
    gcc -Wall -Wextra -O0 -g -c math_ops.c   # Produces math_ops.o
    ```

2.  **Link**: Combine the object files into a single executable.

    ```bash
    gcc main.o math_ops.o -o calc
    ```

### GDB Commands

Deeper GDB commands allow you to control execution and inspect memory.

-   `break main`: Sets a breakpoint at the `main` function.
-   `run`: Starts the program.
-   `next` (or `n`): Executes the next line, **stepping over** function calls.
-   `step` (or `s`): Executes the next line, **stepping into** function calls.
-   `print <variable>` (or `p <variable>`): Shows the current value of a variable.

> **🧈 `next` vs. `step`**: Use `next` when you trust a function works and just want to execute it. Use `step` when you want to dive into a function to see what's happening inside it.

---

## Day 3: The Power of Pointers

A deep dive into one of C's most defining features.

### Core Pointer Concepts

1.  **Defining (The "License")**: Creates a variable that is licensed to hold a memory address.
    ```c
    int *p = NULL; // Good practice: always initialize pointers to NULL.
    ```
    > **🧈 Why `NULL`?** Initializing a pointer to `NULL` prevents it from holding a random "garbage" address. Trying to access a garbage address is a common source of crashes.

2.  **Linking (The "Assignment")**: Assigns the memory address of another variable to the pointer.
    ```c
    int x = 10;
    p = &x; // The '&' operator means "address of".
    ```

3.  **Dereferencing (The "Action")**: "Follows" the pointer to access or modify the data at the address it holds.
    ```c
    *p = 20; // The '*' here means "value at the address". x is now 20.
    ```

### Pointer Arithmetic

`pointer++` increments the address by the `sizeof` the data type it points to.

> **🧈 Pro-Tip:** This is why defining the correct pointer type is critical! `int *p` and `char *p` point to the same address, but `p++` will move the pointer by 4 bytes for the `int*` and only 1 byte for the `char*`.

### `printf` Format Specifiers

A reference for printing different data types.

| Specifier | Meaning                  | Example                          |
| :-------- | :----------------------- | :------------------------------- |
| `%d`      | `int`                    | `printf("%d", my_int);`          |
| `%ld`     | `long`                   | `printf("%ld", my_long);`        |
| `%c`      | `char`                   | `printf("%c", my_char);`         |
| `%s`      | `string (char*)`         | `printf("%s", my_string);`       |
| `%f`      | `float`                  | `printf("%f", my_float);`        |
| `%lf`     | `double`                 | `printf("%lf", my_double);`      |
| `%p`      | Pointer Address          | `printf("%p", (void*)p);`        |
| `%x`      | Integer in Hexadecimal   | `printf("%x", my_int);`          |
| `%zu`     | `size_t` (from `sizeof`) | `printf("%zu", sizeof(int));`    |

> **🧈 Casting to `(void*)`**: When printing a pointer address with `%p`, it's best practice to cast it to `(void*)`. This is the generic pointer type and ensures compatibility across different systems.

---

## Day 4: Dynamic Memory Management

Learning to manually control memory on the **Heap**.

### Stack vs. Heap

-   **Stack**: Fast, automatically managed memory for local variables. Limited in size.
-   **Heap**: A large pool of memory that you control manually. Slower, but flexible.

### Heap Allocation Functions

1.  **`malloc` (Memory Allocation)**
    -   Allocates a block of bytes. The memory is **not initialized** and contains garbage.
    ```c
    int *arr = (int*) malloc(10 * sizeof(int));
    ```

2.  **`calloc` (Contiguous Allocation)**
    -   Allocates memory and **initializes all bytes to zero**. Slightly slower but safer than `malloc`.
    ```c
    int *arr = (int*) calloc(10, sizeof(int)); // Note the two arguments
    ```

3.  **`realloc` (Re-allocation)**
    -   Resizes a previously allocated memory block. May move the block to a new location.
    ```c
    int *bigger_arr = (int*) realloc(arr, 20 * sizeof(int));
    ```
> **🧈 The Golden Rule of `malloc`/`realloc`**: After any allocation, **ALWAYS** check if the returned pointer is `NULL`. This happens when the system is out of memory.
> ```c
> int *arr = (int*) malloc(10 * sizeof(int));
> if (arr == NULL) {
>     // Handle memory allocation failure!
>     perror("Failed to allocate memory");
>     exit(1); 
> }
> ```

4.  **`free` (Releasing Memory)**
    -   Returns memory to the system. If you don't `free` what you `malloc`, you get a **memory leak**.
    ```c
    free(arr);
    ```

### Valgrind: Your Memory Debugger

Valgrind is an essential tool for finding memory leaks and invalid memory access.

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./your_program
```
> **🧈 What is `--track-origins=yes`?** This tells Valgrind to try and identify exactly where an uninitialized value came from, making debugging much easier.

---

## Day 5: File I/O - Standard Library vs. System Calls

Exploring the two primary ways to interact with files.

### 1. Standard Library I/O (`stdio.h`)

-   **Abstraction Level**: High. It's portable and easy to use.
-   **Key Idea**: Uses a **buffer**. `fprintf` writes to an in-memory buffer, and the library decides when to actually perform the expensive write to the disk. This is efficient for many small writes.
-   **Functions**: `fopen()`, `fclose()`, `fprintf()`, `fscanf()`, `fgets()`.

**`fopen` Modes:**

| Mode | Meaning                          | File Status      |
| :--- | :------------------------------- | :--------------- |
| `r`  | Read only                        | Must exist       |
| `w`  | Write only                       | Created or wiped |
| `a`  | Append (write at end)            | Created if new   |
| `r+` | Read & Write                     | Must exist       |
| `w+` | Read & Write                     | Created or wiped |

### 2. System Call I/O

-   **Abstraction Level**: Low. A direct interface to the operating system kernel.
-   **Key Idea**: Unbuffered (by default). Every `read()` or `write()` call goes directly to the OS, which has a performance overhead (a "context switch"). This can be faster for transferring very large, single chunks of data.
-   **Functions**: `open()`, `close()`, `read()`, `write()`.

### Key Differences Summarized

| Feature           | Standard Library (`stdio.h`)  | System Calls (`unistd.h`)    |
| :---------------- | :---------------------------- | :--------------------------- |
| **Representation**  | `FILE*` (a complex struct)  | `int` (a file descriptor)    |
| **Buffering**     | Yes (buffered by default)     | No (unbuffered)              |
| **Performance**   | Faster for many small I/Os    | Faster for large, bulk I/Os  |
| **Portability**   | High (ANSI C standard)        | Lower (POSIX standard)       |

### Important Concepts

-   **File Permissions (`0644`)**: The leading `0` signifies an **octal** (base-8) number. `644` means:
    -   `6` (Owner): Read & Write
    -   `4` (Group): Read-only
    -   `4` (Other): Read-only
-   **File Descriptor**: A simple integer the kernel uses to identify an open file. It's like a coat-check ticket for your file.
-   **`perror()`**: A crucial function for diagnosing errors. When a system call fails, it sets a global `errno` variable. `perror()` prints a user-supplied message followed by a human-readable string describing the `errno` value.

    ```c
    int fd = open("myfile.txt", O_RDONLY);
    if (fd == -1) {
        // If open() failed, print a helpful error message and exit.
        perror("Failed to open myfile.txt");
        return 1;
    }
    ```