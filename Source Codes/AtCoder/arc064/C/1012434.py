from heapq import heappush, heappop

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

q = reads()
s = q[0] + q[1] * 1j
t = q[2] + q[3] * 1j

N = read()

p = []; r = []
for i in range(N):
  q = reads()
  p.append(q[0] + q[1] * 1j)
  r.append(q[2])

# N?source, N+1?target
E = [[0]*(N+2) for _ in range(N+2)]
for i in range(N):
  for j in range(N):
    E[i][j] = max(abs(p[i] - p[j]) - r[i] - r[j], 0)

for i in range(N):
  E[N][i]   = E[i][N]   = max(abs(p[i] - s) - r[i], 0)
  E[N+1][i] = E[i][N+1] = max(abs(p[i] - t) - r[i], 0)

E[N][N+1] = E[N+1][N] = abs(t - s)

INF = 10**15 * 1.0

dist = [E[N][i] for i in range(N+2)] + [INF]
stab = [False] * (N+2)

stab[N] = True

for _ in range(N+1):
  i = N+2
  for j in range(N+2):
    if not stab[j] and dist[j] < dist[i]:
      i = j
  stab[i] = True
  for j in range(N+2):
    dist[j] = min(dist[j], dist[i] + E[i][j])

print(dist[N+1])