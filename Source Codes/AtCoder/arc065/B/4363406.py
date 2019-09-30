# D
class UnionFind:
    """size(int)???
    root(x:int)->int:      ?????
    unite(x,y:int):        ???????????? 
    isSame(x,y:int)->bool: ????????????????
    """
    # ???????
    # ?????????????  
    def __init__(self, size: int):
        self.par = [-1]*size # ????
        for i in range(size):
            self.par[i] = i  # ??? ????????
    
    def root(self, x: int) -> int:
        """?????"""
        if self.par[x] == x: # if root
            return x
        else:
            self.par[x] = self.root(self.par[x]) # ????
            return self.par[x]
    
    def isSame(self, x:int, y:int)->bool:
        """x ? y ????????????"""
        return self.root(x)==self.root(y)
    
    def unite(self, x:int, y:int):
        """x ? y ?????????"""
        x = self.root(x)
        y = self.root(y)
        if x == y: return
        self.par[x] = y
        
# ------------------
N,K,L = map(int, input().split())
uf_k = UnionFind(N)
uf_l = UnionFind(N)
for _ in range(K):
    p,q = map(int, input().split())
    uf_k.unite(p-1, q-1)
for _ in range(L):
    r,s= map(int, input().split())
    uf_l.unite(r-1, s-1)

cnt = dict()
for i in range(N):
    r_k,r_l = uf_k.root(i), uf_l.root(i)
    if (r_k,r_l) in cnt.keys():
        cnt[(r_k,r_l)] += 1
    else:
        cnt[(r_k,r_l)] = 1

ans = []
for i in range(N):
    r_k,r_l = uf_k.root(i), uf_l.root(i)
    ans.append(cnt[(r_k,r_l)])
print(*ans, sep=" ", end="\n")