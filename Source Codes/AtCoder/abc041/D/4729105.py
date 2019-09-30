import itertools
N,M=map(int,input().split())
G=[set() for i in range(N)]
for line in range(M):
    x,y=map(int,input().split());x-=1;y-=1
    G[y].add(x)
F=[0 for i in range(2**N)]
for seq in itertools.product(range(2),repeat=N):
    S=set()
    T=0
    for i in range(N):
        if seq[i]==1:
            S.add(i)
            T+=2**i
    if T==0:
        F[T]=1
        continue
    for k in S:
        if len(S&G[k])==0:
            F[T]+=F[T^(2**k)]
print(F[-1])