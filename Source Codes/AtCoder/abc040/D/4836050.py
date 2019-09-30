import heapq
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


N, M = map(int, input().split())
road = [list(map(int, input().split())) for _ in range(M)]
Q = int(input())
query = []
for i in range(Q):
    q, year = list(map(int, input().split()))
    query.append([i, q, year])

road = sorted(road, key=lambda x: x[2], reverse=True)
query = sorted(query, key=lambda x: x[2], reverse=True)

Un = UnionFind(N)

ans = [0]*Q
left = 0
for i, n, q in query:
    for j in range(left, M):
        if road[j][2] > q:
            Un.union(road[j][0]-1, road[j][1]-1)
            left += 1
        else:
            break
    ans[i] = Un.size[Un.find(n-1)]
print("\n".join(map(str, ans)))