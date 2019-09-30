N, M = [int(_) for _ in input().split()]
LRD = [[int(_) for _ in input().split()] for _ in range(M)]
G = {}
for l, r, d in LRD:
    l -= 1
    r -= 1
    #0-indexed
    G[l] = G.get(l, {})
    G[r] = G.get(r, {})
    G[l][r] = d
    G[r][l] = -d
INF = float('inf')
D = [INF] * N
for i in range(N):
    if i in G and D[i] == INF:
        D[i] = 0
        table = []
        while True:
            for k, v in G[i].items():
                if D[k] == INF:
                    table += [k]
                    D[k] = D[i] + v
                elif D[k] != D[i] + v:
                    print('No')
                    exit()
            if table:
                i = table.pop()
            else:
                break
print('Yes')