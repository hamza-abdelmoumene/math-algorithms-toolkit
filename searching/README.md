# searching

Searching is about one thing: finding a target as fast as possible given what you know about the data. If it's unsorted, you're stuck with linear. If it's sorted, you can do much better — and this module covers the full spectrum.

## Files

| File | Language | Contents |
|------|----------|----------|
| `linear_search.py/c` | Python & C | `linear`, `sentinel` |
| `binary_search.py/c` | Python & C | `binary_iterative`, `binary_recursive`, `lower_bound`, `upper_bound` |
| `interpolation_search.py/c` | Python & C | `interpolation` |
| `exponential_search.py/c` | Python & C | `exponential` |

## Linear Search

The baseline. No assumptions about the data, just scan from left to right. Sentinel search is a small optimization — it appends the target to the end so the loop avoids checking the boundary condition on every iteration.

## Binary Search

The one you need to know cold. It halves the search space on every step, giving O(log n) on sorted arrays. `lower_bound` and `upper_bound` are variants that find the first and last position of a target in an array with duplicates — essential for range queries.

| Function | Time | Space |
|----------|------|-------|
| `binary_iterative` | O(log n) | O(1) |
| `binary_recursive` | O(log n) | O(log n) |
| `lower_bound` | O(log n) | O(1) |
| `upper_bound` | O(log n) | O(1) |

## Interpolation & Exponential Search

Interpolation search improves on binary search when values are uniformly distributed — instead of always probing the midpoint, it estimates where the target likely is. Best case drops to O(log log n), but degrades to O(n) on skewed data.

Exponential search is useful when the array size is unknown or very large — it first finds a range where the target could be by doubling the bound, then runs binary search within that range.

| Algorithm | Requires Sorted | Best | Worst |
|-----------|----------------|------|-------|
| Linear | ❌ | O(1) | O(n) |
| Sentinel | ❌ | O(1) | O(n) |
| Binary | ✅ | O(1) | O(log n) |
| Interpolation | ✅ | O(log log n) | O(n) |
| Exponential | ✅ | O(1) | O(log n) |
