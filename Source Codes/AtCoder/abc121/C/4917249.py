n, m = map(int, input().split())
ab = [ [int(x) for x in input().split()] for _ in range(n) ]

ab.sort()

ans = 0

for (a, b) in ab:
    if m == 0:
        break
    for _ in range(b):
        if m == 0:
            break
        m -= 1
        ans += a

print(ans)