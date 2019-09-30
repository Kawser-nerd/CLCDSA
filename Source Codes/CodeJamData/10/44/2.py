import math
def dist(a, b):
    return math.sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)
if __name__ == '__main__':
    for case in xrange(input()):
        N, M = [int(s) for s in raw_input().split()]
        P = []
        A = []
        for _ in xrange(N):
            P += [[int(s) for s in raw_input().split()]]
        for _ in xrange(M):
            A += [[int(s) for s in raw_input().split()]]

        resl = []
        for a in A:
            d = dist(P[0], P[1]);
            r0 = dist(a, P[0])
            r1 = dist(a, P[1])
            a0 = 2.0 * math.acos( (r0 * r0 + d * d - r1 * r1) / (2.0 * r0 * d) )
            a1 = 2.0 * math.acos( (r1 * r1 + d * d - r0 * r0) / (2.0 * r1 * d) )
            res = (0.5 * a1 * r1 * r1 - 0.5 * r1 * r1 * math.sin(a1) +
                  0.5 * a0 * r0 * r0 - 0.5 * r0 * r0 * math.sin(a0))

            resl += [res]

        print 'Case #%d: %s' % (case+1, (' '.join('%.7lf' % r for r in resl)))
