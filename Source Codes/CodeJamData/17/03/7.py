for cas in xrange(1,1+input()):
    n, k = map(int, raw_input().strip().split())

    pieces = [n]
    from collections import defaultdict
    from itertools import count
    ct = defaultdict(int)
    ct[n] += 1
    for i in count():
        n = pieces[i]
        c = ct[n]
        mx, mn = n>>1, n-1>>1
        if k <= c:
            break
        k -= c
        if mx not in ct: pieces.append(mx)
        ct[mx] += c
        if mn not in ct: pieces.append(mn)
        ct[mn] += c

    print "Case #%s: %s %s" % (cas, mx, mn)
