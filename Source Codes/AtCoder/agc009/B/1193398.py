from sys import stdin, setrecursionlimit

setrecursionlimit(10**7)

def solve():
    N = int(stdin.readline())
    Adj = [[] for i in range(N)]

    for i in range(N - 1):
        a = int(stdin.readline()) - 1
        Adj[a].append(i + 1)

    ans = dfs(N, Adj, 0, -1)

    print(ans)

def dfs(N, Adj, v, p):
    dl = []

    for u in Adj[v]:
        if u == p:
            continue

        dl.append(dfs(N, Adj, u, v))

    dl.sort(reverse=True)

    if not dl:
        return 0

    res = max(dl[i] + i + 1 for i in range(len(dl)))

    return res

if __name__ == '__main__':
    solve()