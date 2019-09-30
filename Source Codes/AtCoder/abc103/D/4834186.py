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
    E[v].append(u)
a =0
b = 0
counter =0
for i in range(1,N+1):
    if E[i]:
        if a<max(E[i]):
          if b>max(E[i]):
            a = max(E[i])
            continue
          a = max(E[i])
          b = i
          counter +=1
print(counter)