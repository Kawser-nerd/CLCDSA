def solve(e, r, n, v):
    before = [e] * n
    after = [0] * n
    finish = [0] * n
    gain = 0

    vv = list(enumerate(v))
    vv.sort(key=lambda v: v[1], reverse=True)

    for i, v in vv:
        finish[i] = 1
        B = before[i]
        A = after[i]
        gain += v * (B - A)

        a = B
        for ii in xrange(i-1, -1, -1):
            if finish[ii]:
                break
            a -= r
            if a < 0:
                break
            after[ii] = a

        b = A
        for ii in xrange(i+1, n):
            if finish[ii]:
                break
            b += r
            if b > e:
                break
            before[ii] = b

    return gain


import sys
T = int(sys.stdin.readline())
for i in range(1, T+1):
    e, r, n = map(int, sys.stdin.readline().split())
    vs = map(int, sys.stdin.readline().split())
    print "Case #%d: %d" % (i, solve(e, r, n, vs))
