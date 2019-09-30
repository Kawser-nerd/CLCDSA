N, X = map(int, input().split())
X -= 1
H = list(map(int, input().split()))

T = [[] for i in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    T[a].append(b)
    T[b].append(a)

visited = [0] * N
ans = 0


def dfs(n):
    global ans
    visited[n] = 1

    for c in T[n]:
        if visited[c]:
            continue

        if dfs(c):
            ans += 2
            H[n] = 1

    return H[n]


dfs(X)
print(ans)