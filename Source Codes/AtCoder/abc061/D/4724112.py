n, m = map(int,input().split())

a = [0] * m
b = [0] * m
c = [0] * m

for i in range(0,m):
    a[i], b[i], c[i] = map(int,input().split())
    a[i] = a[i] - 1
    b[i] = b[i] - 1
    c[i] = -c[i]

INF = (n-1) * max(abs(min(c)),abs(max(c)))

dist = [INF] * n

dist[0] = 0

for j in range(0,n-1):
    for i in range(0,m):
        if dist[a[i]] == INF:
            continue
        dist[b[i]] = min(dist[b[i]], dist[a[i]] + c[i])

ans = - dist[n-1]

negative = [False] * n

for j in range(0,n):
    for i in range(0,m):
        if dist[a[i]] == INF:
            continue
        if negative[a[i]]:
            negative[b[i]] = True
        elif dist[a[i]] + c[i] < dist[b[i]]:
            dist[b[i]] = dist[a[i]] + c[i]
            negative[b[i]] = True

if negative[n-1]:
    print("inf")
else:
    print(ans)