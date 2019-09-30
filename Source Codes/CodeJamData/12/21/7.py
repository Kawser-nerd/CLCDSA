def safe(i, xs, d):
    spare = 1-d
    X = xs[i] + d
    for j, x in enumerate(xs):
        if j != i:
            if x < X:
                spare -= X-x
        if spare < 0:
            return True
    return False

def solve(xs):
    n = float(len(xs))
    total = sum(xs)
    xs = [x/total for x in xs]

    results = []
    for i, x in enumerate(xs):
        lo, hi = 0, 1
        while hi - lo > 1.e-8:
            mid = .5 * (lo+hi)
            if safe(i, xs, mid):
                hi = mid
            else:
                lo = mid
        results.append(lo)
    return ' '.join(str(100.*r) for r in results)

rd = raw_input
for t in range(1, 1+int(rd())):
    print 'Case #%d: %s' % (t, solve(map(float, rd().split()[1:])))
