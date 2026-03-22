# Sieve of Eratosthenes
# Time: O(n log log n) | Space: O(n)
def sieve(n):
    lst = [True] * (n + 1)

    # 0 and 1 are not prime
    lst[0] = lst[1] = False

    # only need to check up to √n
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

    # check only 6k±1 candidates
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


if __name__ == "__main__":
    # --- sieve ---
    print(f"sieve(30):      {sieve(30)}")       # [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

    # --- is_prime ---
    print(f"is_prime(13):   {is_prime(13)}")    # True
    print(f"is_prime(1):    {is_prime(1)}")     # False
    print(f"is_prime(4):    {is_prime(4)}")     # False

    # --- factorize ---
    print(f"factorize(360): {factorize(360)}")  # {2: 3, 3: 2, 5: 1}