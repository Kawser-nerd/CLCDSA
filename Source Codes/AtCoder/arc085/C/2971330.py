from collections import deque
class Dinic:
    def __init__(self,number):
        self.table = [[0]*(number) for i in range(number)]
        self.n=number
    
    def add(self,x,y,f):
        self.table[x][y]=f
    
    def bfs(self,x):
        self.visit[x]=0
        h=deque()
        h.append(x)
        while h:
            y=h.popleft()
            for i in range(self.n):
                if self.visit[i]==-1 and self.table[y][i]>0:
                    self.visit[i]=self.visit[y]+1
                    h.append(i)
        return 0
    
    def dinic(self,s,t,f):
        if s==t:
            return f
        for i in range(self.n):
            if self.visit[i]>self.visit[s] and self.table[s][i]>0:
                df = self.dinic(i,t,min(f,self.table[s][i]))
                if df>0:
                    self.table[s][i]-=df
                    self.table[i][s]+=df
                    return df
        return 0
    
    def flow(self,s,t):
        ans=0
        inf=10**20
        while True:
            self.visit=[-1]*(self.n)
            self.bfs(s)
            if self.visit[t]==-1:
                break
            while True:
                df=self.dinic(s,t,inf)
                if df==0:
                    break
                ans+=df
        return ans
N=int(input())
P=[int(i) for i in input().split()]
inf=10**20
maxflow=Dinic(N+2)
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