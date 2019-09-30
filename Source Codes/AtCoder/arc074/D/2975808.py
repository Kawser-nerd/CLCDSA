import sys
sys.setrecursionlimit(10**8)
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

H,W=map(int,input().split())
C=[input() for i in range(H)]
maxflow=FK(W+H+2)
inf=10**20
for i in range(W):
    for j in range(H):
        if C[j][i]=='S':
            sx=i
            sy=j
            maxflow.add(0,i+1,inf)
            maxflow.add(0,W+1+j,inf)
            continue
        if C[j][i]=='T':
            gx=i
            gy=j
            maxflow.add(i+1,W+H+1,inf)
            maxflow.add(W+1+j,W+H+1,inf)
            continue
        if C[j][i]=='o':
            maxflow.add(i+1,W+1+j,1)
            maxflow.add(W+1+j,i+1,1)
#print(maxflow.table)
if gx==sx or gy==sy:
    print('-1')
    sys.exit()
ans=maxflow.flow(0,H+W+1)
print(ans)