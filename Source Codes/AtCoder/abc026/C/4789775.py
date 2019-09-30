n = int(input())
edges = [[0]*n for i in range(n)]
for i in range(n-1):
    b = int(input())
    edges[b-1][i+1] = 1

def dfs(u):
    if 1 not in edges[u]:
        return 1
    else:
        money = []
        for v in range(n):
            if edges[u][v] == 1:
                money.append(dfs(v))
        return max(money)+min(money)+1

print(dfs(0))