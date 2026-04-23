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

void test(const char *label, long long result, long long expected)
{
    bool ok = (result == expected);
    printf("  [%s] %-40s got %lld  (expected %lld)\n",
            ok ? "OK  " : "FAIL", label, result, expected);
    ok ? pass_count++ : fail_count++;
}

int main(void)
{
    /* ── gcd_iterative ──────────────────────────────────────── */
    separator("GCD (iterative)");
    test("gcd(12, 8)",                gcd_iterative(12, 8),       4);
    test("gcd(81, 9)",                gcd_iterative(81, 9),       9);
    test("gcd(7, 13)  — coprimes",    gcd_iterative(7, 13),       1);
    test("gcd(0, 5)   — zero left",   gcd_iterative(0, 5),        5);
    test("gcd(5, 0)   — zero right",  gcd_iterative(5, 0),        5);
    test("gcd(6, 6)   — equal",       gcd_iterative(6, 6),        6);
    test("gcd(100, 75)",              gcd_iterative(100, 75),     25);

    /* ── gcd_recursive ──────────────────────────────────────── */
    separator("GCD (recursive)");
    test("gcd(12, 8)",                gcd_recursive(12, 8),       4);
    test("gcd(81, 9)",                gcd_recursive(81, 9),       9);
    test("gcd(7, 13)  — coprimes",    gcd_recursive(7, 13),       1);
    test("gcd(0, 5)   — zero left",   gcd_recursive(0, 5),        5);
    test("gcd(5, 0)   — zero right",  gcd_recursive(5, 0),        5);
    test("gcd(6, 6)   — equal",       gcd_recursive(6, 6),        6);
    test("gcd(100, 75)",              gcd_recursive(100, 75),     25);

    /* ── lcm ────────────────────────────────────────────────── */
    separator("LCM");
    test("lcm(4, 6)",                 lcm(4, 6),                  12);
    test("lcm(7, 13)  — coprimes",    lcm(7, 13),                 91);
    test("lcm(6, 6)   — equal",       lcm(6, 6),                  6);
    test("lcm(1, 9)",                 lcm(1, 9),                  9);
    test("lcm(12, 18)",               lcm(12, 18),                36);
    test("lcm(100, 75)",              lcm(100, 75),               300);

    /* ── fast_pow ───────────────────────────────────────────── */
    separator("FAST POW (exponentiation by squaring)");
    test("fast_pow(2, 0)  — exp=0",   fast_pow(2, 0),             1);
    test("fast_pow(2, 1)",            fast_pow(2, 1),             2);
    test("fast_pow(2, 10)",           fast_pow(2, 10),            1024);
    test("fast_pow(3, 5)",            fast_pow(3, 5),             243);
    test("fast_pow(5, 4)",            fast_pow(5, 4),             625);
    test("fast_pow(1, 100) — base=1", fast_pow(1, 100),           1);
    test("fast_pow(0, 5)  — base=0",  fast_pow(0, 5),             0);

    /* ── mod_pow ────────────────────────────────────────────── */
    separator("MOD POW (modular exponentiation)");
    test("mod_pow(2, 10, 1000)",      mod_pow(2, 10, 1000),       24);
    test("mod_pow(2, 0,  7)  — exp=0",mod_pow(2, 0,  7),          1);
    test("mod_pow(3, 5,  13)",        mod_pow(3, 5,  13),         9);
    test("mod_pow(2, 10, 1024)",      mod_pow(2, 10, 1024),       0);
    test("mod_pow(7, 3,  50)",        mod_pow(7, 3,  50),         43);
    test("mod_pow(1, 99, 7)  — base=1",mod_pow(1, 99, 7),         1);

    /* ── summary ────────────────────────────────────────────── */
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("   %d passed  |  %d failed\n", pass_count, fail_count);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

    return fail_count > 0 ? 1 : 0;
}

#endif