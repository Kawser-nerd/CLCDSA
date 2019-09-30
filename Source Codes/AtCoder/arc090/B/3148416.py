class WeightedUnionFind(object):
    __slots__ = ["nodes", "weight"]

    def __init__(self, n: int) -> None:
        self.nodes = [-1]*n
        self.weight = [0]*n

    def get_root(self, x: int) -> int:
        if x < 0:
            raise ValueError("Negative Index")

        if self.nodes[x] < 0:
            return x
        else:
            parent, self.nodes[x] = self.nodes[x], self.get_root(self.nodes[x])
            self.weight[x] += self.weight[parent]
            return self.nodes[x]

    def unite(self, x: int, y: int) -> None:
        if x < 0 or y < 0:
            raise ValueError("Negative Index")

        root_x, root_y = self.get_root(x), self.get_root(y)
        if root_x != root_y:
            bigroot, smallroot = \
                (root_x, root_y) if self.nodes[root_x] < self.nodes[root_y] else (root_y, root_x)
            self.nodes[bigroot] += self.nodes[smallroot]
            self.nodes[smallroot] = bigroot

    def relate(self, smaller: int, bigger: int, diff_weight: int) -> None:
        if smaller < 0 or bigger < 0:
            raise ValueError("Negative Index")

        s_root, b_root = self.get_root(smaller), self.get_root(bigger)
        if s_root == b_root:
            # ??????????????????????-1??????
            if self.weight[smaller] + diff_weight == self.weight[bigger]:
                return
            raise ValueError("relate?????")
        else:
            self.weight[b_root] = diff_weight - self.weight[bigger]
            self.nodes[s_root] += self.nodes[b_root]
            self.nodes[b_root] = smaller

    def diff(self, x: int, y: int) -> int:
        root_x, root_y = self.get_root(x), self.get_root(y)
        if root_x != root_y:
            return None
        return self.weight[y] - self.weight[x]

import sys
N, M = map(int, input().split())
tree = WeightedUnionFind(N+1)
try:
    for l, r, d in (map(int, l.split()) for l in sys.stdin):
        tree.relate(l, r, d)
    print("Yes")
except Exception as e:
    print("No")