def solve1(a):
    return sum([max(0, x-y) for x, y in zip(a, a[1:])])

def solve2(a):
    rate_per_10 = max([max(0, x-y) for x, y in zip(a, a[1:])])
    if rate_per_10 == 0: return 0
    eaten = 0
    for x in a[:-1]:
        eaten += min(x, rate_per_10)
    return eaten

rl = raw_input
t = int(rl())
for c in xrange(t):
    n = int(rl())
    m = map(int, rl().strip().split())

    print 'Case #%d: %d %d' % (c+1, solve1(m), solve2(m))
