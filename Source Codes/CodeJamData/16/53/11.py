T = input()
from collections import defaultdict

def do_k(graph):
    parent = dict()
    rank = dict()

    def make_set(vertice):
        parent[vertice] = vertice
        rank[vertice] = 0

    def find(vertice):
        if parent[vertice] != vertice:
            parent[vertice] = find(parent[vertice])
        return parent[vertice]

    def union(vertice1, vertice2):
        root1 = find(vertice1)
        root2 = find(vertice2)
        if root1 != root2:
            if rank[root1] > rank[root2]:
                parent[root2] = root1
            else:
                parent[root1] = root2
                if rank[root1] == rank[root2]: rank[root2] += 1

    for vertice in graph['vertices']:
        make_set(vertice)

    minimum_spanning_tree = set()
    edges = list(graph['edges'])
    edges.sort()
    for edge in edges:
        weight, vertice1, vertice2 = edge
        if find(vertice1) != find(vertice2):
            union(vertice1, vertice2)
            minimum_spanning_tree.add(edge)
    return minimum_spanning_tree


def do_dfs(adj_l):
    adj = defaultdict(dict)
    for w, a, b in adj_l:
        adj[a][b] = w
        adj[b][a] = w

    seen = {0}
    q = [(0, 0)]
    qpos = 0
    while qpos < len(q):
        x, v = q[qpos]
        if x == 1: return v
        seen.add(x)
        for n, w in adj[x].iteritems():
            if n not in seen:
                q.append((n, max(v, w)))
        qpos += 1



def d((a, b, c), (x, y, z)):
    return ((a - x) ** 2 + (b - y) ** 2 + (c - z) ** 2) ** 0.5

def solve(N, P):
    graph = {
        'vertices': range(N),
        'edges': set([
            (d(P[x], P[y]), x, y) for x in range(N) for y in range(N) if y != x
        ])
    }
    adj_l = do_k(graph)
    # print len(adj_l)
    return do_dfs(adj_l)

for i in range(1, T + 1):
    N, S = map(int, raw_input().strip().split())
    P = []
    for q in range(N):
        a, b, c, x, y, z = map(float, raw_input().strip().split())
        P.append((a, b, c))
    print 'Case #{}: {}'.format(i, solve(N, P))
