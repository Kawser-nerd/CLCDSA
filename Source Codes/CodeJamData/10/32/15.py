import sys

def ntests(L, P, C):
    #print L,P,C
    ratio = P*1.0/L
    if ratio<=C: return 0

    # special case that otherwise causes infinite loop
    if L==1 and P==3: return 1

    # test at the square root of the ratio
    testpoint = int(L * (ratio**0.5))
    # check both ways to handle off-by-one
    count = max(1 + ntests(L, testpoint, C), 1 + ntests(testpoint, P, C))
    # if exact square root, we're done
    if (testpoint*testpoint==L*P or testpoint+1==P):
        return count
    # otherwise see if trying testpoint+1 is better
    count2 = max(1 + ntests(L, testpoint+1, C), 1 + ntests(testpoint+1, P, C))
    return min(count, count2)
    

infile = sys.stdin
T = int(infile.readline().strip())        
for i in xrange(T):
    L,P,C = map(int, infile.readline().strip().split())
    result = ntests(L,P,C)
    print("Case #%d: %s" % (i+1, str(result)))
    
