import numpy as np
N, x = map(int, input().split())
a = np.array(list(map(int, input().split())))
a.sort()
s = np.cumsum(a)
b = (s <= x)
if b.all():
  if s[-1] == x:
    c = b.sum()
  else:
    c = b.sum() - 1
elif b.any():
  c = b.sum()
  r = x - s[c-1]
  if (r == a[c:]).any():
    c += 1
else:
  c = 0
print(c)