#include "libraries.h"

// PART 3/3
// Mutex functions: init, lock, unlock, destroy
// !! MUTEXES ONLY MAKE SENSE IF YOU UNDERSTAND THREADS !!
// Learning Objectives:
//    - Use mutexes to prevent memory access problems in multithreading
//    - Avoid common issues in implementing/cleaning up mutexes
//    - Discover debugging tools such as -fsanitise-thread and
//      valgrind tools like drd/helgrind

// common problems e.g data races/deadlock will be discussed in next section
// here we will discuss how threads behave with mutexes
