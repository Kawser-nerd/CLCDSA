from math import sqrt
T = input()
for i in xrange(T):
    N = input()
    x, y, z, vx, vy, vz = 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    for j in xrange(N):
        v = [float(s) for s in raw_input().split()]
        x += v[0]
        y += v[1]
        z += v[2]
        vx += v[3]
        vy += v[4]
        vz += v[5]
    V = vx*vx + vy*vy + vz*vz
    t = 0 if V == 0.0 else -(x*vx + y*vy + z*vz)/V
    if t < 0.0: t = 0.0
    d = sqrt((x + t*vx)**2 + (y + t*vy)**2 + (z + t*vz)**2)/N
    print "Case #%i: %.8f %.8f" % (i+1, d, t)
