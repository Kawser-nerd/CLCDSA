from collections import Counter
s = input()
n = len(s)
d = Counter(s)
c = 0
for x in d:
  c += d[x]*(d[x]-1)//2
print(1 + n*(n-1)//2 - c)