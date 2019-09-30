# coding:utf-8

import sys
from operator import itemgetter


input = sys.stdin.readline
INF = float('inf')
MOD = 10 ** 9 + 7


def inpl(): return list(map(int, input().split()))


class UnionFind:
    __slots__ = ['nodes', 'weight']

    def __init__(self, size: int) -> None:
        self.nodes = [-1] * size  # ???????????????????????????????
        self.weight = [0] * size  # ???x -> ???(???x)???????

    # ??
    def find(self, x: int) -> int:
        if self.nodes[x] < 0:
            return x
        else:
            parent = self.find(self.nodes[x])
            self.weight[x] += self.weight[self.nodes[x]]
            self.nodes[x] = parent
            return parent

    # ??
    def unite(self, x: int, y: int, w: int) -> bool:
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return False
        else:
            rank_x = -self.nodes[root_x]
            rank_y = -self.nodes[root_y]
            if rank_x < rank_y:
                self.nodes[root_x] = root_y
                self.weight[root_x] = w + self.weight[y] - self.weight[x]
            else:
                self.nodes[root_y] = root_x
                self.weight[root_y] = -w + self.weight[x] - self.weight[y]

                if rank_x == rank_y:
                    self.nodes[root_x] += -1

            return True

    # ?????
    def is_same(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)


N, M = inpl()
graph = [(0, i + 1, int(input())) for i in range(N)]

for _ in range(M):
    graph.append(tuple(inpl()))

graph.sort(key=itemgetter(2))

uf = UnionFind(N + 1)
ans = 0
for i in range(N + M):
    a, b, c = graph[i]
    if uf.is_same(a, b):
        continue
    else:
        uf.unite(a, b, 0)
        ans += c

print(ans)