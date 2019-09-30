import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

for no_t in xrange(1, read_int() + 1):
    b, n = read_ints()
    n -= 1

    a = read_ints()

    lo, hi = 0, 2**100
    while lo + 1 < hi:
        md = (lo + hi) / 2
        s = sum((md + x - 1) / x for x in a)
        if s <= n:
            lo = md
        else:
            hi = md

    already = sum((lo + x - 1) / x for x in a)
    just = [i for i, x in enumerate(a) if lo % x == 0]

    ans = just[n - already] + 1


    print 'Case #%d: %s' % (no_t, ans)
