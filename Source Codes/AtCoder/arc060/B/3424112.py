def digit_sum(n, s):
    if s > n:
        return -1
    if s == n:
        return n + 1

    b = 2
    while b**2 < n:
        if f(b, n) == s:
            return b

        b += 1

    p = int(n ** 0.5)
    while p >= 1:
        b = (n - s) // p + 1
        if b > 1 and f(b, n) == s:
            return b
        
        p -= 1

    return -1


def f(b, n):
    if n < b:
        return n

    return f(b, n // b) + (n % b)

def solve():
    n = int(input())
    s = int(input())
    result = digit_sum(n, s)
    print(result)

solve()