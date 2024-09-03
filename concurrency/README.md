# Concurrency

This module provides resources and exercises on concurrent programming and its
importance in distributed systems. Programmers who have taken an introductory
systems or operating systems course should find this material familiar. Those
without prior experience writing concurrent programs should approach this topic
slowly and deliberately.

A solid fundamental understanding of concurrency is important not only to write
programs that take full advantage of modern hardware, but in identifying subtle
bugs that arise in virtually any distributed system. Detecting concurrency bugs
is extraordinarily difficult; many of the tools normally used to find errors in
an implementation are unreliable when non-determinism is introduced.

## Objectives

- Understand the basic primitives of concurrent programming
- Identify the challenges potential bugs that arise in an concurrent system
- Develop a conceptual framework for thinking about concurrency

## Recommended Readings

- Tanenbaum (3.1)
- [What are Race Conditions?](https://dl.acm.org/doi/pdf/10.1145/130616.130623) (Sections 1 and 2)
- Youtube Lectures (from Chris Kanich's [Systems Programming Course](https://www.youtube.com/watch?v=TavEuAJ4z9A&list=PLhy9gU5W1fvUND_5mdpbNVHC1WCIaABbP))
    - [Concurrency: what's good about it, what's hard about it](https://www.youtube.com/watch?v=YKGa8NCJhZs&list=PLhy9gU5W1fvUND_5mdpbNVHC1WCIaABbP&index=37)
    - [what's the difference between processes, threads, and io multiplexing](https://www.youtube.com/watch?v=85T_ZaT8EUI&list=PLhy9gU5W1fvUND_5mdpbNVHC1WCIaABbP&index=37)

## Optional Readings

- [Dive into Systems](https://diveintosystems.org/) (Accessible introduction to Computer Systems)
    - [14.1 - Programming Multicore Systems](https://diveintosystems.org/singlepage/#_programming_multicore_systems)
    - [14.2 - Hello Threading!](https://diveintosystems.org/singlepage/#_hello_threading_writing_your_first_multithreaded_program)
    - [14.3 - Synchronizing Threads](https://diveintosystems.org/singlepage/#_synchronizing_threads)
    - [14.6 - Thread Safety](https://diveintosystems.org/singlepage/#_thread_safety)
- [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/) (Excellent Free Book!)
    - [Concurrency and Threads](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-intro.pdf)
    - [Locks](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf)
    - [Semaphores](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-bugs.pdf)

## Exercises

1. The program [hellothread.c](./hellothread.c) is meant to print "hello, world"
   from the `sayHello` routine. Instead, the program exits silently. Correct the
   bug in this program.

2. [count.c](./count.c) is a program that uses two threads to increment a counter.
   The program contains a bug known as a data race. Modify the program to fix
   this mistake.

   NOTE: If you are not convinced the program is incorrect, trying running it
   with larger inputs

   Challenge: Can you think of a way to fix the implementation that does not use
   explicit synchronization (e.g mutexes)?

3. Parallel computing has important applications in science and mathematics. In
   this exercise, a program called [dotp.c](./dotp.c) computes the dot product
   of two vectors. A sequential implementation is provided, but when the input
   to the program becomes large, the computation is incredibly slow. Modify the
   program to compute the dot product in parallel.

   HINT: using semaphores or other forms of synchronization are unlikely to have
   a dramatic impact on the performance of the program. Can you think of a way
   this operation can be split apart and then combined later?

   Challenge: Implementing your own linear algebra operations is generally ill-
   advised. Most hardware chips have Basic Linear Algebra Subroutines (BLAS) as
   a part of the firmware. For an extra challenge, modify the program use the
   c-bindings for BLAS (CBLAS).
