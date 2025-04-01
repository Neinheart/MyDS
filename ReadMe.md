# DSU Learning Framework (C++23)

## 📚 Project Overview

This repository is part of a **dual-track learning plan** aimed at mastering both:

1. **Data Structures & Algorithms (DSA)** – starting with Disjoint Set Union (DSU).
2. **Modern C++ Development** – using C++23, including modules, ranges, concepts, and performance benchmarking.

The framework includes:
- Modular codebase using C++23 and CMake
- Automatic functional testing using `doctest`
- Benchmarking with high-resolution timers
- Structured test & bench directories
- Command-line switchable `main.cpp` supporting:
    - `all` – run all modules
    - `func` – run only functional tests
    - `bench` – run only benchmarks

---

## 📂 Project Structure

```
.
├── include/                 # Public headers
├── src/                    # Core data structures (e.g., naive/compressed DSU)
├── test/                   # Functional test cases (with doctest)
├── bench/                  # Benchmark tests (custom timers)
├── common/                 # Common utils: logging, registry, etc.
├── third_party/            # External dependencies (e.g., doctest.h)
├── main.cpp                # Main entry (dispatches tests/bench/all)
├── CMakeLists.txt          # CMake build config
└── README.md
```

---

## 🧪 Implemented Modules

| Module Name                  | Type         | Status       | Notes                      |
|-----------------------------|--------------|--------------|----------------------------|
| `dsu_naive`                 | Functional   | ✅ Completed | Basic union-find           |
| `dsu_compressed`            | Functional   | ⚡ Designing | Path compression version   |

---

## 🧪 Testing & Benchmarking

Each module comes with:

- **Unit tests** in `test/xxx_test.cpp`
    - Basic correctness
    - Edge case coverage
- **Benchmarks** in `bench/xxx_bench.cpp`
    - 1M element stress tests
    - Timing using `std::chrono::steady_clock`

---

## 🛠️ Build & Run

### Requirements

- C++23 compatible compiler (e.g., GCC 13+, Clang 17+, MSVC 2022)
- CMake 3.16+
- CLion or VSCode (recommended)

### Build

```bash
cmake -S . -B build
cmake --build build -j
```

### Run

```bash
./build/main all dsu_disjoint_set_naive      # run both tests + benchmarks
./build/main func dsu_disjoint_set_naive     # run only tests
./build/main bench dsu_disjoint_set_naive    # run only benchmark
```

---

## 🔬 Learning Plan

### 📀 Data Structures Track

| Data Structure | Versions               | Status         |
|----------------|------------------------|----------------|
| DSU            | naive, compressed      | 🟢 In progress |
| Segment Tree   | base, lazy propagation | ⏳ Upcoming    |
| Heap           | binary, d-ary          | ⏳ Upcoming    |

### 💡 Modern C++ Track

| Topic         | Status         |
|---------------|----------------|
| `auto`, `decltype` | ✅ Done        |
| `constexpr`, `consteval` | ⏳ In progress |
| Ranges/Concepts | ⏳ Upcoming    |
| Smart Pointers | ⛔ Skipped (manual memory by design) |

---

## 📓 Notes

- All source files use `snake_case`.
- All comments are written in **English**, while explanations in documentation use **Chinese** to facilitate understanding.
- Testing is automated via `doctest` using registration macros in `common/registry.h`.

---

## 📍 Todo

- [x] Build project structure
- [x] Implement `dsu_naive`
- [x] Add full test coverage for `dsu_naive`
- [ ] Implement `dsu_compressed`
- [ ] Add full test coverage for `dsu_compressed`
- [ ] Benchmark comparison of naive vs compressed
- [ ] Start segment tree module

---

## 🧠 Author’s Note

This repo is developed as part of my graduate study and preparation for 秋招 (Autumn job season). My goal is not only to prepare for coding interviews, but also to gain deeper understanding of algorithm design and modern C++ engineering practices.
