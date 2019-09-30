import sys


def kruskal(v_count: int, edges: list) -> int:
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

    def unite(a) -> bool:
        x, y = get_root(a[1]), get_root(a[2])
        if x != y:
            big, small = (x, y) if tree[x] < tree[y] else (y, x)
            tree[big] += tree[small]
            tree[small] = big
        return x != y

    cost = 0
    for w, _s, _t in islice(filter(unite, sorted(edges)), v_count-1):
        cost += w
    return cost


if __name__ == "__main__":
    N, M = map(int, input().split())
    edges = []
    append = edges.append
    for i, c in enumerate(map(int, (sys.stdin.readline() for _ in [0]*N)), start=1):
        append((c, 0, i))
    for i, j, c in (map(int, l.split()) for l in sys.stdin):
        append((c, i, j))
    print(kruskal(N+1, edges))