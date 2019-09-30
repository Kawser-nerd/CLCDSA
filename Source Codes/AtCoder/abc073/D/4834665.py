def getN():
    return int(input())

def getlist():
    return list(map(int, input().split()))

import heapq
inf = 1000000000
ans = inf

def dijkstra(n, graph, start):
    # call n times
    h = []
    routes = [[inf, i] for i in range(n)]
    routes[start][0] = 0
    heapq.heappush(h, routes[start][1])
    while(h):
        cur = heapq.heappop(h)
        for edge in graph[cur]:
            target, cost = edge
            if routes[target][0] > routes[cur][0] + cost:
                routes[target][0] = routes[cur][0] + cost
                heapq.heappush(h, routes[target][1])

    return [route[0] for route in routes]


def dfs(depth, rlist, tmpcost, tmppos, dist):
    if depth == r-1:
        #print("return: cost = {}, terminal = {}".format(tmpcost, tmppos))
        return tmpcost
    else:
        ans = 100000000
        for rnum in rlist:
            if flag[rnum] == 0:
                flag[rnum] = 1
                #print("depth {} pos {} tmpcost {} ".format(depth, tmppos, tmpcost))
                returncost = dfs(depth+1, rlist, tmpcost+dist[rnum-1][tmppos-1], rnum, dist)
                flag[rnum] = 0
                if ans > returncost:
                    ans = returncost
        return ans

def floyd_nanotka(n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if(dist[i][k] + dist[k][j] <  dist[i][j]):
                    dist[i][j] = dist[i][k] + dist[k][j]


n, m, r = getlist()
graph = [[] for i in range(n)]
rlist = getlist()
dist = [[inf for i in range(n)] for j in range(n)]
for i in range(n):
    dist[i][i] = 0

for i in range(m):
    v1, v2, cost = getlist()
    dist[v1-1][v2-1] = cost
    dist[v2-1][v1-1] = cost

#for i in range(n):
#    dist.append(dijkstra(n, graph, i))
floyd_nanotka(n)
#print(dist)
flag = [0 for i in range(n+1)]
ans_candidate = []
for i in rlist:
    flag[i] = 1
    ans_candidate.append(dfs(0, rlist, 0, i, dist))
    flag[i] = 0

print(min(ans_candidate))