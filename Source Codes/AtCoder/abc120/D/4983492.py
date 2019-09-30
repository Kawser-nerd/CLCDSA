N, M = map(int, input().split())

alist = []
blist = []

for i in range(M):
    a,b = map(int, input().split())
    alist.append(a)
    blist.append(b)

class UnionFind(object):
    """docstring for UnionFind."""

    def __init__(self, num_nodes):
        super(UnionFind, self).__init__()
        self.root = [i for i in range(num_nodes+1)]
        self.rank = [0]*(num_nodes+1)
        self.size = [1]*(num_nodes+1)

    def find(self, x):
        if x != self.root[x]:
            self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x, y):
        xroot, yroot = self.find(x), self.find(y)
        if xroot == yroot:
            return
        elif self.rank[xroot] < self.rank[yroot]:
            self.root[xroot] = yroot
            self.size[yroot] += self.size[xroot]
        else:
            self.root[yroot] = xroot
            self.size[xroot] += self.size[yroot]
            if self.rank[xroot] == self.rank[yroot]:
                self.rank[xroot] += 1

anslist = []
ans = N*(N-1)/2

unionfind = UnionFind(N)
alist = alist[::-1]
blist = blist[::-1]

for i in range(M):
    anslist.append(ans)
    a = alist[i]
    b = blist[i]
    aroot, broot = unionfind.find(a), unionfind.find(b)
    # print(aroot, broot)
    if aroot == broot:
        continue
    p, q = unionfind.size[aroot], unionfind.size[broot]
    unionfind.union(aroot, broot)
    ans -= p*q

for i in range(M):
    print(int(anslist[M-i-1]))