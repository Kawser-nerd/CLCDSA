for i in xrange(int(raw_input())):
    n, K = map(int, raw_input().split(" "))
    l = []
    for j in xrange(n):
       l.append(raw_input()[:n])
    for j in xrange(n):
       l[j] = l[j].replace('.','').rjust(n, ".")
    blue = False
    red = False
    for j in xrange(n):
       for k in xrange(n-K+1):
           if l[j][k:k+K] == "B"*K: blue = True
           if l[j][k:k+K] == "R"*K: red = True
           if ''.join([x[j] for x in l[k:k+K]]) == "B"*K: blue = True
           if ''.join([x[j] for x in l[k:k+K]]) == "R"*K: red = True
    for j in xrange(n-K+1):
       for k in xrange(n-K+1):
            if ''.join([l[j+z][k+z] for z in xrange(K)]) == "B"*K: blue = True
            if ''.join([l[j+z][k+z] for z in xrange(K)]) == "R"*K: red = True
    for j in xrange(n-K+1):
       for k in xrange(K-1, n):
            if ''.join([l[j+z][k-z] for z in xrange(K)]) == "B"*K: blue = True
            if ''.join([l[j+z][k-z] for z in xrange(K)]) == "R"*K: red = True
    if blue and red: print "Case #%i: Both" %(i+1)
    if blue and not red: print "Case #%i: Blue" %(i+1)
    if not blue and red: print "Case #%i: Red" %(i+1)
    if not blue and not red: print "Case #%i: Neither" %(i+1)
