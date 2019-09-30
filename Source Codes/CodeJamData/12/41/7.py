import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        n = int(f.readline())

        dists = []
        lengths = []
        for i in xrange(n):
            d, l = map(int, f.readline().split())
            dists.append(d)
            lengths.append(l)

        D = int(f.readline())
        dists.append(D)
        lengths.append(0)
        n += 1

        max_swing = [-1] * n

        assert lengths[0] >= dists[0]

        max_swing[0] = dists[0]
        for i in xrange(n):
            for j in xrange(i+1, n):
                if dists[j] - dists[i] > max_swing[i]:
                    break

                swing = min(lengths[j], dists[j] - dists[i])
                max_swing[j] = max(max_swing[j], swing)

        # print max_swing

        print "Case #%d: %s" % (_t+1, "NO" if max_swing[-1] == -1 else "YES")
