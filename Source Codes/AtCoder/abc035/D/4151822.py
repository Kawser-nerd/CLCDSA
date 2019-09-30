from scipy.sparse.csgraph import dijkstra
from scipy.sparse import csr_matrix

n, m, t = map(int, input().split())
x = list(map(int, input().split()))
start = []
goal = []
time = []
for i in range(m):
    a, b, c = map(int, input().split())
    start.append(a-1)
    goal.append(b-1)
    time.append(c)

path1 = csr_matrix((time, (start, goal)), shape=(n, n))
path2 = csr_matrix((time, (goal, start)), shape=(n, n))


time1 = dijkstra(path1, indices=0)
time2 = dijkstra(path2, indices=0)

ans = 0
for i in range(n):
    ans = max(x[i]*(t-time1[i]-time2[i]), ans)

print(int(ans))