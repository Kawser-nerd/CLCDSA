R, C, K = map(int, input().split())
S = [input() for i in range(R)]
si = sj = -1
ci = cj = -1
gi = gj = -1
for i in range(R):
    s = S[i]
    for j in range(C):
        if s[j] == 'S':
            si = i; sj = j
        elif s[j] == 'C':
            ci = i; cj = j
        elif s[j] == 'G':
            gi = i; gj = j

INF = 10**18
from heapq import heappush, heappop

dd = ((-1, 0), (0, -1), (1, 0), (0, 1))

def dijkstra(si, sj):
    dist = [[[INF]*(K+1) for j in range(C)] for i in range(R)]
    que = [(0, si, sj, 0)]
    dist[si][sj][0] = 0
    while que:
        cost, vi, vj, k = heappop(que)
        if dist[vi][vj][k] < cost:
            continue
        for di, dj in dd:
            ui = vi + di; uj = vj + dj
            if not 0 <= ui < R or not 0 <= uj < C or S[ui][uj] == 'T':
                continue
            if S[ui][uj] == 'E':
                if k+1 <= K and cost + 1 < dist[ui][uj][k+1]:
                    dist[ui][uj][k+1] = cost + 1
                    heappush(que, (cost + 1, ui, uj, k+1))
            else:
                if cost + 1 < dist[ui][uj][k]:
                    dist[ui][uj][k] = cost + 1
                    heappush(que, (cost + 1, ui, uj, k))
    res = [[[] for i in range(C)] for j in range(R)]
    for i in range(R):
        for j in range(C):
            tmp = INF-20
            base = 1 if S[i][j] == 'E' else 0
            for k in range(K+1):
                if dist[i][j][k] < tmp:
                    tmp = dist[i][j][k]
                    res[i][j].append((k-base, tmp))
    return res
res_s = dijkstra(si, sj)
res_c = dijkstra(ci, cj)
res_g = dijkstra(gi, gj)

ans = INF
for i in range(R):
    for j in range(C):
        base = 1 if S[i][j] == 'E' else 0
        lst = res_g[i][j]
        for k1, d1 in res_s[i][j]:
            l = len(lst)-1
            for k2, d2 in res_c[i][j]:
                while l >= 0 and k1+k2+lst[l][0]+base > K:
                    l -= 1
                if l < 0:
                    break
                ans = min(ans, d1+d2*2+lst[l][1])
print(ans if ans < INF else -1)