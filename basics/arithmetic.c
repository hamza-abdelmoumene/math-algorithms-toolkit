// GCD - Euclidean Algorithm (iteravive)
// Time: O(Log(n))
#include <stdio.h>

int gcd_iterative(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// GCD - Euclidean Algorithm (recursive)
int gcd_recursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

// Test:
int main(void)
{
    printf("%d\n", gcd_iterative(10, 8));  // 2
    printf("%d\n", gcd_recursive(17, 13)); // 1
    return 0;
}
