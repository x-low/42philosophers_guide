#include "libraries.h"

// PART 1/3
// Time functions: usleep, gettimeofday
// Learning Objectives:
//    - How to use gettimeofday to obtain current time in different units
//    - How to use usleep
//    - How to write custom usleep wrapper functions for precision/ease of use

// gettimeofday reads number of seconds and microseconds
// elapsed since Unix Epoch into struct timeval

unsigned long long	get_current_time(void) {
  struct timeval	tv;

  gettimeofday(&tv, NULL); // read sec and microsec into struct
  return (tv.tv_sec * 1000 + tv.tv_usec / 1000); // return time in millisec
}

// usleep accepts parameter in microsec and is
// known to have slight inaccuracy in actual time slept

// lets write a wrapper function that accepts ms

void	usleep_in_milliseconds(int ms) {
  unsigned long long	start;

  start = get_current_time();
  while (get_current_time() <= start + ms - 1)
	usleep(100); // this is 0.1 ms
}

// why use that weird loop instead of just writing the following?

// void	usleep_in_milliseconds(int ms) {
// usleep(ms * 1000); }

// compare the actual time waited between the two implementations!
// small differences/inaccuracies accumulate over time

int	main() {
  unsigned long long	starting_time = get_current_time();
  usleep(1 * 1000); // it could be helpful to think of usleep(ms * 1000)
  usleep(200 * 1000); // sleeps 200 ms
  printf("The difference in time should be 201! Time elapsed: %lldms\n",
	  get_current_time() - starting_time);

  starting_time = get_current_time();
  for (int i = 0; i < 50; i++)
  usleep_in_milliseconds(40); // try switching the implementations
  printf("The difference in time should be 2000! Time elapsed: %lldms\n",
	  get_current_time() - starting_time);
}
