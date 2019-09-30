from __future__ import print_function
from copy import deepcopy

def floyd(w):
    dist=deepcopy(w)
    n=len(w)
    inf=float('inf')
    for i in range(n):
        for j in range(n):
            if i==j:
                dist[i][j]=0
            elif dist[i][j]==-1:
                dist[i][j]=inf
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
    return dist


with open('C-large.in','r') as f, open('out.txt','w') as fout:
    print('Input file:',f.name)
    t=int(f.readline().strip())
    for case in range(1,t+1):
        n,q=[int(s) for s in f.readline().strip().split()]
        e=[]
        s=[]
        for _ in range(n):
            ei,si=[int(s) for s in f.readline().strip().split()]
            e.append(ei)
            s.append(si)
        w=[]
        for i in range(n):
            d=[int(s) for s in f.readline().strip().split()]
            w.append(d)
        d=floyd(w)
        h=deepcopy(d)
        for i in range(n):
            for j in range(n):
                if i==j or d[i][j]>e[i]:
                    h[i][j]=-1
                else:
                    h[i][j]=d[i][j]/s[i]
        ans=floyd(h)
        resp=[]
        for i in range(q):
            u,v=[int(s) for s in f.readline().strip().split()]
            resp.append(ans[u-1][v-1])
        print('Case #%d:'%case, ' '.join(str(x) for x in resp),file=fout)
