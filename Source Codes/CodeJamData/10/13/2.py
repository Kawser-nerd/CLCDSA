import sys

cache = {}
a = []

N= 1000003

def fill_a(a):
    a[:] = [0] * N
    a[1] = 1
    last = 1
    last2 = 1
    for i in range(1, N):
        for j in range(last, min(a[i]+i, N)):
            a[j] = last2
        last = a[i]+i
        last2 = i+1
        if(a[i]+i >= N):
            break
        a[a[i]+i] = i+1
    #for i, x in enumerate(a):
    #    print i, x
            
        
        

def _calc(i, j):
    t1 = j // i;
    t2 = j % i;

    if t1 == 1:
        if calc(j-i, i) == 0:
            return 1
        else:
            return 0

    return 1

def calc(i, j):
    if i > j:
        i, j = j, i
    if i == j:
        return 0
    if (i, j) not in cache:
        t = _calc(i, j)
        cache[(i,j)] = t
    return cache[(i,j)]

def foo(ifile):
    A1, A2, B1, B2 = [int(x) for x in ifile.readline().split()]
    res = 0
    for i in range(A1, A2+1):
        t1 = a[i]
        t2 = a[i] + i
        n = B2 - B1 + 1
        t3 = max(0, min(t2, B2+1) - max(B1, t1))
        res += n - t3
    return res
            
    

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))

def tmp():
    for i in range(1, 10):
        b = None
        last = None
        for j in xrange(i//2+1, i**2):
            t = calc(i, j)
            if t == last:
                continue
            else:
                if last == 0:
                    print i, b, j-1, last
                b = j
                last = t
        #print b, 1000000, last

if __name__ == '__main__':
    fill_a(a)
    main(sys.stdin)
