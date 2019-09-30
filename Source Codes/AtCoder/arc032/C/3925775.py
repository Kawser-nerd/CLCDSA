from heapq import heappush, heappop
N = int(input())
P = []
for i in range(N):
    a, b = map(int, input().split())
    P.append((a, b, i))

T = [0]*N

P.sort(key=lambda x: x[1])
que = []
cur = 0; l = None
for i in range(N-1, -1, -1):
    a, b, j = P[i]
    while que and b <= -que[0][0]:
        x, k, v = heappop(que)
        if cur < v or (cur == v and k < l):
            cur = v
            l = k
    T[j] = l
    heappush(que, (-a, j, cur+1))
while que:
    x, k, v = heappop(que)
    if cur < v or (cur == v and k < l):
        cur = v
        l = k
print(cur)
ans = []
v = l
while v is not None:
    ans.append(v+1)
    v = T[v]
print(*ans)