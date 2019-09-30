
mem = {}
memch = {}

def ch(n,k):
#    print 'call', n, k
    if k == 0 or k == n:
        return 1
    if k > n:
        return 0
    if (n,k) in memch:
        return memch[(n,k)]
    rv = ch(n-1,k-1) + ch(n-1,k)
    memch[(n,k)] = rv
    return rv

def p_gets(n,r,d,g):
#    print '    >>> gets', n, r, d, g
    if g > r or g > d or n < g:
        return 0.0
    assert n >= r
#    print ' !!! ', n, d, float(ch(n,d))
    return ch(r,g) * ch(n-r,d-g) / float(ch(n,d))

def e(c,r,n):
#    print '*** e', c, r, n
    if r == 0:
        return 0.0
    if (c,r,n) in mem:
        return mem[(c,r,n)]
    p_stay = p_gets(n,r,c,0)
#    print '  stay', p_stay
    e_red = 0.0
    for g in xrange(1, r+1):
        e_red += p_gets(n,r,c,g) * e(c, r-g, n)
#        print '  red', r, e_red
    rv = (1 + e_red) / (1 - p_stay)
    mem[(c,r,n)] = rv
    return rv

def ans(c,n):
    return e(c,n,n)

import sys

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for i in xrange(1,T+1):
        mem = {}
        memch = {}
        n, c = map(int,sys.stdin.readline().split(' '))
        print 'Case #%d: %.7f' % (i, ans(c,n))
