def solve():
    a = map(int,raw_input().split())
    n = a[0]
    a = a[1:]
    s = sum(a)
    res = []
    b = sorted(a)
    for x in a:
        l, r = 0., 1.
        while r-l > 1e-10:
            c = (l + r) * .5
            z = 0.
            t = x + c * s
            for y in b:
                if y >= t: break
                z += t - y
            #print c,x,t,z,s
            if z < s: l = c
            else: r = c
        res.append(l * 100)
    return " ".join("%.8f"%x for x in res)

t = input()
for i in xrange(t):
    print "Case #%d: %s"%(i+1,solve())
