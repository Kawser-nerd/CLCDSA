import sys

def ff(res, x):
    r = x
    while res[r] >= 0:
        r = res[r]
    if res[x] >= 0:
        res[x] = r
    return r

def mm(res, x, y):
    x1 = ff(res, x)
    y1 = ff(res, y)
    if x1 == y1:
        return False
    if x1 > y1:
        x1, y1 = y1, x1
    res[x1] += res[y1]
    res[y1] = x1
    return True

primes = [1] * 1000003
def initprime():
    primes[0] = 0
    primes[1] = 0
    n = len(primes)
    for i in range(n):
        if not primes[i]:
            continue
        j = i * 2
        while j < n:
            primes[j] = 0
            j += i

def foo(idx, ifile):
    A, B, P = tuple([int(x) for x in ifile.readline().split()])
    c = B-A+1
    res = [-1] * c
    res2 = len(res)
    for i in range(P, 1000002):
        if not primes[i]:
            continue
        ai = (A-1) // i + 1
        bi = B // i + 1
        ks = [i*j-A for j in range(ai, bi)]
        if not ks or len(ks) == 1:
            continue

        for j in range(1, len(ks)):
            if mm(res, ks[0], ks[j]):
                res2 -= 1
    print 'Case #%i: %s' % (idx, res2)

def main():
    initprime()
    ifile = file(sys.argv[1])
    n = int(ifile.readline().strip())
    for i in range(n):
        foo(i+1, ifile)

if __name__ == '__main__':
    main()
