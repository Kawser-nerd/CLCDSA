class UnionFind:
    def __init__(self, n):
        #?????????????par[x] == x?????????root
        self.par = [i for i in range(n)]
        #???????????0?
        self.rank = [0] * n

    def find(self, x):
        #???????
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def same(self, x, y):
        # x?y?????????????
        return self.find(x) == self.find(y)

    def union(self, x, y):
        #????
        #??????
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

N, Q = map(int, input().split())

#?i?towns[i]???towns[i + N]???
towns = UnionFind(2 * N)
answers = []
for k in range(Q):
    wi, xi, yi, zi = map(int, input().split())
    if wi == 1:
        if zi % 2 == 0:
            towns.union(xi - 1, yi - 1)
            towns.union(xi - 1 + N, yi - 1 + N)
        else:
            towns.union(xi - 1, yi - 1 + N)
            towns.union(xi - 1 + N, yi - 1)
    else:
        answers.append('YES' if towns.same(xi - 1, yi - 1) else 'NO')
for ans in answers:
    print(ans)