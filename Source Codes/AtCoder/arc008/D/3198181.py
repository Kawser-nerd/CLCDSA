from collections import defaultdict
class Segment():
    def __init__(self,number,default):#2*number1 segtree
        self.n=number
        self.seg=[[default]*pow(2,self.n-i)for i in range(self.n+1)]
        
    def update(self,i,x):
        l=i
        for k in range(self.n+1):
            if k==0:
                self.seg[k][l]=x
                continue
            l=l//2
            self.seg[k][l]=self.merge(k,l)
    
    def merge(self,k,l):
        return (self.seg[k-1][2*l][0]*self.seg[k-1][2*l+1][0],self.seg[k-1][2*l+1][0]*self.seg[k-1][2*l][1]+self.seg[k-1][2*l+1][1])

N,M=map(int,input().split())
L=set()
table=[]
for i in range(M):
    p,a,b=map(float,input().split())
    L.add(int(p))
    table.append((int(p),a,b))
L=list(L)
L.sort()
dd=defaultdict(int)
for i in range(len(L)):
    dd[L[i]]=i
Tree=Segment(17,(1,0))
ma=1
mi=1
for p,a,b in table:
    Tree.update(dd[p],(a,b))
    x=Tree.seg[17][0][0]*1+Tree.seg[17][0][1]
    ma=max(ma,x)
    mi=min(mi,x)
print(mi)
print(ma)