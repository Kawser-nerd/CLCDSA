import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
G = [[] for i in range(N)]

for m in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    G[a].append(b)
    G[b].append(a)
visited = set()
ans1, ans2 = [], []

ans1.append(str(1))
visited.add(0)
def dfs(n, ans):
    for ni in G[n]:
        if ni not in visited:
            ans.append(str(ni+1))
            visited.add(ni)
            dfs(ni, ans)
            break


dfs(0, ans1)
dfs(0, ans2)


print(len(ans1) + len(ans2))
print(" ".join(ans2[::-1] + ans1))