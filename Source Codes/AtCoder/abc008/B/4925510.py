from collections import Counter

n = int(input())
s = [input() for _ in range(n)]

c = Counter(s)

ans = ''
t = 0
for x, y in c.items():
    if y > t:
        t = y
        ans = x

print(ans)