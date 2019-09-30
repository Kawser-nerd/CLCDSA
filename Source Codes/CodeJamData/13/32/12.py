T = int(raw_input())
for t in xrange(T):
    tx, ty = [int(x) for x in raw_input().split()]
    res = ''
    d = 1
    if tx < 0:
        x = 0
        while x != tx:
            x += d
            res += 'E'
            d += 1
            x -= d
            res += 'W'
            d += 1
    elif tx > 0:
        x = 0
        while x != tx:
            x -= d
            res += 'W'
            d += 1
            x += d
            res += 'E'
            d += 1

    if ty < 0:
        y = 0
        while y != ty:
            y += d
            res += 'N'
            d += 1
            y -= d
            res += 'S'
            d += 1
    elif ty > 0:
        y = 0
        while y != ty:
            y -= d
            res += 'S'
            d += 1
            y += d
            res += 'N'
            d += 1
    assert len(res) <= 500
    print 'Case #%d: %s' % (t + 1, res)
