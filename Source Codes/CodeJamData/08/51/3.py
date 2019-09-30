import sys
import math
import psyco
psyco.full()

def getints(ifile):
    return tuple([int(x) for x in ifile.readline().split()])

def add(a, b):
    return (a[0]+b[0], a[1]+b[1])

def calcarea(a):
    res = 0
    for i in range(-1, len(a)-1):
        res += (a[i][0] + a[i+1][0]) * (a[i][1] - a[i+1][1])
    return abs(res)/2

def calc(x, y, ys):
    ok = [0] * 4
    for yy in ys:
        if yy[0] > y:
            break
        if yy[1] <= x and yy[2] >= x+1:
            ok[0] = 1
            break

    if ok[0]:
        for i in range(len(ys)-1, -1, -1):
            yy = ys[i]
            if yy[0] <= y:
                break
            if yy[1] <= x and yy[2] >= x+1:
                return True

def calc2(x, y, xs, ys):
    if calc(x, y, ys) or calc(y, x, xs):
        return True
    return False


def calc3(a):
    b = min(a)
    c = []
    for x in a:
        if x == b:
            continue
        dy = x[1] - b[1]
        dx = x[0] - b[0]
        angle = math.atan2(dy, dx)
        c.append((angle, x))
    c.sort()
    c = [b] + [x[1] for x in c]
    d = c[:2]

    cidx = 2
    while 1:
        if len(d) < 2:
            d.append(c[cidx])
            cidx += 1
            continue
        for x in c[2:]:
            if calcangle(d[-2], d[-1], x) >= math.pi:
                del d[-1]
                continue

            else:
                d.append(c)

    

    

def foo(idx2, ifile):
    res = None

    T = getints(ifile)[0]

    a = []
    while len(a) < 2*T:
        a.extend(ifile.readline().split())

    assert len(a) == 2*T

    a = ''.join([a[i]*int(a[i+1]) for i in range(0, len(a), 2)])

    dirs = [(0, 1),
            (1, 0),
            (0, -1),
            (-1, 0)]

    diridx = 0
    res = [(0, 0)]

    idx = 0
    last = None

    for x in a:
        if x == 'F':
            if last == 'F':
                res[-1] = add(res[-1], dirs[diridx])
            else:
                res.append(add(res[-1], dirs[diridx]))

        elif x == 'L':
            diridx += 1
            diridx %= 4
        elif x == 'R':
            diridx += 3
            diridx %= 4
        last = x

    

    assert res[-1] == res[0]
    del res[-1]

    xs = []
    ys = []
    for i in range(-1, len(res)-1):
        x0 = res[i][0]
        y0 = res[i][1]
        x1 = res[i+1][0]
        y1 = res[i+1][1]
        if(x0 == x1):
            xs.append((x0, min(y0, y1), max(y0, y1)))
        else:
            ys.append((y0, min(x0, x1), max(x0, x1)))
    xs.sort()
    ys.sort()
        

    area1 = calcarea(res)


    res2 = 0
    for x in range(-100, 100):
        for y in range(-100, 100):
            if calc2(x, y, xs, ys):
                res2 += 1

    res = res2 - area1
        

    print 'Case #%s: %s' % (idx2, res)

def main():
    ifile = file(sys.argv[1])
    n = int(ifile.readline().strip())
    for i in range(n):
        foo(i+1, ifile)

if __name__ == '__main__':
    main()
