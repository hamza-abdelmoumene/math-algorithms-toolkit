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


# ---- Test: -----------------------------------------------


def test(label, func, *args, expected=None):
    try:
        result = func(*args)
        status = "✅" if expected is None or result == expected else "❌"
        print(f"  {status} {label}: {result}")
    except Exception as e:
        print(f"  {label}: {e}")

if __name__ == "__main__":
    print("━" * 40)
    print("   FACTORIAL")
    print("━" * 40)
    test("factorial(0)",  factorial, 0,  expected=1)
    test("factorial(1)",  factorial, 1,  expected=1)
    test("factorial(5)",  factorial, 5,  expected=120)
    test("factorial(10)", factorial, 10, expected=3628800)
    test("factorial(-3)", factorial, -3)

    print("━" * 40)
    print("   PERMUTATIONS")
    print("━" * 40)
    test("P(5, 3)", permutations, 5, 3, expected=60)
    test("P(5, 0)", permutations, 5, 0, expected=1)
    test("P(5, 5)", permutations, 5, 5, expected=120)
    test("P(3, 5)", permutations, 3, 5)
    test("P(-1, 2)", permutations, -1, 2)

    print("━" * 40)
    print("   BINOMIAL")
    print("━" * 40)
    test("C(5, 3)", binomial, 5, 3, expected=10)
    test("C(5, 0)", binomial, 5, 0, expected=1)
    test("C(5, 5)", binomial, 5, 5, expected=1)
    test("C(10, 3)", binomial, 10, 3, expected=120)
    test("C(3, 5)", binomial, 3, 5)

    print("━" * 40)