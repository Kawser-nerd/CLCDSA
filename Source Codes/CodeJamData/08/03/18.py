import sys
import math

def calcpoly(ps):
    res = 0.0
    for i in range(len(ps)):
        p0 = ps[i-1]
        p1 = ps[i]
        res += (p0[1]+p1[1]) * (p0[0]-p1[0])
    return abs(res)/2.0

def calcd(p1, p2):
    return ((p2[0]-p1[0])**2 + (p2[1]-p1[1])**2) **0.5

def calcarc(p1, p2, rt):
    d = calcd(p1, p2)
  
    area = rt * rt * math.asin(d/2.0/rt)
    h = (rt*rt - d*d/4.0)**0.5

    return area - 0.5*d*h

def calc1(x, y, d, rt):
    p0 = (x, y)
    p1 = (x, (rt*rt-x*x)**0.5)
    p2 = ((rt*rt-y*y)**0.5, y)
    return calcpoly([p0, p1, p2]) + calcarc(p1, p2, rt)

def hh(rt, x):
    return (rt*rt-x*x)**0.5

def calc2(x, y, d, rt):
    p0 = (x, y)
    p1 = (x, y+d)
    p2 = (hh(rt, y+d), y+d)
    p3 = (hh(rt,y), y)
    res1 = calcpoly([p0, p1, p2, p3]) 
    res2 = calcarc(p2, p3, rt)
    #print p0, p1, p2, p3
    #print res1, res2
    return res1 + res2

def calc3(x, y, d, rt):
    return calc2(y, x, d, rt)

def calc4(x, y, d, rt):
    p0 = (x, y)
    p1 = (x, y+d)
    p2 = (hh(rt, y+d), y+d)
    p3 = (x+d, hh(rt,x+d))
    p4 = (x+d, y)
    return calcpoly([p0, p1, p2, p3, p4]) + calcarc(p2, p3, rt)


def calc(x, y, d, rt):
    res = _calc(x, y, d, rt)
    #print res
    return res
def _calc(x, y, d, rt):
    x2 = x + d
    y2 = y + d
    
    a0 = 1 if x*x + y*y < rt*rt else 0
    a1 = 1 if x*x + y2*y2 < rt*rt else 0
    a2 = 1 if x2*x2 + y*y < rt*rt else 0
    a3 = 1 if x2*x2 + y2*y2 < rt*rt else 0

    if not a0:
        return 0.0

    if not a1 and not a2:
        return calc1(x, y, d, rt)

    if a1 and not a2:
        return calc2(x, y, d, rt)

    if not a1 and a2:
        return calc3(x, y, d, rt)

    if a3:
        return d * d

    return calc4(x, y, d, rt)


def foo(idx, ifile, ofile):
    line = ifile.readline()
    words = [float(x) for x in line.split()]
    f, R, t, r, g = tuple(words)
    r += f
    t += f
    g -= f + f
    f = 0

    if g <= 0.0:
        return 1.0

    res = 0.0
    y = r
    x = r
    rt = R - t
    g2r = g + 2 * r
    _i = 0
    while y < rt:
        y2 = y + g
        x22 = rt*rt - y2*y2
        if x22 > 0:
            x2 = x22 ** 0.5
            x2r = x2 + r
            n = int(math.floor(x2r/g2r))
        else:
            n = 0
        #n = 0
        #print _i, n
        res += n * g*g
        x += n * g2r

        _i2 = n
        
        while x*x+y*y < rt*rt:
            delta = calc(x, y, g, rt)
            #print _i, _i2, delta
            res += delta
            _i2 += 1
            x += g2r
        _i += 1
        y += g2r
        x = r

   
    total = math.pi * R * R
    #print total, res
    res = total - res * 4

    return res / total


def foo2(idx, ifile, ofile):
    res = foo(idx, ifile, ofile)
    ofile.write('Case #%i: %.6f\n' % (idx, res))

    

def main(ifile, ofile):
    n = int(ifile.readline().strip())
    for i in range(n):
        foo2(i+1, ifile, ofile)

if __name__ == '__main__':
    assert calcd((1.0, 1.0), (4.0, 5.0)) == 5.0
    assert calcpoly([(1.0, 1.0), (1.0, 2.0), (2.0, 1.0)]) == 0.5
    assert 0.09 < calcarc((0.0, 0.0), (0.0, 1.0), 1) < 0.091
    main(file(sys.argv[1]), sys.stdout)
