/* Dot Product
 *
 * This program computes the dot product of two vectors whose length is given by
 * a command-line argument. The objective of this exercise is to compute the dot
 * product of these vectors efficiently. A sequential version of the program is
 * given.
 *
 * The dot product of vectors u = [u1, u2, ..., un] and v = [v1, v2, ..., vn] is
 * given by:
 *
 *  dot(u, v) = u1*v1 + u2*v2 + ... un*vn
 *
 * You do not have to account for integer overflow in this program.
 *
 * USAGE:
 *  ./dtop <length>
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

// you do not need to modify this routine to complete this exercise.
long dot(size_t n, long u[n], long v[n]) {
  long sum = 0;

  for (size_t i = 0; i < n; i++)
    sum += u[i]*v[i];

  return sum;
}

// hint: you can use this procedure to check the output of your implementation.
// This is called using a test 'oracle'.
long seqdot(size_t n, long u[n], long v[n]) {
  return dot(n, u, v);
}

// read the provided length. This function will exit if an invalid argument is
// given.
size_t readlen(char* length) {
  char* end;
  long n = strtol(length, &end, 10);

  if (end == length) {
    fprintf(stderr, "invalid argument %s: %s\n", length, strerror(errno));

    exit(EXIT_FAILURE);
  }

  if (n <= 0) {
    fprintf(stderr, "length must be greater than 0, got: %ld\n", n);

    exit(EXIT_FAILURE);
  }

  return (size_t)n;
}

// Insert random integers between 1 and 10 into the provided vector. I don't use
// a seed for this program to make debugging easier, but one can be provided if
// the programmer would like an extra challenge. See srand().
void randomize(size_t n, long vec[n]) {
  for (size_t i = 0; i < n; i++) {
    vec[i] = (rand() % 10) + 1;
  }
}

int main(int argc, char* argv[argc]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <length>\n", argv[0]);

    return EXIT_FAILURE;
  }

  size_t length = readlen(argv[1]);

  long* v1 = calloc(length, sizeof(long));
  long* v2 = calloc(length, sizeof(long));

  if (!(v1 && v2)) {
    fprintf(stderr, "failed to allocate vectors error: %s\n", strerror(errno));

    return EXIT_FAILURE;
  }

  randomize(length, v1);
  randomize(length, v2);

  printf("dot(u, v) = %ld\n", seqdot(length, v1, v2));

  free(v1);
  free(v2);

  return EXIT_SUCCESS;
}
