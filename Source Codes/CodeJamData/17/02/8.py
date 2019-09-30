for cas in xrange(1,1+input()):
    n = map(int, raw_input())
    mn = 10
    last9 = len(n)-1
    for i in xrange(len(n)-1,-1,-1):
        if n[i] > mn:
            n[i] -= 1
            while last9 > i:
                n[last9] = 9
                last9 -= 1
            mn = 10
        mn = min(mn, n[i])
    ans = ''.join(map(str, n)).lstrip('0')

    print "Case #%s: %s" % (cas, ''.join(ans))
