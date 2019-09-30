r = [int(input()) for _ in range(int(input()))]
r.sort(reverse=True)
ans = 0
for i in range(len(r)):
    if i % 2 == 0:
        if i == len(r) - 1:
            ans += r[i] ** 2
        else:
            ans += r[i] ** 2 - r[i + 1] ** 2
import math
print(ans * math.pi)