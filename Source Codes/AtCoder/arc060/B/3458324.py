from math import floor, sqrt

def f(b, n):
    if n < b:
        return n
    else:
        return f(b, n // b) + n % b

def solve(n, s):
    if s > n:
        return -1
    elif s == n:
        return n + 1

    for b in range(2, floor(sqrt(n)) + 1):
        if f(b, n) == s:
            return b

    for p in reversed(range(1, floor(sqrt(n)) + 1)):
        if (n - s) % p == 0:
            b = (n - s) // p + 1
            if f(b, n) == s:
                return b

    return -1


n = int(input())
s = int(input())

print(solve(n, s))