from math import pi

n = int(input())
r = [int(input()) for _ in range(n)]

r.sort()

ans = 0

for i in range(n):
    if i % 2 == 0:
        ans += r[i] ** 2
    else:
        ans -= r[i] ** 2

print(abs(ans) * pi)