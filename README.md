*This project has been created as part of the 42 curriculum by kriad.*

# push_swap

## Description

**push_swap** is an algorithmic project whose goal is to sort a stack of integers using
a limited set of operations and an auxiliary stack.

The program receives a list of unique integers as arguments and must output a sequence
of operations that sorts the numbers in ascending order, using two stacks (`a` and `b`)
and a predefined instruction set.

The main challenge of this project is not only to sort the data correctly, but to do so
with the smallest possible number of operations, which requires careful algorithmic
choices and optimizations.

---

## Instructions

### Compilation

To compile the project, run:

```bash
make
```
This will generate the executable push_swap.

Usage
Run the program by passing integers as arguments:

```bash
./push_swap 3 2 1
```
You can also pass multiple numbers as a single argument:

```bash
./push_swap "4 7 3 6 2"
```
To check if the output correctly sorts the stack, you can use the provided checker:

```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```
The program outputs a list of operations (sa, pb, ra, etc.) that, when executed,
sort the stack.

### Algorithm Overview
This implementation is based on a **chunk-based sorting** strategy:

Each number is first assigned an index representing its rank in the sorted order.

The stack is divided into chunks of indices.

Numbers belonging to the current chunk are pushed from stack A to stack B.

Stack B is partially organized during pushes to reduce rotations later.

Finally, elements are pushed back from B to A in descending index order.

For small inputs (≤ 5 numbers), a dedicated optimized sorting routine is used.

This approach provides a good balance between performance, correctness, and code clarity.

## Resources
42 subject PDF: push_swap

Stack and sorting concepts:

https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
https://en.wikipedia.org/wiki/Sorting_algorithm

Algorithm inspiration:

Chunk-based sorting strategies

Greedy approaches for constrained instruction sets

### Use of AI
AI tools were used during the development of this project as an assistant, mainly for:

Clarifying algorithmic concepts (chunk strategy, stack manipulation)

Debugging logic errors and understanding edge cases

Improving code structure and readability

Helping with documentation and explanations

All implementation decisions, algorithm choices, and final code were written and validated
by the author.