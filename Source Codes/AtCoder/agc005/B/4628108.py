# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


class UnionFind:
    """
    size?????
    """

    def __init__(self, N):
        self.parent = [i for i in range(N)]
        self.size = [1 for _ in range(N)]

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            return self.find(self.parent[x])

    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px == py:
            return
        if self.size[px] < self.size[py]:
            self.parent[px] = py
            self.size[py] += self.size[px]
        else:
            self.parent[py] = px
            self.size[px] += self.size[py]

    def same(self, x, y):
        return self.find(x) == self.find(y)


N = int(input())
A = list(map(int, input().split()))

Un = UnionFind(N+1)
pos = [-1]*(N+1)
for i, a in enumerate(A):
    pos[a] = i

ans = 0
for i in reversed(range(1, N+1)):
    ind = pos[i]
    left = 0
    right = 0
    if ind > 0 and A[ind] < A[ind-1]:
        left = Un.size[Un.find(ind-1)]
        Un.union(ind, ind-1)
    if ind+1 < N and A[ind+1] > A[ind]:
        right = Un.size[Un.find(ind+1)]
        Un.union(ind, ind+1)
    ans += (left+1)*(right+1)*A[ind]

print(ans)