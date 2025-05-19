# Philosophers

> An implementation of Edsger Dijkstra’s famous **Dining Philosophers** concurrency problem, written in C for the 42 Cursus.  
> The goal is to model five (or more) philosophers who must share forks, eat, think and sleep without starving or dead-locking one another.

## 📁 Directory Layout

| Path | Purpose |
|------|---------|
| **`philo/Makefile`** | Builds the project; creates `objs/`, compiles sources and links the final binary `philo`. |
| **`philo/includes/`** | Public headers (`philo.h`) defining `t_philo`, `t_program` and helper prototypes. |
| **`philo/srcs/`** | All implementation files (`main.c`, `init.c`, `routine.c`, `utils.c`, …). |
| **`philo/objs/`** | Auto-generated object files (ignored by Git). |
| **`.gitignore`** | Excludes build artefacts and common temp files. |

## 🛠️ Compilation

```bash
cd philo
make            # builds ./philo
make clean      # removes object files
make fclean     # removes object files + binary
make re         # full rebuild
````

The code is pure ANSI C; any modern **GCC** or **Clang** tool-chain works. No extra libraries are required beyond **pthread** (linked automatically by the Makefile).

## 🚀 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
        [number_of_times_each_philosopher_must_eat]
```

| Argument                                                 | Meaning                                                                              |
| -------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| `number_of_philosophers`                                 | Number of philosophers *and* forks (1 – 200, per the subject).                       |
| `time_to_die`                                            | Maximum time in **milliseconds** a philosopher may stay hungry before dying.         |
| `time_to_eat`                                            | Eating time in milliseconds (forks held).                                            |
| `time_to_sleep`                                          | Sleeping time in milliseconds.                                                       |
| `number_of_times_each_philosopher_must_eat` *(optional)* | If given, the simulation stops once **every** philosopher has eaten this many times. |

### Example

```text
$ ./philo 5 310 200 100
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
...
```

## 🧩 Algorithm Overview

1. **Initialization**

   * Parse and validate CLI arguments.
   * Allocate a `t_program` instance, create `philo_count` mutexes (forks) and spawn one thread per philosopher.

2. **Philosopher routine** (`philo_routine`)

   * Repeats **think → take forks → eat → sleep** while `alive == true`.
   * Odd and even IDs pick up forks in opposite order to avoid circular wait.

3. **Monitor thread** (`routine_check`)

   * Periodically checks each philosopher; sets `alive = false` if `now - last_meal ≥ time_to_die`.
   * When everyone has satisfied `meals_to_finish`, flips a global `finished` flag so each routine can exit cleanly.

4. **Shutdown**

   * Join or detach every thread, destroy all mutexes and free heap-allocated resources.

<details>
<summary>Dead-lock theory</summary>

The four classic dead-lock conditions—**mutual exclusion**, **hold-and-wait**, **no pre-emption** and **circular wait**—are neutralised here through lock ordering (odd/even strategy) and timely fork release.

</details>

## 🧪 Testing & Debugging

| Tool                 | Command                                  | Purpose                                                            |
| -------------------- | ---------------------------------------- | ------------------------------------------------------------------ |
| **Valgrind**         | `valgrind --leak-check=full ./philo …`   | Detects leaks and invalid memory access.                           |
| **AddressSanitizer** | `CFLAGS='-g -fsanitize=address' make re` | Fast runtime detection of out-of-bounds or use-after-free bugs.    |
| **strace / ltrace**  | `strace -c ./philo …`                    | Measures system-call footprint and mutex/futex blocking behaviour. |
