import sys
sys.setrecursionlimit(10**7)

N,M = map(int,input().split())
es = [tuple(map(lambda x:int(x)-1,input().split())) for i in range(M)]
gr = [[0 for j in range(N)] for i in range(N)]
for a,b in es:
    gr[a][b] = gr[b][a] = 1
compgr = [[] for i in range(N)]
for i in range(N-1):
    for j in range(i+1,N):
        if gr[i][j]: continue
        compgr[i].append(j)
        compgr[j].append(i)

colors = [0] * N
def dfs(v,color):
    colors[v] = color
    b,w = (1,0) if color==1 else (0,1)
    for to in compgr[v]:
        if colors[to] == color:
            print(-1)
            exit()
        elif colors[to] == 0:
            db,dw = dfs(to, -color)
            b += db
            w += dw
    return [b,w]

dp = set([0])
for i in range(N):
    if colors[i] != 0: continue
    b,w = dfs(i,1)
    dp2 = set()
    for n in dp:
        dp2.add(n+b)
        dp2.add(n+w)
    dp = dp2

ans = N*N
for a in dp:
    b = N-a
    tmp = a*(a-1)//2 + b*(b-1)//2
    ans = min(ans, tmp)
print(ans)