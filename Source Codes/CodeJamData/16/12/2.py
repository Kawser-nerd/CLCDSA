from collections import defaultdict


def sol(n, l):
    c = defaultdict(int)
    for ll in l:
        for a in ll:
            c[a] += 1
    res = []
    for k, v in c.iteritems():
        if v % 2 == 1:
            res.append(k)
    return ' '.join(map(str, sorted(res)))


rl = lambda: map(int, raw_input().split())

t = input()
for i in xrange(t):
    n = input()
    l = [rl() for _ in xrange(2*n -1)]
    print "Case #%d:" % (i + 1), sol(n, l)
