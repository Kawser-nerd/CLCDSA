def alphabet(n, l, p):
    v = []
    for i in xrange(n):
        v.append((-p[i], i))
    v.sort()
    return " ".join([str(j[1]) for j in v])

if __name__ == "__main__":
    fn = open("A-small-attempt0.in","r")
    tcase = int(fn.readline())
    for x in range(tcase):
        ab = int(fn.readline())
        kk = fn.readline()
        zl = [int(k) for k in kk.split()]
        kk = fn.readline()
        zp = [int(k) for k in kk.split()]
        print "Case #%d: %s" % (x+1, alphabet(ab,zl,zp))
