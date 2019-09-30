from itertools import accumulate
from collections import Counter


n = int(input())
a = list(map(int, input().split()))

l = [0] + list(accumulate(a))
c = Counter(l)


s = 0
for key, value in c.items():
    s = s + value * (value - 1) // 2

print(s)