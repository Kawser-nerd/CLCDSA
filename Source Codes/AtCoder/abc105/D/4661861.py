from itertools import accumulate as ac
from collections import Counter as c
n,m=map(int,input().split())
d=c([i%m for i in [0]+list(ac(list(map(int,input().split()))))])
a=0
for i in d.values():
    if i>1:
        a+=i*(i-1)//2
print(a)