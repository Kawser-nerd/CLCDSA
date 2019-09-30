import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        Hd, Ad, Hk, Ak, B, D = map(int, f.readline().split())

        # if Ad >= Hk:
            # ans = 1
        # elif Ak - D >= Hd:
            # ans = "IMPOSSIBLE"
        # elif max(Ad * 2, Ad + B) >= Hk:
            # ans = 2
        # elif (Ak - D) * 2 >= Hd:
            # ans = "IMPOSSIBLE"
        # else:
        if 1:
            def turns(nd, nb):
                hd = Hd
                ad = Ad
                ak = Ak
                hk = Hk
                n = 0

                for i in xrange(nd):
                    if hd <= ak - D:
                        hd = Hd - ak
                        n += 1
                        # print 'C',
                    ak = max(0, ak - D)
                    hd -= ak
                    if hd <= 0:
                        return float('inf')
                    n += 1
                    # print 'D',

                for i in xrange(nb):
                    if hd <= ak:
                        hd = Hd - ak
                        n += 1
                        # print 'C',

                    ad += B
                    hd -= ak
                    if hd <= 0:
                        return float('inf')
                    n += 1
                    # print 'B',

                while hk > 0:
                    if hd <= ak and hk > ad:
                        hd = Hd - ak
                        n += 1
                        # print 'C',

                    hk -= ad
                    if hk > 0:
                        hd -= ak
                        if hd <= 0:
                            return float('inf')
                    n += 1
                    # print 'A',
                # print

                return n

            best = float('inf')
            for i in xrange(101):
                for j in xrange(101):
                    r = turns(i, j)
                    best = min(r, best)
                    # print "d=%d, b=%d: %s" % (i, j, r)
            import math
            if math.isinf(best):
                ans = "IMPOSSIBLE"
            else:
                ans = best

        print "Case #%d: %s" % (_T + 1, ans)
