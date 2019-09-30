for cas in xrange(1,1+input()):
    s, k = raw_input().strip().split()
    k = int(k)
    s = [v != '+' for v in s]
    f = [0]*(len(s)+1)
    m = 0
    for i in xrange(len(s)):
        if i+k <= len(s) and (s[i] ^ f[i]):
            f[i] ^= 1
            f[i+k] ^= 1
            m += 1
        s[i] ^= f[i]
        f[i+1] ^= f[i]
    print "Case #%s: %s" % (cas, 'IMPOSSIBLE' if any(s) else m)
