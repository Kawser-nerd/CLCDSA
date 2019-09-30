def gcd(a,b):
    if a<b:
        return gcd(b,a)
    if b==0:
        return a
    return gcd(b, a - b * (a//b))




t = int(raw_input())
for case in xrange(t):
    data = [int(s) for s in raw_input().split()]
    n=data[0]
    events=data[1:]
    gaps=[abs(events[i+1]-events[i]) for i in xrange(len(events)-1)]
    big_t=reduce(gcd, gaps)
    y=(-events[0])%big_t
    print "Case #%s: %s" % (case+1,y)

