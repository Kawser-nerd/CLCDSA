import math
n = int(input())
r = []
for i in range(n):
    r.append(int(input()))
r.sort()
r = reversed(r)
c = 0
for i, r_ in enumerate(r):
    c += ((-1) **(i)) * math.pi * (r_ ** 2)
print(c)