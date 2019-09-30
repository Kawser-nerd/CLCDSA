# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


class UnionFind:
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for _ in range(size)]

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            return self.find(self.parent[x])

    def union(self, x, y):
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
        return self.find(x) == self.find(y)

    def __str__(self):
        ret = "parents\n"
        ret += " ".join(map(str, self.parent))
        ret += '\n'
        ret += " ".join(map(str, self.rank))
        return ret


N, K, L = map(int, input().split())


def solve1():
    root = UnionFind(N)
    train = UnionFind(N)

    for _ in range(K):
        a, b = map(lambda x: int(x)-1, input().split())
        root.union(a, b)

    for _ in range(L):
        a, b = map(lambda x: int(x)-1, input().split())
        train.union(a, b)
    ans = [1]*N
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            else:
                if root.same(i, j) and train.same(i, j):
                    ans[i] += 1
    print(" ".join(map(str, ans)))


def solve2():
    ans = [0]*N
    root = UnionFind(N)
    train = UnionFind(N)
    for _ in range(K):
        a, b = map(lambda x: int(x)-1, input().split())
        root.union(a, b)

    for _ in range(L):
        a, b = map(lambda x: int(x)-1, input().split())
        train.union(a, b)

    d = 10**6
    nums = dict()
    for i in range(N):
        n = root.find(i)+train.find(i)*d
        if n in nums.keys():
            nums[n] = nums[n]+1
        else:
            nums[n] = 1

    for i in range(N):
        ans[i] = nums[root.find(i)+train.find(i)*d]

    print(" ".join(map(str, ans)))


solve2()