# Week 1 — C Fundamentals & Linux Programming Basics

The purpose of Week 1 is to build a solid foundation in C programming, understand the Linux development toolchain, and write your first system-level programs.  
By the end of this week, you will be comfortable with gcc, gdb, valgrind, strace, pointers, dynamic memory, basic syscalls, fork/exec, and completing a real mini-project.

---

## Table of Contents
1. Overview
2. Daily Plan
3. Day 1 — Hello C & Toolchain
4. Day 2 — Variables, Functions, Multi-file Builds
5. Day 3 — Pointers
6. Day 4 — Dynamic Memory
7. Day 5 — File I-O and Syscalls
8. Day 6 — Processes fork–exec
9. Day 7 — Mini Project: File Copier
10. Completion Checklist

---

# Overview

### Goals of Week 1
- Learn how to write, compile, and debug C programs.  
- Understand memory, pointers, and dynamic allocation.  
- Learn to use Linux developer tools (gcc, gdb, valgrind, strace).  
- Understand how processes work using fork() and exec().  
- Build a small but real systems-level project.

### Daily Time Required  
**1.5–2 hours per day** (evening schedule).

---

# Daily Plan

| Day | Topic | What You Learn |
|-----|-------|----------------|
| 1 | Toolchain, Hello C | gcc, binary basics, strace |
| 2 | Functions + Multi-file builds | modular C, linking |
| 3 | Pointers | memory addressing, arrays vs pointers |
| 4 | Dynamic Memory | malloc, free, valgrind |
| 5 | File IO | open/read/write syscalls |
| 6 | fork + exec | process creation |
| 7 | Project | file copier using syscalls |

---

# Day 1 — Hello C & Toolchain

**Time:** 1.5–2 hours

### What you learn
- gcc basics  
- how a C program becomes a binary  
- system calls using `strace`

### Tasks
1. Create folder `day1/`  
2. Create file `day1/hello.c` with:

```
#include <stdio.h>

int main() {
    printf("Hello Systems World!\\n");
    return 0;
}
```

3. Compile & run:


```
gcc hello.c -o hello
./hello

```

4. Inspect the binary:


```
file hello
ldd hello
strace ./hello
```

5. Write observations in `day1/README.md`

### Reading
OSTEP — Introduction (~10 pages)

### Deliverables
- hello.c  
- README.md

---

# Day 2 — Variables, Functions, Multi-file Builds

**Time:** 1.5 hours

### What you learn
- functions  
- headers  
- multi-file compilation  

### Tasks
1. Create `day2/main.c` and `day2/math_ops.c`
2. Implement add/sub/mul/div
3. Compile:


```
gcc main.c math_ops.c -o calc

```
### Reading
K&R C — Chapters 1–2

### Deliverables
- main.c  
- math_ops.c  
- README.md

---

# Day 3 — Pointers

**Time:** 2 hours

### What you learn
- pointers  
- memory addresses  
- pointer arithmetic  
- arrays vs pointers  

### Tasks
1. Create `day3/pointers.c`
2. Print addresses & use pointer arithmetic
3. Debug with:


```
gdb ./pointers

```

### Reading  
K&R — Pointers  
OSTEP — Processes overview

### Deliverables  
- pointers.c

---

# Day 4 — Dynamic Memory

**Time:** 2 hours

### What you learn
- malloc  
- free  
- realloc  
- valgrind usage  

### Tasks
1. Create `day4/memory.c`
2. Allocate & free memory
3. Introduce a memory leak
4. Detect with:


```
valgrind ./memory

```
### Reading  
CS:APP — Memory intro

### Deliverables
- memory.c  
- README.md  
- valgrind output

---

# Day 5 — File I-O and Syscalls

**Time:** 1.5 hours

### What you learn
- open  
- read  
- write  
- close  
- differences between stdio and syscalls  

### Tasks
1. Create `day5/file_ops.c`
2. Use syscalls to write a file
3. Compare with stdio (`fopen`, `fwrite`)

### Reading  
man 2 open  
OSTEP — File system intro

### Deliverables  
- file_ops.c

---

# Day 6 — Processes fork & exec

**Time:** 2 hours

### What you learn
- fork()  
- parent vs child  
- exec() family  
- process IDs  

### Tasks
1. Create `day6/fork_demo.c`
2. Use fork()
3. In child:


```
execl("/bin/ls", "ls", NULL);

```

4. Inspect via:


```
strace ./fork_demo

```

### Reading  
OSTEP — Process API

### Deliverables  
- fork_demo.c  
- README.md

---

# Day 7 — Mini Project: File Copier

**Time:** 2–3 hours

### Objective  
Build a file copier using ONLY syscalls.

### Requirements
- Accept input & output file names  
- Read in chunks (4096 bytes recommended)  
- Use open/read/write/close  
- Print:
  - total bytes copied  
  - time taken  

### Time measurement
Use:


```
clock_gettime(CLOCK_MONOTONIC, &ts);

```


README must include:
- example output  
- performance notes  

---

# Completion Checklist

- [ ] Compile C programs with gcc  
- [ ] Debug using gdb  
- [ ] Detect memory issues using valgrind  
- [ ] Understand pointers clearly  
- [ ] Use dynamic memory safely  
- [ ] Use POSIX syscalls  
- [ ] Understand fork() and exec()  
- [ ] Complete mini project  

---

# End of Week 1 Plan

