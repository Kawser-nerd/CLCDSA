from collections import deque
N,K = map(int,input().split())
es = [tuple(map(lambda x:int(x)-1,input().split())) for i in range(N-1)]
tr = [[] for i in range(N)]
for a,b in es:
    tr[a].append(b)
    tr[b].append(a)

def reachable_points(root_v, cant_visit_v):
    visited = [0] * N
    visited[root_v] = visited[cant_visit_v] = 1
    q = deque([(root_v,0)])
    ret = 0
    while q:
        v,dep = q.popleft()
        if dep == K//2: break
        for to in tr[v]:
            if visited[to]: continue
            ret += 1
            q.append((to,dep+1))
            visited[to] = 1
    return ret

def reachable_edges(root_e):
    a,b = es[root_e]
    return reachable_points(a,b) + reachable_points(b,a)

if K%2:
    ans = N
    for center_e in range(N-1):
        ans = min(ans, N - 2 - reachable_edges(center_e))
    print(ans)
else:
    ans = N
    for center_v in range(N):
        ans = min(ans, N - 1 - reachable_points(center_v, center_v))
    print(ans)