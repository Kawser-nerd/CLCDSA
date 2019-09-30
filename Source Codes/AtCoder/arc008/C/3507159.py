import sys
from itertools import product
from math import hypot


def dijkstra(v_count: int, edges: list, start: int,
             *, adj_matrix: bool = False, unreachable=float("inf")) -> list:
    """ ??????
    :param v_count: ???
    :param edges: ?????(?????or????)
    :param start: ????????
    :param adj_matrix: edges??????????????True
    :param unreachable: ???????????
                        ???????????????????????????
    """
    from heapq import heappush, heappop

    vertices = [unreachable] * v_count
    vertices[start] = 0
    q, rem = [(0, start)], v_count - 1

    while q and rem:
        cost, v = heappop(q)
        if vertices[v] < cost:
            continue
        rem -= 1

        dests = enumerate(edges[v]) if adj_matrix else edges[v]

        for dest, _cost in dests:
            newcost = cost + _cost
            if vertices[dest] > newcost:
                vertices[dest] = newcost
                heappush(q, (newcost, dest))

    return vertices


N = int(input())
a = [list(map(int, l.split())) for l in sys.stdin]
matrix = [[0]*N for _ in [0]*N]
for (i, (x1, y1, t1, r1)), (j, (x2, y2, t2, r2)) in product(enumerate(a), repeat=2):
    if i == j:
        continue
    matrix[i][j] = hypot(x1-x2, y1-y2) / (t1 if t1 < r2 else r2)
costs = [0] + [i+n for i, n in enumerate(sorted(dijkstra(N, edges=matrix, start=0, adj_matrix=True), reverse=True)[:-1])]
print(max(costs))