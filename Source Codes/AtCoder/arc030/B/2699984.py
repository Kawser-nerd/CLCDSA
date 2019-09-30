N, X = map(int, input().split())
X -= 1
H = list(map(int, input().split()))

G = [[] for i in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    G[a].append(b)
    G[b].append(a)


visited = set()
ans = 0


def dfs(n):
    global ans
    visited.add(n)

    for e in G[n]:
        if e in visited:
            continue
        if dfs(e):
            ans += 2
            H[n] = 1

    return H[n]


dfs(X)
print(ans)