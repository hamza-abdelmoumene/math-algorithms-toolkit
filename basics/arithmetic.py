# GCD - Euclidean Algorithm (iteravive)
# Time: O(Log(n))
def gcd_iterative(x, y):
    while y:
        x, y = y, x % y
    return x

# GCD - Euclidean Algorithm (recursive)
def gcd_recursive(x, y):
    return x if y == 0 else gcd_recursive(y, x % y)

# Test:

if __name__ == "__main__":
    print(gcd_iterative(8,3)) # 1
    print(gcd_recursive(81, 9)) # 9