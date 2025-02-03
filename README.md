# push_swap

![sort](https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExaTVsZ2FxejJrdXB5YTcxNG5yYmc4dWoxdmM0Z3lmYTB0cnpubjB4OCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/e7VzxgmzN5EwRY68Ml/giphy.gif)


## Project Overview

The `push_swap` project is a sorting algorithm implementation designed to efficiently sort a list of integers using only two stacks (`a` and `b`). The challenge is to sort the list with the fewest number of operations possible. In this implementation, I used **Radix Sort**, an efficient sorting algorithm that operates by sorting the numbers based on their individual digits.

The purpose of this project is not only to sort the integers but also to get familiar with stack manipulation, algorithmic thinking, and optimizing the number of operations performed.

## Problem

You are provided with a list of integers, and your task is to sort them using the following operations:

- `sa` - Swap the first two elements of stack `a`.
- `sb` - Swap the first two elements of stack `b`.
- `ss` - Swap both stack `a` and `b` at the same time.
- `pa` - Push the top element of stack `b` onto stack `a`.
- `pb` - Push the top element of stack `a` onto stack `b`.
- `ra` - Rotate stack `a` (shift all elements up by one, with the top element moving to the bottom).
- `rb` - Rotate stack `b` (shift all elements up by one, with the top element moving to the bottom).
- `rr` - Rotate both stacks `a` and `b` at the same time.
- `rra` - Reverse rotate stack `a` (shift all elements down by one, with the bottom element moving to the top).
- `rrb` - Reverse rotate stack `b` (shift all elements down by one, with the bottom element moving to the top).
- `rrr` - Reverse rotate both stacks `a` and `b` at the same time.

The objective is to sort the numbers in the fewest possible operations while using only the allowed stack operations.

## Solution

### Radix Sort

In this implementation, I used **Radix Sort** to efficiently sort the list of integers. Radix Sort is a non-comparative sorting algorithm that works by processing the numbers digit by digit, starting with the least significant digit (LSD) and working towards the most significant digit (MSD). This allows for sorting the numbers without direct comparison.

1. **Binary Representation:** Radix Sort works with the binary representation of numbers. The program performs a series of iterations, each based on one bit (or binary digit). The integers are processed from the least significant bit to the most significant bit.

2. **Sorting Process:** In each iteration, the list is divided into two groups based on the current bit being processed. Numbers with a 0 in the current bit go to stack `a`, and numbers with a 1 in the current bit go to stack `b`. After this grouping, the elements are rotated or swapped between the two stacks to maintain the sorted order.

3. **Operations Optimization:** The goal of the Radix Sort implementation is to minimize the number of stack operations. In each iteration, elements are moved between the stacks using the fewest operations required to achieve the desired grouping based on the current digit being processed.

### Stack Operations

The core of this project lies in efficiently managing the two stacks (`a` and `b`) while performing the sorting. The operations allowed by the project (`sa`, `sb`, `ra`, `pb`, etc.) provide the necessary tools to rearrange the elements in the stacks in order to sort them. The key is to find the most efficient way to use these operations in conjunction with the Radix Sort algorithm to minimize the total number of operations.

The operations are grouped as follows:

- **Swap Operations:** `sa`, `sb`, `ss` swap the first two elements of a stack.
- **Push Operations:** `pa`, `pb` push elements between the two stacks.
- **Rotate Operations:** `ra`, `rb`, `rr` rotate the elements of the stacks.
- **Reverse Rotate Operations:** `rra`, `rrb`, `rrr` reverse rotate the stacks.

The implementation of Radix Sort requires rotating and pushing elements in a way that minimizes the number of operations.

### Efficiency Considerations

The implementation focuses on minimizing the number of stack operations required to sort the list. Since Radix Sort is based on sorting the integers by individual bits, the number of iterations is limited by the number of bits required to represent the largest integer. The time complexity of Radix Sort is linear with respect to the number of integers in the list and the number of bits in the largest integer, making it efficient for large datasets.

## Features

- **Radix Sort Algorithm:** An efficient non-comparative sorting algorithm that sorts integers based on their binary digits.
- **Stack Operations:** Implements stack operations like swap, push, and rotate to manage the two stacks while sorting.
- **Efficiency Optimization:** Focuses on minimizing the number of stack operations required to achieve a sorted list.

## Installation

1. Clone the repository:

```bash
git clone https://github.com/yourusername/push_swap.git
cd push_swap
```

2. Compile the program using make:

```bash
make
```

3. After compilation, you can run the program with a list of integers to sort:

```bash
./push_swap 3 2 1 4 5
```

This will output the sequence of operations needed to sort the integers in ascending order.

## Usage

The program accepts a list of integers and sorts them using Radix Sort. Here’s an example usage:

```bash
./push_swap 5 1 3 2 4
```

The program will output the sequence of operations (like `sa`, `ra`, `pb`, etc.) required to sort the list.

### Example Output

For the input `5 1 3 2 4`, the output might look something like this:

```bash
pb
pb
ra
ra
sa
pa
pa
```

Each line represents a stack operation that will transform the unsorted list into a sorted list.

## Algorithm Explanation

### Radix Sort Process:

1. **Preparation:** Convert the integers to their binary form.
2. **Iterations:** For each digit (bit) starting from the least significant bit, group the numbers into two stacks based on the current bit.
3. **Rotations and Swaps:** Use the allowed operations (`ra`, `rb`, `sa`, `sb`, etc.) to move the elements between the stacks.
4. **Finalization:** After all iterations are completed, the list will be sorted.

### Time Complexity

The time complexity of Radix Sort is 

\[O(n \cdot k)
\]

where:

- `n` is the number of elements in the list.
- `k` is the number of bits in the largest number (i.e., the number of iterations required).

Since the algorithm works in a linear fashion with respect to the number of elements and the number of bits, it is efficient for large datasets.
