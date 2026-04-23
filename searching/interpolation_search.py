# Interpolation Search
# TIME : BEST = O(log log n) | WORST = O(n) 
# SPACE : O(1)
def interpolation_search(lst, target):
    low = 0
    high = len(lst) - 1

    while low <= high:
        low_val, high_val = lst[low], lst[high]

        if low_val == high_val:
            return low if low_val == target else -1

        pos = low + int((target - low_val) * (high - low) / (high_val - low_val))

        if pos < low or pos > high:
            return -1

        if lst[pos] < target:
            low = pos + 1
        elif lst[pos] > target:
            high = pos - 1
        else:
            return pos

    return -1

def test(label, func, *args, expected=None):
    try:
        result = func(*args)
        status = "OK" if expected is None or result == expected else "FAIL"
        print(f"  [{status}] {label:<40} got {result}  (expected {expected})")
    except Exception as e:
        print(f"  [ERR ] {label:<40} {e}")

def separator(title):
    print(f"\n{'━' * 40}\n   {title}\n{'━' * 40}")

if __name__ == '__main__':
    separator("INTERPOLATION SEARCH (iterative)")
    test("found at start",        interpolation_search, [1,2,3,4,5], 1, expected=0)
    test("found at middle",       interpolation_search, [1,2,3,4,5], 3, expected=2)
    test("found at end",          interpolation_search, [1,2,3,4,5], 5, expected=4)
    test("not found",             interpolation_search, [1,2,3,4,5], 9, expected=-1)
    test("single element hit",    interpolation_search, [7],          7, expected=0)
    test("single element miss",   interpolation_search, [7],          3, expected=-1)
    test("empty list",            interpolation_search, [],           1, expected=-1)
