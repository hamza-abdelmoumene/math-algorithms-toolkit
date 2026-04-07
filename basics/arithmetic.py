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

if __name__ == "__main__":
    print(gcd_iterative(12, 8))  # 4
    print(gcd_recursive(81, 9))  # 9
    print(lcm(4, 6))             # 12
    print(fast_pow(2, 10))       # 1024
    print(mod_pow(2, 10, 1000))  # 24