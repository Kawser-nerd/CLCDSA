import sys
#import psyco
#psyco.full()

def rotate(a):
    b = []
    n = len(a)
    for x in a:
        x = x.replace('.', '')
        x = x[::-1]
        x += '.' * (n-len(x))
        b.append(x)
    return b

def resolve(a, K, k):
    n = len(a)
    keyword = k * K
    for i in range(n):
        if keyword in a[i]:
            return 1

    for i in range(n):
        if keyword in ''.join([x[i] for x in a]):
            return 1

    for i in range(n):
        t = ''.join([a[x][i-x] for x in range(i+1)])
        #print t
        if keyword in t:
            return 1

    for i in range(n, 2*n):
        t = ''.join([a[x][i-x] for x in range(i-n+1, n)])
        #print t
        if keyword in t:
            return 1

    for i in range(-n, n):
        b = []
        for j in range(n):
            k = i+j
            if 0 <= k < n:
                b.append(a[j][k])
        if keyword in ''.join(b):
            return 1
        
        
    return 0
        
        

def foo(ifile):
    N, K = [int(x) for x in ifile.readline().split()]
    a = [ifile.readline().strip() for i in range(N)]
    b = rotate(a)
    #for x in b:
    #    print x
    rr = resolve(b, K, 'R')
    rb = resolve(b, K, 'B')
    #print rr, rb
    if rr:
        if rb:
            return 'Both'
        else:
            return 'Red'
    else:
        if rb:
            return 'Blue'
        else:
            return 'Neither'
        
        

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))

main(sys.stdin)
