# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


class UnionFind:
    """
    ???????Union Find
    """

    def __init__(self, size):
        """
        size:????
        """
        self.parent = [i for i in range(size)]
        self.rank = [0 for _ in range(size)]

    def find(self, x):
        """
        x?root???
        """
        if self.parent[x] == x:
            return x
        else:
            return self.find(self.parent[x])

    def union(self, x, y):
        """
        x,y??????????????
        """
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        """
        x?y?????????True
        """
        return self.find(x) == self.find(y)

    def component(self):
        """
        ??????root??????
        len()????????????????
        return-> set()
        """
        comp = set()
        for i in self.parent:
            p = self.find(i)
            comp.add(p)
        return comp

    def __str__(self):
        """
        for debug
        ????list??????
        """
        ret = "parents\n"
        ret += " ".join(map(str, self.parent))
        ret += '\n'
        ret += " ".join(map(str, self.rank))
        return ret


N, M = map(int, input().split())
Un = UnionFind(N+1)

for _ in range(M):
    a, b = map(int, input().split())
    Un.union(a, b)
g = len(Un.component())
print(g-2)