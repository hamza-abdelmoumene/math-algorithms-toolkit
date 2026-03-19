# basics

Core mathematical operations used as building blocks across algorithms and competitive programming.

## Files

| File | Language | Contents |
|------|----------|----------|
| `arithmetic.py/c` | Python & C | `gcd`, `lcm`, `fast_pow`, `mod_pow` |
| `primes.py/c` | Python & C | `sieve`, `is_prime`, `factorize` |
| `combinatorics.py/c` | Python & C | `factorial`, `binomial`, `permutations` |

## Complexity

| Function | Time | Space |
|----------|------|-------|
| `gcd` | O(log min(a,b)) | O(1) |
| `lcm` | O(log min(a,b)) | O(1) |
| `fast_pow` | O(log n) | O(1) |
| `sieve` | O(n log log n) | O(n) |
| `is_prime` | O(√n) | O(1) |
| `factorize` | O(√n) | O(log n) |
| `factorial` | O(n) | O(1) |
| `binomial` | O(n·k) | O(n·k) |
