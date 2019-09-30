A, B, C, D, E, F = map(int, input().split())
ans = 100 * A, 0
w = set()
for a in range(0, F + 1, 100 * A):
    for b in range(0, F - a + 1, 100 * B):
        if a + b:
            w.add(a + b)
s = set()
for c in range(0, F + 1, C):
    for d in range(0, F + 1 - c, D):
        s.add(c + d)
for wi in w:
    for sj in s:
        if wi + sj <= F and 100 * sj / wi <= E:
            ans = max(ans, (wi + sj, sj), key=lambda x: x[1] / x[0])

print(*ans)