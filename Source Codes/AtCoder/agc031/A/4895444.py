N = int(input())
mod = 10**9+7
s = input()
from collections import Counter
c = Counter(s)
ans = 1
for i in c:
    ans *= (c[i]+1)%mod

print((ans-1)%mod)