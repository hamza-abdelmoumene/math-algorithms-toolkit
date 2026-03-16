# GCD - Euclidean Algorithm (iteravive)
# Time: O(Log(n))

def gcd_iterative(x, y):
    while y:
        x, y = y, x % y
    return x

# Test:

if __name__ == "__main__":
    print(gcd_iterative(8,3)) # 1
    print(gcd_iterative(81, 9)) # 9