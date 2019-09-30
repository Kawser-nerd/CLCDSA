def intersect(a, b):
    def lr(p, q):
        ox, oy = p[2] - p[0], p[3] - p[1]
        ax, ay = q[0] - p[0], q[1] - p[1]
        bx, by = q[2] - p[0], q[3] - p[1]
        s = ox * ay - oy * ax
        t = ox * by - oy * bx
        assert s * t != 0
        return s * t < 0
    return lr(a, b) and lr(b, a)

v = list(map(int, input().split()))
n = int(input())
xys = [list(map(int, input().split())) for i in range(n)]
xys.append(xys[0])
c = len([1 for i in range(n) if intersect(v, xys[i] + xys[i + 1])])
print(c // 2 + 1)