import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

class UnionFind:
    def __init__(self, node:int) -> None:
        self.n = node
        self.par = [i for i in range(self.n)]
        self.rank = [0 for i in range(self.n)]
        self.elem = [1 for i in range(self.n)]
        
    def find(self, x:int) -> int:
        if x == self.par[x]:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]
        
    def unite(self, x:int, y:int) -> bool:
        if self.isSame(x,y):
            #print("x and y has already united")
            return False
        
        rx = self.find(x)
        ry = self.find(y)
        
        if self.rank[rx] < self.rank[ry]:
            self.par[rx] = self.par[ry]
            
            self.elem[ry] += self.elem[rx]
            self.elem[rx] = 0
        
        else:
            self.par[ry] = self.par[rx]
            
            if self.rank[rx] == self.rank[ry]:
                self.rank[rx] += 1
                
            self.elem[rx] += self.elem[ry]
            self.elem[ry] = 0
                        
        return True
                
    def isSame(self, x:int, y:int) -> bool:
        return self.find(x) == self.find(y)
    
    
# ??
n,m = li()
road = []
for _ in range(m):
    a,b,y = li()
    a -= 1
    b -= 1
    road.append((y,a,b))
    
road.sort()
    
# ????????
q = ni()
query = []
for _ in range(q):
    v,w = li()
    v -= 1
    query.append((w,v))

querydic = [qi for qi in query]
 
query.sort(reverse=True)

# ?????????unite
uf = UnionFind(n)
ufdic = {}
for wi, vi in query:
    for i in range(m):
        if len(road) == 0:
            break
        
        y,a,b = road.pop()
        if y <= wi:
            road.append((y,a,b))
            break
        
        else:
            uf.unite(a,b)
      
    ufdic.update({(wi, vi): uf.elem[uf.find(vi)]})

for i in range(q):
    print(ufdic[querydic[i]])