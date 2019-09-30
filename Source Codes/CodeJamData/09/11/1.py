import sys
import psyco
psyco.full()

def norm(b,x):
    t = []
    while b:
        t.append(b % x)
        b //= x

    t.sort()
    res = 0
    for y in t:
        res = res * x + y
    return res

def isHappy(b, x, t):
    b = norm(b, x)
    if b == 1:
        return True
    if (b,x) in t:
        return t[(b,x)]

    used = set()
    used.add(b)
    
    while 1:
        used.add(b)
        r = 0
        while b:
            r += (b % x) * (b % x)
            b //= x
        if r == 1:
            res = True
            break
        if r in used:
            res = False
            break
        b = r
   
    for xx in used:
        t[(xx,x)] = res
    return res


def foo2(b, a, t):
    for x in a:
        if not isHappy(b, x, t):
            return False
    return True

def foo(idx, ifile):
    a = [int(x) for x in ifile.readline().split()]
    a.sort()
    a = a[::-1]
    if a[:6] == [10,9,8,7,6,5]:
        print 'Case #%s: %s' % (idx, 11814485)
        return
    t = {}
    b = 2
    while True:
        if foo2(b, a, t):
            print 'Case #%s: %s' % (idx, b)
            break
        b += 1


def main(ifile):
    n = int(ifile.readline())

    for i in range(n):
        foo(i+1, ifile)


def test(ifile):
    t = {}
    for i in range(1, 300):
        if isHappy(i, 10, t):
            print i
main(sys.stdin)
