from collections import defaultdict as dd
d = dd(int)
mod = 10**9+7
a,b = map(int, input().split())
for i in range(b+1,a+1):
  x = i
  for j in range(2,int(x**.5)+2):
    while x%j == 0:
      x //= j
      d[j] += 1
  if x>1:
      d[x] += 1
ans = 1
for x in d:
  ans = ans * (d[x]+1) % mod
print(ans)