N = int(input())
S1 = input()
S2 = input()

D = {chr(ord("A")+i-10): i for i in range(10, 36)}
for i in range(10):
    D[str(i)] = i


class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0] * n
        self.size = [1] * n

    # ??
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # ??
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.size[y] += self.size[x]
            self.size[x] = 0
        else:
            self.par[y] = x
            self.size[x] += self.size[y]
            self.size[y] = 0
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    # ???????????
    def same(self, x, y):
        return self.find(x) == self.find(y)

    # ????????????????
    def all_find(self):
        for n in range(len(self.par)):
            self.find(n)


# 0 ~ 9, A~Z, ?????
UF = UnionFind(37)

# ????????????
UF.union(D[S1[0]], 36)
UF.union(D[S2[0]], 36)

# union
for s1, s2 in zip(S1, S2):
    UF.union(D[s1], D[s2])
UF.all_find()

# ?????
ans = 1
used = set()
for s1 in S1:
    for i in range(10):
        if UF.same(D[s1], i) or UF.par[D[s1]] in used:
            break
    else:
        used.add(UF.par[D[s1]])
        if UF.same(D[s1], 36):
            ans *= 9
        else:
            ans *= 10

print(ans)