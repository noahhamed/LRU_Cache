# LRU Cache (C++)

A C++ implementation of an LRU (Least Recently Used) cache that supports constant-time `get` and `put` operations.  
The project includes an interactive command-line demo and basic tests to verify correctness.

---

## Features
- Fixed-capacity cache with automatic eviction
- O(1) average-time `get` and `put` operations
- Least recently used item is evicted when capacity is exceeded
- Interactive CLI to experiment with cache behavior
- Simple assertion-based tests

---

## Tech Stack
- C++
- STL (`std::unordered_map`, `std::list`)
- CMake

---

## How It Works
- A hash map provides fast lookup from key to cache entry
- A doubly linked list tracks usage order
- Most recently used items are kept at the front
- Least recently used items are removed when the cache is full

---

## How to Run

### Requirements
- C++ compiler that supports C++17
- CMake
- An IDE such as CLion, or a terminal environment

### Steps
1. Clone the repository to your local machine.
2. Open the project folder in your IDE (for example, CLion).
3. Build the project using CMake.
4. Run the `lru_cache` target to start the interactive demo.
5. Follow the on-screen instructions to interact with the cache.

  
### Demo
1. Build and run the `lru_cache` target.
2. Enter a cache capacity when prompted.
3. Use the following commands:
   - `put <key> <value>` — insert or update an entry
   - `get <key>` — retrieve a value
   - `print` — display cache contents (MRU → LRU)
   - `quit` — exit the program
