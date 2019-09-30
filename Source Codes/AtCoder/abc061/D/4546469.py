n, m = map(int, input().split())
abc = []

INF = 10 ** 20

for i in range(m):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    c *= -1
    abc.append([a, b, c])

dist = [INF for _ in range(n)]
dist[0] = 0

for i in range(n - 1):
    for a, b, c in abc:
        if dist[a] == INF:
            continue
        elif dist[b] > dist[a] + c:
            dist[b] = dist[a] + c

ans = dist[n - 1]

check = [-1 for _ in range(n)]

for i in range(n - 1):
    for a, b, c in abc:
        if dist[a] == INF:
            continue
        elif dist[b] > dist[a] + c:
            dist[b] = dist[a] + c
            check[b] = 0

if check[n-1] == 0:
    print('inf')
else:
    print(-ans)