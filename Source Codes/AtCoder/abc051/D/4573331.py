import heapq

n, m = map(int, input().split())
abc = [tuple(int(x) - 1 for x in input().split()) for _ in range(m)]

dist = [[9999999 for _ in range(n)] for _ in range(n)]

e = [dict() for _ in range(n)]

for i in range(m):
    a, b, c = abc[i][0], abc[i][1], abc[i][2]
    e[a][b] = c + 1
    e[b][a] = c + 1

for i in range(n):
    h = []
    heapq.heappush(h, [0, i])
    temp = set()
    #temp.add(i)
    while len(temp) < n:
        d, p = heapq.heappop(h)
        while p in temp:
            d, p = heapq.heappop(h)
        dist[i][p] = d
        temp.add(p)
        for x in e[p].keys():
            heapq.heappush(h, [d + e[p][x], x])

#for i in range(n): print(dist[i])

ans = m
for a, b, c in abc:
    for i in range(n):
        if c + 1 == dist[a][i] - dist[b][i]:
            ans -= 1
            break
print(ans)