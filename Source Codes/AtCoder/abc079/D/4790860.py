from scipy.sparse.csgraph import floyd_warshall
h,w = map(int,input().split())
cost = []
for i in range(10):
  sub = list(map(int,input().split()))
  cost.append(sub)
d = [[float("inf")]*10 for i in range(10)]
L = []
for i in range(10):
    d[i][i] = 0
for i in range(10):
    for j in range(10):
        d[i][j] = cost[i][j]
        d[j][i] = cost[j][i]
d = floyd_warshall(d)
wall = []
for i in range(h):
    cur = list(map(int,input().split()))
    wall.append(cur)
ans = 0
for i in range(h):
    for j in range(w):
        if wall[i][j] != -1:
            ans += d[wall[i][j],1]
print(int(ans))