class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
        self.size = [1] * size

    def root(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.root(self.parent[x])
        return self.parent[x]

    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)

        if x == y:
            return 0

        # ????????????????
        if self.rank[x] > self.rank[y]:
            self.parent[y] = x
            self.size[x] += self.size[y]
            return self.diff_combine(self.size[x], self.size[x] - self.size[y], self.size[y])
        else:
            # ???????????????????????????
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1
            self.parent[x] = y
            self.size[y] += self.size[x]
            return self.diff_combine(self.size[y], self.size[x], self.size[y] - self.size[x])

    def diff_combine(self, num1, num2, num3):
        return (num1 * (num1 - 1) // 2) - (num2 * (num2 - 1) // 2) - (num3 * (num3 - 1) // 2)

    def same(self, x, y):
        return self.root(x) == self.root(y)


def solve(n, m, graphs):
    num = n * (n - 1) // 2
    buff = [num]
    union = UnionFind(n)

    for key in range(m - 1, 0, -1):
        x, y = graphs[key]
        diff = union.unite(x-1, y-1)
        num -= diff
        buff.append(num)

    for num in reversed(buff):
        print(num)


def main():
    n, m = map(int, input().split())

    graphs = []
    for _ in range(m):
        direction = list(map(int, input().split()))
        graphs.append(direction)

    solve(n, m, graphs)


main()