import numpy as np

def solve(n, m, a, b):
    p = [-1] * (n+1)
    u = [1] * (n+1)
    def find(x):
        if p[x] == -1:
            return x
        else:
            return find(p[x])
    total = n * (n-1) // 2
    res = [total]
    for i in range(m-1, 0, -1):
        x, y = a[i], b[i]
        px = find(x)
        py = find(y)
        if px > py:
            px, py = py, px
        if px != py:
            n1 = u[px]
            n2 = u[py]
            p[py] = px
            u[px] = n1 + n2
            total -= n1 * n2
        res.append(total)
    return res[::-1]

n, m = map(int, input().split())
a = np.zeros(m, dtype=int)
b = np.zeros(m, dtype=int)
for i in range(m):
    a[i], b[i] = map(int, input().split())
print("\n".join(map(str, solve(n, m, a, b))))