from itertools import accumulate as ac
from collections import Counter as c
n,m=map(int,input().split())
a=0
for i in c([i%m for i in [0]+list(ac(list(map(int,input().split()))))]).values():
    a+=i*(i-1)//2
print(a)