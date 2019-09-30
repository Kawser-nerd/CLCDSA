N,M = map(int,input().split())
edges = []
for _ in range(M):
    a,b,c = map(int,input().split())
    edges.append((a,b,-c))
INF = 10**9*M*10*2
d = [INF for _ in range(N+1)]
d[1] = 0
def update():
    for edge in edges:
        a,b,c = edge
        d[b] = min(d[b],d[a]+c)
for _ in range(N-1):
    update()
ansA = d[N]
for _ in range(N):
    update()
ansB = d[N]
if ansA == ansB:
    answer = -ansA
else:
    answer = 'inf'
print(answer)