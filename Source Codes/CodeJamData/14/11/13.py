import sys

fin = iter(sys.stdin)
T = int(next(fin))
for t in xrange(T):
    N, L = map(int, next(fin).split())
    flows = next(fin).split()
    devs = next(fin).split()

    res = set()
    q = [([(flows, devs)], 0, 0)]
    while q:
        parts, index, flips = q.pop(0)

        failed = False
        new_parts = []
        for flows, devs in parts:
            f0 = [f for f in flows if f[index] == '0']
            f1 = [f for f in flows if f[index] == '1']
            d0 = [f for f in devs if f[index] == '0']
            d1 = [f for f in devs if f[index] == '1']

            if len(f0) != len(d0) or len(f1) != len(d1):
                failed = True
                break

            if f0:
                new_parts.append((f0, d0))
            if f1:
                new_parts.append((f1, d1))

        if not failed:
            if index + 1 != L:
                q.append((new_parts, index + 1, flips))
            else:
                res.add(flips)

        failed = False
        new_parts = []
        for flows, devs in parts:
            f0 = [f for f in flows if f[index] == '1']
            f1 = [f for f in flows if f[index] == '0']
            d0 = [f for f in devs if f[index] == '0']
            d1 = [f for f in devs if f[index] == '1']

            if len(f0) != len(d0) or len(f1) != len(d1):
                failed = True
                break

            if f0:
                new_parts.append((f0, d0))
            if f1:
                new_parts.append((f1, d1))

        if not failed:
            if index + 1 != L:
                q.append((new_parts, index + 1, flips + 1))
            else:
                res.add(flips + 1)

    if res:
        print 'Case #%d: %d' % (t+1, min(res))
    else:
        print 'Case #%d: NOT POSSIBLE' % (t+1)
