def one_stroke_path(N: int, M: int, edges: list) -> int:
    g = [[] for _ in range(N)]
    for u, v in edges:
        g[u-1].append(v-1)
        g[v-1].append(u-1)

    visited = [False] * N
    visited[0] = True

    def dfs(current: int, visited_num: int) -> int:
        if not visited[current] and visited_num + 1 == N:
            return 1

        visited[current] = True

        total = sum(dfs(to, visited_num + 1)
                    for to in g[current] if not visited[to])

        visited[current] = False

        return total

    return dfs(0, 0)


if __name__ == "__main__":
    M = 0
    N, M = map(int, input().split())
    edges = [tuple(int(s) for s in input().split()) for _ in range(M)]
    ans = one_stroke_path(N, M, edges)
    print(ans)