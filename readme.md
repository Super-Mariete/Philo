*This project has been created as part of the 42 curriculum by made-ped.*

# 🍽️ Philosophers

## Description

**Philosophers** is a concurrent programming project from the 42 curriculum based on the classic **Dining Philosophers Problem**, originally formulated by Edsger Dijkstra in 1965. The problem illustrates the core challenges of concurrent systems: **synchronization**, **deadlock prevention**, and **data race avoidance**.

In this simulation, a number of philosophers sit at a round table with a fork between each pair of adjacent philosophers. Each philosopher alternates between three states: **thinking**, **eating**, and **sleeping**. To eat, a philosopher must pick up both forks adjacent to them. The challenge is to coordinate access to shared resources (forks) without causing deadlocks, starvation, or race conditions.

### Key concepts covered

- POSIX threads (`pthread`) — creation, joining, and lifecycle management
- Mutex locks for safe access to shared resources
- Thread synchronization and timing precision
- Deadlock prevention via even/odd philosopher fork ordering
- A dedicated **monitor thread** that detects death and meal completion conditions

> During development, several approaches were explored including an implementation of **Peterson's algorithm** for mutual exclusion and various Git branches to study deadlock and data race scenarios. These were ultimately discarded in favor of the standard `pthread_mutex` API as required by the project subject.

---

## Instructions

### Requirements

- CC compiler
- `make`
- POSIX-compliant OS (Linux / macOS)
- `pthread` library

### Compilation

```bash
make
```

This will produce the `philo` executable.

To clean object files:
```bash
make clean
```

To clean everything including the binary:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```

### Usage

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

| Parameter | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` | Time in milliseconds before a philosopher dies if they haven't started eating |
| `time_to_eat` | Time in milliseconds a philosopher spends eating |
| `time_to_sleep` | Time in milliseconds a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Simulation stops when all philosophers have eaten this many times |

### Examples

```bash
# 5 philosophers, no one should die
./philo 5 800 200 200

# Simulation stops after each philosopher eats 3 times
./philo 5 800 200 200 3

# 1 philosopher — takes one fork, cannot eat, dies
./philo 1 800 200 200

# Someone will die
./philo 4 310 200 100
```

---

## Technologies

| Technology | Role |
|---|---|
| **C (C99)** | Core implementation language |
| **POSIX Threads (`pthread`)** | Thread creation, joining, and mutex management |
| **Mutexes (`pthread_mutex_t`)** | Fork locking, death detection, print synchronization, meal tracking |
| **`gettimeofday`** | High-precision timing for death detection and sleep |
| **`make` / `Makefile`** | Build system |
| **Git** | Version control, used across multiple branches to experiment with deadlock and data race scenarios |
| **Valgrind / Helgrind** | Memory leak detection and thread error analysis |
| **ThreadSanitizer (`-fsanitize=thread`)** | Runtime data race detection |

---

## Resources

### Core references

- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming — Lawrence Livermore National Laboratory](https://hpc-tutorials.llnl.gov/posix/)
- [pthread_mutex_lock man page](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [pthread_create man page](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [gettimeofday man page](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)

### Deadlock & concurrency theory

- [Peterson's Algorithm — Wikipedia](https://en.wikipedia.org/wiki/Peterson%27s_algorithm)
- [Race Condition — Wikipedia](https://en.wikipedia.org/wiki/Race_condition)
- [Deadlock — Wikipedia](https://en.wikipedia.org/wiki/Deadlock)

### Tools

- [Valgrind / Helgrind documentation](https://valgrind.org/docs/manual/hg-manual.html)
- [ThreadSanitizer documentation](https://clang.llvm.org/docs/ThreadSanitizer.html)

### AI usage

[Claude (Anthropic)](https://claude.ai) was used in the following parts of the project:

- **When blocked on synchronization bugs** — to understand and debug subtle race conditions and incorrect mutex usage.
- **Project planning** — to organize the work into daily milestones and define incremental checkpoints.
- **Final validation checks** — to review the code for potential data races, logic errors in the monitor thread, and edge cases such as the `must_eat` stopping condition.
- **Memory leak analysis** — to interpret Valgrind and Helgrind output and identify mutex and allocation cleanup issues.
