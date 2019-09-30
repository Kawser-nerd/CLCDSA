import sys

b = []

def calcb(a):
    res = []
    last = 0
    for i in range(len(a)-1):
        res.append(last + a[i] * (a[i+1]-1))
        last = res[-1]
    b[:] = res


def foo(ifile):
    L, N = [int(x) for x in ifile.readline().split()]
    a = [int(x) for x in ifile.readline().split()]
    a.sort()
    calcb(a)
    res = {}
    res[0] = (0, 0)

    n = len(a)
    

    for i in range(n-1):
        res2 = {}
        for k, v in res.iteritems():
            #print k, v
            for j in range(v[1], v[1]+a[i+1]):
                t1 = k + a[i] * j
                t2 = t1 // a[i+1] 
                t3 = t1 % a[i+1]

                t4 = v[0] + j - t2
                t5 = (t4, t2)

                if t3 not in res2:
                    res2[t3] = t5
                else:
                    res2[t3] = min(res2[t3], t5)
        res = res2
    t = L % a[-1]

    if t not in res:
        return 'IMPOSSIBLE'
    else:
        return L // a[-1] + res[t][0]
    

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))
        sys.stdout.flush()

        
    


if __name__ == '__main__':
    main(sys.stdin)
