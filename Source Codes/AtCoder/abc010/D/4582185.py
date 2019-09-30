import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
from collections import deque

class Dinic:
    def __init__(self,n,edges):
        self.n=n
        self.edges=[[] for _ in range(n)]
        self.iter=[0]*n
        self.level=None
        self.create_graph(edges)
    def create_graph(self,E):
        edges=self.edges
        for origin,dest,cap in E:
            edges[origin].append([dest,cap,len(edges[dest])])
            edges[dest].append([origin,0,len(edges[origin])-1])
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

n,g,e=map(int,input().split())
P=list(map(int,input().split()))
edges=[]
for p in P:
    edges.append([p,n,1])
for _ in range(e):
    a,b=map(int,input().split())
    edges.append([a,b,1])
    edges.append([b,a,1])
dinic=Dinic(n+1,edges)
print(dinic.maxflow(0,n))