n,m = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(m)]
l = [[0]*n for _ in range(n)]
for a_ in a:
    l[a_[0]-1][a_[1]-1] = 1
    l[a_[1]-1][a_[0]-1] = 1
visited = [False]*n
def dfs(v):
    visited[v] = True
    for i in range(n):
        if l[v][i]==1 and not visited[i]:
            dfs(i)
    return visited
ans = 0
for a_ in a:
    l[a_[0]-1][a_[1]-1] = 0
    l[a_[1]-1][a_[0]-1] = 0
    bridge = False
    k = dfs(0)
    for i in k:
        if not i:
            bridge=True
    if bridge:
        ans += 1
    visited = [False]*n
    l[a_[0]-1][a_[1]-1] = 1
    l[a_[1]-1][a_[0]-1] = 1
print(ans)