def alphabet(nnn, s):
    mp = [4,8,None,None,3,None,9,None,1,None,None,None,None,None,0,None,None,None,5,7,None,None,None,None,None,None]
    din = [0]*36
    dout = [0]*36
    e = set()
    for i in xrange(len(s)-1):
        c = s[i]
        d = s[i+1]
        posc = ord(c)-ord('a')
        posd = ord(d)-ord('a')
        if (posc+10,posd+10) not in e:
            e.add((posc+10,posd+10))
            #print "1"
            din[posc+10] += 1
            dout[posd+10] += 1
        if mp[posc] is not None and (mp[posc],posd+10) not in e:
            e.add((mp[posc],posd+10))
            #print "2"
            din[mp[posc]] += 1
            dout[posd+10] += 1
        if mp[posd] is not None and (posc+10,mp[posd]) not in e:
            e.add((posc+10,mp[posd]))
            din[posc+10] += 1
            #print '3'
            dout[mp[posd]] += 1
        if mp[posc] is not None and mp[posd] is not None and (mp[posc],mp[posd]) not in e:
            e.add((mp[posc],mp[posd]))
            din[mp[posc]] += 1
            dout[mp[posd]] += 1
            #print '4'
    edges = sum(din)
    problem = sum([max(0,din[i]-dout[i]) for i in xrange(36)])
    if problem == 0:
        return edges+1
    else:
        return edges+problem

if __name__ == "__main__":
    fn = open("D-small-attempt0.in","r")
    tcase = int(fn.readline())
    for x in range(tcase):
        ab = int(fn.readline())
        kk = fn.readline()
        print "Case #%d: %d" % (x+1, alphabet(ab,kk[:-1]))
