/** Count
 *
 * This program uses two threads to increment a global counter. The counter is
 * initialized to 0. A command line argument determines the number by which each
 * thread will increment the counter. The final output of this program should be
 *
 *  2 * <inc>
 *
 *  where <inc> is a nonnegative integer.
 *
 *  However, there is a bug in the implementation. Correct the following program
 *  (without making it single-threaded).
 *
 * You can compile this program with
 *
 *  c99 -Wall -Wextra -o count count.c
 *
 * USAGE:
 *
 *  ./count <inc>
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

volatile long counter = 0;

// Thread routine.
void* count(void* vargp) {
  long inc = *(long *)vargp;

  for (int i = 0; i < inc; i++)
    counter++;

  return (void*)0;
}

// error-handling helper function. Included here to show an alternative strategy
// for handling errors.
void handle_pthread_error(int code) {
  if (code) {
    fprintf(stderr, "pthread error: %s\n", strerror(code));

    exit(EXIT_FAILURE);
  }
}

// Read <inc> CLI argument. Exits if unable to read an integer.
long readinc(char* incstr) {
  char* end;
  long inc = strtol(incstr, &end, 10);

  // No numbers read
  if (end == incstr) {
    fprintf(stderr, "invalid argument %s: %s\n", incstr, strerror(errno));

    exit(EXIT_FAILURE);
  }

  return inc;
}

int main(int argc, char* argv[argc]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <inc>\n", argv[0]);

    return EXIT_FAILURE;
  }

  long inc = readinc(argv[1]);
  if (inc < 0) {
    fprintf(stderr, "invalid argument: %ld\n", inc);

    return EXIT_FAILURE;
  }

  // Create two threads, providing &inc to each.
  pthread_t t1, t2;
  handle_pthread_error(pthread_create(&t1, (void*)0, count, &inc));
  handle_pthread_error(pthread_create(&t2, (void*)0, count, &inc));

  // Wait for each thread to finish its work.
  handle_pthread_error(pthread_join(t1, (void*)0));
  handle_pthread_error(pthread_join(t2, (void*)0));

  if (counter != 2*inc) {
    fprintf(stderr, "expected counter=%ld. Got %ld\n", 2*inc, counter);

    return EXIT_FAILURE;
  }

  printf("well done!\n");

  return EXIT_SUCCESS;
}
