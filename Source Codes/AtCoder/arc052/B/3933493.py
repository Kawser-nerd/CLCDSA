import numpy as P
def I(): return map(int,input().split())
M,G=P.maximum,range;N,Q=I();X,R,H=P.array([list(I())for _ in G(N)]).T
for _ in G(Q):a,b=I();K,L=M(X+H-M(X,([a],[b])),0);print(P.sum(P.pi*(K**3-L**3)*(R/H)**2/3))