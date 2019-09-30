import sys

t = int(sys.stdin.readline())

def ncr(n, r):
    if r < 0 or r > n:
        return 0
    t = 1
    for i in xrange(n-r+1, n+1):
        t *= i
    for i in xrange(1, r+1):
        t /= i
    return t

for _t in xrange(t):
    n, c = [int(s) for s in sys.stdin.readline().split()]

    e = []
    e.append(0.0)
    poss = ncr(n, c) * 1.0
    for left in xrange(1, n+1):
        have = n - left
        exp = 0.0
        # print left, "left"
        for new in xrange(1, c+1):
            if new > left:
                break
            prob = ncr(left, new) * ncr(have, c - new) / poss
            # print "prob of getting %d new when have %d left: %f" % (new, left, prob)
            exp += prob * e[left-new]

        prob0 = ncr(left, 0) * ncr(have, c) / poss
        exp = (1 + exp) / (1 - prob0)
        e.append(exp)

    print "Case #%d: %f" % (_t+1, e[-1])
