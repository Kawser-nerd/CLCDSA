n,m=map(int,input().split())
x = [list(map(int, input().split())) for _ in range(n)]
from itertools import *
res = 0
for a in product([-1, 1], [-1, 1], [-1, 1]):
    ts =[]
    for t in x:
        ta = 0
        for i,j in zip(a,t):
            ta+=i*j
        ts.append(ta)
    s = sum(sorted(ts,reverse=True)[:m])
    res = max(res, s)
print(res)