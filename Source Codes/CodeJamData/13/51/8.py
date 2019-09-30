
code = "A-large"

infile = code + ".in"
outfile = code + ".out"

def profit(x, m):
    w = min(x)
    p = [mi for mi, xi in zip(m, x) if xi == w]
    return sum(p) * 36.0 / len(p) - sum(m)

def solve(b, x):
    x += [0] * (37 - len(x))
    x.sort()
    x.append(10**100)
    m = [0] * 37
    best = 0.0
    for i in xrange(37):
        if x[i] == x[i + 1]:
            continue
        while x[i] < x[i + 1] and b >= 0:
            xx = x[:]
            mm = m[:]
            for j in xrange(min(i+1, b)):
                xx[i-j] += 1
                mm[i-j] += 1
                best = max(best, profit(xx, mm))
            z = max(x[i + 1] - x[i] - 1, 1)
            for j in xrange(i+1):
                if b < j+1:
                    continue
                zz = min((b - j - 1) // (i + 1) + 1, z)
                if zz <= 1:
                    continue
                xx = x[:]
                mm = m[:]
                for k in xrange(i+1):
                    q = zz if k <= j else (zz - 1)
                    xx[i-k] += q
                    mm[i-k] += q
                best = max(best, profit(xx, mm))
            for j in xrange(i+1):
                b -= z
                x[i-j] += z
                m[i-j] += z
    return best

lines = [s.strip() for s in open(infile)]
c = int(lines[0])
f = open(outfile, "w")
lineno = 1
for i in range(1, c+1):
    b, n = map(int, lines[lineno].split())
    x = map(int, lines[lineno+1].split())
    r = solve(b, x[:n])
    lineno += 2
    msg = "Case #{}: {:.9f}".format(i, r)
    print msg
    print >> f, msg
f.close()
