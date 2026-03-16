// GCD - Euclidean Algorithm (recursive)

#include <stdio.h>

int gcd_recursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Test:
int main(void)
{
    printf("%d\n", gcd_recursive(1, 2));   // 1
    printf("%d\n", gcd_recursive(24, 26)); // 2
    return 0;
}