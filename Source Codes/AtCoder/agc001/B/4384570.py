def solve(s, a, b):
    if a % b == 0:
        return s + ((a // b) * 2 - 1) * b
    if b % a == 0:
        return s + ((b // a) * 2 - 1) * a
    elif a > b:
        s += (a // b) * 2 * b
        return solve(s, a % b, b)
    else:
        s += (b // a) * 2 * a
        return solve(s, a, b % a)

n, x = map(int, input().split())
print(solve(n, n - x, x))