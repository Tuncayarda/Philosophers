# Philosophers

> An implementation of Edsger Dijkstra’s famous **Dining Philosophers** concurrency problem, written in C for the 42 Cursus.  
> The goal is to model five (or more) philosophers who must share forks, eat, think and sleep without starving or dead-locking each other.:contentReference[oaicite:0]{index=0}

## 📁 Directory Layout

| Path | Purpose |
|------|---------|
| **`philo/Makefile`** | One-shot build script; creates `objs/`, compiles sources and links the final binary `philo`.:contentReference[oaicite:5]{index=5} |
| **`philo/includes/`** | Public headers (`philo.h`) defining `t_philo`, `t_program` plus every helper signature.:contentReference[oaicite:6]{index=6} |
| **`philo/srcs/`** | All implementation files (`main.c`, `init.c`, `routine.c`, `utils.c`, …).:contentReference[oaicite:7]{index=7} |
| **`philo/objs/`** | Auto-generated object files (ignored by Git). |
| **`.gitignore`** | Filters build artefacts and common temp files.:contentReference[oaicite:8]{index=8} |

---

## 🛠 Compilation

```bash
cd philo
make            # builds ./philo
make clean      # removes object files
make fclean     # removes object files + binary
make re         # full rebuild
````

The project is pure ANSI C; any modern **GNU tool-chain** or **Clang** works. No extra libraries are required beyond **pthread** (linked automatically by the Makefile).([GitHub][1])

---

## 🚀 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
        [number_of_times_each_philosopher_must_eat]
```

| Argument                                                   | Meaning                                                                            |
| ---------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| `number_of_philosophers`                                   | Count of philosophers *and* forks (1 – 200 as per subject).([GitHub][2])           |
| `time_to_die`                                              | Max ms a philosopher may stay hungry before dying.                                 |
| `time_to_eat`                                              | Eating time in ms (forks held).                                                    |
| `time_to_sleep`                                            | Sleeping time in ms.                                                               |
| `number_of_times_each_philosopher_must_eat` <br>(optional) | If set, the simulation stops once **every** philosopher has eaten this many times. |

### Example

```text
$ ./philo 5 310 200 100
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
...
```

---

## 🧩 Algorithm Sketch

1. **Initialization**

   * Parse/validate CLI, allocate `t_program`, create `philo_count` mutexes (forks) and spawn one thread per philosopher.([GitHub][3])
2. **Philosopher routine** (`philo_routine`)

   * *Think* → *take forks* → *eat* → *sleep* in a loop while `alive == true`.
   * Odd/even IDs pick up forks in opposite order to prevent circular wait.([GitHub][3])
3. **Monitor thread** (`routine_check`)

   * Polls all philosophers; marks `alive = false` if `current_time - last_meal ≥ time_to_die`.
   * When everyone has satisfied `meals_to_finish`, toggles the global `finished` flag so every routine can exit gracefully.([GitHub][4], [GitHub][3])
4. **Shutdown**

   * Join/detach every thread, destroy all mutexes and free heap buffers.

> For those curious about the theory, the canonical dead-lock conditions (mutual exclusion, hold-and-wait, no pre-emption, circular wait) are the same obstacles we neutralise here with careful lock ordering.([Wikipedia][5], [man7.org][6])

---

## 🧪 Testing & Debugging

| Tool                 | Command                                  | Why                                                                                  |
| -------------------- | ---------------------------------------- | ------------------------------------------------------------------------------------ |
| **Valgrind**         | `valgrind --leak-check=full ./philo …`   | Verifies zero leaks and detects invalid memory access.                               |
| **AddressSanitizer** | `CFLAGS='-g -fsanitize=address' make re` | Fast runtime detection of out-of-bounds or use-after-free.                           |
| **strace / ltrace**  | `strace -c ./philo …`                    | Measure sys-call footprint and blocking behaviour on mutexes/futexes.([man7.org][7]) |

---

## 📚 Further Reading

* 42 official subject PDF (EN version) for mandatory & bonus specs.([GitHub][2])
* 42 Evaluation Sheet to cross-check grading expectations.([42-evaluation-sheets-hub.vercel.app][8])
* *Dining Philosophers Problem* — Wikipedia overview & historical context.([Wikipedia][5])
* POSIX Threads (pthreads(7)) manual for mutex primitives.([man7.org][6])
* Medium article “Philosophers 42 Guide” for an approachable walk-through.([Medium][9])
