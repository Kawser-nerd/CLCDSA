n,m=map(int,input().split())
a=[[float("inf") if j!=i else 0 for j in range(n+1)]for i in range(n+1)]
from scipy.sparse.csgraph import floyd_warshall as wf
c=[]
d=[]
for i in range(m):
    u,v,l=map(int,input().split())
    if u!=1 and v!=1:
        a[u][v]=l
        a[v][u]=l
    elif u==1:
        c.append(v)
        d.append(l)
    else:
        c.append(u)
        d.append(l)
a=wf(a,directed=False)
l=float("inf")
for i in range(len(c)-1):
    for j in range(i+1,len(c)):
        l=min(l,d[i]+d[j]+a[c[i]][c[j]])
print(int(l) if l!=float("inf")else -1)