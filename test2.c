// fork many processes use setpriority and assign priority to check
// priority based scheduler
# include "types.h"
#include "stat.h"
#include "user.h"

//#deine NUM_PROCS 5

#define NUM_PROCS 10

int main(void) {
  int i, pid;
  
  // number for testing 0-200
  //int test_priority = 250

  printf(1, "Starting priority based test...\n");
  
  // Loop through until number of processes reached
  for(i=0; i< NUM_PROCS; i++) 
  {
    pid = fork();
    
    if(pid<0)
    {
      printf(1, "Fork Failed\n");
      exit();
    }
    else if (pid==0)
    { 
      // child process
      // varrying priorities
      int priority = (i + 1) * 20; // setting diff priorities
    
      // default priorites
      // int priority = 50;
  
      setpriority(priority);

      //print message to indicate priority and process id
      printf(1, "Process %d started with priority %d\n", getpid(), priority);
      

      // default priority
      // printf(1, "Process %d started with default priority %d\n", getpid(), 50);

      // busy loop
      volatile int counter = 0;
      while(counter < 50000000) 
      {
        counter++;
      } 
      printf(1, "Process %d complete.\n", getpid());
      exit();
    }
  }

  for(int i=0; i < NUM_PROCS; i++) 
  {
    wait();
  }
  
  printf(1, "Priority scheduling test finished.\n");
  exit();
}


