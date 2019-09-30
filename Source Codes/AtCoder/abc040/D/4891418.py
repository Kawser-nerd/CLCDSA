class UnionFind:
    def __init__(self, size: int):
        self.__size = size
        self.__root = [-1] * size

    def find(self, x: int)->int:
        if self.__root[x] < 0:
            return x

        self.__root[x] = self.find(self.__root[x])
        return self.__root[x]

    def same(self, x: int, y: int)->bool:
        return self.find(x) == self.find(y)

    def unite(self, x: int, y: int)->bool:
        rx, ry = self.find(x), self.find(y)

        if rx == ry:
            return

        if self.__root[ry] < self.__root[rx]:
            rx, ry = ry, rx

        self.__root[rx] += self.__root[ry]
        self.__root[ry] = rx

    def size(self, x: int)->bool:
        rx = self.find(x)
        return -self.__root[rx]


def road_aging_measures(N: int, M: int, edges: list, Q: int, queries: list)->list:
    ret = [0] * Q

    uf = UnionFind(N)

    ei = 0
    edges = sorted(edges, key=lambda x: -x[2])
    queries = sorted((-w, v, i) for i, (v, w) in enumerate(queries))

    for w, v, i in queries:
        w = -w

        while ei < M and edges[ei][2] > w:
            s, t, _ = edges[ei]
            uf.unite(s-1, t-1)
            ei += 1

        ret[i] = uf.size(v-1)

    return ret


if __name__ == "__main__":
    M = 0
    N, M = map(int, input().split())
    edges = [tuple(int(s) for s in input().split()) for _ in range(M)]
    Q = int(input())
    queries = [tuple(int(s) for s in input().split()) for _ in range(Q)]

    ans = road_aging_measures(N, M, edges, Q, queries)
    for a in ans:
        print(a)