# Systems Playground — 12-Week Operating Systems & Low-Level Engineering Journey

This repository documents a structured 12-week journey into OS development, systems programming, C internals, Linux kernel fundamentals, concurrency, assembly, performance engineering, and systems architecture.

The purpose of this project is simple:

**Become a systems engineer who understands software from the perspective of hardware, memory, processes, CPU, kernel, and low-level constructs — not frameworks.**

This repo contains:
- Daily C and OS experiments  
- Kernel module exercises  
- Concurrency + networking projects  
- Bootloader and hobby OS work  
- Benchmarking, profiling, and assembly practice  
- Weekly deliverables and public write-ups  

All work is done inside a dedicated Linux VM to ensure safety and reproducibility.

---

# Why This Repository Exists

Modern engineers rely heavily on abstractions.  
This journey intentionally removes them.

The goal is to:
- Understand how the OS interacts with hardware  
- Understand memory deeply  
- Understand processes, syscalls, scheduling, threading  
- Build components that most engineers never touch  
- Reach FAANG/HFT-level systems depth  

By the end of 12 weeks, this repo becomes a portfolio demonstrating real systems engineering competence.

---

# Learning Philosophy

### 1. Depth > Speed  
Master fundamentals deeply instead of rushing.

### 2. Hands-on Every Day  
Every evening includes coding or debugging or reading OS internals.

### 3. Weekly Real Projects  
Each week ends with a tangible artifact (program, module, benchmark, etc.).

### 4. GitHub as Source of Truth  
Every day → commit.  
Every week → publish a summary.

---

# Repository Structure

```
systems-playground/
│
├── README.md
│
├── WEEK1/
│ ├── WEEK1.md
│ ├── day1/
│ ├── day2/
│ ├── day3/
│ ├── day4/
│ ├── day5/
│ ├── day6/
│ ├── projects/
│ └── assets/ (optional)
│
├── WEEK2/
│ ├── WEEK2.md
│ ├── day1/
│ ├── projects/
│ └── ...
│
├── WEEK3/
│ ├── WEEK3.md
│ ├── day1/
│ └── ...
│
└── WEEK12/
├── WEEK12.md
└── projects/
```


---

# HOW THE 12-WEEK EVENING JOURNEY WORKS

### Daily Time Blocks  
Default: **8:30–10:30 PM** IST (flexible)

#### High-energy day (2 hours):
- 5 min → setup  
- 75–90 min → coding + experiments  
- 20–30 min → reading + notes + commit  

#### Low-energy fallback (1–1.5h):
- 5 min → setup  
- 45–60 min → minimal task  
- 15–20 min → commit + notes  

---

# WEEK 0 — ENVIRONMENT & PREP

### Goal  
Build a safe playground for OS development.

### Day 0.1
- Create repo `systems-playground`
- Install VM (Ubuntu), VirtualBox/QEMU
- Create snapshot: **clean-base**
- Configure shared folders or SSH workflow

### Day 0.2
- Install: `build-essential`, gdb, valgrind, git, python3  
- Clone repo inside VM

### Deliverable:
VM ready + repo initialized.

---

# WEEK 1 — C Fundamentals & Memory  
**Goal:** Understand C, pointers, malloc/free, syscalls, fork/exec  
**Weekly Project:** memplay utilities + file operations + process demos

### Day 1 — Intro to C & Toolchain  
hello.c, sum.c, gcc basics, commit.

### Day 2 — Pointers & arrays  
pointer arithmetic, reverse_string.c.

### Day 3 — Dynamic memory  
malloc/free demos, valgrind leak checks.

### Day 4 — File IO  
filecopy.c using syscalls (open/read/write/close).

### Day 5 — fork & exec  
fork_demo.c + strace.

### Weekend (3–4h) — Pipe Aggregator  
Parent–child pipe communication project.

---

# WEEK 2 — Concurrency & Threads  
**Goal:** pthreads, mutexes, race conditions, IO multiplexing  
**Weekly Project:** Multi-threaded echo server

### Day 8 — pthread basics  
race condition demo → fix with mutex.

### Day 9 — Mutex + cond var  
producer-consumer.

### Day 10 — Atomics  
stdatomic.h, atomic increment.

### Day 11 — IO multiplexing  
select/poll echo server.

### Day 12 — Profiling  
perf, gprof.

### Weekend — Thread-pool echo server  
Benchmark using wrk/ab.

---

# WEEK 3 — Assembly, ABI, Microbenchmarks  
**Goal:** Registers, calling conventions, cache behavior  
**Weekly Project:** Cache + performance benchmark suite

### Day 15 — Inspect assembly  
gcc -S, objdump -d.

### Day 16 — Write assembly function  
add.s callable from C.

### Day 17 — Stack frame exploration  
locals, arrays, gdb stack inspection.

### Day 18 — Cache microbenchmarks  
stride tests, CSV output.

### Day 19 — Loop optimization  
unrolling, perf comparisons.

### Weekend — Benchmark Report  
Analyze cache + performance effects.

---

# WEEK 4 — Kernel Modules & User↔Kernel Boundary  
**Goal:** Write real kernel modules safely  
**Weekly Project:** chardev + ioctl interface

**Important:** Always use VM snapshots before kernel work.

### Day 22 — Kernel build env + hello module  
insmod, rmmod, dmesg.

### Day 23 — kmalloc/kfree  
memory allocation in kernel space.

### Day 24 — Character device  
alloc_chrdev_region, cdev_add, user clients.

### Day 25 — IOCTL  
toggle module behavior.

### Day 26 — Safe crashing & inspection  
test failure modes.

### Weekend — Final chardev project  
Polish module + README + logs.

---

# WEEKS 5–12 — ADVANCED PROJECT TRACK  
Each week = one real system artifact.

---

# WEEK 5 — User-space Scheduler Simulator  
Implement FCFS, RR, SJF, MLFQ.  
**Deliverable:** scheduler/ + visualizer.

---

# WEEK 6 — Write-Ahead Log (WAL) KV Store  
Append-only WAL + memtable + crash recovery.  
**Deliverable:** kv/wal-kv.

---

# WEEK 7 — Concurrency for KV Store  
Add locking, crash tests, durability.  
**Deliverable:** kv-store with concurrent writes.

---

# WEEK 8 — Replication (Leader–Follower)  
Log shipping, replay, consistency.  
**Deliverable:** replication/ demo.

---

# WEEK 9 — Bootloader + Minimal OS (QEMU)  
Stage 1 bootloader → print to serial.  
**Deliverable:** hobby-os/bootloader.

---

# WEEK 10 — OS Scheduler  
Cooperative or basic preemptive scheduler.  
**Deliverable:** hobby-os/scheduler.

---

# WEEK 11 — Bytecode VM OR KV Store Extensions  
Choose one major path.  
**Deliverable:** bytecode-vm/ or kv-compaction/.

---

# WEEK 12 — Final Integration & Presentation  
Benchmark, polish, record a 10–15 min screencast.  
Tag release **v1.0**.

---

# DAILY CHECKLIST TEMPLATE

[ ] Start VM (restore snapshot if kernel work)
[ ] Pull latest code
[ ] Open notes.md
[ ] 75–90 min coding / experiments
[ ] Run tests, capture logs
[ ] git commit -m "weekN: <task>"
[ ] Push
[ ] Write 10–20 lines of notes/reflection
[ ] 45–60 min small task
[ ] commit + note


---

# FREE RESOURCE LIST (EVERYTHING IS FREE)

- Operating Systems: Three Easy Pieces (OSTEP)  
- CS:APP — Computer Systems: A Programmer’s Perspective  
- MIT 6.828 — OS Engineering  
- Learn-C.org  
- Linux Kernel Module Programming Guide  
- Gynvael Coldwind (YouTube)  
- Ben Eater (YouTube)  
- Little OS Book + OSDev Wiki  
- strace, gdb, perf, valgrind manuals  
- System V AMD64 ABI (for calling conventions)  
- x86-64 assembly tutorials  

---

# FINAL NOTES (HONEST & DIRECT)

- Consistency > Talent.  
- Protect your evening block — it is a contract with your future self.  
- Commit before risky changes.  
- Snapshot before kernel work.  
- If you miss days → recover on weekend with a reduced load.  
- This 12-week journey builds the foundation top engineers rely on.  

This repo will be your **systems engineering identity**.

