#include <stdio.h>
#include <stdbool.h>

// Sieve of Eratosthenes
// Time: O(n log log n) | Space: O(n)
void sieve(int n, int result[], int *count)
{
    bool arr[n + 1];

    for (int i = 0; i <= n; i++)
        arr[i] = true;

    // 0 and 1 are not prime
    arr[0] = arr[1] = false;

    // only need to check up to √n
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
                arr[j] = false;
        }
    }

    *count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
            result[(*count)++] = i;
    }
}

// Prime Checking - Trial Division up to √n
// Time: O(√n) | Space: O(1)
bool is_prime(int x)
{
    if (x <= 1)
        return false;
    if (x == 2 || x == 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;

    // check only 6k±1 candidates
    int i = 5;
    while (i * i <= x)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

// Prime Factorization - Trial Division
// Time: O(√n) | Space: O(log n)
void factorize(int n, int factors[], int exponents[], int *count)
{
    *count = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors[*count] = i;
            exponents[*count] = 0;
            while (n % i == 0)
            {
                exponents[*count]++;
                n /= i;
            }
            (*count)++;
        }
    }
    if (n > 1)
    {
        factors[*count] = n;
        exponents[(*count)++] = 1;
    }
}

#ifdef RUN_MAIN
int main(void)
{
    // --- sieve ---
    int primes[100], count;
    sieve(30, primes, &count);
    printf("sieve(30):      ");
    for (int i = 0; i < count; i++)
        printf("%d ", primes[i]);   // 2 3 5 7 11 13 17 19 23 29
    printf("\n");

    // --- is_prime ---
    printf("is_prime(13):   %s\n", is_prime(13) ? "true" : "false");   // true
    printf("is_prime(1):    %s\n", is_prime(1)  ? "true" : "false");   // false
    printf("is_prime(4):    %s\n", is_prime(4)  ? "true" : "false");   // false

    // --- factorize ---
    int factors[20], exponents[20], fcount;
    factorize(360, factors, exponents, &fcount);
    printf("factorize(360): ");
    for (int i = 0; i < fcount; i++)
        printf("%d^%d ", factors[i], exponents[i]);  // 2^3 3^2 5^1
    printf("\n");

    return 0;
}
#endif