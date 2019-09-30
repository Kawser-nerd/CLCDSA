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
        nums = map(int, f.readline().split())
        bad = 0
        for i in xrange(n):
            if nums[i] != i+1:
                bad += 1

        print "Case #%d: %.6f" % (_t+1, bad)



