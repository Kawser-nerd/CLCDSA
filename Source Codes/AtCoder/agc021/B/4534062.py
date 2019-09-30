import math

n = int(input())
c = [[0]*2 for i in range(n) ]
a = [0] * n
p = math.pi
for i in range(n):
    c[i][0], c[i][1] = map(float, input().split())

def f(ax, ay, bx, by, cx, cy):
    vx = ax - cx
    vy = ay - cy
    wx = bx - cx
    wy = by - cy
    s = 1
    if vx * wy - vy * wx < 0: s = -1
    p = vx * wx + vy * wy
    q = ( vx * vx + vy * vy ) ** 0.5
    r = ( wx * wx + wy * wy ) ** 0.5
    t = p / (q * r)
    t = max(-1, min(1, t))
    t = (math.acos( t )) * s
    return t

for i in range(n):
    k = (i+1)%n
    tax = 0
    tin = 0
    for j in range(n):
        if j != i and j != k:
            t = f(c[k][0], c[k][1], c[j][0], c[j][1], c[i][0], c[i][1])
            tax = max(tax, t)
            tin = min(tin, t)
    if tax - tin < p:
        a[i] = (p - tax + tin) / (p * 2)

for i in range(n):
    print(round(a[i], 6))