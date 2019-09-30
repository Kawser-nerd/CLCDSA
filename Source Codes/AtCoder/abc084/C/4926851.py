import math

n = int(input())
c = [0] * n
s = [0] * n
f = [0] * n

for i in range(1, n):
    c[i], s[i], f[i] = [int(i) for i in input().split(" ")]

for i in range(1, n + 1):
    t = 0
    for j in range(i, n):
        if t <= s[j]:
            t = s[j] + c[j]
        else:
            t = math.ceil(t / f[j]) * f[j] + c[j]
    print(t)