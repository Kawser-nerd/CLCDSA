import math
N = int(input())
c = [int(input()) for i in range(N)]
c.sort(reverse=True)
tmp = 0
for i in range(N):
    if i % 2 == 0:
        tmp += c[i]**2
    else:
        tmp -= c[i]**2
print(tmp * math.pi)