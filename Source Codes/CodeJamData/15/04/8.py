bawal = set([(3,1),(4,1),(4,2),(5,1),(5,2),(6,1),(6,2),(6,3)])
for cas in xrange(1,1+input()):
    x, r, c = map(int, raw_input().strip().split())
    print "Case #%s: %s" % (cas, "GABRIEL" if (r*c)%x == 0 and x <= 6 and (x,r*c) != (5,15) and (x,min(r,c)) not in bawal else "RICHARD")
