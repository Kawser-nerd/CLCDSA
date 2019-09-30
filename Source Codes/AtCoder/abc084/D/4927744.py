import math

p = [True] * (10**5 + 1)

p[0] = False
p[1] = False
i = 2
while i * i <= 10**5:
    if p[i]:
        n = i * 2
        while n <= 10**5:
            p[n] = False
            n += i
    i += 1

s = [0] * (10**5 + 2)
for i in range(2, 10**5 + 2):
    s[i] = s[i - 1] + (1 if (p[i - 1] and p[i // 2]) else 0)

q = int(input())
l = [0] * q
r = [0] * q

for i in range(0, q):
    l[i], r[i] = [int(i) for i in input().split(" ")]

for i in range(0, q):
    print(s[r[i] + 1] - s[l[i]])