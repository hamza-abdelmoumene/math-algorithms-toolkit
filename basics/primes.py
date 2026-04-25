# Sieve of Eratosthenes
# Time: O(n log log n) | Space: O(n)
def sieve(n):
    lst = [True] * (n + 1)

    lst[0] = lst[1] = False

    for i in range(2, int(n**0.5) + 1):
        if lst[i]:
            for j in range(i * i, n + 1, i):
                lst[j] = False

    return [i for i, x in enumerate(lst) if x]


# Prime Checking - Trial Division up to √n
# Time: O(√n) | Space: O(1)
def is_prime(x):
    if x <= 1:
        return False
    if x == 2 or x == 3:
        return True
    if x % 2 == 0 or x % 3 == 0:
        return False

    i = 5
    while i * i <= x:
        if x % i == 0 or x % (i + 2) == 0:
            return False
        i += 6
    return True


# Prime Factorization - Trial Division
# Time: O(√n) | Space: O(log n)
def factorize(n):
    factors = {}
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            factors[i] = 0
            while n % i == 0:
                factors[i] += 1
                n //= i
    if n > 1:
        factors[n] = 1
    return factors


# ━━━━━━━━━ Test: ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

def test(label, func, *args, expected=None):
    try:
        result = func(*args)
        status = "OK  " if expected is None or result == expected else "FAIL"
        print(f"  [{status}] {label:<40} got {result}  (expected {expected})")
    except Exception as e:
        print(f"  [ERR ] {label:<40} {e}")

def separator(title):
    print(f"\n{'━' * 40}\n   {title}\n{'━' * 40}")


if __name__ == "__main__":

    separator("SIEVE OF ERATOSTHENES")
    test("sieve(1)  — no primes",        sieve, 1,   expected=[])
    test("sieve(2)  — smallest prime",   sieve, 2,   expected=[2])
    test("sieve(10)",                    sieve, 10,  expected=[2, 3, 5, 7])
    test("sieve(30)",                    sieve, 30,  expected=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29])
    test("sieve(50)",                    sieve, 50,  expected=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47])

    separator("IS PRIME")
    test("is_prime(0)  — zero",          is_prime, 0,   expected=False)
    test("is_prime(1)  — one",           is_prime, 1,   expected=False)
    test("is_prime(2)  — smallest",      is_prime, 2,   expected=True)
    test("is_prime(3)",                  is_prime, 3,   expected=True)
    test("is_prime(4)  — even",          is_prime, 4,   expected=False)
    test("is_prime(9)  — perfect square",is_prime, 9,   expected=False)
    test("is_prime(13)",                 is_prime, 13,  expected=True)
    test("is_prime(97) — large prime",   is_prime, 97,  expected=True)
    test("is_prime(100)",                is_prime, 100, expected=False)

    separator("PRIME FACTORIZATION")
    test("factorize(1)   — no factors",  factorize, 1,    expected={})
    test("factorize(2)   — prime",       factorize, 2,    expected={2: 1})
    test("factorize(12)",                factorize, 12,   expected={2: 2, 3: 1})
    test("factorize(97)  — prime",       factorize, 97,   expected={97: 1})
    test("factorize(360)",               factorize, 360,  expected={2: 3, 3: 2, 5: 1})
    test("factorize(1024) — 2^10",       factorize, 1024, expected={2: 10})