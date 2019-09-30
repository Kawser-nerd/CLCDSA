import sys
from fractions import gcd
from itertools import groupby as gb
from itertools import permutations as perm
from collections import Counter as C
from collections import defaultdict as dd
sys.setrecursionlimit(10**5)

n = int(input())
a = list(map(int,input().split()))
if a[0] != 0 or a.count(0) > 1:
    print(0)
    exit()
a = sorted(a)
g = gb(a)
l = []
cnt = []
for k,v in g:
    l.append(k)
    ln = len(list(v))
    cnt.append(ln)
if l != list(range(len(l))):
    print(0)
    exit()
res = 1
MOD = 10**9+7
for i in range(1, len(cnt)):
    res *= pow((pow(2, cnt[i - 1], MOD) - 1) % MOD, cnt[i], MOD)
    res *= pow(2, cnt[i] * (cnt[i] - 1) // 2, MOD)
    res %= MOD
print(res)