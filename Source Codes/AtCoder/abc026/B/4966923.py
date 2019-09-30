import math

n = int(input())
r = [int(input()) for _ in range(n)]

pi = math.pi
r.sort(reverse=True)

R = 0
for i in range(len(r)):
    if r.index(r[i])%2 == 0:
        R += r[i]**2
    else:
        R -= r[i]**2
print(R*pi)