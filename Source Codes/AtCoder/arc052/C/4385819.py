def dijkstra(v_count: int, edges: list, start: int, unreachable=10**18) -> list:
    """ ??????
    :param v_count: ???
    :param edges: ?????(?????or????)
    :param start: ????????
    :param unreachable: ???????????
    """
    from heapq import heappush, heappop

    vertices = [[unreachable]*300 for _ in [0]*v_count]
    min_b = [0] + [-1]*(N-1)
    vertices[start] = [0] * 300
    q, rem = [(0, 0, start)], v_count - 1

    while q:
        b, cost, v = heappop(q)
        if vertices[v][b-min_b[v]] < cost:
            continue

        for dest, _b in edges[v]:
            new_b = b + _b
            new_cost = cost + (new_b if _b else 1)
            if min_b[dest] == -1:
                min_b[dest] = new_b
            b_index = new_b - min_b[dest] + 1
            if min(vertices[dest][:b_index+1]) > new_cost:
                vertices[dest][b_index] = new_cost
                heappush(q, (new_b, new_cost, dest))

    return vertices


if __name__ == "__main__":
    import sys

    N, M = map(int, input().split())
    edges = [[] for _ in [0]*N]
    for c, a, b in (map(int, l.split()) for l in sys.stdin):
        edges[a].append((b, c))
        edges[b].append((a, c))
    dists = dijkstra(N, edges, 0)

    print(0)
    for l in dists[1:]:
        print(min(l))