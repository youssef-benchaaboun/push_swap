*This project has been created as part of the 42 curriculum by yoben-ch and stelescu.*

# Push_swap

## Description

Push_swap is a sorting project developed at 42 School. The objective is to sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of stack operations.

Unlike traditional sorting algorithms, the goal is not only to obtain a sorted result but also to minimize the number of Push_swap operations generated.

This project implements the four strategies required by the subject:

* Simple Strategy — O(n²)
* Medium Strategy — O(n√n)
* Complex Strategy — O(n log n)
* Adaptive Strategy — automatically selects the most appropriate algorithm according to the disorder index

The repository also includes the bonus `checker` program used to validate generated instruction sequences.

---

# Authors

| Login                   | Contribution                                                                                                 |
| ----------------------- | ------------------------------------------------------------------------------------------------------------ |
| **yoben-ch**            | Input parsing and validation, option management, adaptive strategy, benchmark system, bonus implementation   |
| **stelescu**            | Medium algorithm implementation, small-sort algorithms (≤5 elements), argument splitting utilities           |
| **yoben-ch & stelescu** | Complex algorithm design and implementation (Radix-based strategy), overall project architecture and testing |

Both contributors fully understand all algorithms and all parts of the codebase.

---

# Features

## Input Validation

The program validates:

* Integer format
* INT_MIN / INT_MAX overflow
* Duplicate values
* Empty arguments
* Invalid flags

Invalid input produces:

```bash
Error
```

on stderr.

---

## Supported Flags

### Adaptive Mode (default)

```bash
./push_swap 4 2 1 3
```

or

```bash
./push_swap --adaptive 4 2 1 3
```

Automatically chooses the best strategy.

---

### Simple Strategy

```bash
./push_swap --simple 4 2 1 3
```

Forces the O(n²) algorithm.

---

### Medium Strategy

```bash
./push_swap --medium 4 2 1 3
```

Forces the O(n√n) algorithm.

---

### Complex Strategy

```bash
./push_swap --complex 4 2 1 3
```

Forces the O(n log n) algorithm.

---

### Benchmark Mode

```bash
./push_swap --bench --adaptive 4 2 1 3
```

Displays:

* Disorder percentage
* Selected strategy
* Complexity class
* Total operations
* Operation statistics

Benchmark information is printed on stderr as required by the subject.

---

# Build

## Compile Push_swap

```bash
make
```

## Compile Bonus Checker

```bash
make bonus
```

## Clean

```bash
make clean
```

## Full Clean

```bash
make fclean
```

## Rebuild

```bash
make re
```

---

# Stack Representation

The project uses an array-based stack implementation:

```c
typedef struct s_stack
{
    int *tab;
    int size;
    int top;
} t_stack;
```

Advantages:

* O(1) push/pop
* Low memory overhead
* Fast rotations

---

# Normalization

Before sorting, all values are normalized.

Example:

```text
Original:
40 10 90 20

Normalized:
2 0 3 1
```

Normalization replaces each number with its rank in the sorted sequence.

Benefits:

* Removes dependence on actual integer values
* Simplifies comparisons
* Improves radix performance

Complexity:

```text
Time: O(n²)
Space: O(n)
```

This preprocessing step is executed once before sorting.

---

# Disorder Index

The subject requires a disorder index.

Our implementation follows exactly the required inversion-count model.

For every pair:

```text
(i, j) with i < j
```

we count an inversion whenever:

```text
a[i] > a[j]
```

Formula:

```text
disorder = inversions / total_pairs
```

Implementation:

```c
int ft_disorder(t_stack *a)
```

The result is stored as:

```text
0 -> completely sorted
10000 -> maximum disorder
```

Equivalent to:

```text
0.00% -> 100.00%
```

---

# Adaptive Strategy

The adaptive algorithm chooses a sorting method according to the disorder index.

## Low Disorder

```text
disorder < 20%
```

Uses:

```text
Simple Strategy
```

Complexity:

```text
O(n)
```

for nearly sorted inputs because most elements are already close to their final positions.

---

## Medium Disorder

```text
20% ≤ disorder < 50%
```

Uses:

```text
Medium Strategy
```

Complexity:

```text
O(n√n)
```

---

## High Disorder

```text
disorder ≥ 50%
```

Uses:

```text
Complex Strategy
```

Complexity:

```text
O(n log n)
```

### Why these thresholds?

The thresholds come directly from the subject requirements:

* Below 20% the stack is close to sorted.
* Between 20% and 50% partitioning techniques become more efficient.
* Above 50% highly disordered data benefits from radix-based processing.

These values provide a smooth transition between the required complexity classes.

---

# Simple Algorithm — O(n²)

## Selected Strategy

We implemented a Selection-Style Extraction Sort.

### Idea

The algorithm repeatedly searches for the next smallest normalized value.

Example:

```text
A: 3 2 1 0
```

Move:

```text
0 -> stack B
1 -> stack B
2 -> stack B
3 -> stack B
```

Then restore:

```text
B -> A
```

Sorted result:

```text
0 1 2 3
```

### Why O(n²)?

To extract each value we may need to rotate through a significant part of the stack.

For:

```text
n elements
```

we may perform approximately:

```text
n + (n-1) + (n-2) + ...
```

operations.

Therefore:

```text
O(n²)
```

Push_swap operation complexity:

```text
Worst case:
≈ n² / 2 rotations
+ 2n pushes
```

Thus:

```text
O(n²)
```

---

# Medium Algorithm — O(n√n)

Implemented by:

```c
ft_medium()
```

## Core Idea

The stack is divided into:

```text
√n partitions
```

Each partition contains approximately:

```text
√n values
```

Example:

```text
100 elements
```

Partitions:

```text
0-9
10-19
20-29
...
90-99
```

---

## Phase 1

Move each partition from A to B.

Elements belonging to the current partition are pushed immediately.

Other elements are rotated.

---

## Phase 2

Rebuild the stack.

The largest available value is moved back first from B to A.

A cost function determines whether:

```text
rb
```

or

```text
rrb
```

is cheaper.

---

## Complexity Analysis

Number of partitions:

```text
√n
```

Each partition requires scanning approximately:

```text
n
```

elements.

Total Push_swap operations:

```text
n × √n
```

Therefore:

```text
O(n√n)
```

This satisfies the complexity class required by the subject.

---

# Complex Algorithm — O(n log n)

Implemented by:

```c
radix_sort()
```

This algorithm was designed jointly by both contributors.

---

## Design Choice

Traditional Push_swap radix implementations often use:

```text
Base 2
```

We chose a dynamic base:

```c
base = sqrt(n)
```

Implemented in:

```c
radix_base()
```

Example:

```text
n = 100

base = 10
```

---

## Why Use √n as the Base?

Traditional binary radix requires:

```text
log₂(n)
```

passes.

Using:

```text
base = √n
```

reduces the number of digit levels while preserving efficient partitioning.

This creates larger buckets and reduces unnecessary stack traversals.

---

## Partition Strategy

Instead of processing a single digit at a time, the algorithm tracks two active buckets:

```text
upper
bottom
```

Values belonging to either bucket are pushed to stack B.

All other values are rotated.

Additional optimizations:

* Smart rotations
* Combined rotations (`rr`)
* Dynamic bucket progression

---

## Reconstruction Phase

Elements are returned from B to A.

The algorithm continuously selects the largest remaining value.

A cost analysis determines whether:

```text
rb
```

or

```text
rrb
```

produces fewer operations.

Adjacent values may be repaired with:

```text
sa
```

to avoid extra rotations.

---

## Complexity Proof

Let:

```text
base = √n
```

Number of digit groups:

```text
log_base(n)
```

Since:

```text
base = √n
```

then:

```text
log_{√n}(n) = 2
```

which remains bounded.

Each element participates in a limited number of passes and stack operations.

The total number of generated Push_swap operations grows proportionally to:

```text
n log n
```

Therefore the algorithm satisfies the required:

```text
O(n log n)
```

complexity class.

---

# Small Sort Optimizations

## order_three()

Handles every permutation of 3 values using the minimum possible operations.

Operations used:

```text
sa
ra
rra
```

---

## order_five()

For 4–5 values:

1. Push smallest values to B.
2. Sort remaining three values.
3. Restore values from B.

This significantly reduces operation count for small inputs.

---

# Benchmark System

Implemented by:

```c
display_bench()
```

The benchmark tracks:

```text
sa
sb
ss
pa
pb
ra
rb
rr
rra
rrb
rrr
```

and prints:

```text
Disorder percentage
Strategy used
Complexity class
Total operations
Per-operation statistics
```

This feature is required by the project specification.

---

# Bonus

The repository includes:

```bash
checker
```

Features:

* Reads instructions from stdin
* Executes every operation
* Validates the final state

Output:

```text
OK
```

if:

* Stack A is sorted
* Stack B is empty

Otherwise:

```text
KO
```

Invalid instructions produce:

```text
Error
```

---

# Complexity Summary

| Strategy | Algorithm                  | Complexity                  |
| -------- | -------------------------- | --------------------------- |
| Simple   | Selection-style extraction | O(n²)                       |
| Medium   | √n partitioning            | O(n√n)                      |
| Complex  | Optimized Radix Sort       | O(n log n)                  |
| Adaptive | Disorder-based selection   | O(n²), O(n√n) or O(n log n) |

---

# AI Usage

Artificial Intelligence tools were used only as learning and documentation aids.

AI assistance was limited to:

* Reviewing README structure
* Improving technical explanations
* Refining complexity analysis descriptions
* Grammar and documentation improvements

All algorithms, implementations, data structures, benchmark logic, parsing logic, adaptive strategy, and sorting techniques were designed, implemented, tested, and understood by the project contributors.

---

# Resources

## Algorithm Analysis

* Introduction to Algorithms — Cormen, Leiserson, Rivest, Stein
* The Art of Computer Programming — Donald Knuth
* Algorithm Design Manual — Steven Skiena

## Complexity Theory

* https://www.youtube.com/watch?v=XMUe3zFhM5c

## Sorting Algorithms

* https://www.youtube.com/watch?v=XiuSW_mEn7g&pp=ygUUcmFkaXggc29ydCBwdXNoX3N3YXA%3D

## Push_swap Community Resources

* Peer evaluations and project discussions within the 42 community
