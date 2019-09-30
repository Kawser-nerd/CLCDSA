import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        data = [int(x) for x in f.readline().strip().split()]
        
        numentries = data[0]
        surprising = data[1]
        threshold = data[2]
        
        entries = data[3:]
        
        good = 0
        potential = 0
        for entry in entries:
            d = entry / 3
            m = entry % 3
            if m == 0:
                normal = (d,d,d)
                surp = (d-1,d,d+1)
            elif m == 1:
                normal = (d,d,d+1)
                surp = (d-1,d+1,d+1)
            else:
                normal = (d,d+1,d+1)
                surp = (d,d,d+2)
                
            if sum(surp) != entry:
                raise Exception("DSDSDSDD")
                
            if sum(normal) != entry:
                raise Exception("DSDSDSDD")
                
            if max(surp) - min(surp) != 2:
                raise Exception("DSDSDSDD")
                
            if max(normal) - min(normal) > 1:
                raise Exception("DSDSDSDD")
                
            for v in surp:
                if v < 0 or v > 10:
                    surp = normal
                    break
                
            nflag = 0
            for v in normal:
                if v >= threshold:
                    nflag = 1
                    break
                
            sflag = 0
            for v in surp:
                if v >= threshold:
                    sflag = 1
                    break
                
            if nflag == 1:
                good += 1
                
            if nflag == 0 and sflag == 1:
                potential += 1
                
                
        result = good + min(potential, surprising)
        print "Case #%d: %d" % (caseno+1, result)
            

main()