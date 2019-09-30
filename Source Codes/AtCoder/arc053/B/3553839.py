import collections
s = list(input())
n = len(s)
c = collections.Counter(s)
k = 0
for x in c.values():
  k += x%2
if k == 0:
  print(n)
else:
  print(((n-k)//2)//k*2+1)