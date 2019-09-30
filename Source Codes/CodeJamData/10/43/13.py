C = int(raw_input())

for c in range(C):
    R = int(raw_input())
    d = []
    for i in range(R):
        v = map( int, raw_input().split() )
        x1, y1, x2, y2 = v
        #print "v", v
        for x in range(x1, x2+1):
            for y in range(y1, y2+1):
               d.append( (x, y) )
    #print d
    dat = set(d)
    
    t = 0
    while dat:
        ndat = set()
        for x, y in dat:
            if (x-1, y) in dat or (x, y-1) in dat:
                ndat.add( (x, y) )
            if (x-1, y+1) in dat:
                ndat.add( (x, y+1) )
        dat = ndat
        t += 1
        #print t, dat
    
    print "Case #%d: %d" % (c+1, t)