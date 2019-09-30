import sys, math


def solve():
    N, P = map(int, sys.stdin.readline().split())
    Ingr = map(int, sys.stdin.readline().split())
    Pkg = [map(int, sys.stdin.readline().split()) for _ in xrange(N)]
    can_make = [[] for _ in xrange(N)]
    for i in xrange(N):
        m = Ingr[i]
        Pkg[i].sort()
        # low = (m * 9) / 10.
        # high = (m * 11) / 10.
        for p in Pkg[i]:
            x = (10 * p + m * 11 - 1) / (m * 11)
            y = (10 * p) / (m * 9)
            if x <= y:
                can_make[i].append((int(x), int(y)))
    # print
    # print N, P
    # print can_make
    ans = 0
    while True:
        if not all(can_make):
            break
        firsts = [x[0] for x in can_make]
        x, y = zip(*firsts)
        if max(x) <= min(y):
            ans += 1
            can_make = [c[1:] for c in can_make]
        else:
            i = firsts.index(min(firsts))
            can_make[i] = can_make[i][1:]
    return ans


T = int(sys.stdin.readline())
for i in xrange(T):
    print 'Case #%d:' % (i+1), solve()
