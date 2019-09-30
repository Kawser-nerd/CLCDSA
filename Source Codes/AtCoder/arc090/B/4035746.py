from collections import deque
n,m = map(int,input().split())
inf = 10**10

edge = [[] for i in range(n)]
x = [inf]*n
for i in range(m):
    l,r,d = map(int,input().split())
    edge[l-1].append((r-1,d))
    edge[r-1].append((l-1,-d))


for i in range(n):
    if x[i] == inf:
        x[i]=0
        q = deque([i])
        while len(q)!=0:
            now = q.popleft()
            for e in edge[now]:
                if x[e[0]] == inf:
                    x[e[0]] = x[now]+e[1]
                    q.append(e[0])
                elif x[e[0]]-x[now]!=e[1]:
                    print("No")
                    exit()

print("Yes")