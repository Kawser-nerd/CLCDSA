from collections import Counter
from functools import reduce

n = int(input())
ss = [Counter(input()) for _ in range(n)]

s = ''
for c in sorted(reduce(lambda x, y: x & y, [{c for c, n in s.items()} for s in ss])):
    s += c * min(s[c] for s in ss)

print(s)