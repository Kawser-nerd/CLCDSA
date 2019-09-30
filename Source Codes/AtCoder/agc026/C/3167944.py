n = int(input())
s = input()

sl = s[:n]
sr = s[n:][::-1]

from collections import Counter
l = Counter()
r = Counter()

from itertools import product
for m in product([False, True], repeat=n):
  key = [sl[i] for i in range(n) if not m[i]]
  key += ['-']
  key += [sl[i] for i in range(n) if m[i]]
  l[''.join(key)] += 1
  
  key = [sr[i] for i in range(n) if not m[i]]
  key += ['-']
  key += [sr[i] for i in range(n) if m[i]]
  r[''.join(key)] += 1
  
ans = sum(l[lk] * r[lk] for lk in l.keys())

print(ans)