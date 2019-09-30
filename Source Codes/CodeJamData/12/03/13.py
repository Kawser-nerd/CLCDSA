import sys

import psyco; psyco.full()

def main():
    mapping = {}
    for i in xrange(1, 2000000+1):
        s = str(i)
        minval = 9999999
        for j in xrange(len(s)):
            s2 = s[j:] + s[:j]
            if s2[0] != "0":
                minval = min(minval, int(s2))
                #print minval, i
                
        mapping[i] = minval
            
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        data = [int(x) for x in f.readline().strip().split()]
        
        low = data[0]
        high = data[1]
        
        counts = {}
        for i in xrange(low, high+1):
            minval = mapping[i]        
            if minval not in counts:
                counts[minval] = 0
            counts[minval] += 1
            
        result = 0
        for v in counts:
            if counts[v] >= 2:
                t = counts[v]
                add = (t * (t-1)) / 2
                result += add
                
        print "Case #%d: %d" % (caseno+1, result)

main()