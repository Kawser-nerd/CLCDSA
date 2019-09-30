'''
Created on May 20, 2011

@author: herman
'''

infile = open("small_input.txt","r")
outfile = open("small_output.txt","w")

trials = int(infile.readline())

for i in xrange(trials):
    N = int(infile.readline())
    stats = []
    for j in xrange(N):
        stats.append(infile.readline().strip())
    WP = [0.0 for x in xrange(N)]
    WPex = [[0.0 for x in xrange(N)] for y in xrange(N)]
    
    WPtotal = [0.0 for x in xrange(N)]
    for j in xrange(N):
        for k in xrange(N):
            if stats[j][k] == "1":
                WP[j] += 1.0
                WPtotal[j] += 1.0
            elif stats[j][k] == "0":
                WPtotal[j] += 1.0
                
    #print "WPTOTAL,WP\n"
    #for j in xrange(N):
    #    print WPtotal[j],WP[j]
    for j in xrange(N):
        for k in xrange(N):
            total = WPtotal[j]
            WPex[j][k] = WP[j]
            if stats[j][k] == "1":
                WPex[j][k] -= 1.0
                total -= 1.0
            elif stats[j][k] == "0":
                total -= 1.0
            WPex[j][k] = WPex[j][k] / total
        WP[j] = WP[j] / WPtotal[j]
    #print "WPex"
    #for j in xrange(N):
    #    print WPex[j]
    OWP = [0.0 for x in xrange(N)]
    for j in xrange(N):
        for k in xrange(N):
            if j != k and stats[j][k] != ".":
                OWP[j] += WPex[k][j]
        OWP[j] = OWP[j] / WPtotal[j]
    #print "OWP"
    #for j in xrange(N):
    #    print OWP[j]
    
    OOWP = [0.0 for x in xrange(N)]
    for j in xrange(N):
        for k in xrange(N):
            if j != k and stats[j][k] != ".":
                OOWP[j] += OWP[k]
        OOWP[j] = OOWP[j] / WPtotal[j]
            
    #print "OOWP"
    #for j in xrange(N):
    #    print OOWP[j]
                
    s = "Case #%d: \n" % (i+1)
    for j in xrange(N):
        s += "%f\n" % ((0.25*WP[j]) + (0.5*OWP[j]) + (0.25*OOWP[j]))
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
