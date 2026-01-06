# Thread-Safe MT19937 (C++)

A clean, deterministic, thread-safe implementation of the MT19937
(Mersenne Twister) pseudorandom number generator in modern C++.

This project focuses on **correct RNG infrastructure design**, not just
number generation — including deterministic seeding, thread isolation,
and reproducibility.

---

## Features

-  MT19937 implementation (32-bit)
-  Thread-safe RNG usage via `thread_local`
-  Deterministic per-thread random streams
-  Multithreaded correctness tests
-  Modular design (library + tests)
-  No global mutable RNG state
-  No external dependencies

---

## Design Overview

### Core RNG (`mt19937`)
- Implements the standard MT19937 algorithm
- Maintains per-instance internal state
- No global variables

### Thread RNG Manager

`ThreadRNGManager` provides deterministic, thread-safe access to RNGs.

Key properties:
- Each thread gets its own `mt19937` instance
- Seeds are derived deterministically from a master seed and thread index
- No reliance on OS thread IDs
- No locking required

```cpp
ThreadRNGManager rng_mgr(1234);
auto& rng = rng_mgr.get(thread_index);
uint32_t x = rng.next();
```

### Build Steps
```bash
git clone <repo-url>
cd mt19937_thread_safe
mkdir build
cd build
cmake ..
cmake --build .
```

### Running Tests
```bash
./test_thread_rng
```

### Notes

This project intentionally avoids std::mt19937 to explore
low-level RNG design and infrastructure.

The focus is correctness and reproducibility, not cryptographic security.

MT19937 is not suitable for cryptographic use.