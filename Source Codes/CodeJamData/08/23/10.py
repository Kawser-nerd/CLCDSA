for case in xrange(input()):
    K = input()
    l = map(int, raw_input().split())
    n = l[0]
    l = l[1:]

    d = [0] * K
    sp = range(K)
    d[0] = 1
    p = 0
    sp.pop(0)
    for k in xrange(2,K+1):
        p = (p+k-1) % len(sp)
        pl = sp.pop(p)
        d[pl] = k
        # for i in xrange(k):
        #     p = (p+1) % K
        #     while d[p] != 0:
        #         p = (p+1) % K

    print 'Case #%d: %s' % (case+1, ' '.join([str(d[p-1]) for p in l]))
    
        
