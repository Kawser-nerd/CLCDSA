rl = lambda: map(int, raw_input().split())

def solve():
    n = input()
    l = rl()
    p = rl()
    ps = [100-x for x in p]
    a = zip(ps, range(n))
    a.sort()
    return " ".join(map(str, [i for _, i in a]))

t = input()
for i in xrange(t):
    print "Case #%d: %s" % (i + 1, solve())
