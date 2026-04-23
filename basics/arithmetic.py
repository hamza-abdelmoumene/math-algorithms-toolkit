# arithmetic.py

# GCD - Euclidean Algorithm (iterative)
# Time: O(log(min(a,b)))
def gcd_iterative(a, b):
    while b:
        a, b = b, a % b
    return a

# GCD - Euclidean Algorithm (recursive)
# Time: O(log(min(a,b)))
def gcd_recursive(a, b):
    return a if b == 0 else gcd_recursive(b, a % b)

# LCM - Formula: LCM(a,b) = (a*b) / GCD(a,b)
# Time: O(log(min(a,b)))
def lcm(a, b):
    return (a * b) // gcd_iterative(a, b)

# fast_pow - Exponentiation by Squaring
# Time: O(log n)
def fast_pow(base, exp):
    if exp == 0:
        return 1
    if exp % 2 == 0:
        return fast_pow(base ** 2, exp // 2)
    return base * fast_pow(base, exp - 1)

# mod_pow - Modular Exponentiation
# Time: O(log n)
def mod_pow(base, exp, mod):
    if exp == 0:
        return 1
    if exp % 2 == 0:
        return mod_pow((base * base) % mod, exp // 2, mod)
    return (base * mod_pow(base, exp - 1, mod)) % mod

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

    separator("GCD (iterative)")
    test("gcd(12, 8)",               gcd_iterative, 12, 8,        expected=4)
    test("gcd(81, 9)",               gcd_iterative, 81, 9,        expected=9)
    test("gcd(7, 13)  — coprimes",   gcd_iterative, 7,  13,       expected=1)
    test("gcd(0, 5)   — zero left",  gcd_iterative, 0,  5,        expected=5)
    test("gcd(5, 0)   — zero right", gcd_iterative, 5,  0,        expected=5)
    test("gcd(6, 6)   — equal",      gcd_iterative, 6,  6,        expected=6)
    test("gcd(100, 75)",             gcd_iterative, 100, 75,      expected=25)

    separator("GCD (recursive)")
    test("gcd(12, 8)",               gcd_recursive, 12, 8,        expected=4)
    test("gcd(81, 9)",               gcd_recursive, 81, 9,        expected=9)
    test("gcd(7, 13)  — coprimes",   gcd_recursive, 7,  13,       expected=1)
    test("gcd(0, 5)   — zero left",  gcd_recursive, 0,  5,        expected=5)
    test("gcd(5, 0)   — zero right", gcd_recursive, 5,  0,        expected=5)
    test("gcd(6, 6)   — equal",      gcd_recursive, 6,  6,        expected=6)
    test("gcd(100, 75)",             gcd_recursive, 100, 75,      expected=25)

    separator("LCM")
    test("lcm(4, 6)",                lcm, 4,   6,                  expected=12)
    test("lcm(7, 13)  — coprimes",   lcm, 7,   13,                 expected=91)
    test("lcm(6, 6)   — equal",      lcm, 6,   6,                  expected=6)
    test("lcm(1, 9)",                lcm, 1,   9,                  expected=9)
    test("lcm(12, 18)",              lcm, 12,  18,                  expected=36)
    test("lcm(100, 75)",             lcm, 100, 75,                  expected=300)

    separator("FAST POW (exponentiation by squaring)")
    test("fast_pow(2, 0)   — exp=0",  fast_pow, 2, 0,              expected=1)
    test("fast_pow(2, 1)",            fast_pow, 2, 1,              expected=2)
    test("fast_pow(2, 10)",           fast_pow, 2, 10,             expected=1024)
    test("fast_pow(3, 5)",            fast_pow, 3, 5,              expected=243)
    test("fast_pow(5, 4)",            fast_pow, 5, 4,              expected=625)
    test("fast_pow(1, 100) — base=1", fast_pow, 1, 100,            expected=1)
    test("fast_pow(0, 5)   — base=0", fast_pow, 0, 5,              expected=0)

    separator("MOD POW (modular exponentiation)")
    test("mod_pow(2, 10, 1000)",      mod_pow, 2, 10, 1000,        expected=24)
    test("mod_pow(2, 0,  7)  — exp=0",mod_pow, 2, 0,  7,           expected=1)
    test("mod_pow(3, 5,  13)",        mod_pow, 3, 5,  13,          expected=9)
    test("mod_pow(2, 10, 1024)",      mod_pow, 2, 10, 1024,        expected=0)
    test("mod_pow(7, 3,  50)",        mod_pow, 7, 3,  50,          expected=43)
    test("mod_pow(1, 99, 7)  — base=1",mod_pow,1, 99, 7,           expected=1)