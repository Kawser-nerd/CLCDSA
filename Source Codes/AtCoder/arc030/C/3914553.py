def scc(N, G, RG):
    order = []
    used = [0]*N
    group = [None]*N
    def dfs(s):
        used[s] = 1
        for t in G[s]:
            if not used[t]:
                dfs(t)
        order.append(s)
    def rdfs(s, col):
        group[s] = col
        used[s] = 1
        for t in RG[s]:
            if not used[t]:
                rdfs(t, col)
    for i in range(N):
        if not used[i]:
            dfs(i)
    used = [0]*N
    label = 0
    for s in reversed(order):
        if not used[s]:
            rdfs(s, label)
            label += 1
    return label, group

# ??????????
def construct(N, G, label, group):
    G0 = [set() for i in range(label)]
    GP = [[] for i in range(label)]
    for v in range(N):
        lbs = group[v]
        for w in G[v]:
            lbt = group[w]
            if lbs == lbt:
                continue
            G0[lbs].add(lbt)
        GP[lbs].append(v)
    return G0, GP


N, M, K = map(int, input().split())
*C, = input().split()

G = [[] for i in range(N)]
GR = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    GR[b-1].append(a-1)

label, group = scc(N, G, GR)
G0, GP = construct(N, G, label, group)
SS = [[] for i in range(label)]
L = [0]*label
for i in range(label):
    for v in GP[i]:
        SS[i].append(C[v])
    SS[i].sort()
    SS[i] = "".join(SS[i])
    L[i] = len(SS[i])

dist = [-1]*label
MD = [-1]*label
def dfs0(v):
    if dist[v] != -1:
        return dist[v]
    l = len(SS[v])
    r = 0
    if G0[v]:
        r = max(map(dfs0, G0[v]))
    dist[v] = res = r + l
    MD[v] = r
    return res
for i in range(label):
    dfs0(i)

memo = [[None]*(K+1) for i in range(label)]
for i in range(label):
    memo[i][0] = ""

def dfs(v, k):
    if memo[v][k] is not None:
        return memo[v][k]
    s = SS[v]
    res = None if L[v] < k else s[:k]
    if G0[v]:
        for l in range(max(k-MD[v], 0), min(L[v], k)+1):
            r = None
            for w in G0[v]:
                if dist[w] >= k-l:
                    r0 = dfs(w, k-l)
                    if r0 is not None:
                        r = r0 if r is None else min(r, r0)
            if r is not None:
                res = s[:l] + r if res is None else min(res, s[:l] + r)
    memo[v][k] = res
    return res
ans = None
for v in range(label):
    if dist[v] >= K:
        ans = dfs(v, K) if ans is None else min(ans, dfs(v, K))
print(ans if ans is not None else "-1")