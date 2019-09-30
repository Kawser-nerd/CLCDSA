from collections import Counter

n = int(input())
a = [int(input()) for _ in range(n)]

c = Counter(a)

ans = 0
for x, y in c.items():
    if y >= 2:
        ans += y - 1

print(ans)