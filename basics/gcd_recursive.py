# GCD - Euclidean Algorithm (recursive)

def gcd_recursive(x, y):
    return x if y == 0 else gcd_recursive(y, x % y)

# Test:
print(gcd_recursive(12, 32))
