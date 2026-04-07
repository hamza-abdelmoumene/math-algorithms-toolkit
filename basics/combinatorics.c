#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Factorial - Recursive
// Time: O(n) | Space: O(n) call stack
// safer:
long long factorial(int n)
{
    if (n < 0)
        return -1;
    if (n <= 1)
        return 1;

    long long sub = factorial(n - 1);
    if (sub == -1)
        return -1; // propagate

    return n * sub;
}

// Factorial - Iterative
// Time: O(n) | Space: O(1)
bool factorial_iterative(int n, long long *result)
{
    if (n < 0)
        return false;
    *result = 1;
    for (int i = 2; i <= n; i++)
        *result *= i;
    return true;
}

// Permutations - Ordered arrangements of r items from n
// P(n, r) = n! / (n-r)!
// Time: O(n) | Space: O(n) call stack
bool permutations(int n, int r, long long *result)
{
    if (n < 0 || r < 0)
        return false;
    if (n < r)
        return false;
    *result = factorial(n) / factorial(n - r);
    return true;
}

// Binomial Coefficient - Unordered selections of r items from n
// C(n, r) = n! / (r! * (n-r)!) = P(n, r) / r!
// Time: O(n) | Space: O(n) call stack
bool binomial(int n, int r, long long *result)
{
    if (n < 0 || r < 0)
        return false;
    if (n < r)
        return false;
    *result = factorial(n) / (factorial(n - r) * factorial(r));
    return true;
}

#ifdef RUN_MAIN
int main()
{
    long long result;

    printf("-- FACTORIAL (recursive) --\n");
    printf("  factorial(0)  = %lld\n", factorial(0));
    printf("  factorial(1)  = %lld\n", factorial(1));
    printf("  factorial(5)  = %lld\n", factorial(5));
    printf("  factorial(10) = %lld\n", factorial(10));
    printf("  factorial(-3) = %lld (error sentinel)\n", factorial(-3));

    printf("-- FACTORIAL (iterative) --\n");
    factorial_iterative(5, &result);
    printf("  factorial_iterative(5)  = %lld\n", result);
    factorial_iterative(10, &result);
    printf("  factorial_iterative(10) = %lld\n", result);

    printf("-- PERMUTATIONS --\n");
    permutations(5, 3, &result);
    printf("  P(5,3) = %lld\n", result);
    permutations(5, 0, &result);
    printf("  P(5,0) = %lld\n", result);
    permutations(5, 5, &result);
    printf("  P(5,5) = %lld\n", result);
    printf("  P(3,5) = %s\n", permutations(3, 5, &result) ? "ok" : "invalid input");

    printf("-- BINOMIAL --\n");
    binomial(5, 3, &result);
    printf("  C(5,3)  = %lld\n", result);
    binomial(5, 0, &result);
    printf("  C(5,0)  = %lld\n", result);
    binomial(5, 5, &result);
    printf("  C(5,5)  = %lld\n", result);
    binomial(10, 3, &result);
    printf("  C(10,3) = %lld\n", result);
    printf("  C(3,5) = %s\n", binomial(3, 5, &result) ? "ok" : "invalid input");

    return 0;
}
#endif