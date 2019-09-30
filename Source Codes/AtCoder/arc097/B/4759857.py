n, m = map(int, input().split())
ps = list(map(int, input().split()))
xys = [tuple(map(int, input().split())) for _ in range(m)]

t = {p:p for p in ps}

def trace(x):
    route = [x]
    while t[x] != x:
        x = t[x]
        route.append(x)
    for v in route:
        t[v] = route[-1]
    return route

for x, y in xys:
    u = trace(x)[-1]
    v = trace(y)[-1]
    if u!=v:
        t[u] = v

avs = [
    p
    for i, p in enumerate(ps)
    if trace(i+1)[-1] == trace(p)[-1]
]

print(len(avs))