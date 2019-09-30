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
        tot = 0
        for x in nums:
            tot ^= x

        if tot != 0:
            ans = "NO"
        else:
            ans = sum(nums) - min(nums)
        print "Case #%d: %s" % (_t+1, ans)


