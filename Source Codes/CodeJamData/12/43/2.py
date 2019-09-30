rl = lambda: map(int, raw_input().split())

def solve():
    n = input()
    x = rl()
    h = [0] * n
    a = [0] * n
    st = []
    h [n-1] = -1
    a [n-1] = -1
    #print x
    for i in xrange(n-1):
        if h[i]: continue
        q = []
        j = i
        while not h[j]:
            q.append(j)
            nj = x[j] -1
            if any(h[j + 1: nj]): return "Impossible"
            j = nj
        #print q, j
        jj = j
        hh = h[j]
        aa = a[j] + 1
        a[j] += 1
        for j in q:
            a[j] = aa
            h[j] = hh - aa * (jj - j)

    mh = -min(h)
    return " ".join(map(str,[mh + x for x in h]))

t = input()
for i in xrange(t):
    print "Case #%d: %s" % (i + 1, solve())
