class Unionfindtree:
    def __init__(self,number):
        self.par = [i for i in range(number)]
        self.rank = [0]*(number)

    def find(self,x):#???? x?????
        if self.par[x] ==x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def union(self,x,y):#x,y????
        px = self.find(x)
        py = self.find(y)
        if px == py:
            return 
        if self.rank[px]<self.rank[py]:
            self.par[px]=py
        else:
            self.par[py]=px
        if self.rank[px]==self.rank[py]:
            self.rank[px] +=1
    
    def connect(self,x,y):#???????
        return self.find(x)==self.find(y)

#?????????2N-2 2N-1
N,Q = map(int,input().split())
tree = Unionfindtree(2*N)
A = []
for i in range(Q):
    w,x,y,z = map(int,input().split())
    if w == 1:
        if z %2==0:
            tree.union(2*(x-1),2*(y-1))
            tree.union(2*x-1,2*y-1)
        else:
            tree.union(2*(x-1),2*y-1)
            tree.union(2*x-1,2*(y-1))
    else:
        if tree.connect(2*(x-1),2*(y-1)):
            A.append('YES')
        else:
            A.append('NO')
print('\n'.join(A))