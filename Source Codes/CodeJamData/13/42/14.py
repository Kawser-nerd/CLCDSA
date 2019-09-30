
code = "B-large"

infile = code + ".in"
outfile = code + ".out"

def willwin(n, s):
    pos = 0
    for i in xrange(n):
        if s > 0:
            pos += 2 ** (n - i - 1)
            s = (s - 1) // 2
    return pos

def maywin(n, w):
    pos = 0
    for i in xrange(n):
        if w > 0:
            w = (w - 1) // 2
        else:
            pos += 2 ** (n - i - 1)
    return pos

def solve(n, p):
    if p == 2 ** n:
        return p - 1, p - 1
    low, high = 0, 2 ** n - 1
    while high - low > 1:
        mid = (low + high) // 2
        if willwin(n, mid) < p:
            low = mid
        else:
            high = mid
    will = low
    low, high = 0, 2 ** n - 1
    while high - low > 1:
        mid = (low + high) // 2
        if maywin(n, 2 ** n - mid - 1) < p:
            low = mid
        else:
            high = mid
    may = low
    return will, may

lines = [s.strip() for s in open(infile)]
c = int(lines[0])
f = open(outfile, "w")
lineno = 1
for i in range(1, c+1):
    n, p = map(int, lines[lineno].split())
    r = solve(n, p)
    lineno += 1
    msg = "Case #{0}: {1[0]} {1[1]}".format(i, r)
    print msg
    print >> f, msg
f.close()
