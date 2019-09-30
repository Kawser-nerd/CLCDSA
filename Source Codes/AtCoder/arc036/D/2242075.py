N, Q = map(int, input().split())
*p, = range(N+N)
def root(x):
    if x == p[x]:
        return x
    y = p[x] = root(p[x])
    return y
def unite(x, y):
    px = root(x); py = root(y)
    if px < py:
        p[py] = px
    else:
        p[px] = py

ans = []
for i in range(Q):
    w, x, y, z = map(int, input().split())
    x -= 1; y -= 1
    if w == 1:
        if z % 2:
            unite(x, y+N)
            unite(x+N, y)
        else:
            unite(x, y)
            unite(x+N, y+N)
    else:
        if root(x) == root(y) or root(x + N) == root(y + N):
            ans.append('YES')
        else:
            ans.append('NO')
print(*ans, sep='\n')