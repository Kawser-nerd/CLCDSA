from itertools import*

import sys
input=lambda:sys.stdin.readline()

n,q=map(int,input().split())
x=[0]*n
for i in range(q):
    a,b=map(int,input().split())
    x[a-1]+=1
    if b!=n:
        x[b]-=1
print("".join(map(str,[i%2 for i in accumulate(x)])))