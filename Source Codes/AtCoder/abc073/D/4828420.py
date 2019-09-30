from itertools import permutations as pe
from scipy.sparse.csgraph import floyd_warshall as wf
n,m,r=map(int,input().split())
s=[[(0 if i==j else float("inf"))for j in range(n+1)]for i in range(n+1)]
g=list(pe(list(map(int,input().split()))))
for i in range(m):
    a,b,c=map(int,input().split())
    s[a][b]=c
    s[b][a]=c
s=wf(s,directed=False)
k=float("inf")
for i in range(len(g)):
    d=g[i]
    c=0
    for j in range(1,len(d)):
        c+=s[d[j-1]][d[j]]
        if c>=k:
            break
    else:
        k=min(c,k)
print(int(k))