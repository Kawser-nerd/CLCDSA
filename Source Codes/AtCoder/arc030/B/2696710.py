N, X = map(int, input().split())
X -= 1
H = list(map(int, input().split()))

G = [[] for i in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    G[a].append(b)
    G[b].append(a)

V = set()
ans = 0


def dfs(n):
    global ans
    V.add(n)
    for e in G[n]:
        if e in V:
            continue
        if dfs(e):
            ans += 2
            H[n] = 1
    jewelry = H[n]
    return jewelry


dfs(X)
print(ans)