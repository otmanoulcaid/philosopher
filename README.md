## Philosopher Project
# Overview
The Philosopher Project simulates the dining philosophers problem, a classic concurrency challenge in C. It involves multiple philosophers who alternately think and eat, sharing limited resources (forks) while avoiding deadlock and starvation. The project employs mutexes and semaphores for synchronization to manage access to shared resources.

# Features
Multi-threaded simulation using pthreads
Mutexes for locking resources
Semaphores to control access to forks
Configurable number of philosophers and eating times
Requirements
C compiler (GCC recommended)
pthread library
