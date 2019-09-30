n,m=map(int,input().split())

X=[[] for _ in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    X[a-1].append(b-1)
    X[b-1].append(a-1)


path=[i for i in range(2,n+1)]

visited=[1]+[0]*(n-1)

def dfs(v):
    if visited==[1]*n:
        return 1
    res=0
    for x in X[v]:
        if visited[x]==0:
            visited[x]=1
            res+=dfs(x)
            visited[x]=0
    return res

print(dfs(0))