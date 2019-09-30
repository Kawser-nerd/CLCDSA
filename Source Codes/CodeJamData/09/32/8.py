import math
t = int(raw_input())

for i in range(t):
    x = 0.0
    y = 0.0
    z = 0.0
    vx = 0.0
    vy = 0.0
    vz = 0.0
    n = int(raw_input())
    for j in range(n):
        tpl = map(int, raw_input().split())
        x += tpl[0]
        y += tpl[1]
        z += tpl[2]
        vx += tpl[3]
        vy += tpl[4]
        vz += tpl[5]
    A = vx**2 + vy**2 + vz**2
    B = 2 * x * vx + 2 * y * vy + 2 * z * vz
    C = x**2 + y**2 + z**2
    if math.fabs(A) > 0.000001:
        t = (-1) * B / 2.0 / A
        if t < 0.0:
            t = 0.0
        d = A * (t**2) + B * t + C
        d = d / (n**2)
    else:
        t = 0.0
        d = C / (n**2)
#    print t, d
    print "Case #%d: %.8f %.8f"%(i+1, math.sqrt(math.fabs(d)), math.fabs(t))
