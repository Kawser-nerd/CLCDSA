import heapq
X,Y,Z = map(int,input().split())
N = X+Y+Z
src = [tuple(map(int,input().split())) for i in range(N)]
src.sort(key=lambda x:x[0]-x[1])

l_opt = [0]*(N+1)
r_opt = [0]*(N+1)

silver = bronze = 0
q_sb = []
heapq.heapify(q_sb)
for i,(g,s,b) in enumerate(src):
    heapq.heappush(q_sb, (s-b, s, b))
    silver += s
    if i >= Y:
        _, s2, b2 = heapq.heappop(q_sb)
        silver -= s2
        bronze += b2
    l_opt[i+1] = silver + bronze

gold = bronze = 0
q_gb = []
heapq.heapify(q_gb)
for i,(g,s,b) in enumerate(reversed(src)):
    heapq.heappush(q_gb, (g-b, g, b))
    gold += g
    if i >= X:
        _, g2, b2 = heapq.heappop(q_gb)
        gold -= g2
        bronze += b2
    r_opt[N-1-i] = gold + bronze

ans = 0
for l,r in list(zip(l_opt, r_opt))[Y:Y+Z+1]:
    ans = max(ans, l+r)
print(ans)