from collections import deque
def dfs(v,N,memo):
    ans =0
    if not False in memo.values():
        return 1
    for u in E[v]:
        if memo[u]!=True:
            memo[u] = True
            ans += dfs(u,N,memo)
            memo[u] = False
    return ans
N,M = list(map(int,input().split()))
memo = {i:False for i in range(1,N+1)}
E = {i: []for i in range(1,N+1)}
for i in range(M):
    u,v = list(map(int,input().split()))
    E[u].append(v)
    E[v].append(u)
memo[1] = True
print(dfs(1,N,memo))