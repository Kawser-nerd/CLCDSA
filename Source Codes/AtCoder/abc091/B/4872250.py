n = int(input())
a = [input() for i in range(n)]
m = int(input())
b = [input() for i in range(m)]

from collections import Counter

c = Counter(a)
d = Counter(b)

max = 0

for key, value in c.items():
    if value - d[key] > max:
        max = value - d[key]

print(max)