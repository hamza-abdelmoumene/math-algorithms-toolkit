# Factorial - Recursive
# Time: O(n) | Space: O(n) call stack
def factorial(n):
    if n < 0:
        raise ValueError(f"n must be non-negative, got {n}")
    if n <= 1:
        return 1
    return n * factorial(n - 1)


# Factorial - Iterative
# Time: O(n) | Space: O(1)
def factorial_iterative(n):
    if n < 0:
        raise ValueError(f"n must be non-negative, got {n}")
    result = 1
    for x in range(2, n + 1):
        result *= x
    return result


# Permutations - Ordered arrangements of r items from n
# P(n, r) = n! / (n-r)!
# Time: O(n) | Space: O(n) call stack
def permutations(n, r):
    if n < 0 or r < 0:
        raise ValueError(f"n and r must be non-negative, got n={n}, r={r}")
    if r > n:
        raise ValueError(f"r must be <= n, got n={n}, r={r}")
    return factorial(n) // factorial(n - r)


# Binomial Coefficient - Unordered selections of r items from n
# C(n, r) = n! / (r! * (n-r)!) = P(n, r) / r!
# Time: O(n) | Space: O(n) call stack
def binomial(n, r):
    if n < 0 or r < 0:
        raise ValueError(f"n and r must be non-negative, got n={n}, r={r}")
    if r > n:
        raise ValueError(f"r must be <= n, got n={n}, r={r}")
    return permutations(n, r) // factorial(r)

# ━━━━━━━━━ Test: ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def test(label, func, *args, expected=None, expect_error=False):
    try:
        result = func(*args)
        status = "OK  " if expected is None or result == expected else "FAIL"
        print(f"  [{status}] {label:<40} got {result}  (expected {expected})")
    except Exception as e:
        status = "OK  " if expect_error else "ERR "
        print(f"  [{status}] {label:<40} raised {type(e).__name__}: {e}")

def separator(title):
    print(f"\n{'━' * 40}\n   {title}\n{'━' * 40}")


if __name__ == "__main__":

    separator("FACTORIAL (recursive)")
    test("factorial(0)",           factorial, 0,   expected=1)
    test("factorial(1)",           factorial, 1,   expected=1)
    test("factorial(5)",           factorial, 5,   expected=120)
    test("factorial(10)",          factorial, 10,  expected=3628800)
    test("factorial(-3) — error",  factorial, -3,  expect_error=True)

    separator("FACTORIAL (iterative)")
    test("factorial_iterative(0)",           factorial_iterative, 0,   expected=1)
    test("factorial_iterative(1)",           factorial_iterative, 1,   expected=1)
    test("factorial_iterative(5)",           factorial_iterative, 5,   expected=120)
    test("factorial_iterative(10)",          factorial_iterative, 10,  expected=3628800)
    test("factorial_iterative(-3) — error",  factorial_iterative, -3,  expect_error=True)

    separator("PERMUTATIONS")
    test("P(5, 3)",                permutations, 5, 3,  expected=60)
    test("P(5, 0)  — r=0",         permutations, 5, 0,  expected=1)
    test("P(5, 5)  — r=n",         permutations, 5, 5,  expected=120)
    test("P(1, 1)",                permutations, 1, 1,  expected=1)
    test("P(3, 5)  — r>n error",   permutations, 3, 5,  expect_error=True)
    test("P(-1, 2) — neg error",   permutations, -1, 2, expect_error=True)

    separator("BINOMIAL COEFFICIENT")
    test("C(5, 3)",                binomial, 5,  3,  expected=10)
    test("C(5, 0)  — r=0",         binomial, 5,  0,  expected=1)
    test("C(5, 5)  — r=n",         binomial, 5,  5,  expected=1)
    test("C(10, 3)",               binomial, 10, 3,  expected=120)
    test("C(10, 7) — symmetry",    binomial, 10, 7,  expected=120)
    test("C(3, 5)  — r>n error",   binomial, 3,  5,  expect_error=True)