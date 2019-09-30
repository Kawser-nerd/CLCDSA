import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, C, M = map(int, f.readline().split())

        by_seat = [0] * N
        people = [[] for i in xrange(C)]
        tickets = []
        for i in xrange(M):
            p, b = map(int, f.readline().split())
            p -= 1
            b -= 1
            by_seat[p] += 1
            people[b].append(p)

        def can_do(rides):
            avail = 0
            promotions = 0
            for i in xrange(N):
                needed = by_seat[i] - rides
                if needed > 0:
                    if needed > avail:
                        return -1
                    avail -= needed
                    promotions += needed
                else:
                    avail -= needed
            return promotions

        ans = 0
        for l in people:
            ans = max(ans, len(l))

        while True:
            r = can_do(ans)
            # print ans, r
            if r == -1:
                ans += 1
                continue
            break

        print "Case #%d: %d %d" % (_T + 1, ans, r)
