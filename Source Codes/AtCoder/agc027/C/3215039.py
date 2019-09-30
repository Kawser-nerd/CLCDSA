import sys
sys.setrecursionlimit(1000000)

N, M = map(int, input().split())
s = input()
G = [[] for _ in range(2 * N)]
for _ in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    if s[a] == s[b]:
        G[a].append(b + N)
        G[b].append(a + N)
    else:
        G[a + N].append(b)
        G[b + N].append(a)

status = [0] * (2 * N) #0 = ????1 = ??? 2 = ???
def dfs(v):
    if status[v] == 1:
        print('Yes')
        exit()
    elif status[v] == 0:
        status[v] = 1
        for u in G[v]:
            dfs(u)
        status[v] = 2

for v in range(2 * N):
    dfs(v)
print('No')