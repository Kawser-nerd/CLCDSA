from heapq import heappush,heappop
class Dijk:
    def __init__(self,n):
        self.table=[[] for i in range(n)]
        self.n=n
    
    def add(self,x,y,f):
        self.table[x].append((y,f))
        
    def di(self,s):
        inf=10**20
        self.val=[inf]*self.n
        self.val[s]=0
        h=[]
        heappush(h,(0,s))
        while h:
            q,i=heappop(h)
            if self.val[i]<q:
                continue
            for x,c in self.table[i]:
                if self.val[x]>self.val[i]+c:
                    self.val[x]=self.val[i]+c
                    heappush(h,(self.val[x],x))
                    
    def dist(self,s,t):
        return self.val[t]

K=int(input())
d=Dijk(K)
for i in range(1,K):
    d.add(i,(i+1)%K,1)
    d.add(i,(10*i)%K,0)
d.di(1)
print(d.dist(1,0)+1)