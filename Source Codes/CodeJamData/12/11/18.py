def alphabet(a, b, z):
    ans = float(b+2)
    p = 1
    for i in xrange(a):
        p *= z[i]
        v = p*(a+b-(i+1)*2+1)+(1-p)*(a+b-(i+1)*2+1+b+1)
        if v<ans:
            ans = v
    return ans

if __name__ == "__main__":
    fn = open("A-large.in","r")
    tcase = int(fn.readline())
    for x in range(tcase):
        ab = fn.readline().split()
        a = int(ab[0])
        b = int(ab[1])
        kk = fn.readline()
        z = [float(k) for k in kk.split()]
        print "Case #%d: %f" % (x+1, alphabet(a,b,z))
