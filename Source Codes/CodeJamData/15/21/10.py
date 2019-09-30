def split(nn, sp):
    aareal = nn / (10**sp)
    bb = nn % (10**sp)
    aa = int(str(aareal)[::-1])
    return (aareal, aa, bb)

tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    l = len(str(n))
    ans = 0
    if l == 1:
        ans = n
    else:
        for i in xrange(1,l):
            if i == 1:
                ans += 10
            elif i % 2 == 0:
                ans += 2*(10 ** (i/2))-1
            else:
                ans += (10 ** ((i+1)/2))+(10 ** ((i-1)/2))-1
        if l % 2 == 0:
            delta = n - (10 ** (l-1))
            if delta > 2:
                alen = l/2
                blen = l/2
                (areal,a,b) = split(n,blen)
                if b == 0:
                    delta = min(delta, int(str(areal-1)[::-1])+(10**blen))
                else:
                    delta = min(delta, a+b)
            ans += delta
        else:
            delta = n - (10 ** (l-1))
            if delta > 2:
                # take 1
                alen = (l+1)/2
                blen = (l-1)/2
                (areal,a,b) = split(n,blen)
                if b == 0:
                    delta = min(delta, int(str(areal-1)[::-1])+(10**blen))
                else:
                    delta = min(delta, a+b)
                # take 2
                alen = (l-1)/2
                blen = (l+1)/2
                (areal,a,b) = split(n,blen)
                if b == 0:
                    delta = min(delta, int(str(areal-1)[::-1])+(10**blen))
                else:
                    delta = min(delta, a+b)
            ans += delta
    print 'Case #%d: %d' % (t, ans)