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
}

// Test:
int main(void)
{
    printf("%d\n", gcd_iterative(10, 8));  // 2
    printf("%d\n", gcd_iterative(17, 13)); // 1
    return 0;
}
