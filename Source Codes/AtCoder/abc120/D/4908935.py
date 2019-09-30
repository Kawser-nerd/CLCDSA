class UnionFind:
    def __init__(self, nodes):
        self._parents = {k: k for k in nodes}
        self._ranks = {k: 0 for k in nodes}
        self._sizes = {k: 1 for k in nodes}

    def union(self, x, y):
        """
        x ?????? y ????????
        :param x:
        :param y:
        :return:
        """
        x = self.find(x)
        y = self.find(y)
        if x != y:
            # rank ???????
            if self._ranks[x] > self._ranks[y]:
                self._parents[y] = x
                self._sizes[x] += self._sizes[y]
            else:
                self._parents[x] = y
                self._sizes[y] += self._sizes[x]
                if self._ranks[x] == self._ranks[y]:
                    self._ranks[y] += 1

    def find(self, x):
        """
        x ?????? root
        :param x:
        :return:
        """
        if self._parents[x] == x:
            return x
        self._parents[x] = self.find(self._parents[x])
        return self._parents[x]

    def size(self, x):
        """
        x ??????????
        :param x:
        :return:
        """
        return self._sizes[self.find(x)]


n, m = map(int, input().split())

bridges = []
for _ in range(m):
    bridges.append(list(map(int, input().split())))


def c2(n):
    # n ??2???????? nC2
    return int(n * (n - 1) / 2)


bridges.reverse()
uf = UnionFind(nodes=[i + 1 for i in range(n)])
# ???; ???????????????
useful = 0
useful_history = []

for bridge in bridges:
    useful_history.append(useful)

    if uf.find(bridge[0]) != uf.find(bridge[1]):
        # ????????????????
        size0 = uf.size(bridge[0])
        size1 = uf.size(bridge[1])
        useful += c2(size0 + size1) - c2(size0) - c2(size1)
        uf.union(bridge[0], bridge[1])

for u in reversed(useful_history):
    print(useful - u)