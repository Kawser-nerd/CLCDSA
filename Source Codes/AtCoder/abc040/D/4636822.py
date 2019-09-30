from operator import itemgetter

n, m = map(int, input().split())
aby = [[int(i) for i in input().split()] for _ in range(m)]
q = int(input())
vw = [[int(i) for i in input().split()] + [j] for j in range(q)]

aby.sort(key=itemgetter(2), reverse=True)
vw.sort(key=itemgetter(1), reverse=True)

class UnionFind:
    def __init__(self, size):
        self.rank = [-1 for _ in range(size)]
        self.number = [1 for _ in range(size)]

    def find(self, x):
        while self.rank[x] >= 0:
            x = self.rank[x]
        return x

    def size(self, x):
        return self.number[self.find(x)]

    def union(self, s1, s2):
        if s1 == s2:
            return
        if self.rank[s1] == self.rank[s2]:
            self.rank[s1] -= 1
            self.rank[s2] = s1
            self.number[s1] += self.number[s2]
        elif self.rank[s1] < self.rank[s2]:
            self.rank[s2] = s1
            self.number[s1] += self.number[s2]
        else:
            self.rank[s1] = s2
            self.number[s2] += self.number[s1]

uft = UnionFind(n)

ans = [0] * q

t = 0

for v, w, j in vw:
    for i in range(t, m):
        a, b, y = aby[i]
        if y <= w:
            t = i
            break
        if uft.find(a-1) != uft.find(b-1):
            uft.union(uft.find(a-1), uft.find(b-1))
    else:
        t = m
    ans[j] = uft.size(v-1)

for i in range(q):
    print(ans[i])