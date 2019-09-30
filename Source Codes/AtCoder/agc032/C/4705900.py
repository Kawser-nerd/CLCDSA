N,M = map(int,input().split())
es = [tuple(map(lambda x:int(x)-1,input().split())) for i in range(M)]

degs = [0] * N
for a,b in es:
    degs[a] += 1
    degs[b] += 1

if any(d%2 for d in degs):
    print('No')
    exit()
if any(d>=6 for d in degs):
    print('Yes')
    exit()

fours = degs.count(4)
if fours <= 1:
    print('No')
    exit()
elif fours >= 3:
    print('Yes')
    exit()

assert fours == 2
u = degs.index(4)
v = degs[u+1:].index(4) +u+1

g = [[] for i in range(N)]
for a,b in es:
    g[a].append(b)
    g[b].append(a)

for s in g[u]:
    visited = [0] * N
    stack = [s]
    first = True
    while stack:
        p = stack.pop()
        if p==u:
            print('Yes')
            exit()
        elif p==v:
            break
        visited[p] = 1
        for q in g[p]:
            if visited[q]: continue
            if first and q==u:
                first = False
                continue
            stack.append(q)
print('No')