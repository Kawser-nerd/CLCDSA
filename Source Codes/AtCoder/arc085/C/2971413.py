class FK:
    def __init__(self,n):
        self.table=[[0]*n for i in range(n)]
        self.n=n
    
    def add(self,x,y,f):
        self.table[x][y]=f
        
    def ford(self,s,t,f):
        self.visit[s]=True
        if s==t:
            return f
        for i in range(self.n):
            if (not self.visit[i]) and self.table[s][i]>0:
                df=self.ford(i,t,min(f,self.table[s][i]))
                if df>0:
                    self.table[s][i]-=df
                    self.table[i][s]+=df
                    return df
        return 0
    
    def flow(self,s,t):
        ans=0
        inf=10**20
        while True:
            self.visit=[False]*(self.n)
            df=self.ford(s,t,inf)
            if df==0:
                break
            ans+=df
        return ans

N=int(input())
P=[int(i) for i in input().split()]
inf=10**20
maxflow=FK(N+2)
for i in range(1,N+1):
    if P[i-1]>0:
        maxflow.add(i,N+1,P[i-1])
    else:
        maxflow.add(0,i,-P[i-1])
    for j in range(2*i,N+1,i):
        maxflow.add(i,j,inf)
ans=maxflow.flow(0,N+1)
num=sum([p for p in P if p>0])
print(num-ans)