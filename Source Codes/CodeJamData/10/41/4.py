from sys import stdin

def main():
    k = int(stdin.readline())
    a = [[] for _ in xrange(k)]
    for i in xrange(2*k-1):
        v = map(int, stdin.readline().split())
        z = 0 if i < k else i+1-k
        for j, w in enumerate(v):
            a[j+z].append(w)

    def spr_ptw(b):
        if k == 1:
            return 0
        for ll in xrange(k):
            l = k-ll
            ok = True
            for x in xrange(l):
                for y in xrange(l):
                    if b[x][y] != b[l-1-y][l-1-x]:
                        ok = False
            if ok:
                return ll
    x1 = spr_ptw(a)
    a.reverse()
    x2 = spr_ptw(a)
    for c in a:
        c.reverse()
    x3 = spr_ptw(a)
    a.reverse()
    x4 = spr_ptw(a)
    kk = k+min(x1, x3) +  min(x2, x4)
    return str(kk*kk-k*k)

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())
