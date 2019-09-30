import sys

def cmp(idx1, idx2):
    # print idx1, idx2, p, l
    # print p[idx1] * l[idx2], p[idx2] * l[idx1]
    if p[idx1] * l[idx2] > p[idx2] * l[idx1]:
        return -1
    if p[idx1] * l[idx2] < p[idx2] * l[idx1]:
        return 1
    return idx1 - idx2

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        n = int(f.readline())

        l = map(int, f.readline().split())
        p = map(int, f.readline().split())

        assert len(l) == n
        assert len(p) == n
        idx = range(n)
        idx.sort(cmp=cmp)
        print "Case #%d:" % (_t+1),
        for _i, ix in enumerate(idx):
            if _i != n-1:
                print ix,
            else:
                print ix
