def bfs(graph,start,n,check):
    if check == False:
        arrival = [0 for i in range(n+1)]
    else:
        arrival = [0 for i in range(n+1)]
        arrival[check] = -1
    q = [start]
    arrival[start] = 1
    while len(q) != 0:
        for i in range(len(graph[q[0]])):
            if arrival[graph[q[0]][i]] == 0:
                q.append(graph[q[0]][i])
                arrival[graph[q[0]][i]] = arrival[q[0]]+1
        q.pop(0)
    return arrival

n = int(input())
graph = dict()
for i in range(1,n+1):
    graph[i] = []

for i in range(n-1):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)


fstart = bfs(graph,1,n,False)
sstart = bfs(graph,n,n,False)
fennec = 0
snuke = 0
for i in range(1,n+1):
    if abs(fstart[i]-fstart[1]) <= abs(sstart[i]-sstart[n]):
        fennec += 1
    else:
        snuke += 1


if fennec > snuke:
    print("Fennec")
else:
    print("Snuke")