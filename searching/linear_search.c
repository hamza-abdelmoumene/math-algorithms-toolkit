#include <stdio.h>
#include <stdbool.h>

// Linear Search - sequential scan
// Time: O(n) | Space: O(1)
bool linear_search(int *array, int target, int *index, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            *index = i;
            return true;
        }
    }
    *index = -1;
    return false;
}

// Sentinel Search - eliminates bounds check by placing target at end
// Time: O(n) | Space: O(1)
bool sentinel(int *array, int target, int *index, int size)
{
    if (size == 0)
    {
        *index = -1;
        return false;
    }

    int original = array[size - 1];
    array[size - 1] = target;
    *index = 0;
    while (array[*index] != target)
        (*index)++;
    array[size - 1] = original;

    if ((*index < size - 1) || (original == target))
        return true;

    *index = -1;
    return false;
}

// ━━━━━━━━━ Test: ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#ifdef RUN_MAIN

static int pass_count = 0;
static int fail_count = 0;

void test(const char *label, bool result, int index, bool exp_result, int exp_index)
{
    bool ok = (result == exp_result) && (index == exp_index);
    printf("  [%s] %-35s got %-5s idx=%2d  (expected %-5s idx=%2d)\n",
           ok ? "OK  " : "FAIL", label,
           result ? "true" : "false", index,
           exp_result ? "true" : "false", exp_index);
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
    int arr[] = {4, 7, 2, 9, 1, 5};  int na = 6;
    int one[] = {7};                  int no = 1;
    int idx;

    /* ── linear_search ──────────────────────────────────────── */
    separator("LINEAR SEARCH");
    test("found at start",      linear_search(arr, 4,   &idx, na), idx, true,  0);
    test("found at middle",     linear_search(arr, 9,   &idx, na), idx, true,  3);
    test("found at end",        linear_search(arr, 5,   &idx, na), idx, true,  5);
    test("not found",           linear_search(arr, 3,   &idx, na), idx, false, -1);
    test("single element hit",  linear_search(one, 7,   &idx, no), idx, true,  0);
    test("single element miss", linear_search(one, 3,   &idx, no), idx, false, -1);
    test("empty array",         linear_search(arr, 4,   &idx,  0), idx, false, -1);

    /* ── sentinel ───────────────────────────────────────────── */
    separator("SENTINEL SEARCH");
    test("found at start",      sentinel(arr, 4, &idx, na), idx, true,  0);
    test("found at middle",     sentinel(arr, 9, &idx, na), idx, true,  3);
    test("found at end",        sentinel(arr, 5, &idx, na), idx, true,  5);
    test("not found",           sentinel(arr, 3, &idx, na), idx, false, -1);
    test("single element hit",  sentinel(one, 7, &idx, no), idx, true,  0);
    test("single element miss", sentinel(one, 3, &idx, no), idx, false, -1);
    test("empty array",         sentinel(arr, 4, &idx,  0), idx, false, -1);

    /* ── summary ────────────────────────────────────────────── */
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("   %d passed  |  %d failed\n", pass_count, fail_count);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");

    return fail_count > 0 ? 1 : 0;
}

#endif