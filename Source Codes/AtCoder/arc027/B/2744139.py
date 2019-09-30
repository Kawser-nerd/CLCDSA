N = int(input())
S1 = input()
S2 = input()
A = {chr(ord("A")+ i): i+10 for i in range(26)}
for i in range(10):
    A[str(i)] = i


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
    def same_check(self, x, y):
        return self.find(x) == self.find(y)

    # ????????????????
    def all_find(self):
        for n in range(1, len(self.par)):
            self.find(n)


# 0 ~ 9, A ~ Z, TOP
uf = UnionFind(37)

uf.union(A[S1[0]], 36)
uf.union(A[S2[0]], 36)

for s1, s2 in zip(S1, S2):
    uf.union(A[s1], A[s2])

uf.all_find()


U = set()
ans = 1
for s1 in S1:
    for i in range(10):
        if uf.same_check(A[s1], i):
            break
    else:
        if uf.find(A[s1]) not in U:
            if uf.same_check(A[s1], 36):
                ans *= 9
            else:
                ans *= 10
            U.add(uf.find(A[s1]))

print(ans)