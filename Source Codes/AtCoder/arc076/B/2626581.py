import numpy as np

def ii():
    return int(input())


def lii():
    return list(map(int, input().split(' ')))


def lvi(N):
    l = []
    for _ in range(N):
        l.append(ii())
    return l


def lv(N):
    l = []
    for _ in range(N):
        l.append(input())
    return l


def next_pair(lst):
    n = len(lst)
    for i in range(n-1):
        yield lst[i], lst[i+1]


class UnionFind(object):

    def __init__(self, n):
        # ??node???
        self.par = [i for i in range(n)]

    def root(self, x):
        if self.par[x] == x:
            return x
        else:
            # ????
            self.par[x] = self.root(self.par[x])
            return self.par[x]

    def same(self, x, y):
        return self.root(x) == self.root(y)

    def union(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return

        self.par[x] = y


class UnionFindRank(UnionFind):

    def __init__(self, n):
        UnionFind.__init__(self, n)

        self.rank = [0 for _ in range(n)]

    def union(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.rank[x] += 1
        else:
            self.par[y] = x
            self.rank[y] += 1


class UnionFindRankCount(UnionFind):

    def __init__(self, n):
        UnionFind.__init__(self, n)

        self.rank = [0 for _ in range(n)]
        self.count = [1 for _ in range(n)]

    def union(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.count[y] += self.count[x]
        else:
            self.par[y] = x
            self.count[x] += self.count[y]
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1


def kruskal(n, edges):
    """
    :param n: int node?
    :param edges: list(tuple(int)) edge
        ex.) edges = [(0, 1, 10), (1, 0, 50), (2, 0, 30)]  (from, to, weight)
    :return: ??????????????edges??????
    """
    edges = sorted(edges, key=lambda x: x[2])
    u = UnionFindRankCount(n)

    k = []
    cnt = 0
    for e in edges:
        i, j, w = e
        if not u.same(i, j):
            u.union(i, j)
            k.append(e)
            cnt += 1

        if cnt == n-1: break

    return k



def main():
    N = ii()
    coord = []
    for n in range(N):
        x, y = lii()
        coord.append((x, y, n))

    c_sortx = sorted(coord, key=lambda x: x[0])
    c_sorty = sorted(coord, key=lambda x: x[1])

    edges = []
    for p1, p2 in next_pair(c_sortx):
        w = min(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]))
        edges.append([p1[2], p2[2], w])

    for p1, p2 in next_pair(c_sorty):
        w = min(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]))
        edges.append([p1[2], p2[2], w])

    min_tree = kruskal(N, edges)
    return sum(map(lambda x: x[2], min_tree))


if __name__ == '__main__':
    print(main())