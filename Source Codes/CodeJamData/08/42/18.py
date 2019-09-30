def solve(n, m, a):
    for x2 in xrange(0, n + 1):
        for y1 in xrange(0, m + 1):
            b = a + x2 * y1
            for x1 in xrange(1, n + 1):
                if b % x1 == 0 and b // x1 <= m:
                    return "%d %d %d %d %d %d" % (0, 0, x1, y1, x2, b // x1)
    return "IMPOSSIBLE"

for c in range(input()):
    n, m, a = map(int, raw_input().split())
    print("Case #%d: %s" %(c + 1, solve(n, m, a)))