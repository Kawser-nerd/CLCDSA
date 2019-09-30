from sys import stdin
from math import sqrt
c = int(stdin.readline().strip())
for _ in xrange(c):
    fc = int(stdin.readline().strip())
    flies = [ map(int, stdin.readline().split()) for __ in xrange(fc) ]

    #f(t) = a tt + b t + c
    a,b,c=0,0,0
    for off in xrange(3):
        for x in flies:
            for y in flies:
                c += x[off] * y[off]
                b += x[off] * y[off+3]
                b += x[off+3] * y[off]
                a += x[off+3] * y[off+3]
    if a == 0: t = 0.0
    else: t = float(-b) / float(2*a)
    if t < 0.0: t = 0.0
    f = a * t * t + b * t + c
    if f < 0: f = 0.0
    print "Case #%d: %.8f %.8f"%(_+1,sqrt(float(f)/float(len(flies))/float(len(flies))), t)
