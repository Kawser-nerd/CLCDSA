rl = lambda: map(int, raw_input().split())

DX = (1, 1, 0, -1, -1, 0)
DY = (0, 1, 1, 0, -1, -1)
DD = zip(DX,DY)
D = [complex(x,y) for x,y in zip(DX,DY)]
V = set()
for i in xrange(1, 7):
    for j in xrange(1, 7):
        for k in xrange(1, 7):
            if i==j or j==k or i == k: continue
            V.add(2**j + 2**i + 2**k)

for i in xrange(1, 7):
    for j in xrange(1, 7):
        for v in V.copy():
            V.add(v | 2 ** j)


def bfs(sv, sa, srr, q, s):
    for p in q:
        for d in D:
            n = p + d
            if n in srr: continue
            if n in sv: continue
            if n not in sa: continue
            sv.add(n)
            q.append(n)
    return len(q)


def dcu_root(d, p):
    x = p
    while d[x] != x: x = d[x]
    while d[p] != x:
        t = p
        p = d[p]
        d[p] = x
    return x

def dcu_join(d, dc, p, np):
    a = dcu_root(d, p)
    b = dcu_root(d, np)
    if a == b: return dc[p]
    if (p[0] + np[0])&1: a,b = b,a
    d[b] = a
    ss, ff = dc[b]
    s, f = dc[a]
    dc[a] = (s + ss, f | ff)
    return dc[a]

def solve():
    s, m = rl()
    types = set()
    a = [tuple(rl()) for _ in xrange(m)]
    sa = set(a)
    ss = s * 2 - 1
    q = [complex(0, 0)]
    sv = set(q)
    sa = set()
    srr = set()
    for x,y in a:
        p = complex(x,y)
        srr.add(p)
        sa.add(p)
        for d in D:
            sa.add(p+d)
    corners = set(((1, 1), (s, 1), (1, s), (ss, s), (s, ss), (ss, ss)))
    sides = {}
    for i in xrange(2, s):
        x = i + s - 1
        for j, pe in enumerate(((1, i), (i, 1), (x, i), (i, x), (x, ss), (ss, x))):
            sides[pe] = 2 ** (j + 1)
    # print 'sides', sides

    for i in xrange(0, s+1):
        x = i + s
        for xx,yy in ((0, i), (i, 0), (x, i), (i, x), (x, ss + 1), (ss + 1, x)):
            sa.add(complex(xx,yy))
            # print xx, yy
    # print sa
    bfs(sv, sa, srr, q, ss)
    # print sv

    l_ring = None
    i = m + 1
    for x, y in reversed(a):
        p = complex(x, y)
        srr.remove(p)
        i -= 1
        if all(d+p not in sv for d in D):
            continue
        q = [p]
        sv.add(p)
        nfs = bfs(sv, sa, srr, q, ss)
        if nfs > 1:
            l_ring = i

    d = {}
    dc = {}
    i = 1
    for p in a:
        cf = int(p in corners)
        sf = sides.get(p, 0)
        d[p] = p
        dc[p] = (cf, sf)
        x, y = p
        for dx, dy in DD:
            np = x + dx, y + dy
            if np not in d: continue
            cf, sf = dcu_join(d, dc, p, np)
            if cf >= 2: types.add("bridge")
            if sf in V: types.add("fork")

        if l_ring == i: types.add("ring")
        if types:
            return "-".join(sorted(types)) + " in move %d" % i
        i += 1
    return "none"

t = input()
for i in xrange(t):
    print "Case #%d: %s" % (i + 1, solve())
