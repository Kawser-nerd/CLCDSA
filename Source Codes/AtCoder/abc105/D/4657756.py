from collections import defaultdict as dd
d = dd(int)
d[0] = 1
n,m = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
f = 0
for i in range(1,n+1):
  f = (f + a[i-1])%m
  d[f] += 1
for i in d:
  ans += d[i]*(d[i]-1)//2
print(ans)