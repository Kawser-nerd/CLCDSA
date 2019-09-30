n, m = map(int, input().split())

edge = [(0, i+1, int(input())) for i in range(n)]
for _ in range(m):
    edge.append(tuple(map(int,input().split())))

edge.sort(key=lambda x:x[2])

parent = [i for i in range(n+1)]
rank = [1]*(n+1)

def getroot(x):
    global parent
    if parent[x] == x:
        return x
    else:
        root = getroot(parent[x])
        parent[x] = root
        return root

def is_group(x,y):
    return getroot(x) == getroot(y)

def union(x, y):
    global rank
    rootx = getroot(x)
    rankx = rank[rootx]
    rooty = getroot(y)
    ranky = rank[rooty]
    if rankx > ranky:
        parent[rooty] = rootx
    else:
        parent[rootx] = rooty
        rank[rooty] = max(rank[rooty], rank[rootx]+1)

ans = 0
for i in range(n+m):
    a, b, c = edge[i]
    if is_group(a,b):
        continue
    else:
        ans += c
        union(a, b)
print(ans)