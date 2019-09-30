import sys
sys.setrecursionlimit(int(1e9))

class LCA:
    LOG_V = 17
    root = 0
    def __init__(self, number_of_node):
        self.V = number_of_node
        self.G = [[] for i in range(number_of_node)]
        self.parent = [[-1]*number_of_node for i in range(self.LOG_V)]
        self.depth = [0] * number_of_node
        self.D = [0] * number_of_node
        
        
    def add_edge(self,a, b, c):
        self.G[a].append((b, c))
        self.G[b].append((a, c))
        
    def invoke_dfs(self):
        parent = self.parent
        depth = self.depth
        D = self.D
        G = self.G
        def dfs(v, p, d, c):
            parent[0][v] = p
            depth[v] = d
            D[v] = c
            for to, cost in G[v]:
                if to != p:
                    dfs(to, v, d+1, c + cost)
        dfs(self.root, -1, 0, 0)
        
    def getAnc(self, v, n):
        parent = self.parent
        for k in range(self.LOG_V):
            if v != -1 and ((n>>k) & 1):
                v = parent[k][v];
        return v

    def build(self):
        self.invoke_dfs()
        parent = self.parent
        for k in range(self.LOG_V-1):
            for v in range(self.V):
                if parent[k][v] < 0:
                    parent[k+1][v] = -1
                else:
                    parent[k+1][v] = parent[k][parent[k][v]]
                
            
    def lca(self, u, v):
        depth = self.depth
        if depth[u] > depth[v]:
            u, v = v, u
        v = self.getAnc(v, depth[v] - depth[u])
        if u == v:
            return u;

        parent = self.parent
        for k in range(self.LOG_V-1, -1, -1):
            if parent[k][u] != parent[k][v]:
                u = parent[k][u]
                v = parent[k][v]
        return parent[0][u];

    def getDis (self, u, v):
        return self.D[u] + self.D[v] - 2 * self.D[self.lca(u, v)];
    


N = int(input())
lca = LCA(N)
add_edge = lca.add_edge
for i in range(N-1):
    x, y = (int(i) for i in sys.stdin.readline().split())
    #x, y = (int(i) for i in input().split())
    add_edge(x - 1, y - 1, 1)
    
lca.build()

Q = int(input())
getDis = lca.getDis
depth = lca.depth
lca = lca.lca
for i in range(Q):
    a, b = (int(i) for i in sys.stdin.readline().split())
    a = a - 1
    b = b - 1
    #a, b = (int(i) for i in input().split())
    ans = depth[a] + depth[b] - 2 * depth[lca(a, b)] + 1;
    print (ans)