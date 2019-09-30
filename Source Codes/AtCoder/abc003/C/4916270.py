n, k = map(int, input().split())
r = list(map(int, input().split()))

r.sort()

ans = 0.0

for x in r[n - k:]:
    ans = (ans + x) / 2

print(ans)