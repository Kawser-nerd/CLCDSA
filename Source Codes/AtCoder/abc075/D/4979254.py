n, k = (int(i) for i in input().split())
p = [[int(i) for i in input().split()] for i in range(n)]
p = sorted(p)
q = list(enumerate(p))

ans = float("inf")

for i, (a, b) in q[:n-k+1]:
    for j, (c, d) in q[i+k-1:]:
        r = sorted(y for x, y in p[i:j+1])
        r2 = r[k-1:]
        for i2, j2 in zip(r, r2):
            if i2 <= b and d <= j2:
                ans = min(ans, (c-a)*(j2-i2))

print(ans)