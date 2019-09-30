n, m = [int(item) for item in input().split()]
edge = [[0]*n for _ in range(n)]
for i in range(m):
    a, b = [int(item) for item in input().split()]
    edge[a-1][b-1] = 1
    edge[b-1][a-1] = 1

ans = 0
order = 0
pre = [-1]*n
low = [-1]*n
def dfs(node, prev):
    global order, ans
    pre[node] = order
    low[node] = order
    order += 1
    for to in range(n):
        if to == prev or edge[node][to] == 0:
            continue
        if pre[to] == -1:
            ret = dfs(to, node)
            low[node] = min(low[node], ret)
        else:
            low[node] = min(low[node], pre[to])
        if pre[node] < low[to]:
            ans += 1
    return low[node]
    
dfs(0, -1)
print(ans)