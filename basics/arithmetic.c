// arithmetic.c

#include <stdio.h>
#include <math.h>

// GCD - Euclidean Algorithm (iterative)
// Time: O(log(min(a,b)))
long long gcd_iterative(long long a, long long b)
{
    while (b)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// GCD - Euclidean Algorithm (recursive)
// Time: O(log(min(a,b)))
long long gcd_recursive(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

// LCM - Formula: LCM(a,b) = (a*b) / GCD(a,b)
// Time: O(log(min(a,b)))
long long lcm(long long a, long long b)
{
    return (a / gcd_iterative(a, b)) * b;
}

// fast_pow - Exponentiation by Squaring
// Time: O(log n)
long long fast_pow(long long base, int exp)
{
    if (exp == 0)
        return 1;
    if (exp % 2 == 0)
        return fast_pow(base * base, exp / 2);
    return base * fast_pow(base, exp - 1);
}

// mod_pow - Modular Exponentiation
// Time: O(log n)
long long mod_pow(long long base, int exp, long long mod)
{
    if (exp == 0)
        return 1;
    if (exp % 2 == 0)
        return mod_pow((base * base) % mod, exp / 2, mod);
    return (base * mod_pow(base, exp - 1, mod)) % mod;
}

#ifdef RUN_MAIN
int main(void)
{
    printf("%lld\n", gcd_iterative(12, 8));  // 4
    printf("%lld\n", gcd_recursive(81, 9));  // 9
    printf("%lld\n", lcm(4, 6));             // 12
    return 0;
}
#endif