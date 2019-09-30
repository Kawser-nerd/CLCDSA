def bellman_ford(vertex_num: int, edges: list, source: int, sink: int) -> list:
    # 1) initialize distance
    distances = [float('inf')] * (vertex_num)
    distances[source] = 0

    # 2) update distances (upto vertex_num-1 times)
    for _ in range(vertex_num):
        for u, v, c in edges:
            distances[v] = min(distances[v], distances[u] + c)

    # 3) detect negative-loop
    for u, v, c in edges:
        if distances[u] + c < distances[v]:
            distances[v] = distances[u] + c

            if v == sink:
                return []

    return distances


def score_attack(N: int, M: int, edges: list) -> int:
    distances = bellman_ford(N, [(u-1, v-1, -c) for u, v, c in edges], 0, N-1)

    return -distances[N - 1] if distances else float('inf')


if __name__ == "__main__":
    M = 0
    N, M = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(M)]
    ans = score_attack(N, M, edges)
    print(ans)