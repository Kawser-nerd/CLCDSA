class UnionFind:
    def __init__(self, length):
        self.par = [-1 for _ in range(length)]
        self.rank = [0 for _ in range(length)]
 
    def root(self,x):
        if (self.par[x] < 0 ):
             return x
        else:
            #change connection
            root = self.root(self.par[x])
            self.par[x] = root
            return root
    
    def unite(self,x,y):
        root_x = self.root(x)
        root_y = self.root(y)
        if (root_x==root_y):
            return 
        else:
            if self.rank[root_x] < self.rank[root_y]:
                self.par[root_y] += self.par[root_x]
                self.par[root_x] = root_y

            else:
                self.par[root_x] += self.par[root_y]
                self.par[root_y] = root_x
                if self.rank[root_x] == self.rank[root_y]:
                    self.rank[root_x]+=1
        
    def same(self,x,y):
        root_x = self.root(x)
        root_y = self.root(y)
        return root_x == root_y 
    
    def size(self,x):
        return -self.par[self.root(x)]

"""
uf = UnionFind(5)
uf.unite(3,4)
uf.unite(1,2)

uf.unite(1,4)
print(uf.size_dict)
"""
def solve(edges,N,M):
 
    score= N*(N-1)//2
    outputs = [score]
    uf = UnionFind(N)
    for edge in edges[::-1]:
        if not uf.same(*edge):
            score -= uf.size(edge[0]) * uf.size(edge[1])
            uf.unite(*edge)
        outputs.append(score)
    for i in range(M):
        print(int(outputs[M-i-1]))

def get_input():
    N,M = map(int, input().split())
    edges = [tuple(map(lambda x:  int(x)-1, input().split())) for _ in range(M)]
    return N,M,edges

N,M,edges = get_input()
# = 10**6
#M=10**5
#import numpy as np
#edges = [(np.random.randint(N),np.random.randint(N)) for i in range(M)]
solve(edges,N,M)