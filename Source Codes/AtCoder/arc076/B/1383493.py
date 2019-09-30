class Edge:
    def __init__(self, u, v, cost):
        self.u = u
        self.v = v
        self.cost = cost
        # self.n = n


class Coordinate:
    def __init__(self, x, y, n):
        self.x = x
        self.y = y
        self.n = n

    def __repr__(self):
        return repr((self.x, self.y))


# union find????
def init(_n):
    for i in range(0, _n):
        par[i] = i
        rank[i] = 0


# ???????
def find(_x):
    if par[_x] == _x:
        return _x
    else:
        par[_x] = find(par[_x])
        return par[_x]


# ?????
def unite(_x, _y):
    _x = find(_x)
    _y = find(_y)
    if _x == _y:
        return

    if rank[_x] < rank[_y]:
        par[_x] = _y
    else:
        par[_y] = _x
        if rank[_x] == rank[_y]:
            rank[_x] += 1


# ????????
def same(_x, _y):
    return find(_x) == find(_y)


def comp(edge1, edge2):
    return edge1.cost < edge2.cost


def kruskal():
    sorted_edges = sorted(Edges, key=lambda edges: edges.cost)
    init(V)
    res = 0
    # for i in range(E):
    # # print("u" + str(sorted_edges[i].u) + "v" + str(sorted_edges[i].v) + "cost" + str(sorted_edges[i].cost))

    for i in range(0, E):
        tmp_edge = sorted_edges[i]
        if not same(tmp_edge.u, tmp_edge.v):
            unite(tmp_edge.u, tmp_edge.v)
            # print("tmp_edge.cost" + str(tmp_edge.cost))
            res += tmp_edge.cost

    return res


if __name__ == '__main__':
    N = int(input())
    x = []
    y = []
    Coordinates = []
    for i in range(0, N):
        tmp_x, tmp_y = list(map(int, input().split()))
        # x.append(tmp_x)
        # y.append(tmp_y)
        Coordinates.append(Coordinate(tmp_x, tmp_y, i))

    sorted_by_x = sorted(Coordinates, key=lambda coordinate: coordinate.x)
    sorted_by_y = sorted(Coordinates, key=lambda coordinate: coordinate.y)

    Edges = []
    for i in range(0, N - 1):
        cost_x = min(abs(sorted_by_x[i].x - sorted_by_x[i + 1].x), abs(sorted_by_x[i].y - sorted_by_x[i + 1].y))
        Edges.append(Edge(sorted_by_x[i].n, sorted_by_x[i + 1].n, cost_x))
        # Edges.append(Edge(sorted_by_x[i + 1].n, sorted_by_x[i].n, cost_x))
        cost_y = min(abs(sorted_by_y[i].x - sorted_by_y[i + 1].x), abs(sorted_by_y[i].y - sorted_by_y[i + 1].y))
        Edges.append(Edge(sorted_by_y[i].n, sorted_by_y[i + 1].n, cost_y))
        # Edges.append(Edge(sorted_by_y[i + 1].n, sorted_by_y[i].n, cost_y))

    par = [0 for i in range(N)]
    rank = [0 for i in range(N)]
    V = N
    E = 2 * (N - 1)

    print(kruskal())