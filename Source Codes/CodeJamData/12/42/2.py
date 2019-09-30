import random

rl = lambda: map(int, raw_input().split())

def solve():
    n, w, l = rl()
    r = rl()
    rr = [(x, i) for i,x in enumerate(r)]
    rr.sort(reverse=True)
    x = [0] * n
    y = [0] * n
    # print r
    # print rr
    ii = -1
    for _, i in rr:
        ii += 1
        f = False
        while not f:
            xx = random.randrange(w+1)
            yy = random.randrange(l+1)
            f = True
            for jj in xrange(ii):
                j = rr[jj][1]
                if (xx - x[j]) ** 2 + (yy - y[j]) ** 2 < (r[i] + r[j]) ** 2:
                    f = False
                    break
        x[i], y[i] = xx, yy

    return " ".join("%d %d" % (xx, yy) for xx, yy in zip(x, y))

t = input()
for i in xrange(t):
    print "Case #%d: %s" % (i + 1, solve())
