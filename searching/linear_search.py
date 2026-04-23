# Linear Search - sequential scan
# Time: O(n) | Space: O(1)
def linear_search(lst, target):
    for x in range(0, len(lst)):
        if lst[x] == target:
            return x
    return -1

# Sentinel Search - eliminates bounds check by placing target at end
# Time: O(n) | Space: O(1)
def sentinel(lst, target):
    n = len(lst)
    original = lst[n - 1]
    lst[n - 1] = target

    x = 0
    while lst[x] != target:
        x += 1

    lst[n - 1] = original 

    if x < n - 1 or original == target:
        return x
    return -1

# ━━━━━━━━━ Test: ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
def test(label, func, *args, expected=None):
    try:
        result = func(*args)
        status = "OK  " if expected is None or result == expected else "FAIL"
        print(f"  [{status}] {label:<40} got {result}  (expected {expected})")
    except Exception as e:
        print(f"  [ERR ] {label:<40} {e}")

def separator(title):
    print(f"\n{'━' * 40}\n   {title}\n{'━' * 40}")


if __name__ == "__main__":

    separator("LINEAR SEARCH")
    test("found at start",        linear_search, [1,2,3,4,5], 1, expected=0)
    test("found at middle",       linear_search, [1,2,3,4,5], 3, expected=2)
    test("found at end",          linear_search, [1,2,3,4,5], 5, expected=4)
    test("not found",             linear_search, [1,2,3,4,5], 9, expected=-1)
    test("single element hit",    linear_search, [7],          7, expected=0)
    test("single element miss",   linear_search, [7],          3, expected=-1)
    test("empty list",            linear_search, [],           1, expected=-1)

    separator("SENTINEL SEARCH")
    test("found at start",        sentinel, [1,2,3,4,5], 1, expected=0)
    test("found at middle",       sentinel, [1,2,3,4,5], 3, expected=2)
    test("found at end",          sentinel, [1,2,3,4,5], 5, expected=4)
    test("not found",             sentinel, [1,2,3,4,5], 9, expected=-1)
    test("single element hit",    sentinel, [7],          7, expected=0)
    test("single element miss",   sentinel, [7],          3, expected=-1)
    test("list restored after",   sentinel, [1,2,3,4,5], 3, expected=2)