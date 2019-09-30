
from collections import defaultdict

code = "A-large"

infile = code + ".in"
outfile = code + ".out"

MOD = 1000002013

def price(n, o, e):
    d = e - o
    return n * d - d * (d - 1) // 2

def solve(n, oe):
    expected = sum(p * price(n, o, e) for o, e, p in oe)
    enter = defaultdict(int)
    leave = defaultdict(int)
    for o, e, p in oe:
        enter[o] += p
        leave[e] += p
    stations = list(sorted(set(enter.keys() + leave.keys())))
    cards = []
    got = 0
    for s in stations:
        cards.append((s, enter[s]))
        p = leave[s]
        while p > 0:
            cs, cp = cards[-1]
            pp = min(p, cp)
            got += pp * price(n, cs, s)
            if p >= cp:
                cards.pop()
            else:
                cards[-1] = (cs, cp - pp)
            p -= pp
    return (expected - got) % MOD

lines = [s.strip() for s in open(infile)]
c = int(lines[0])
f = open(outfile, "w")
lineno = 1
for i in range(1, c+1):
    n, m = map(int, lines[lineno].split())
    oe = [map(int, lines[lineno+j].split()) for j in xrange(1, m+1)]
    r = solve(n, oe)
    lineno += 1 + m
    msg = "Case #{}: {}".format(i, r)
    print msg
    print >> f, msg
f.close()
