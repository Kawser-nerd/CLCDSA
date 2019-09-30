def solve(k, d, fl):
    if k <= 1:
        if d == 0:
            return 10 ** k
        return 0
    x = (-d) % 10
    c = 9 - x + 1 - fl
    d -= 10 ** (k - 1) * x - x
    return c * solve(k - 2, abs(d) // 10, 0)

d = int(input())

ans = 0
for i in range(1, 100):
    ans += solve(i, d, 1)
print(ans)