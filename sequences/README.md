# sequences

Mathematical sequences are where recursion and dynamic programming start to make intuitive sense. This module covers the classic ones — from Fibonacci to geometric series — and builds intuition for recurrence relations and closed-form expressions.

## Files

| File | Language | Contents |
|------|----------|----------|
| `fibonacci.py/c` | Python & C | `fib_recursive`, `fib_iterative` |
| `arithmetic_seq.py/c` | Python & C | `arith_term`, `arith_sum` |
| `geometric_seq.py/c` | Python & C | `geo_term`, `geo_sum`, `geo_infinite` |
| `special_sequences.py/c` | Python & C | `catalan`, `triangular`, `square_pyramidal`, `pascal_triangle` |

## Fibonacci

The classic entry point into recursion. The recursive version is intentionally naive — it's here to show why overlapping subproblems are a problem, not as something you'd use in practice. The iterative version is the one you'd actually reach for.

# sequences

Mathematical sequences are where recursion and dynamic programming start to make intuitive sense. This module covers the classic ones — from Fibonacci to geometric series — and builds intuition for recurrence relations and closed-form expressions.

## Files

| File | Language | Contents |
|------|----------|----------|
| `fibonacci.py/c` | Python & C | `fib_recursive`, `fib_iterative` |
| `arithmetic_seq.py/c` | Python & C | `arith_term`, `arith_sum` |
| `geometric_seq.py/c` | Python & C | `geo_term`, `geo_sum`, `geo_infinite` |
| `special_sequences.py/c` | Python & C | `catalan`, `triangular`, `square_pyramidal`, `pascal_triangle` |

## Fibonacci

The classic entry point into recursion. The recursive version is intentionally naive — it's here to show why overlapping subproblems are a problem, not as something you'd use in practice. The iterative version is the one you'd actually reach for.

| Function | Time | Space | Notes |
|----------|------|-------|-------|
| `fib_recursive` | O(2^n) | O(n) | Naive, for illustration only |
| `fib_iterative` | O(n) | O(1) | Practical default |
```python
# TODO: fib_memoized and fib_matrix — after studying memoization and matrix exponentiation
```

## Arithmetic & Geometric Series

Arithmetic sequences grow by a fixed difference, geometric by a fixed ratio. `geo_infinite` computes the sum of an infinite geometric series — only valid when |r| < 1, otherwise it raises an error.

## Special Sequences

Catalan numbers appear in surprisingly many places — counting valid bracket expressions, binary trees, and triangulations. Pascal's triangle gives you binomial coefficients at a glance and is worth understanding visually before using it programmatically.
