from collections import Counter
N, = list(map(int, input().split()))
S = input()
m = 10**9+7
c = Counter(S)
r = 1
for k in c:
  r = (r*(c[k]+1)) % m
print((r-1)%m)