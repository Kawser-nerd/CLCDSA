import sys
input=sys.stdin.readline
from math import atan2,pi

def InnerProduct(V0,V1):
    x0,y0=V0
    x1,y1=V1
    return x0*x1+y0*y1
def CrossProduct(V0,V1):
    x0,y0=V0
    x1,y1=V1
    return x0*y1-x1*y0
def clockwise(P0,P1,P2):
    V0,V1=(P1[0]-P0[0],P1[1]-P0[1]),(P2[0]-P0[0],P2[1]-P0[1])
    return CrossProduct(V0,V1)<0

def MonotoneChain(V):
    upper,lower=[],[]
    P=sorted(V)
    for p in P:
        while len(lower)>1 and (not clockwise(lower[-2],lower[-1],p)):
            lower.pop()
        lower.append(p)
    for p in P[::-1]:
        while len(upper)>1 and (not clockwise(upper[-2],upper[-1],p)):
            upper.pop()
        upper.append(p)
    return lower[:-1]+upper[:-1]

n=int(input())
P=[tuple(map(int,input().split())) for _ in range(n)]
d={p: i for i,p in enumerate(P)}
ans=[0]*n
CH=MonotoneChain(P)
CH+=[CH[0],CH[1]]
for (x0,y0),(x1,y1),(x2,y2) in zip(CH,CH[1:],CH[2:]):
    V0,V1=(x0-x1,y0-y1),(x2-x1,y2-y1)
    ans[d[(x1,y1)]]=(pi-atan2(CrossProduct(V0,V1),InnerProduct(V0,V1)))/(2*pi)
for a in ans:
    print(a)