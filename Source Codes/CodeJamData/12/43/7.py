def alphabet(n, z):
    ans = [0]*n
    ans[-1] = 1000000000
    for i in xrange(n-1,-1,-1):
        fir = True
        firj = None
        for j in xrange(i):
            if z[j]==i:
                if fir:
                    if i==n-1:
                        ans[j] = ans[i]
                    else:
                        h = ans[z[i]]-ans[i]
                        w = z[i]-i
                        v = i-j
                        ans[j] = ans[i]-(h*v+w-1)/w
                    fir = False
                    firj = j
                else:
                    if i==n-1:
                        ans[j] = ans[i]-1
                    else:
                        h = ans[i]-ans[firj]
                        w = i-firj
                        v = i-j
                        ans[j] = ans[i]-(h*v+w)/w
    ver = True
    for i in xrange(n-1):
        see = i+1
        for j in xrange(i+2,n):
            if (ans[j]-ans[i])*(see-i) > (ans[see]-ans[i])*(j-i):
                see = j
        if see != z[i]:
            ver = False
            break
    m = min(ans)
    #if not ver:
    #    print "FAIL"
    if m < 0 or not ver:
        return "Impossible"
    else:
        ansmod = [str(y-m) for y in ans]
        return " ".join(ansmod)

if __name__ == "__main__":
    fn = open("C-small-attempt1.in","r")
    tcase = int(fn.readline())
    for x in range(tcase):
        ab = int(fn.readline())
        kk = fn.readline()
        z = [int(k)-1 for k in kk.split()]
        print "Case #%d: %s" % (x+1, alphabet(ab,z))
