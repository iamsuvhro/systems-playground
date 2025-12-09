WEEK 1 — C Fundamentals + Linux Programming Basics

Goal of Week 1:
Establish a strong C foundation, get comfortable with compiling, debugging, memory, and system-level thinking.
By end of week → you should be able to write small C programs and use Linux dev tools.

📅 Day 1 — Hello C + Toolchain Basics (1.5–2 hrs)

Topics:

gcc usage

basic C syntax

strace intro

Tasks:

Create day1/hello.c

Compile and run:

gcc hello.c -o hello
./hello


Analyze binary:

file hello
ldd hello
strace ./hello


Reading:

OSTEP Intro (first 10 pages)

Commit:
day1/hello.c, notes in day1/README.md

📅 Day 2 — Variables, Functions, I/O (1.5 hrs)

Topics:

data types

scanf/printf

multiple C files & compilation

Tasks:

Create day2/math_ops.c

Write functions: add, sub, mul, div

Compile with multiple files:

gcc math_ops.c main.c -o calc


Reading:

K&R C (free PDF) — Chapter 1 & 2

Short video: "C Programming Tutorial" by freeCodeCamp (first 30 mins)

Commit:
day2/ folder with programs + notes

📅 Day 3 — Pointers Deep Dive (2 hrs)

Topics:

pointers

pointer arithmetic

arrays vs pointers

memory layout

Tasks:

Write pointer examples in day3/pointers.c

Print addresses, offsets

Create small function operating on arrays

Debug with gdb:

gdb ./pointers


Reading:

K&R pointers section

OSTEP: Processes (first part)

Commit:
day3/pointers.c

📅 Day 4 — Dynamic Memory (malloc/free) (2 hrs)

Topics:

malloc

calloc

realloc

memory leaks

Tasks:

Build day4/memory.c

Allocate & free array

Introduce an intentional memory leak

Detect leak:

valgrind ./memory


Reading:

CS:APP Memory chapter (first 6–10 pages)

Commit:
day4/memory.c + valgrind output screenshot

📅 Day 5 — File I/O & Basic Syscalls (1.5 hrs)

Topics:

fopen/fread/fwrite

POSIX open/read/write

file descriptors

Tasks:

Create day5/file_ops.c

Write program using:

int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
write(fd, "hello", 5);
close(fd);


Compare with fopen version

Reading:

man 2 open

OSTEP: File system intro (5–7 pages)

Commit:
day5/file_ops.c

📅 Day 6 — Process & fork() Intro (2 hrs)

Topics:

fork()

getpid()

parent/child behavior

execve basics

Tasks:

Create day6/fork_demo.c

Print parent/child PIDs

Create a child that execs /bin/ls

Trace with strace:

strace ./fork_demo


Reading:

OSTEP Process API chapter

Short video: “fork() in 10 minutes”

Commit:
day6/

📅 Day 7 — Week 1 Mini Project (2–3 hrs)
Project: Mini File Copier with Logging

Build a program that:

takes 2 arguments: input file, output file

reads input file in chunks

writes to output file

prints logs: bytes copied, time taken

handles errors properly

Skills tested:

file I/O

loops

error handling

command-line args

performance measurement

Bonus: measure time using:

clock_gettime(CLOCK_MONOTONIC, &ts)


Commit:
projects/week1-filecopy/

Screenshot: run the program on a 20MB file and include output in README.
