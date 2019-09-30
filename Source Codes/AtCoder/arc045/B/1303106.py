import heapq
N, M = map(int, input().split())
a = [0] * (N+2)
q = []
for i in range(1, M+1):
    s, t = map(int, input().split())
    a[s] += 1
    a[t+1] -= 1
    q.append((s, t, i))
q.sort()

t = 0
result = []
j = []
for i in range(N+1):
    while q and q[0][0] == i:
        _q = heapq.heappop(q)
        heapq.heappush(j, (_q[1], _q[2]))

    t += a[i]
    if t >= 2:
        while j and j[0][0] == i:
            result.append(heapq.heappop(j)[1])
    else:
        j = []
result.sort()
print(len(result))
if result:
    print("\n".join([str(n) for n in result]))