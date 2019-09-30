import sys
import math

def asin(a):
    if a >= 1.0:
        return math.pi / 2.0
    if a <= -1.0:
        return -math.pi/ 2.0
    return math.asin(a)

def dis(x, y):
    dx = x[0] - y[0]
    dy = x[1] - y[1]
    return math.sqrt(dx*dx+dy*dy)

def run(p, q):
    ab = dis(p[0], p[1])
    ax = dis(p[0], q)
    bx = dis(p[1], q)

    dunjiao = 0
    if(ab*ab+ax*ax < bx*bx):
        return run(p[::-1], q)
    if(bx*bx+ab*ab < ax*ax):
        dunjiao = 1
    
    #print ab, ax, bx
    p = (ab+ax+bx)/2.0

    area = math.sqrt(p*(p-ab)*(p-ax)*(p-bx))
    #print area

    height = area / ab * 2.0
    #print height
    #print height/ax

    angle1 = asin(height/ax)
    #print height/bx
    angle2 = asin(height/bx)
    res = 0.0

    if not dunjiao:
        d1 =  ax * ax * angle1
        d2 = bx * bx * angle2
        #print d1, d2

        res += (d1 + d2)/2.0
        res -= area
        res *= 2
        return res
    else:
        d1 =  ax * ax * angle1 / 2.0
        d2 = bx * bx * angle2 / 2.0
        res = d2 + area - d1

        return bx * bx * math.pi - res * 2

        
        
    

def foo(ifile):
    n, m = [int(x) for x in ifile.readline().split()]
    p = [None] * n
    q = [None] * m
    for i in range(n):
        p[i] = [float(x) for x in ifile.readline().split()]
    for j in range(m):
        q[j] = [float(x) for x in ifile.readline().split()]

    res = []
    for x in q:
        res.append(run(p, x))
    return ' '.join(['%.7f' % x for x in res])

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))
    


if __name__ == '__main__':
    main(sys.stdin)
