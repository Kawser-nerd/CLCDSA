def candidates_of_no_shortest_paths(N: int, M: int, edges: list)->int:
    INF = float('inf')

    d = [[0 if i == j else INF for i in range(N)] for j in range(N)]

    for u, v, c in edges:
        d[u-1][v-1] = d[v-1][u-1] = c

    # warshall-floyd
    for k in range(N):
        for u in range(N):
            for v in range(N):
                if d[u][v] > d[u][k] + d[k][v]:
                    d[u][v] = d[u][k] + d[k][v]

    def used(edge: tuple)->bool:
        u, v, c = edge
        for s in range(N):
            if d[s][u-1] + c == d[s][v-1]:
                return True
        return False

    return sum(not used(edge) for edge in edges)


if __name__ == "__main__":
    M = 0
    N, M = map(int, input().split())
    edges = [tuple(int(s) for s in input().split()) for _ in range(M)]
    ans = candidates_of_no_shortest_paths(N, M, edges)
    print(ans)