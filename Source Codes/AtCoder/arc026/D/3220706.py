import sys


def kruskal(v_count: int, edges: list, wage: int) -> int:
    """
    :param v_count: ???
    :param edges: [(weight, from, to), ... ]
    """
    from itertools import islice
    tree = [-1]*v_count

    def get_root(x) -> int:
        if tree[x] < 0:
            return x
        tree[x] = get_root(tree[x])
        return tree[x]

    def unite(a, b) -> bool:
        x, y = get_root(a), get_root(b)
        if x != y:
            big, small = (x, y) if tree[x] < tree[y] else (y, x)
            tree[big] += tree[small]
            tree[small] = big
        return x != y

    cost = 0
    edges = sorted((c-t*wage, a, b) for a, b, c, t in edges)
    from bisect import bisect_right
    inf = float("inf")
    border = bisect_right(edges, (0, inf, inf))
    count = 1
    for w, _s, _t in edges[:border]:
        count += unite(_s, _t)
        cost += w
    if count < N:
        for w, _s, _t in edges[border:]:
            if unite(_s, _t):
                count += 1
                cost += w
                if count == N:
                    break

    return cost


N, M = map(int, input().split())
edges = []
append = edges.append
for a, b, c, t in ((map(int, l.split())) for l in sys.stdin):
    append((a, b, c, t))

ng, ok = 10**15, 0
while ng-ok > 1e-5:
    mid = (ok+ng) / 2
    cost = kruskal(N, edges, mid)
    if cost < 0:
        ng = mid
    else:
        ok = mid
print(ok)