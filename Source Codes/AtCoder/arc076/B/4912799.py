# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


class UnionFind:
    def __init__(self, size):
        """
        size:????
        parent[x]->parent of x
        rank[x] -> height of tree of x
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

    def componentNum(self):
        """
        ?????????
        """
        return len(self.component())

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


N = int(input())
X = []
Y = []
cand = []
for i in range(N):
    x, y = map(int, input().split())
    X.append([i, x])
    Y.append([i, y])

X = sorted(X, key=lambda x: x[1])
Y = sorted(Y, key=lambda x: x[1])

for p1, p2 in zip(X, X[1:]):
    i1, x1 = p1
    i2, x2 = p2
    cand.append([i1, i2, x2-x1])

for p1, p2 in zip(Y, Y[1:]):
    i1, y1 = p1
    i2, y2 = p2
    cand.append([i1, i2, y2-y1])

Un = UnionFind(N)
ans = 0

cand = sorted(cand, key=lambda x: x[2])
for s, g, w in cand:
    if Un.same(s, g):
        continue
    else:
        Un.union(s, g)
        ans += w
print(ans)