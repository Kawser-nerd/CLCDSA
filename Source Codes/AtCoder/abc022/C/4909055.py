import itertools
from scipy.sparse.csgraph import floyd_warshall

N, M = map(int, input().split())

city = []
for i in range(N):
    city.append([float('inf')]*N)
    city[i][i] = 0

home = []

for i in range(M):
    u, v, l = map(int, input().split())
    if u == 1:
        home.append([v-1, l])
    elif v == 1:
        home.append([u-1, l])
    else:
        city[u-1][v-1] = l
        city[v-1][u-1] = l

city_dist = floyd_warshall(city)

dist_min = float('inf')
for u, v in itertools.combinations(home, 2):
    dist = city_dist[u[0]][v[0]]
    if dist == float('inf'):
        pass
    elif  dist_min > dist + u[1] + v[1]:
        dist_min = dist + u[1] + v[1]
    else:
        pass
      
if dist_min == float('inf'):
    print(-1)
else:
    print(int(dist_min))