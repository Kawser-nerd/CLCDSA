import sys
input = sys.stdin.readline

class Tree:
    def __init__(self, n):
        self.par = [i for i in range(n)]
    
    def unite(self, par, chi):
        self.par[chi] = par
    
    def get_child(self, par):
        child = set()
        for i in range(len(self.par)):
            if i != par and self.par[i] == par:
                child.add(i)
        return child


def salary(x):
    if money[x] != -1:
        return money[x]
    else:
        chilist = member.get_child(x)
        if len(chilist) == 0:
            money[x] = 1
            return money[x]
        else:
            sub = set()
            for i in chilist:
                sub.add(salary(i))
            money[x] = max(sub) + min(sub) + 1
            return money[x]


N = int(input())
B = [0]*2 + [int(input()) for _ in range(N-1)]
member = Tree(N+1)
money = [-1]*(N+1)

for i in range(2, N+1):
    member.unite(B[i], i)

print(salary(1))