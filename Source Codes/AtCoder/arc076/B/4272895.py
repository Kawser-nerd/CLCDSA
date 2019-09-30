import heapq
def prim_heap():
    used = [True] * n #True:???
    edgelist = []
    for e in edge[0]:
        heapq.heappush(edgelist,e)
    used[0] = False
    res = 0
    while len(edgelist) != 0:
        minedge = heapq.heappop(edgelist)
        if not used[minedge[1]]:
            continue
        v = minedge[1]
        used[v] = False
        for e in edge[v]:
            if used[e[1]]:
                heapq.heappush(edgelist,e)
        res += minedge[0]
    return res

#########################
n = int(input())

#???????? edge[i]:[???,??]
edge = [[] for i in range(n)]
p=[]
edge=[[] for i in range(n)]
for i in range(n):
    p.append(tuple(map(int,input().split()))+tuple([i]))
x_sorted=sorted(p,key=lambda x:x[0])
y_sorted=sorted(p,key=lambda x:x[1])
for i in range(n-1):
    edge[x_sorted[i][2]].append((x_sorted[i+1][0]-x_sorted[i][0],x_sorted[i+1][2]))
    edge[x_sorted[i+1][2]].append((x_sorted[i+1][0]-x_sorted[i][0],x_sorted[i][2]))
    edge[y_sorted[i][2]].append((y_sorted[i+1][1]-y_sorted[i][1],y_sorted[i+1][2]))
    edge[y_sorted[i+1][2]].append((y_sorted[i+1][1]-y_sorted[i][1],y_sorted[i][2]))

print(prim_heap())