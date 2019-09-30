for izi in xrange(1,1+int(raw_input())):
    n = int(raw_input())
    wires = [[int(z) for z in raw_input().split()] for k in range(n)]
    wires.sort()
    sc = len([1 for i in xrange(len(wires)-1) for j in xrange(i,len(wires)) if wires[i][1] > wires[j][1]])
    print "Case #%d: %d" % (izi, sc)
    
