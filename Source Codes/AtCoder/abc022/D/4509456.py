n = int(input())
ax = [0] * n
ay = [0] * n
bx = [0] * n
by = [0] * n

g = [0] * 4
for i in range(n):
    ax[i], ay[i] = map(int, input().split())
    g[0] += ax[i]
    g[1] += ay[i]
for i in range(n):
    bx[i], by[i] = map(int, input().split())
    g[2] += bx[i]
    g[3] += by[i]
g[0] /= n
g[1] /= n
g[2] /= n
g[3] /= n
d = [0] * 2
for i in range(n):
    tx = ax[i] - g[0]
    ty = ay[i] - g[1]
    t = tx * tx + ty * ty
    d[0] = max(d[0], t)
    tx = bx[i] - g[2]
    ty = by[i] - g[3]
    t = tx * tx + ty * ty
    d[1] = max(d[1], t)
ans = (d[1] / d[0]) ** 0.5
print(ans)