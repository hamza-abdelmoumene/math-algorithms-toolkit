# sorting

Sorting is one of the most studied problems in computer science — not because it's unsolved, but because the tradeoffs between algorithms are a perfect lens for understanding time complexity, stability, memory usage, and real-world performance. This module implements nine algorithms across three categories.

## Files

| File | Language | Contents |
|------|----------|----------|
| `comparison_sorts.py/c` | Python & C | `bubble_sort`, `selection_sort`, `insertion_sort`, `merge_sort`, `quick_sort`, `heap_sort` |
| `non_comparison_sorts.py/c` | Python & C | `counting_sort`, `radix_sort`, `bucket_sort` |
| `hybrid_sorts.py/c` | Python & C | `timsort_manual`, `introsort` |

## Comparison Sorts

These sort by comparing elements against each other. The simple ones (bubble, selection, insertion) are O(n²) but worth knowing — insertion sort in particular is fast on nearly-sorted data and is used inside Timsort. Merge sort is the reliable O(n log n) choice when stability matters. Quick sort is fast in practice despite its O(n²) worst case. Heap sort is the one you reach for when you need guaranteed O(n log n) with no extra memory.

| Algorithm | Best | Average | Worst | Stable | In-place |
|-----------|------|---------|-------|--------|----------|
| Bubble | O(n) | O(n²) | O(n²) | ✅ | ✅ |
| Selection | O(n²) | O(n²) | O(n²) | ❌ | ✅ |
| Insertion | O(n) | O(n²) | O(n²) | ✅ | ✅ |
| Merge | O(n log n) | O(n log n) | O(n log n) | ✅ | ❌ |
| Quick | O(n log n) | O(n log n) | O(n²) | ❌ | ✅ |
| Heap | O(n log n) | O(n log n) | O(n log n) | ❌ | ✅ |

## Non-Comparison Sorts

These don't compare elements — they exploit the structure of the data itself. That's how they break the O(n log n) theoretical lower bound for comparison sorts. Counting sort works on integers in a known range. Radix sort extends that to larger numbers digit by digit. Bucket sort works best on uniformly distributed floats.

| Algorithm | Time | Stable | Notes |
|-----------|------|--------|-------|
| Counting | O(n+k) | ✅ | k = value range |
| Radix | O(nk) | ✅ | k = number of digits |
| Bucket | O(n+k) | ✅ | Best for uniform floats in [0,1) |

## Hybrid Sorts

Timsort and Introsort are what real-world sort implementations actually look like. Timsort (Python's built-in) combines insertion sort for small runs with merge sort for the rest. Introsort (used in C++ STL) starts with quicksort and falls back to heapsort when recursion depth gets too deep.
