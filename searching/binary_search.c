#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search (Iterative Version)
// Time: O(log n) | Space: O(1)
int binary_iterative(int *array, int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] < target)
            low = mid + 1;
        else if (array[mid] > target)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

// Binary Search (Recursive Version)
// Time: O(log n) | Space: O(log n)
int binary_recursive(int *array, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (array[mid] < target)
        return binary_recursive(array, target, mid + 1, high);
    else if (array[mid] > target)
        return binary_recursive(array, target, low, mid - 1);
    else
        return mid;
}

// Upper Bound 
// Time: O(log n) | Space: O(1)
int upper_bound(int *array, int target, int size)
{
    int low = 0;
    int high = size - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] < target)
            low = mid + 1;
        else if (array[mid] > target)
            high = mid - 1;
        else
        {
            result = mid;
            low = mid + 1;
        }
    }
    return result;
}

// Lower Bound 
// Time: O(log n) | Space: O(1)
int lower_bound(int *array, int size, int target)
{
    int low = 0;
    int high = size - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] < target)
            low = mid + 1;
        else if (array[mid] > target)
            high = mid - 1;
        else
        {
            result = mid;
            high = mid - 1;
        }
    }
    return result;
}

// ━━━━━━━━━ Test: ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#ifdef RUN_MAIN
static int pass_count = 0;
static int fail_count = 0;

void test(const char *label, int result, int expected)
{
    bool ok = (result == expected);
    printf("  [%s] %-35s got %2d  (expected %2d)\n",
            ok ? "OK  " : "FAIL", label, result, expected);
    ok ? pass_count++ : fail_count++;
}

void separator(const char *title)
{
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("   %s\n", title);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

int main(void)
{
    int a[]   = {1, 2, 3, 4, 5};         int na = 5;
    int dup[] = {1, 2, 3, 3, 3};         int nd = 5;
    int dps[] = {3, 3, 3, 4, 5};         int ns = 5;
    int all[] = {3, 3, 3, 3, 3};         int nl = 5;
    int gap[] = {1, 2, 4, 5};            int ng = 4;
    int one[] = {7};                      int no = 1;

    /* ── binary_iterative ───────────────────────────────────── */
    separator("BINARY SEARCH (iterative)");
    test("found at start",        binary_iterative(a,   na, 1), 0);
    test("found at middle",       binary_iterative(a,   na, 3), 2);
    test("found at end",          binary_iterative(a,   na, 5), 4);
    test("not found",             binary_iterative(a,   na, 9), -1);
    test("single element hit",    binary_iterative(one, no, 7), 0);
    test("single element miss",   binary_iterative(one, no, 3), -1);
    test("empty array",           binary_iterative(a,    0, 1), -1);

    /* ── binary_recursive ───────────────────────────────────── */
    separator("BINARY SEARCH (recursive)");
    test("found at start",        binary_recursive(a,   1, 0, na - 1), 0);
    test("found at middle",       binary_recursive(a,   3, 0, na - 1), 2);
    test("found at end",          binary_recursive(a,   5, 0, na - 1), 4);
    test("not found",             binary_recursive(a,   9, 0, na - 1), -1);
    test("single element hit",    binary_recursive(one, 7, 0, no - 1), 0);
    test("single element miss",   binary_recursive(one, 3, 0, no - 1), -1);
    test("empty array",           binary_recursive(a,   1, 0,     -1), -1);

    /* ── upper_bound ────────────────────────────────────────── */
    separator("UPPER BOUND (last occurrence)");
    test("unique target",         upper_bound(a,   3, na), 2);
    test("duplicates at end",     upper_bound(dup, 3, nd), 4);
    test("duplicates at start",   upper_bound(dps, 3, ns), 2);
    test("all same",              upper_bound(all, 3, nl), 4);
    test("target not present",    upper_bound(gap, 3, ng), -1);
    test("single element hit",    upper_bound(one, 7, no), 0);
    test("single element miss",   upper_bound(one, 3, no), -1);

    /* ── lower_bound ────────────────────────────────────────── */
    separator("LOWER BOUND (first occurrence)");
    test("unique target",         lower_bound(a,   na, 3), 2);
    test("duplicates at end",     lower_bound(dup, nd, 3), 2);
    test("duplicates at start",   lower_bound(dps, ns, 3), 0);
    test("all same",              lower_bound(all, nl, 3), 0);
    test("target not present",    lower_bound(gap, ng, 3), -1);
    test("single element hit",    lower_bound(one, no, 7), 0);
    test("single element miss",   lower_bound(one, no, 3), -1);

    /* ── summary ────────────────────────────────────────────── */
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("   %d passed  |  %d failed\n", pass_count, fail_count);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

    return fail_count > 0 ? 1 : 0;
}
#endif