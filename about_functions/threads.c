#include "libraries.h"

// Thread functions: create, join, detach

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
  //then try again with valgrind, then gdb. What is happening?

  //pthread_join(tid, NULL);
  //pthread_detach(tid);

  usleep(1000);
  printf("%s\n", str);

  //observe that str was changed in main by an action in a thread routine
  //how is memory handled in threads compared to processes(fork)?
  //what problems can this lead to? what are the benefits?

  return (0);
}
