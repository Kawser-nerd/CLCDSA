for tc in range(1, int(raw_input()) + 1):
    c, d, v = tuple([int(i) for i in raw_input().split()])
    n = sorted([int(i) for i in raw_input().split()])
    r, m = 0, 1
    while m <= v:
        if n and n[0] <= m:
            m += n[0] * c
            n = n[1:]
        else:
            r += 1
            m += m * c
    print "Case #%d: %d" % (tc, r)
