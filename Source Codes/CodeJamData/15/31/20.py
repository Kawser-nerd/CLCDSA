for tc in range(1, int(raw_input()) + 1):
    r, c, w = tuple([int(i) for i in raw_input().split()])
    t = r * (c / w) - 1
    t += min(w + 1, (c % w) + w)
    print "Case #%d: %d" % (tc, t)
