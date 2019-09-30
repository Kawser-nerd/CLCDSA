import math
n = int(input())
r = [int(input()) for i in range(n)]
r = sorted(r,reverse=True)
res = 0
for i in range(n):
    if i%2==0:
        res += r[i]**2
    else:
        res -= r[i]**2
print(res*math.pi)