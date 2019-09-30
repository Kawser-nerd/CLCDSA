import numpy as P
def I(): return map(int,input().split())
M,G,V=P.maximum,range,list;N,Q=I();X,R,H=P.array([V(I())for _ in G(N)]).T
for _ in G(Q):K,L=M(X+H-M(X,V(zip(*[I()]))),0);print(P.sum(P.pi*(K**3-L**3)*(R/H)**2/3))