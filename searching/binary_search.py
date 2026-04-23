# Binary Search (Iterative Version)
# Time: O(log n) | Space: O(1)
def binary_iterative(lst, target):
    low = 0
    high = len(lst) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if lst[mid] < target:
            low = mid + 1   
        elif lst[mid] > target:
            high = mid - 1 
        else:
            return mid
    return -1

# Binary Search (Recursive Version)
# Time: O(log n) | Space: O(log n)
def binary_recursive(lst, target, low=0, high=None):
    if high is None:
        high = len(lst) - 1
    
    if low > high:
        return -1
    
    mid = low + (high - low) // 2
    
    if lst[mid] < target:
        return binary_recursive(lst, target, mid + 1, high)
    elif lst[mid] > target:
        return binary_recursive(lst, target, low, mid - 1)
    else:
        return mid

# Upper Bound 
# Time: O(log n) | Space: O(1)
def upper_bound(lst, target):
    low = 0
    high = len(lst) - 1
    result = -1                       

    while low <= high:
        mid = low + (high - low) // 2

        if lst[mid] < target:
            low = mid + 1
        elif lst[mid] > target:
            high = mid - 1
        else:                            
            result = mid
            low = mid + 1              

    return result

# Lower Bound 
# Time: O(log n) | Space: O(1)
def lower_bound(lst, target):
    low = 0
    high = len(lst) - 1
    result = -1

    while low <= high:
        mid = low + (high - low) // 2

        if lst[mid] < target:
            low = mid + 1
        elif lst[mid] > target:
            high = mid - 1
        else:
            result = mid
            high = mid - 1

    return result


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

    separator("BINARY SEARCH (iterative)")
    test("found at start",        binary_iterative, [1,2,3,4,5], 1, expected=0)
    test("found at middle",       binary_iterative, [1,2,3,4,5], 3, expected=2)
    test("found at end",          binary_iterative, [1,2,3,4,5], 5, expected=4)
    test("not found",             binary_iterative, [1,2,3,4,5], 9, expected=-1)
    test("single element hit",    binary_iterative, [7],          7, expected=0)
    test("single element miss",   binary_iterative, [7],          3, expected=-1)
    test("empty list",            binary_iterative, [],           1, expected=-1)

    separator("BINARY SEARCH (recursive)")
    test("found at start",        binary_recursive, [1,2,3,4,5], 1, expected=0)
    test("found at middle",       binary_recursive, [1,2,3,4,5], 3, expected=2)
    test("found at end",          binary_recursive, [1,2,3,4,5], 5, expected=4)
    test("not found",             binary_recursive, [1,2,3,4,5], 9, expected=-1)
    test("single element hit",    binary_recursive, [7],          7, expected=0)
    test("single element miss",   binary_recursive, [7],          3, expected=-1)
    test("empty list",            binary_recursive, [],           1, expected=-1)

    separator("UPPER BOUND (last occurrence)")
    test("unique target",         upper_bound, [1,2,3,4,5],   3, expected=2)
    test("duplicates at end",     upper_bound, [1,2,3,3,3],   3, expected=4)
    test("duplicates at start",   upper_bound, [3,3,3,4,5],   3, expected=2)
    test("all same",              upper_bound, [3,3,3,3,3],   3, expected=4)
    test("target not present",    upper_bound, [1,2,4,5],     3, expected=-1)
    test("single element hit",    upper_bound, [3],            3, expected=0)
    test("single element miss",   upper_bound, [5],            3, expected=-1)

    separator("LOWER BOUND (first occurrence)")
    test("unique target",         lower_bound, [1,2,3,4,5],   3, expected=2)
    test("duplicates at end",     lower_bound, [1,2,3,3,3],   3, expected=2)
    test("duplicates at start",   lower_bound, [3,3,3,4,5],   3, expected=0)
    test("all same",              lower_bound, [3,3,3,3,3],   3, expected=0)
    test("target not present",    lower_bound, [1,2,4,5],     3, expected=-1)
    test("single element hit",    lower_bound, [3],            3, expected=0)
    test("single element miss",   lower_bound, [5],            3, expected=-1)