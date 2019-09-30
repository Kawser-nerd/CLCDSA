from collections import deque

class Dinic:
    def __init__(self,n):
        self.n=n
        self.edges=[[] for _ in range(n)]
        self.iter=[0]*n
        self.level=None
    def add_edge(self,fr,to,cap):
        self.edges[fr].append([to,cap,len(self.edges[to])])
        self.edges[to].append([fr,0,len(self.edges[fr])-1])
    def maxflow(self,source,sink):
        max_flow=0
        while True:
            self.bfs(source)
            if self.level[sink]<0:
                return max_flow
            self.iter=[0]*self.n
            flow=self.dfs(source,sink,float('inf'))
            while flow:
                max_flow+=flow
                flow=self.dfs(source,sink,float('inf'))
    def bfs(self,source):
        edges=self.edges
        level=[-1]*self.n
        level[source]=0
        q=deque([source])
        while q:
            fr=q.popleft()
            for to,cap,_ in edges[fr]:
                if cap>0>level[to]:
                    level[to]=level[fr]+1
                    q.append(to)
        self.level=level
    def dfs(self,source,sink,flow):
        if source==sink:
            return flow
        while self.iter[source]<len(self.edges[source]):
            to,cap,rev=self.edges[source][self.iter[source]]
            if cap>0 and self.level[source]<self.level[to]:
                f=self.dfs(to,sink,min(flow,cap))
                if f:
                    self.edges[source][self.iter[source]][1]-=f
                    self.edges[to][rev][1]+=f
                    return f
            self.iter[source]+=1
        return 0

n=int(input())
m=20**3
dinic=Dinic(m*2+2)
V=set()
def add_v(x,y,z):
    for i in range(1,x):
        va,vb=i*y*z,(x-i)*y*z
        dinic.add_edge(va,vb+m,1)
        V.add(va)
for _ in range(n):
    x,y,z=map(int,input().split())
    add_v(x,y,z)
    add_v(y,z,x)
    add_v(z,x,y)
for v in V:
    dinic.add_edge(0,v,1)
    dinic.add_edge(v+m,m*2+1,1)
print(len(V)*2-dinic.maxflow(0,m*2+1))