N, M = map(int, input().split())
E = [list(map(int, input().split())) for i in range(M)]

def solve(k):
    *p, = range(N)
    def root(x):
        if x == p[x]:
            return x
        p[x] = y = root(p[x])
        return y
    def unite(x, y):
        px = root(x); py = root(y)
        if px == py:
            return 0
        if px < py:
            p[py] = px
        else:
            p[px] = py
        return 1
    E.sort(key=lambda x: x[2] - x[3]*k)

    res = 0
    for a, b, c, t in E:
        v = c - t*k
        if v <= 0:
            unite(a, b)
            res += v
        else:
            if unite(a, b):
                res += v
    return res <= 0

EPS = 1e-4
left = 0; right = 10**7
while right - left > EPS:
    mid = (left + right) / 2
    if solve(mid):
        right = mid
    else:
        left = mid
print(right)