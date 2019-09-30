from heapq import heappush, heappop

# ??
N, C = map(int, input().split())
s, t, c = zip(*(map(int, input().split()) for _ in range(N)))

# ????????????????????
Q = []
p = [0 for _ in range(C + 1)]
ans = 0
for x, y, z in sorted(zip(s, t, c)):
    while Q and (Q[0] < x or Q[0] == x == p[z]):
        p[z] = 0
        heappop(Q)
    p[z] = y
    heappush(Q, y)
    ans = max(ans, len(Q))

# ??
print(ans)