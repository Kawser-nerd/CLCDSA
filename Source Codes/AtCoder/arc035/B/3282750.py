import sys
from itertools import accumulate
from collections import Counter

def facmod(n):
    for i in range(2, n):
        n = (n*i) % mod
    return n or 1

N = int(input())
a = sorted(map(int, sys.stdin))
counter = Counter(a)
mod = 10**9+7
ans = 1
for v in counter.values():
    ans = (ans*facmod(v)) % mod
print(sum(accumulate(a)))
print(ans)