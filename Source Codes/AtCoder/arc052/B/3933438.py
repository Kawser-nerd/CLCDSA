import numpy as P
def J(N): return map(P.array,zip(*[map(int,input().split())for _ in range(N)]))
M=P.maximum;N,Q=map(int,input().split());X,R,H=J(N);A,B=J(Q);K=M(X+H-M(X,A.reshape(-1,1)),0);L=M(X+H-M(X,B.reshape(-1,1)),0);print(*P.sum(P.pi*(K**3-L**3)*(R/H)**2/3,axis=1),sep="\n")