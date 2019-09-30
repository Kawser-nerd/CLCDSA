from math import sqrt
from scipy.sparse.csgraph import dijkstra, csgraph_from_dense
# https://atcoder.jp/users/nadare881

def calc_dist(p1,p2):
    return max(0, sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2) - (p1[2]+p2[2]))

xs, ys, xg, yg = map(int, input().split())
n = int(input())
p = [list(map(int, input().split())) for i in range(n)]
p = [[xs,ys,0], [xg,yg,0]] + p
n += 2
edges = [[float("inf")]*n for i in range(n)]
for i in range(n):
    for j in range(i,n):
        if i == j :continue
        edges[i][j] = edges[j][i] = calc_dist(p[i], p[j])
edges = csgraph_from_dense(edges, null_value=float("inf"))
dist = dijkstra(edges, directed=False, indices=0)
print(dist[1])