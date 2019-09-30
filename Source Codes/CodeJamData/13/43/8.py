import sys

def proc(a, b):
    pairs = zip(a, b)
    sums = [q[0]+q[1] for q in pairs]
    N = len(a)

    valid = [None]
    for i in range(1, N+1):
        valid.append([s <= i+1 for s in sums])

    def go(l, n):
        #p = '  '*n
        #print p, l, n
        if n == N+1: return True

        v = valid[n][:]

        #print p, 'valid:', v

        last = 0
        for i in range(N):
            if l[i]:
                v[i] = False
                last = max(last, a[i])
            elif v[i]:
                v[i] &= a[i] == last+1

        #print p, 'valid:', v

        last = 0
        for i in range(N-1, -1, -1):
            if l[i]:
                v[i] = False
                last = max(last, b[i])
            elif v[i]:
                #print last, b[i], b[i]==last+1
                v[i] &= b[i] == last+1

        #print p, 'valid:', v

        for i in range(N):
            if v[i]:
                l[i] = n
                if go(l, n+1):
                    return True
                l[i] = None
    res = [None] * N
    res[pairs.index((1, 1))] = 1
    go(res, 2)
    return ' '.join(map(str, res))

with open(sys.argv[1]) as f:
    T = int(f.readline())
    for i in range(T):
        N = int(f.readline())
        a = map(int, f.readline().split())
        b = map(int, f.readline().split())

        print 'Case #%d: %s' % (i+1, proc(a, b))
