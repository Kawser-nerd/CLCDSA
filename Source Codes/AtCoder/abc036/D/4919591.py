def draw(N: int, edges: list)->int:
    MOD = 10**9 + 7
    memo_f, memo_g = [0] * N, [0] * N
    graph = [[] for _ in range(N)]

    for u, v in edges:
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)

    def f(parent: int, v: int)->int:
        if memo_f[v]:
            return memo_f[v]

        memo_f[v] = 1
        for child in graph[v]:
            if parent == child:
                continue
            memo_f[v] = (memo_f[v]*g(v, child)) % MOD

        memo_f[v] = (memo_f[v] + g(parent, v)) % MOD
        return memo_f[v]

    def g(parent: int, v: int)->int:
        if memo_g[v]:
            return memo_g[v]

        memo_g[v] = 1
        for child in graph[v]:
            if parent == child:
                continue
            memo_g[v] = (memo_g[v]*f(v, child)) % MOD

        return memo_g[v]

    return f(-1, 0)


if __name__ == "__main__":
    N = int(input())
    edges = [tuple(int(s) for s in input().split()) for _ in range(N-1)]
    ans = draw(N, edges)
    print(ans)