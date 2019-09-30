import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        ns = map(int, f.readline().split())
        n = ns[0]
        s = ns[1]
        p = ns[2]
        assert len(ns) == n + 3
        scores = ns[3:3+n]

        sure = 0
        if_surprising = 0
        for x in scores:
            not_surprising = (x + 2) / 3
            is_surprising = (x + 4) / 3
            if not_surprising >= p:
                sure += 1
            elif (2 <= x <= 28) and is_surprising >= p:
                if_surprising += 1
        print "Case #%d: %d" % (_t+1, sure + min(if_surprising, s))
