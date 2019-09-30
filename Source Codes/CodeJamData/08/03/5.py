
import sys
import math
def sqr(x): return x*x
def sqrt(x):
    assert x > -0.001
    return 0 if x<0 else math.sqrt(x)
acos = math.acos
asin = math.asin
def a0(d, *args):
    return d*d
def a1(d, R, x, y):
    x0 = x + d
    y1 = y + d
    y0 = sqrt(R*R-x0*x0)
    x1 = sqrt(R*R-y1*y1)
    a = asin(y1/R) - asin(y0/R)
    A = (R*R*a - (x0-x1)*y0 - (y1-y0)*x1)/2
    Ao = (x0-x1)*(y1-y0) - A
    #print x0, y0, x1, y1, a, A, Ao, d*d
    return d*d - Ao
def a2(d, R, x, y):
    x1 = x
    y0 = y
    y1 = sqrt(R*R-x1*x1)
    x0 = sqrt(R*R-y0*y0)
    a = asin(y1/R) - acos(x0/R)
    return (R*R*a - (x0-x1)*y0 - (y1-y0)*x1)/2
def a3(d, R, x, y):
    y0 = y
    x0 = sqrt(R*R-y0*y0)
    y1 = y+d
    x1 = sqrt(R*R-y1*y1)
    #print asin(y1/R), acos(x0/R)
    a = asin(y1/R) - acos(x0/R)
    A = (R*R*a - (x0-x1)*y0 - (y1-y0)*x1)/2
    #print x0, y0, x1, y1, a, A, d*(x1-x)
    return d*(x1-x) + A
def main(input):
    N = int(input.readline())
    for i in range(N):
        f,R,t,r,g = (float(x) for x in input.readline().split())
        RR = R*R
        A = A0 = math.pi*RR
        total = 0
        #print 'A', A
        if f*2 < g:
            l = R-t-f
            ll = l*l
            d = g + r + r
            g -= f*2
            r += f
            j = 0
            while True:
                x = r + d * j
                if x >= l:
                    break
                if x*x*2 < ll:
                    if sqr(x+g)*2 < ll:
                        s = a0(g, l, x, x)*4
                        #print 'a0', g, l, x, x, s
                    elif x*x+sqr(x+g) < ll:
                        s = a1(g, l, x, x)*4
                        #print 'a1', g, l, x, x, s
                    else:
                        s = a2(g, l, x, x)*4
                        #print 'a2', g, l, x, x, s
                    A -= s
                    total += s
                for k in range(j):
                    y = r + d * k
                    if x*x + y*y > ll:
                        break
                    if sqr(x+g) + sqr(y+g) < ll:
                        s = a0(g, l, x, y)*8
                        #print 'a0', g, l, x, y, s
                    elif sqr(x+g) + y*y < ll:
                        s = a1(g, l, x, y)*8
                        #print 'a1', g, l, x, y, s
                    elif x*x + sqr(y+g) < ll:
                        s = a3(g, l, x, y)*8
                        #print 'a3', g, l, x, y, s
                    else:
                        s = a2(g, l, x, y)*8
                        #print 'a2', g, l, x, y, s
                    A -= s
                    total += s
                j += 1
        #print A, total
        print 'Case #%d: %.6f'% (i+1, A/A0)

if __name__=='__main__':
    f = sys.stdin
    #f = open('C.txt')
    main(f)
    #print a1(1, 1, 0, 0)
    #print a1(1, 1.2, 0, 0)
    #print a2(1, 1, 0, 0)
    #print a2(1, 0.5, 0, 0)
    #print a3(1.0, 2.0, 1.0, 0)
