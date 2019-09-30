T = int(raw_input())

for z in xrange(1,T+1):
    r, t = map(int,raw_input().split())

    lo = 0
    hi = 2000000000000000000
    best = 0

    while lo <= hi:
        mid = (lo+hi)/2
        if (2 * r * mid + 2 * mid * (mid-1) + mid) <= t:
            best = mid
            lo = mid + 1
        else:
            hi = mid - 1
    print "Case #%d: %d" % (z, best)
