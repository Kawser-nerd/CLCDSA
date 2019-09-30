from math import pi
N = int(input())
r = sorted([int(input()) for _ in range(N)], reverse=True)
ans = 0
for i, n in enumerate(r):
    if i % 2 == 0:
        ans += n ** 2 * pi
    else:
        ans -= n ** 2 * pi
print(ans)