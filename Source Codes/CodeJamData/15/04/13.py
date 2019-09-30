def solve():
    x, r, c = map(int, raw_input().split())
    w = "GABRIEL"
    l = "RICHARD"
    if x >= 7:
        return l
    if x == 1:
        return w
    if r * c % x:
        return l
    if x == 2:
        return w
    if r > c:
        r, c = c, r
    if r == 1:
        return l
    if x == 3:
        return w
    if r == 2:
        return l
    if x == 4:
        return w
    if x == 5:
        if r == 3 and c == 5:
            return l
        return w
    if r == 3:
        return l
    return w

T = int(raw_input())
for i in xrange(T):
    print "Case #%d: %s" % (i + 1, solve())
