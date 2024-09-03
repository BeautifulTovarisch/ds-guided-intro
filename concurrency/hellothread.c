/** Hello Threads
 *
 * This program introduces the basic usage of pthreads. Its sole functionality
 * is to use a thread handler to output "hello, world" to STDOUT. This program
 * contains a bug, however, and does not print anything out to the terminal. A
 * helper function for creating a thread is provided for your convenience.
 *
 * Modify the program below to output "hello, world" deterministically.
 *
 * It is advised to compile with the following command:
 *
 *  c99 -Wall -Wextra -o hellothread -c hellothread.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

// Do not modify.
void* sayHello(void *vargp) {
  // Unused
  (void)vargp;

  printf("hello, world!\n");

  return (void*)0;
}

// pthread_helper executes [fn] under thread [tid]. This helper handles errors
// on behalf of the caller. If an error occurs, the program will print to STDERR
// and exit.
//
// You do not need to modify this procedure.
void pthread_helper(pthread_t* tid, void* (*fn)(void*)) {
  int rc;
  if ((rc = pthread_create(tid, (void*)0, fn, (void*)0))) {
    fprintf(stderr, "error creating thread %s\n", strerror(rc));

    exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[argc]) {
  // Unused
  (void)argv;

  pthread_t thread_id;
  pthread_helper(&thread_id, sayHello);

  return EXIT_SUCCESS;
}
