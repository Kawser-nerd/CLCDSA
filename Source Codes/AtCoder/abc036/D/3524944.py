import sys
sys.setrecursionlimit(10**6)
Mod = 10**9+7
N = int(input())
edge = [[] for i in range(N)]
for i in range(N-1):
    a,b = map(int,input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

visited = [False]*N
visited[0] = True

def paint(v):
    b = 1
    w = 1
    visited[v] = True
    
    for child in edge[v]:
        if not visited[child]:
            b_,w_ = paint(child)
            b *= w_
            b %= Mod
            w *= b_+w_
            w %= Mod

    return b,w

b,w = paint(0)

print((b+w)%Mod)