# GCD - Euclidean Algorithm (recursive)

def gcd_recursive(x, y):
    return x if y == 0 else gcd_recursive(y, x % y)

# Test:
if __name__ == "__main__":
    print(gcd_recursive(12, 32))
