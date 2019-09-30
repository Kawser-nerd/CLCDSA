from itertools import*
from operator import mul
from functools import reduce
from collections import*

n,*a=map(int,open(0).read().split())

def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

b=list(accumulate(a))
print(sum(cmb(v,2)for k,v in Counter(b).items()if v>1)+b.count(0))