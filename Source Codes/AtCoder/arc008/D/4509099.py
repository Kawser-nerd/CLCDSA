class SegmentTree():
    def __init__(self,m,init):
        self.n=1
        while (self.n<m):
            self.n*=2
        self.data=[init]*(2*self.n-1)    
    def update(self,k,a):
        k+=self.n-1
        self.data[k]=a
        while k:
            k=(k-1)//2
            self.data[k]=self.merge(k)
    def merge(self,k):
        l,r=self.data[2*k+1],self.data[2*k+2]
        return (l[0]*r[0],r[0]*l[1]+r[1])   
    def get_top(self):
        return self.data[0]
n,m=map(int,input().split())
P,A,B=[],[],[]
for i in range(m):
    p,a,b=input().split()
    P.append(int(p))
    A.append(float(a))
    B.append(float(b))
D={}
q=sorted(list(set(P)))
D.update(zip(q,list(range(len(q)))))
seg=SegmentTree(m,(1,0))
min_t=1
max_t=1
for i in range(m):
    seg.update(D[P[i]],(A[i],B[i]))
    top=seg.get_top()
    t=top[0]+top[1]
    min_t=min(min_t,t)
    max_t=max(max_t,t)
print(min_t,max_t,sep='\n')