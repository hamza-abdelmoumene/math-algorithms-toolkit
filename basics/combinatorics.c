#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Sieve of Eratosthenes
// Time: O(n log log n) | Space: O(n)
void sieve(int n, int result[], int *count)
{
    bool arr[n + 1];

    for (int i = 0; i <= n; i++)
        arr[i] = true;

    arr[0] = arr[1] = false;

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

// ━━━━━━━━━ Test: ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#ifdef RUN_MAIN

static int pass_count = 0;
static int fail_count = 0;

void separator(const char *title)
{
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("   %s\n", title);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

void test_bool(const char *label, bool result, bool expected)
{
    bool ok = (result == expected);
    printf("  [%s] %-35s got %-5s  (expected %s)\n",
            ok ? "OK  " : "FAIL", label,
            result ? "true" : "false",
            expected ? "true" : "false");
    ok ? pass_count++ : fail_count++;
}

/* compares two int arrays, prints a diff on mismatch */
void test_array(const char *label, int *result, int rcount,
                int *expected, int ecount)
{
    bool ok = (rcount == ecount) &&
              (memcmp(result, expected, ecount * sizeof(int)) == 0);

    printf("  [%s] %-35s got [", ok ? "OK  " : "FAIL", label);
    for (int i = 0; i < rcount; i++)
        printf(i ? " %d" : "%d", result[i]);
    printf("]");

    if (!ok)
    {
        printf("  (expected [");
        for (int i = 0; i < ecount; i++)
            printf(i ? " %d" : "%d", expected[i]);
        printf("])");
    }
    printf("\n");
    ok ? pass_count++ : fail_count++;
}

/* builds "p^e p^e …" string and compares */
void test_factors(const char *label,
                  int *factors, int *exponents, int count,
                  int *exp_f,   int *exp_e,     int exp_count)
{
    bool ok = (count == exp_count);
    if (ok)
        for (int i = 0; i < count; i++)
            if (factors[i] != exp_f[i] || exponents[i] != exp_e[i])
                { ok = false; break; }

    printf("  [%s] %-35s got [", ok ? "OK  " : "FAIL", label);
    for (int i = 0; i < count; i++)
        printf(i ? " %d^%d" : "%d^%d", factors[i], exponents[i]);
    printf("]");

    if (!ok)
    {
        printf("  (expected [");
        for (int i = 0; i < exp_count; i++)
            printf(i ? " %d^%d" : "%d^%d", exp_f[i], exp_e[i]);
        printf("])");
    }
    printf("\n");
    ok ? pass_count++ : fail_count++;
}

int main(void)
{
    int primes[200], count;
    int factors[32], exponents[32], fcount;

    /* ── sieve ──────────────────────────────────────────────── */
    separator("SIEVE OF ERATOSTHENES");

    sieve(30,  primes, &count);
    test_array("sieve(30)",  primes, count,
                (int[]){2,3,5,7,11,13,17,19,23,29}, 10);

    sieve(2,   primes, &count);
    test_array("sieve(2)  — smallest prime",  primes, count,
                (int[]){2}, 1);

    sieve(1,   primes, &count);
    test_array("sieve(1)  — no primes",       primes, count,
                (int[]){}, 0);

    sieve(50,  primes, &count);
    test_array("sieve(50)",  primes, count,
                (int[]){2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}, 15);

    /* ── is_prime ───────────────────────────────────────────── */
    separator("IS PRIME");

    test_bool("is_prime(0)  — zero",          is_prime(0),   false);
    test_bool("is_prime(1)  — one",           is_prime(1),   false);
    test_bool("is_prime(2)  — smallest prime",is_prime(2),   true);
    test_bool("is_prime(3)",                  is_prime(3),   true);
    test_bool("is_prime(4)  — even composite",is_prime(4),   false);
    test_bool("is_prime(9)  — perfect square",is_prime(9),   false);
    test_bool("is_prime(13)",                 is_prime(13),  true);
    test_bool("is_prime(25) — 5*5",           is_prime(25),  false);
    test_bool("is_prime(97) — large prime",   is_prime(97),  true);

    /* ── factorize ──────────────────────────────────────────── */
    separator("PRIME FACTORIZATION");

    factorize(360, factors, exponents, &fcount);
    test_factors("factorize(360) — 2^3 3^2 5^1",
                factors, exponents, fcount,
                (int[]){2,3,5}, (int[]){3,2,1}, 3);

    factorize(1, factors, exponents, &fcount);
    test_factors("factorize(1)  — no factors",
                factors, exponents, fcount,
                (int[]){}, (int[]){}, 0);

    factorize(2, factors, exponents, &fcount);
    test_factors("factorize(2)  — prime itself",
                factors, exponents, fcount,
                (int[]){2}, (int[]){1}, 1);

    factorize(12, factors, exponents, &fcount);
    test_factors("factorize(12) — 2^2 3^1",
                factors, exponents, fcount,
                (int[]){2,3}, (int[]){2,1}, 2);

    factorize(97, factors, exponents, &fcount);
    test_factors("factorize(97) — prime itself",
                factors, exponents, fcount,
                (int[]){97}, (int[]){1}, 1);

    factorize(1024, factors, exponents, &fcount);
    test_factors("factorize(1024) — 2^10",
                factors, exponents, fcount,
                (int[]){2}, (int[]){10}, 1);

    /* ── summary ────────────────────────────────────────────── */
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("   %d passed  |  %d failed\n", pass_count, fail_count);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

    return fail_count > 0 ? 1 : 0;
}

#endif