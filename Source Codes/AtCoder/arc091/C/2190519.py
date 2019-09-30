def solve(n, a, b):
    if n < a + b - 1:
        return [-1]
    if n > a * b:
        return [-1]
    if b == 1:
        return list(range(1, n + 1))
    if a == 1:
        return list(range(n, 0, -1))

    ans = list(range(b, 0, -1))
    ans.extend(range(n - a + 2, n + 1))

    t = b
    for t in range(2 * b - 1, n - a + 1, b - 1):
        ans.extend(range(t, t - b + 1, -1))
    ans.extend(range(n - a + 1, t, -1))
    return ans


n, a, b = map(int, input().split())
print(*solve(n, a, b))