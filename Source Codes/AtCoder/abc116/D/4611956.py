from heapq import heappush, heappop
n, k = map(int, input().split())

H = []
for i in range(n):
    t, d = map(int, input().split())
    heappush(H, (- d, t))

Q = []
used = {}
dsum = 0
for i in range(k):
    d, t = heappop(H)
    if t not in used:
        used[t] = 1
    else:
        heappush(Q, (- d, t))
    dsum += - d
    
ans = len(used) ** 2 + dsum
        
#print(H)
#print(Q)
#print(used)
#print(dsum)
#print(ans)

while H and Q:
    d, t = heappop(H)
    if t not in used:
        used[t] = 1
        m, _ = heappop(Q)
        dsum = dsum - m - d
        ans = max(ans, len(used) ** 2 + dsum)
        
print(ans)