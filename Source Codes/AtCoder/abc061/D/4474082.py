n, m = map(int, input().split())
INF = pow(10, 15)

alist, blist, clist = [], [], []
for _ in range(m):
  a, b, c = map(int, input().split())
  alist.append(a-1)
  blist.append(b-1)
  clist.append(-c)
dist = [INF for _ in range(n)]
dist[0] = 0
for _ in range(n-1):
  for a, b, c in zip(alist, blist, clist):
    if dist[a] == INF:  # ?????????????
      continue
    if dist[b] > dist[a] + c:  # ?????????????????????
      dist[b] = dist[a] + c

ans = dist[n-1]

negative = [False for _ in range(n)]

for _ in range(n):
  for a, b, c in zip(alist, blist, clist):
    if dist[a] == INF:
      continue
    if dist[b] > dist[a] + c:
      dist[b] = dist[a] + c
      negative[b] = True
    if negative[a]:
      negative[b] = True

if negative[n-1]:
  print("inf")
else:
  print(-ans)