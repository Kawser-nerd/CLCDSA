import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

class FordFulkerson:
    def __init__(self,n):
        self.visited=[False]*n
        self.G=[[0]*n for _ in range(n)]
        self.n=n
    def add_edge(self,fr,to,cap):
        self.G[fr][to]=cap
        self.G[to][fr]=cap
    def dfs(self,start,goal,f):
        if start==goal:
            return f
        self.visited[start]=True
        for i in range(self.n):
            if i==start:
                continue
            if (not self.visited[i]) and self.G[start][i]>0:
                d=self.dfs(i,goal,min(f,self.G[start][i]))
                if d>0:
                    self.G[start][i]-=d
                    self.G[i][start]+=d
                    return d
        return 0
    def maxflow(self):
        flow=0
        while True:
            self.visited=[False]*self.n
            f=self.dfs(0,self.n-1,float('inf'))
            if f==0:
                break
            flow+=f
        return flow

n,g,e=map(int,input().split())
P=list(map(int,input().split()))
AB=[list(map(int,input().split())) for _ in range(e)]
FF=FordFulkerson(n+1)
for a,b in AB:
    FF.add_edge(a,b,1)
for p in P:
    FF.add_edge(p,n,1)
print(FF.maxflow())