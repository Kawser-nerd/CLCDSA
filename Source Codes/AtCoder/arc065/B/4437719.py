class UnionFind(object):
    __slots__ = ["nodes"]

    def __init__(self, n: int) -> None:
        self.nodes = [-1]*n

    def get_root(self, x: int) -> int:
        if self.nodes[x] < 0:
            return x
        else:
            self.nodes[x] = self.get_root(self.nodes[x])
            return self.nodes[x]

    def unite(self, x: int, y: int) -> None:
        root_x, root_y = self.get_root(x), self.get_root(y)
        if root_x != root_y:
            bigroot, smallroot = \
                (root_x, root_y) if self.nodes[root_x] < self.nodes[root_y] else (root_y, root_x)
            self.nodes[bigroot] += self.nodes[smallroot]
            self.nodes[smallroot] = bigroot


if __name__ == "__main__":
    import sys
    from collections import Counter

    N, K, L = map(int, input().split())
    uf1 = UnionFind(N)
    uf2 = UnionFind(N)
    for p, q in (map(int, sys.stdin.readline().split()) for _ in [0]*K):
        uf1.unite(p-1, q-1)
    for r, s in (map(int, l.split()) for l in sys.stdin):
        uf2.unite(r-1, s-1)

    counter = Counter()
    key = [None]*N
    for i in range(N):
        key[i] = (uf1.get_root(i), uf2.get_root(i))
        counter[key[i]] += 1

    print(*(counter[key[i]] for i in range(N)))