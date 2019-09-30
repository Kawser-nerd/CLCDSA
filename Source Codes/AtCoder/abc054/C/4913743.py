import sys
sys.setrecursionlimit(100000)

ans=0


def dfs(v,n,visi):
    allv=True

    for i in visi:
        if not i:
            allv=False

    if allv:
        return 1

    ret=0

    for i in range(n):
        if G[v][i]==False:
            continue
        if visi[i]:
            continue
        visi[i]=True
        ret+=dfs(i,n,visi)
        visi[i]=False

    return ret

n,m=map(int,input().split())
ab=[list(map(int,input().split()))for i in range(m)]
G=[[False for i in range(8)]for i in range(8)]

for a,b in ab:
    G[a-1][b-1]=G[b-1][a-1]=True

visi=[False for i in range(n)]

visi[0]=True

print(dfs(0,n,visi))