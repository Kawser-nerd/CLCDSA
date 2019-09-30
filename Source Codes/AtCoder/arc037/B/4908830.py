N,M = (int(x) for x in input().split())
graph = [[] for i in range(N)]

def search(p,a,A,B):
    A += [a]
    c = True
    for i in graph[a]:
        if i in B and i != p:
            return A,False
        if i not in A:
            A,c = search(a,i,A,B+[a])
            if not c:
                break
    return A,c

for i in range(M):
    u,v = (int(x)-1 for x in input().split())
    graph[u].append(v)
    graph[v].append(u)

ans,A,B = 0,[],[]
for i in range(N):
    if i not in A:
        G,c = search(-1,i,[],[])
        if c:
            ans += 1
            A += G
        else:
            A += G
            B += G
print(ans)