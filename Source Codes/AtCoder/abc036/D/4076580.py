import sys
sys.setrecursionlimit(10 ** 9)
mod = 10 ** 9 + 7


N = int(input())
T = [[] for i in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    T[a].append(b)
    T[b].append(a)


ans = 1
f = [1] * N
g = [1] * N


def dfs(x, parent):
    global f, g

    for child in T[x]:
        if child == parent:
            continue
        dfs(child, x)

    for child in T[x]:
        f[x] = (f[x] * g[child]) % mod
        g[x] = (g[x] * f[child]) % mod
    f[x] = (f[x] + g[x]) % mod


dfs(0, -1)
print(f[0])