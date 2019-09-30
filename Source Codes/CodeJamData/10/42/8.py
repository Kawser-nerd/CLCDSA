from sys import stdin

def main():
    p = int(stdin.readline())
    m = map(int, stdin.readline().split())
    m.reverse()
    c = []
    for i in xrange(p):
        c += map(int, stdin.readline().split())
    c.reverse()

    n = 2**p
    v = [None]*(2*n-1)
    for i in xrange(n-1, 2*n-1):
        v[i] = ([0]*(m[i-n+1]+1))
    for i in xrange(n-2, -1, -1):
        vl = v[2*i+1]
        vr = v[2*i+2]
        vv = [0]*min(len(vl), len(vr))
        for j in range(len(vv)):
            vv[j] = vl[j] + vr[j] + c[i]
        for j in range(len(vv)-1):
            vv[j] = min(vl[j+1] + vr[j+1], vv[j])
        v[i] = vv

    return str(v[0][0])

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())
