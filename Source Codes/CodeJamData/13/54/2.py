import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        _o = f.readline().strip()
        N = len(_o)
        occupied = 0
        for i in xrange(N):
            if _o[i] == 'X':
                occupied += (1<<i)

        mem = {}
        def ex(o):
            if o in mem:
                return mem[o]
            if o == (1<<N) - 1:
                return 0.0

            total = 0.0
            for i in xrange(N):
                for wait in xrange(N):
                    bm = (1<<((i+wait)%N))
                    if o & bm == 0:
                        break
                else:
                    raise Exception()
                total += N - wait + ex(o | bm)
            mem[o] = total / N
            return total / N
        print "Case #%d: %.12f" % (_T+1, ex(occupied))
