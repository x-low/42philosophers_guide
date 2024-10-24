#include "libraries.h"

// PART 2/3
// Thread functions: create, join, detach
// Learning Objectives:
//    - Understand how threads behave in execution
//    - When to use Multi-process vs Multi-threaded
//    - Using thread functions to change thread behaviour
//    - Debugging/memory management in multi-threaded programs

// join and detach determine how threads terminate.

// JOIN: blocking command similar to waitpid allows
// synchronisation between threads and exit status retrieval

// DETACH: non-blocking command useful for independent tasks that
// are not acted upon by other threads. No synchronisation/exit status retrieval

void  *routine(void *str) { // what prototype format must routine follow?
  char  *s = str;
  s[0] = 'B';
  while (1);
  return (NULL);
}

int main() {
  char  *str = malloc(2);
  pthread_t tid;

  str[0] = 'A';
  str[1] = '\0';
  pthread_create(&tid, NULL, &routine, str);

  //try executing the program with either join or detach
  //then try again with valgrind. What is happening?

  //pthread_join(tid, NULL);
  //pthread_detach(tid);

  usleep(1000);
  printf("%s\n", str);

  //observe that str was changed in main by an action in a thread routine
  //how is memory handled in threads compared to processes(fork)?
  //what problems can this lead to? what are the benefits?

  return (0);
}

//gdb is not the most useful tool for this.
//figure out how to follow threads in gdb and find out why?
//try creating multiple threads and print something in the routine
//what happens in gdb when you attach to a thread and run the program?
