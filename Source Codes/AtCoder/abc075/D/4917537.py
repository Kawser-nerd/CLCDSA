from itertools import combinations
 
n, k = [int(item) for item in input().split()]
xy = [[int(item) for item in input().split()] for _ in range(n)]
 
xsort = sorted(xy, key=lambda x: x[0])
ysort = sorted(xy, key=lambda x: x[1])
l = [i for i in range(n)]
 
cum = [[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(n):
    for j in range(n):
        cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + ([xsort[i][0], ysort[j][1]] in xy)

def count_points_in_rec(x0, x1, y0, y1):
    point = cum[x1+1][y1+1] - cum[x0][y1+1] - cum[x1+1][y0] + cum[x0][y0]
    return point

ans = 5 * 10**18
comb = []
for a, b in combinations(l, 2):
    if b - a >= k-1:
        comb.append([a, b])
for a, b in comb:
    for c, d in comb:
        if count_points_in_rec(a, b, c, d) == k:
            ans = min(ans, (xsort[b][0]-xsort[a][0]) * (ysort[d][1]-ysort[c][1]))
print(ans)