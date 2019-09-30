import math
phi = (1+math.sqrt(5))/2


for t in xrange(int(raw_input())):
    A1, A2, B1, B2 = map(int, raw_input().split(" "))
    c = 0
    for a in xrange(A1, A2 + 1):
        #A = min(a,b)
        #B = max(a,b)
        #if B >= A*phi: c += 1
        start = int(math.ceil(a/phi))
        end = int(math.floor(a*phi)) + 1
        istart = max(B1, start)
        iend = min(B2 + 1, end)
        dist = iend - istart
        c += dist if dist >0 else 0
    c = (A2 - A1 + 1)*(B2 - B1 + 1) - c
    print "Case #%i: %i" % (t+1, c)
