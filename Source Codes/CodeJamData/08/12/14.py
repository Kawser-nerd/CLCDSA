filename = "B-large.in"
f = open(filename, 'r')
of = open("B-large.out", 'w')

def try_config(ans, cust):
    #if conflict
    for c in cust:
        good = False
        for x in c:
            if(ans[x[0] - 1] == x[1]):
                good = True
                break
        if(not good):
            for x in c:
                if(x[1] == 1):
                    ans[x[0] - 1] = 1
                    if(try_config(ans, cust)):
                        good = True
                        break
                    ans[x[0] - 1] = 0
            return good
    return True


C = int(f.readline())
for x in xrange(C):
    N = int(f.readline())
    M = int(f.readline())
    customers = []
    for y in xrange(M):
        l = [int(i) for i in f.readline().split(' ')]
        l = l[1:]
        customers.append([])
        for i in xrange(len(l)/2):
            customers[-1].append((l[2*i], l[2*i + 1]))
    ans = [0]*N
    if(try_config(ans, customers)):
        s = ""
        for k in ans:
            s += "%d " % k
        print >> of, "Case #%d: %s" % (x+1, s)
        print "Case #%d: %s" % (x+1, s)
    else:
        print >> of, "Case #%d: IMPOSSIBLE" % (x+1)
        print "Case #%d: IMPOSSIBLE" % (x+1)


f.close()
of.close()
