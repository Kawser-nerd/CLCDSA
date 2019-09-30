N = int(input())
Sn = [input() for _ in range(N)]

from collections import Counter
c = Counter()
for S in Sn:
    c[S[0]] += 1

t = 0
d = ['M','A','R','C','H']
from itertools import combinations
for combi in combinations(d, 3):
    v = 1
    for k in combi:
        v *= c[k]
    t += v
print(t)