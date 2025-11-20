# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Yung-Chi Tseng  
Email: s1121411@mail.yzu.edu.tw  

## My Hash Function
### Integer Keys 
- Method: Mid-Square Hashing
- Formula / pseudocode:
  ```text
  Input: integer key, table size m
  1. Compute the square of the key:
        square = key * key

  2. Convert the square into a decimal string.

  3. If the number of digits ≤ 2:
        return square mod m

  4. Extract the middle digits by removing the first and last digit:
        middle = substring(square_string, 1, length-2)

  5. Convert middle substring back to integer.

  6. Return middle mod m.
  ```
- Rationale:
  - Breaks Sequential Patterns
    - Division method maps sequential integers (21,22,23…) to sequential buckets → causes clustering.
    - Middle square destroys this linearity by squaring the number first.
  - Better Distribution for Similar Keys
    - Keys like 21–30 and 51–60 look similar and cause predictable patterns under division.
    - Squaring expands the value and changes the digit structure, improving randomness.
  - Simple to Implement but More Effective
    - No need for complicated math or bit operations.
    - Just square the key, convert to string, and extract middle digits.
 
  
### Non-integer Keys
- Method: Sum of ASCII Values
- Formula / pseudocode:
  ```text
  Input: string str, table size m
  1. Initialize hash = 0

  2. For each character c in str:
        hash += ASCII value of c

  3. Return hash mod m
  ```
- Rationale: 
  - It is simple and effective for short strings.
  - The sum of ASCII values reflects all characters in the string.
  - The main design goal is to avoid using only the first character, because doing so would limit the hash to only 26 possible outcomes and cause many collisions (e.g., “cat”, “cow”, “car” would all collide).

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
### Integer Keys
- method 1: Division
  
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, ,5 , 6, 7, 8, 9, 0 | <ul><li>Linear mapping</li><li>21–30 & 51–60 collide into same buckets → huge clustering</li><li>bad for sequential keys</li></ul> |
| 11             | 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5| <ul><li>Better than m=10, but still purely linear</li><li>Both segments (21–30, 51–60) produce predictable linear sequences</li></ul>|
| 37             | 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 | <ul><li>Low collisions only because 37 is large relative to the key range</li><li>Hash function itself remains weak; no randomness</li></ul>|

- method 2: Mid-Square

| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 4, 8, 2, 7, 2, 7, 2, 8, 4, 0, 0, 0, 0, 1, 2, 3, 4, 6, 8, 0 | <ul><li>Non-linear distribution</li><li>21–30 and 51–60 show different patterns</li><li>Collisions exist but are non-structural</li></ul>|
| 11             | 4, 8, 2, 7, 2, 7, 2, 8, 4, 0, 5, 4, 3, 3, 2, 2, 2, 3, 4, 5 | <ul><li>Well-dispersed and balanced</li><li>Collisions exist but unpredictable</li><li>sequential key segments uncorrelated</li></ul>|
| 37             | 4, 8, 2, 7, 2, 7, 2, 8, 4, 0, 23, 33, 6, 17, 2, 13, 24, 36, 11, 23| <ul><li>Non-linear, very spread</li><li>Larger m enhances randomness from the mid-square operation</li></ul> |

### Non-integer Keys

| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 2, 4, 1, 9, 3, 8, 0, 5, 0, 3 | <ul><li>Small modulus range → many collisions;</li><li>uneven distribution</li></ul>|
| 11             | 4, 6, 3, 10, 4, 8, 3, 7, 1, 3 | <ul><li>Slight improvement, but ASCII-sum weaknesses remain → multiple collisions</li><li>weak randomness</li></ul>|
| 10             | 16, 18, 15, 33, 27, 5, 4, 19, 24, 0 | <ul><li>No collisions, but only because the table is large</li></ul>|

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
