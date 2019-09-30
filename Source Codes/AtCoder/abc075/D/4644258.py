n, k = map(int, input().split())
p = [tuple(map(int, input().split())) for _ in range(n)]
xlist = []
ylist = []
for x, y in p:
    xlist.append(x)
    ylist.append(y)
xlist.sort()
ylist.sort()
cum = [[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(n):
    for j in range(n):
        cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + ((xlist[i], ylist[j]) in p)
minarea = 10 ** 20
for l in range(n-1):
    for r in range(l+2, n+1):
        for u in range(n-1):
            for d in range(u+2, n+1):
                point = cum[r][d] - cum[l][d] - cum[r][u] + cum[l][u]
                if point == k:
                    minarea = min(minarea, (xlist[r-1] - xlist[l]) * (ylist[d-1] - ylist[u]))
print(minarea)