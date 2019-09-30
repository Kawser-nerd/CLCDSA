def reader(inFile):
    return tuple(inFile.getInts())

from fractions import gcd

def solver((N,p,q,r,s)):
    a = [((i * p + q) % r) + s for i in xrange(N)]
    s = [0] * (N + 1)
    for i in xrange(1, N + 1):
        s[i] = s[i - 1] + a[i - 1]
    # print a, s
    smallenough = 0
    total = s[-1]
    toobig = total + 1
    while smallenough + 1 < toobig:
        mid = (smallenough + toobig) / 2
        solveig = total - mid
        a0 = 0
        a1 = N + 1
        while a0 + 1 < a1:
            a2 = (a0 + a1) / 2
            if s[a2] <= solveig:
                a0 = a2
            else:
                a1 = a2
        b0 = N
        b1 = -1
        while b1 + 1 < b0:
            b2 = (b0 + b1) / 2
            if s[b2] >= total - solveig:
                b0 = b2
            else:
                b1 = b2
        if a0 <= b0 and s[b0] - s[a0] <= solveig:
            smallenough = mid
            # print mid, solveig, s[a0], s[b0], total
        else:
            toobig = mid
            # print mid, s[a0], s[b0], "Not possible"
    return (0.0 + smallenough) / total

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2014/3/a/", "a").run()
